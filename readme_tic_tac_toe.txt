# Tic-Tac-Toe: The AI That Roasts You As It Beats You

## 💡 What is this?

This is a classic **Tic-Tac-Toe** game implemented in C...  
...with a twist: the AI has a superiority complex, a sense of sarcasm, and zero chill.

The AI will:
- Evaluate moves using heuristic grading.
- Try to win, block, and corner you like a pro.
- Mock your mistakes.
- Cry (dramatically) when it loses.
- Take your FEEEEET when it wins. 🦶

All packed inside a single beautiful .c file. Yes, it’s monolithic. Deal with it.

---

## 🚀 How to Run

1. Make sure you have GCC installed.
2. Compile using:
3. Run the game:

4. Follow the prompts, press enter for dramatic flair, and try not to lose.

---

## 🧠 How the AI Works

- Uses a 3x3 board to simulate the game.
- Grades every possible move based on:
- Blocking the player (+90)
- Corners and center bonuses
- Potential win forks (can be added)
- AI plays `'o'`, player plays `'x'`
- First or second turn choice available
- Sarcasm not optional

---

## 🎮 Controls

- You will be asked to enter coordinates for your move in the form:

where x = row (0 to 2), y = column (0 to 2)

- Want to mess with the AI? Try entering `9 9`. You’ll see. 😉

---

## 🤖 Future Ideas

- Implement true Minimax or Alpha-Beta pruning
- Add a GUI using SDL or ncurses
- Let the AI trash talk in more languages
- Port to web as a rage-inducing browser game

---

## 📎 File Contents

- `tic_tac_toe.c` – All the logic, AI, print statements, and sass
- No external libraries. Just ANSI C and a bad attitude.

---

## 👤 Created by

Robin – Future overlord of sarcastic game AIs.  

---

## 🧪 Final Words

If you beat this AI:
- Congratulations, you’re above average.
- Expect no mercy in version 2.0.

If you lose:
- Accept defeat.
- Accept sarcasm.
- Accept toe-loss.

Enjoy the game.


