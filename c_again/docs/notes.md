For readonly use:
```c
const char *name = "somename";
```
For mutable
```c
char name[size] = "some name";
```



```bash
Of the slate of command-line options, one worthy of note is -l (little L). This switch is used to link in a library. The -l 
is followed immediately by the library name, as in: clang -Wall weather.c -lcurl
```

clang -Wall weather.c -lcurl -o weather

```bash
exec $SHELL
which $SHELL
ps -p $$ # current shell
```

```bash
gcc -Wall -Wextra -Wpedantic -g \
-fsanitize=address,undefined \
-fno-omit-frame-pointer \
tinyc/greet03.c -o main
```

```bash
gcc -std=c2x -Wall -Wextra -Wpedantic -g \
-fsanitize=address,undefined \
-fno-omit-frame-pointer \
tinyc/greet03.c -o main
```

What each flag does
Flag	Purpose
-Wall	Enables common warnings
-Wextra	Enables additional warnings
-Wpedantic	Enforces stricter ISO C diagnostics
-g	Generates debugging information
-fsanitize=address	Detects memory errors
-fsanitize=undefined	Detects undefined behavior
-fno-omit-frame-pointer	Helps produce better stack traces

```bash
clang -Wall -Wextra -Wpedantic -g \
-fsanitize=address,undefined \
-fno-omit-frame-pointer \
tinyc/greet03.c -o main
```
