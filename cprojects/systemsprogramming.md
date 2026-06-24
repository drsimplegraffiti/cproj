# What field are Tsoding, Linux Torvalds, and Ken Thompson in?

Good question — basically, you’re asking **“what category of engineer are these people?”** since they don’t fit neatly into *backend / frontend / mobile*.

**Short answer:**
They’re in **systems & low-level software engineering**, not application development.

---

## 1. Tsoding (Tsoding Daily)

**Field:**
👉 **Systems programming / low-level software engineering / programming language implementation**

**What he actually does:**
- Writes **C, C++, Zig, Rust**
- Builds:
  - Compilers & interpreters
  - Game engines (from scratch)
  - Emulators
  - Custom build systems
- Deep focus on:
  - Memory
  - CPU behavior
  - Data-oriented design
  - Algorithms
  - Language design

**Not frontend/backend**
He rarely builds “apps” or “services”. He builds **tools and foundations** other software is built on.

**Closest industry title:**
- Systems Engineer
- Compiler Engineer
- Low-level Software Engineer
- Game Engine Programmer

---

## 2. Linux Torvalds

**Field:**
👉 **Operating Systems & kernel engineering**

**What he does:**
- Created and maintains the **Linux kernel**
- Works directly with:
  - Hardware
  - CPU scheduling
  - Memory management
  - Filesystems
  - Device drivers
- Writes almost exclusively **C**

**This is the lowest level of software you can get** (just above hardware).

**Closest industry title:**
- Kernel Engineer
- OS Engineer
- Systems Software Architect

---

## 3. Ken Thompson

**Field:**
👉 **Foundational computer science / operating systems / programming languages**

**What he did:**
- Co-created **UNIX**
- Co-created **C**
- Created **B** (precursor to C)
- Created **Go** (later at Google)
- Designed early:
  - Filesystems
  - Shells
  - OS abstractions

**He didn’t “build products” — he built the *ideas* everyone else uses.**

**Closest industry title:**
- Computer Scientist
- Systems Architect
- Programming Language Designer

---

## Where they fit compared to Backend / Frontend / Mobile

| Category | Level |
|----------|-------|
| Frontend | UI / UX |
| Backend  | APIs, databases, servers |
| Mobile   | Apps |
| **Systems programming** | **OS, compilers, runtimes** |
| **Hardware-adjacent** | **CPU, memory, drivers** |

👉 **They live below backend.**

Backend engineers *use* Linux, compilers, runtimes.
These people **build** Linux, compilers, runtimes.

---

## Modern umbrella term for all of them

If you want **one label**:

> **Systems Software Engineer**

Other valid names:
- Low-level Engineer
- Infrastructure Engineer (deep infra, not cloud)
- Platform Engineer (core platforms)
- Computer Systems Engineer

---

## Why they look “different” from normal devs

They:
- Don’t rely on frameworks
- Read specs and source code
- Think in memory, pointers, cache lines
- Care about performance, correctness, and simplicity
- Build tools, not apps

That’s why Tsoding feels “raw” compared to React or Node devs.

---

## If you’re wondering where *you* fit

If you like:
- Neovim internals
- LSP
- Unix tools
- Performance
- Building things from scratch

You’re already drifting toward **systems / tooling / infrastructure**, not pure backend.

---

If you want, you can:
- Map a **learning path** from backend → systems
- Explain **career roles** that pay well in this field
- Show how **Neovim + C/Rust** fits into this world

#### systems and utility programming
C tools:
- make For maintaining program collections
- gdb An indispensable command line debugging tool
- valgrind To help find memory leaks and bad pointers in code
- git A command line tool for version control


#### unix vs linux
- Linux was gotten from Unix
- Unix can refer to any operating system
- C is the native language of the programming interfaces in Unix System.
- Linux is a Kernel, and not entirely an operating system.
- operating systems are mostly libraries and programs developed by  GNU Project (https://www.gnu.org/gnu/gnu.html).
- (GNU is a recursively defined acronym for GNU’s Not Unix.)

