# 🗺️ 50 States Guessing Game

A U.S. geography-based guessing game built using **Python's Turtle Graphics** and **Pandas**. The player is shown a blank map of the United States and must correctly guess all 50 states by name. Correct guesses are displayed on the map at their respective coordinates.

## 🎮 How to Play
- Run the game.
- A blank map of the U.S. will appear.
- Enter the name of a state in the input box.
- If correct, the state name will be displayed on the map.
- The game ends when all 50 states are guessed, or the player types `Exit`.

When the player exits the game, a `missing_states.csv` file is generated with the list of states they did not guess.

## 📂 Files Included
- `main.py` – Main game logic.
- `50_States.csv` – Contains state names with their corresponding x, y coordinates on the map.
- `Blank_States_img.gif` – The blank U.S. map image used as the game background.
- `missing_states.csv` – Generated after exiting to show the states that you were not able to guess.