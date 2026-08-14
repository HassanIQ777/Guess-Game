# Guess-Game

> *"One of my oldest programs."*

A terminal number guessing game written in C++. circa 2023, back when the journey was just beginning. No engine, no libutils, no spinners, no 2000-line `main.cpp`. Just `<iostream>`, `<ctime>`, and the timeless human struggle of picking a number between 1 and N.

It is 60 lines long. It is complete. It works. There is nothing to add.

---

## Gameplay

You pick a range. The game picks a secret number within `[1, N]`. You guess until you get it. The game tells you if you're too high or too low. You win. You may play again. At the end of your session, it hands you a stats summary and sends you off with *"Thanks for playing!"*

```
Range: 100
***************** Guessing Game ****************
Guess: 50
50 is too Large!

Guess: 25
25 is too Small!

Guess: 37
37 is too Large!

Guess: 31

Congrats you won!

You won in 4 tries.
**********************************************
Play again? [y/n]
> n

[Stats]: Total games played: 1
[Stats]: Total number of tries: 4
[Stats]: Average tries per game: 4
```

---

## Features

- **Custom range** - you set the upper bound `N`; the secret number is `rand() % N + 1`, so it lands in `[1, N]`
- **Hot/cold hints** - tells you if your guess is too large or too small after every attempt
- **Singular/plural grammar** - correctly says *"1 try"* vs *"4 tries"* because details matter even in 60 lines
- **Multi-session play** - `y`/`Y` to replay, `n` (or anything else) to exit
- **Session stats** - on exit, prints total games played, total tries, and average tries per game across your whole session
- **Input validation** - entering `N ≤ 0` prints an error and skips the round gracefully

---

## Optimal Strategy

Binary search. Always guess the midpoint of your remaining range. For a range of 100, you'll always win in at most 7 guesses. The game doesn't know this. It just says *"too Large"* or *"too Small"* and silently respects you.

---

## Building

No dependencies beyond `g++` and `make`.

```bash
git clone https://github.com/HassanIQ777/Guess-Game
cd Guess-Game
make
```

```bash
# Release build (default): -O2 -march=native -flto
make

# Debug build: ASan + UBSan, -Og
make debug

# Build and run
make run

# Clean ("Nothing but echoes remain...")
make clean
```

The binary lands at `./guessgame`.

---

## Running

```bash
./guessgame
```

Works on Linux, Windows, macOS, Termux - anywhere with a terminal and a C++ compiler. The entire I/O stack is `cin` and `cout`.

---

## Project Structure

```
Guess-Game/
├── main.cpp     # 60 lines
├── Makefile
├── .gitignore
└── LICENSE      # MIT
```

---

## License

MIT - It's all yours~

---

*Made by [HassanIQ777](https://github.com/HassanIQ777) - ~2023*