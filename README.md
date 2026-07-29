# c-sandbox

A personal sandbox for learning and exploring C — built incrementally as I go deeper into the language. Each project is self-contained with its own README.

---

## Projects

### Data Structures

| Project                                                         | Description                          |
| --------------------------------------------------------------- | ------------------------------------ |
| [`data-structures/linked_list`](./data-structures/linked_list/) | Singly and Doubly linked list        |
| [`data-structures/stack`](./data-structures/stack/)             | Array and linked list based stack    |
| [`data-structures/queue`](./data-structures/queue/)             | Linear, Circular and Deque ( Queue ) |

| [`dynamic_array`](./dynamic_array/) | Dynamic array for `int` — resizable buffer with manual memory management |
| [`dynamic_array_void`](./dynamic_array_void/) | Generic dynamic array using `void *` — type-agnostic resizable buffer |

### Systems / Networking

| Project                                   | Description                                    |
| ----------------------------------------- | ---------------------------------------------- |
| [`http-server`](./http-server/)           | Minimal HTTP server from scratch using sockets |
| [`memory-allocator`](./memory-allocator/) | Minimal custom memory allocator from scratch   |

---

## Goals

- Get comfortable with manual memory management (`malloc`, `realloc`, `free`)
- Understand pointers, pointer arithmetic, and `void *` generics
- Build foundational data structures from scratch
- Explore systems programming — sockets, I/O, processes
- Write clean, readable C without over-engineering

---

## Structure

```
c-sandbox/
├── dynamic_array/      # ( int ) dynamic array
├── dynamic_array_void/ # ( generic ) dynamic array
├── data-structures/
│   └── linked_list/    # singly and doubly linked list
│   └── stack/    			# Array and linked list based stack
│   └── queue/    			# Linear, circular and deque
├── http-server/        # minimal HTTP server
├── memory-allocator/   # custom memory allocator
└── README.md           # you are here
```

Each subdirectory has its own `README.md` with build instructions, usage, and notes.

---

_This repo grows as I learn. Implementations may be rough — that's the point._
