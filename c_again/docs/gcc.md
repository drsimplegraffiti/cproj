spots in a program. Here are some of the more popular options:
-Wall
-W
-pedantic
-ansi
-std=c89
-std=c99
Causes the compiler to produce warning messages when it
detects possible errors. (-W can be followed by codes for
specific warnings; 
-Wall 
means “all 
-W 
options.”) Should
be used in conjunction with 
-O 
for maximum effect.
Issues additional warning messages beyond those produced
by 
-Wall.
Issues all warnings required by the C standard. Causes pro-
grams that use nonstandard features to be rejected.
Turns off features of GCC that aren’t standard C and enables
a few standard features that are normally disabled.
Specifies which version of C the compiler should use to
check the program.
These options are often used in combination:
% gcc -O -Wall -W -pedantic -ansi -std=c99 -o pun pun.c
