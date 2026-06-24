### C process

- write source code
- compile i.e
- compile it to object code (object code) has a .o extension or .obj
- link it

In modern C,linking and compiling are combined into a single process called building

- original C compiler was called cc i.e C compiler
- Download C lang: https://llvm.org
  or

```bash
sudo apt update
sudo apt install clang
clang --version
```

If you’re using Linux, you already have a compiler, gcc,

#### Different compilers

```bash
clang #I recommend using the clang compiler instead of gcc
cc - C compiler
gcc - GNU c compiler #the command-line compiler in Linux is gcc,which is the GNU version of the original cc compiler from the caveman days of Unix.
```

#### remove a single file

```bash
unlink filename
```

#### compile a C program

```bash
clang -Wall filename.c #I recommend using the clang compiler instead of gcc
clang -Wall source.c -o program
```

#### Linking libraries + Using command-line compiler options

Of the slate of command-line options, one worthy of note is -
l (little L). This switch is used to link in a library. The -l is
followed immediately by the library name, as in:

```bash
clang -Wall main.c -lcurl
```

Here, the libcurl library, named curl, is linked along with
the standard C library to build a program based on the
main.c source code file. (You don’t need to specify the
standard C library, because it’s linked in by default.)

To specify an output filename, use the -o switch as covered
earlier in this chapter:

```bash
clang -Wall main.c -lcurl -o main #With some compilers, option order is relevant.
```

If you see a
slew of linker errors when using the -l switch, change the
argument order to specify -l last

```bash
clang -Wall main.c -o main -lcurl
```

#### shell

The $SHELL argument represents the environment variable assigned to the startup shell
This output may not reflect the current shell—for example, if you’ve subsequently run the sh or zsh or similar command to start another shell.

```bash
ps -p $$
```

![Image](./readme-img/251230-112443.avif)

This output shows the shell command is bash, meaning the current shell is bash regardless of the $SHELL variable’s
assignment.

- To change the shell, use the chsh command. The command is followed by the new shell name. Changing the shell affects
  only your account and applies to any new terminal windows you open after issuing the command.
  for today.

#### shell script home

When a shell starts, it processes commands located in various startup scripts. e.g /bin/bash (.bash_profile)

-The general advice is not to mess with startup shell scripts.

- the shell script files are hidden in your home directory.
  The filenames are prefixed with a single dot. The dot prefix hides files from appearing in a standard directory listing. This stealth allows the files to be handy yet concealed from a casual user’s attempts to meddle with them.

![Image](./readme-img/251230-113317.avif)

Read the content of your home script file:

```bash
cat ~/.zshrc
```

The ~/ pathname is a shortcut for your home directory.
To see the logged in user

```bash
echo "Hello" $LOGNAME
```

#### c hello world

```bash
#include <stdio.h>

int main() {

  printf("hello world\n");
  return (0);
}
```

Run:

```bash
clang -Wall main.c -o main
```

#### C with argument

```bash
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2)
    puts("Hello, you handsome beast!");
  else
    printf("Hello, %s!\n", argv[1]);
  return (0);
}

```

❶ The argument count is always 1 for the program name; if so, a default
message is output.
❷ The first word typed after the program name is represented as argv[1] and is
output here

#### Time

```bash
#include <stdio.h>
#include <time.h>
int main() {

  // The time() function requires the time_t variable’s address, prefixed here
  // with the & address-of operator.
  //
  //
  // The ctime() function requires a pointer argument and returns a string
  // appended with a newline.

  time_t now;
  time(&now);

  printf("The computer thinks it's %ld\n", now);
  printf("%s", ctime(&now));
  return (0);
}

// The output shows the number of seconds of tick-tocking since 1970.
// This same value is swallowed by the ctime() function to output a formatted
// time string.

```

#### Time 2

```bash
#include <stdio.h>
#include <time.h>

int main() {
  time_t now;
  struct tm *clock; // Because localtime() returns a pointer, it’s best to
                    // declare the structure as a pointer.

  time(&now);
  clock = localtime(&now);

  puts("Time details:");
  // In C, -> is the structure pointer member access operator.
  printf(" Day of the year: %d\n", clock->tm_yday);
  printf(" Day of the week: %d\n", clock->tm_wday);
  printf(" Year: %d\n", clock->tm_year + 1900);
  printf(" Month: %d\n", clock->tm_mon + 1);
  printf("Day of the month: %d\n", clock->tm_mday);
  printf(" Hour: %d\n", clock->tm_hour);
  printf(" Minute: %d\n", clock->tm_min);
  printf(" Second: %d\n", clock->tm_sec);

  return (0);
}
```

#### Greet app

```bash
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  time_t now;
  struct tm *clock;
  int hour;
  int min;

  time(&now);
  clock = localtime(&now);
  hour = clock->tm_hour;
  min = clock->tm_min;

  printf("hour is %d\n", hour);

  printf("Good ");
  if (hour < 12)
    printf("morning, the min is %d", min);
  else if (hour < 17)
    printf("afternoon, the min is %d", min);
  else
    printf("evening, the min is %d", min);
  if (argc > 1)
    printf(", %s", argv[1]);
  putchar('\n');

  return (0);
}
```

#### time

```go
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {

  time_t now;

  /* Get current time */
  time(&now);

  /* Safely handle missing argument */
  if (argc > 1) {
    printf("Good day, %s\n", argv[1]);
  } else {
    printf("Good day!\n");
  }

  printf("It’s %s", ctime(&now));

  return 0;
}
```

#### time 5

```go
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  time_t now;
  struct tm *clock;
  char time_string[64];
  time(&now);

  clock = localtime(&now);
  strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock);
  printf("Greetings");

  if (argc > 1)
    printf(", %s", argv[1]);
  printf("!\n%s", time_string);

  return (0);
}
```

![Image](./readme-img/251230-134556.avif)


#### Current moon phase
```go
#include <stdio.h>
#include <time.h>

/* prototype */
int moon_phase(int year, int month, int day);

int main(int argc, char *argv[]) {

  time_t now;
  struct tm *t;
  int phase;

  /* get current date */
  time(&now);
  t = localtime(&now);

  int year = t->tm_year + 1900;
  int month = t->tm_mon + 1;
  int day = t->tm_mday;

  phase = moon_phase(year, month, day);
  printf("Current Moon Phase: %d\n", phase);

  printf("Date: %04d-%02d-%02d\n", year, month, day);
  printf("Moon phase: ");

  switch (phase) {
  case 0:
    printf("New Moon\n");
    break;
  case 1:
    printf("Waxing Crescent\n");
    break;
  case 2:
    printf("First Quarter\n");
    break;
  case 3:
    printf("Waxing Gibbous\n");
    break;
  case 4:
    printf("Full Moon\n");
    break;
  case 5:
    printf("Waning Gibbous\n");
    break;
  case 6:
    printf("Last Quarter\n");
    break;
  case 7:
    printf("Waning Crescent\n");
    break;
  default:
    printf("Unknown\n");
  }

  return 0;
}

int moon_phase(int year, int month, int day) {
  int d, g, e;

  d = day;

  if (month == 2)
    d += 31;
  else if (month > 2)
    d += 59 + (month - 3) * 30.6 + 0.5;

  g = (year - 1900) % 19;
  e = (11 * g + 29) % 30;

  if (e == 25 || e == 24)
    ++e;

  return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}
```

| Value | Phase           |
| ----: | --------------- |
|     0 | New Moon        |
|     1 | Waxing Crescent |
|     2 | First Quarter   |
|     3 | Waxing Gibbous  |
|     4 | Full Moon       |
|     5 | Waning Gibbous  |
|     6 | Last Quarter    |
|     7 | Waning Crescent |


```go
#include <stdio.h>  // Provides FILE, fopen, fgets, printf, fclose
#include <stdlib.h> // Provides exit()

#define BSIZE 256 // Define a constant buffer size of 256 bytes

int main() {

  const char filename[] = "pithy.txt"; // Name of the file to read
  FILE *fp;                            // File pointer for the opened file

  char buffer[BSIZE]; // Buffer to store each line read from the file, this is used to read text from file
  char *r;            // Pointer to track fgets() return value

  fp = fopen(filename, "r"); // Open the file in read mode

  if (fp == NULL) { // Check if the file failed to open
    fprintf(stderr, "Unable to open file %s\n",
            filename); // Print error message
    exit(1);           // Exit program with error status
  }

  while (!feof(fp)) {             // Loop until end-of-file is reached
    r = fgets(buffer, BSIZE, fp); // Read a line from the file into buffer

    if (r == NULL) // Check if fgets failed (EOF or error)
      break;       // Exit the loop

    printf("%s", buffer); // Print the line that was read
  }

  fclose(fp); // Close the file and free resources

  return (0); // Exit program successfully
}
```


### NATO Translator
![Image](./readme-img/251230-150631.avif)



