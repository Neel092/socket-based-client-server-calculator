# Client-Server Calculator (C)

## 🚀 Overview

A modular client-server calculator built in C using socket programming.
Supports multiple input methods including file input, keyboard input, and network-based client-server communication.

---

## 🧠 Features

* Client-Server communication using TCP sockets
* Expression parsing and evaluation
* File-based input processing
* Interactive keyboard input (getch-based)
* Modular architecture (parser, calculator, networking)

---

## ⚙️ Tech Stack

* C (System Programming)
* POSIX Sockets (Networking)
* Modular Design (Multiple source files)

---

## 📂 Project Structure

```
src/
  core/
  network/
  io/
include/
```

---

## ▶️ How to Run

### Compile:

```
gcc src/*.c -Iinclude -o app
```

### Run modes:

#### Keyboard:

```
./app -k
```

#### File:

```
./app -f
```

#### Client-Server:

```
./app -C
```

---

## 🧪 Example Input

```
12+5=
10*3=
```

---

## 📌 Learnings

* Socket programming fundamentals
* Modular C project structure
* Parsing logic design
* Separation of concerns in systems

---

## 🔥 Future Improvements

* Multi-client support (thread pool)
* Logging system
* Error handling improvements
* Deployment (Docker)

---
