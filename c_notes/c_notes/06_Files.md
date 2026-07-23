# 6. File Handling in C (`<stdio.h>`)

## 6.1 Opening and Closing Files
```c
FILE *fp = fopen("data.txt", "r");
if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
}
// ... work with fp ...
fclose(fp);
```

### Common Modes
| Mode | Meaning |
|---|---|
| `"r"` | read (file must exist) |
| `"w"` | write, truncates existing file / creates new |
| `"a"` | append, creates file if it doesn't exist |
| `"r+"` | read and write, file must exist |
| `"w+"` | read and write, truncates/creates |
| `"a+"` | read and append |
| add `"b"` (e.g. `"rb"`, `"wb"`) | binary mode — no text translation of newlines |

**Always check `fopen`'s return value** — it returns `NULL` on failure (file not
found, no permission, etc.).

## 6.2 Sequential (Text) File I/O
```c
// Writing
FILE *fp = fopen("out.txt", "w");
fprintf(fp, "Name: %s, Age: %d\n", name, age);
fclose(fp);

// Reading line by line
FILE *fp = fopen("out.txt", "r");
char line[100];
while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
}
fclose(fp);

// Reading formatted values
int age;
char name[30];
while (fscanf(fp, "%s %d", name, &age) == 2) {
    // process each record
}
```

### Character-by-character I/O
```c
int c;
while ((c = fgetc(fp)) != EOF) {
    putchar(c);
}
```
`fgetc` returns an `int` (not `char`) specifically so it can represent `EOF` as a
value distinct from any valid character.

## 6.3 Detecting End of File / Errors
```c
if (feof(fp)) { /* reached end of file */ }
if (ferror(fp)) { /* an error occurred */ }
```
Note: `feof()` only becomes true **after** a read attempt fails due to reaching the
end — don't use it as the sole loop condition before reading; prefer checking the
return value of the read function itself (as in the `fgets`/`fscanf` examples above).

## 6.4 Binary Files
Binary files store raw memory representations of data — faster and more compact than
text, but not human-readable and less portable across systems with different
architectures (endianness, struct padding).

```c
typedef struct { char name[30]; int age; } Person;

// Writing
FILE *fp = fopen("people.bin", "wb");
Person p = {"Alice", 30};
fwrite(&p, sizeof(Person), 1, fp);   // write 1 record of sizeof(Person) bytes
fclose(fp);

// Reading
FILE *fp = fopen("people.bin", "rb");
Person p;
while (fread(&p, sizeof(Person), 1, fp) == 1) {
    printf("%s is %d\n", p.name, p.age);
}
fclose(fp);
```

### `fwrite` / `fread` Signatures
```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
```
Both return the number of complete items actually written/read — always check this
against the expected count.

## 6.5 Random Access: `fseek`, `ftell`, `rewind`
```c
fseek(fp, 0, SEEK_END);      // move to end of file
long size = ftell(fp);        // current position = file size in bytes
rewind(fp);                    // move back to the beginning (== fseek(fp,0,SEEK_SET))

fseek(fp, n * sizeof(Person), SEEK_SET);   // jump directly to the n-th record
fread(&p, sizeof(Person), 1, fp);           // read just that record
```
`SEEK_SET` (from start), `SEEK_CUR` (from current position), `SEEK_END` (from end)
are the three reference points for `fseek`.

## 6.6 Updating a Record In Place (Binary Files)
```c
FILE *fp = fopen("people.bin", "r+b");   // read+write, doesn't truncate
fseek(fp, index * sizeof(Person), SEEK_SET);
Person updated = {"Alicia", 31};
fwrite(&updated, sizeof(Person), 1, fp);
fclose(fp);
```

## 6.7 Common Pitfalls
- Forgetting to `fclose()` — leaves data unflushed to disk / leaks file handles.
- Using text mode (`"r"`) with binary structured data (misinterprets bytes).
- Not checking `fopen` for `NULL`.
- Mixing struct definitions across systems with different padding — binary files are
  not portable between programs compiled with different alignment/architecture.
- Off-by-one errors in `fseek` offsets — always compute in terms of `sizeof(record)`.
