# C Projects

This folder contains working C implementations for all 20 chapters from the book
**"Build Real World Tools, Games & Systems from Scratch"** by STEM School.

Each chapter is a self-contained project with its own `Makefile` and source files.

## Chapter Index

| Chapter | Project | Build | Run |
|---------|---------|-------|-----|
| 1 | Bare Metal "Hello, World!" (syscall `write`) | `make` | `./hello` |
| 2 | Hello World Framework (multi-file + Makefile) | `make` | `./hello` |
| 3 | Command-Line Calculator (PEMDAS parser) | `make` | `./calculator` |
| 4 | Task Manager (To-Do app, file persistence) | `make` | `./task_manager` |
| 5 | File Explorer Utility (POSIX filesystem) | `make` | `./file_explorer` |
| 6 | Contact Management System (dynamic memory, binary files) | `make` | `./contact_manager` |
| 7 | Console-Based Text Editor (raw mode, ANSI escape) | `make` | `./editor sample.txt` |
| 8 | Multi-Player Tic-Tac-Toe (scoreboard) | `make` | `./tictactoe` |
| 9 | Snake Game (real-time console game) | `make` | `./snake` |
| 10 | Simple Shell (fork/exec, pipes, redirection) | `make` | `./shell` |
| 11 | Lightweight Chat App (TCP client-server) | `make` | `./server` + `./client` |
| 12 | Password Manager (XOR encryption) | `make` | `./password_manager` |
| 13 | Text-Based RPG Game (combat, leveling) | `make` | `./rpg` |
| 14 | Custom Memory Allocator (malloc/free) | `make` | `./allocator_test` |
| 15 | Mini HTTP Server (static file server) | `make` | `./http_server` |
| 16 | Weather Dashboard (libcurl + cJSON API) | `make` | `./weather_dashboard` |
| 17 | Maze Generator & Solver (DFS + BFS) | `make` | `./maze` |
| 18 | Basic Compiler (mini language to C) | `make` | `./compiler` |
| 19 | Virtual Machine (stack-based bytecode) | `make` | `./vm` |
| 20 | Modular OS Shell (final project) | `make` | `./shell` |

## Build Notes

- Chapters 1–15, 17–20 build with just `gcc` (standard C, POSIX where noted).
- Chapter 16 (**Weather Dashboard**) requires `libcurl` and `cJSON`:
  - Debian/Ubuntu: `sudo apt-get install libcurl4-openssl-dev libcjson-dev`
  - macOS (Homebrew): `brew install curl cjson`
- Chapter 7 (Text Editor) and Chapter 9 (Snake) use POSIX terminal APIs (`termios`) — best on Linux/macOS.
- Chapter 10 (Shell) and Chapter 15 (HTTP Server) use `fork()`/`exec()`/sockets — Linux/macOS.

## Quick Test (chapters that need no external libs)

```bash
cd "C Projects/Chapter 03 - Command Line Calculator"
make && echo "3 + 5 * 2" | ./calculator
```

## License

Educational projects from "Build Real World Tools, Games & Systems from Scratch" (STEM School / OceanofPDF).
