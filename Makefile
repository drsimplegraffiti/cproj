CC = gcc
LIBS = -L/usr/local/lib -lraylib -lX11 -lXrandr -lXi -lXcursor -lXinerama -lGL -lm -lpthread -ldl
CFLAGS = -I/usr/local/include

hello: hello.c
	$(CC) hello.c -o hello $(CFLAGS) $(LIBS)
