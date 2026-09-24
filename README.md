# Minitalk

A 42 project in C that sends text between two processes using Unix signals. The client converts each byte into bits; the server reconstructs the bytes and prints the message.

## How it works

1. The server prints its process ID (PID) and waits for signals.
2. The client takes that PID and a message as arguments.
3. Each byte is sent from its most significant bit to its least significant bit: `SIGUSR1` represents `1`, and `SIGUSR2` represents `0`.
4. The server reconstructs a character after eight signals.
5. A null byte (`\0`) marks the end of the message and makes the server print a newline.

The client waits 200 microseconds between signals. There is no acknowledgement from the server or retry mechanism.

## Build

Requires a Unix-like environment with `gcc` and `make`. The utility library is included in `Libft/`.

**Current build issue:** `make` fails because [`Libft/libft.h`](Libft/libft.h) contains unresolved Git conflict markers. Resolve that conflict before using the commands below.

```bash
git clone https://github.com/PSGui/42-Minitalk.git
cd 42-Minitalk
make
```

| Command | Purpose |
| --- | --- |
| `make` | Build `server`, `client` and the bundled library. |
| `make clean` | Remove object files, including those in `Libft`. |
| `make fclean` | Also remove the executables and static library. |
| `make re` | Clean and rebuild. |

The Makefile contains a bonus target, but its variables are commented out and no separate bonus sources are included.

## Usage

After resolving the build issue, start the server in one terminal:

```bash
./server
```

It prints `Server initialized - PID: <number>`. In a second terminal, send a message using that PID:

```bash
./client <server_pid> "Hello, Minitalk!"
```

Replace `<server_pid>` with the actual positive PID printed by the running server. The intended output in the server terminal is:

```text
Hello, Minitalk!
```

The server keeps waiting after each message. Use `Ctrl+C` to stop it. Send messages from one client at a time.

## Files

| File | Purpose |
| --- | --- |
| [`client.c`](client.c) | Check arguments, convert characters into bits and send signals. |
| [`server.c`](server.c) | Register signal handlers, reconstruct characters and print received text. |
| [`minitalk.h`](minitalk.h) | Shared includes, declarations and message terminator. |
| [`Libft/`](Libft/) | Character, string and formatted-output utilities. |
| [`Makefile`](Makefile) | Build and cleanup commands. |

## Limitations

- PID validation checks digit characters but does not reliably reject zero, empty or out-of-range values. The client also ignores errors returned by `kill()`.
- Delivery depends on a fixed delay; the client cannot confirm that the complete message arrived.
- The server uses one shared decoding state and does not distinguish between senders, so overlapping clients can corrupt messages.

Build failure was reproduced in this version. Runtime behavior has not been verified.
