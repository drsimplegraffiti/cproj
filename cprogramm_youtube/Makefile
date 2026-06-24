# Compiler to use
CC = gcc

# Compiler flags:
# -Wall -> show all warnings
# -g    -> include debug information (useful for debugging with gdb)
CFLAGS = -Wall -g


# Target: app
# Depends on main.o (must be built first before creating app)
app: main.o 
	# $(CC) expands to gcc
	# This links the object file to create the final executable "main"
	echo "i am echo something here"
	$(CC) main.o -o main


# Pattern rule:
# %.o means "any .o file"
# %.c means "corresponding .c file"
# Example: main.o will be built from main.c
%.o: %.c
	# -c tells gcc to compile only (no linking)
	# $< refers to the first dependency (the .c file)
	$(CC) $(CFLAGS) -c $<


# Clean target:
# Used to remove generated files
clean:
	# -f forces removal without errors if files don't exist
	rm -f *.o main


# We use .o instead of .c because:
#
# Separates compilation from linking
# Enables incremental builds
# Scales for real-world projects
