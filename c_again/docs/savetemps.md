In C compilers like GCC and Clang, -save-temps is a command-line flag that keeps intermediate files created during compilation instead of deleting them.

What It Does

Running gcc -save-temps main.c leaves behind the intermediate stages of compilation:
• .i — Preprocessed C source code (after expanding macros and #include directives).
• .bc — LLVM bitcode (in LLVM/Clang-based compilers).
• .s — Assembly code generated from the source.
• .o — Compiled object file.
• a.out (or -o target) — Final linked executable (when linking is not skipped with -c or -S).


Useful Variants

• -save-temps=obj — Places intermediate files alongside the output object file (when -o specifies a directory/path) instead of cluttering the current working directory. Most users on StackOverflow agree that -save-temps=obj helps avoid naming collisions when building files with identical names across different directories.
• -dumpbase <name> — Sets a custom base name for auxiliary/intermediate outputs without changing the primary output name.
