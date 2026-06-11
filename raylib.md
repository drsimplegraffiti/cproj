
sudo apt update
sudo apt install build-essential git libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev

Then make a `Makefile`
```make
CC = gcc
LIBS = -L/usr/local/lib -lraylib -lX11 -lXrandr -lXi -lXcursor -lXinerama -lGL -lm -lpthread -ldl
CFLAGS = -I/usr/local/include

hello: hello.c
	$(CC) hello.c -o hello $(CFLAGS) $(LIBS)
```

Then run:
```bash
make
```
