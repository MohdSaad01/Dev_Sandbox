# French English Flashcards 🧠📚

A beginner-friendly flashcard app built using **Python** and **Tkinter** to help users memorize French vocabulary through interactive learning. The app automatically flips cards after a short delay to reveal English meanings, creating a simple and effective self-testing experience.

## Features
- Learn **French words** with their **English meanings**.
- Flashcards automatically flip after **2 seconds**.
- Mark words as **known** to focus on unfamiliar vocabulary.
- Saves learning progress in a `words_to_learn.csv` file.
- Minimal and clean GUI built with **Tkinter**.
- Randomized word selection for better memorization.

## Project Structure

```plaintext
project-folder/
│── data/
│   ├── french_words.csv
│   ├── words_to_learn.csv (auto-generated)
│
│── images/
│   ├── card_front.png
│   ├── card_back.png
│   ├── right.png
│   ├── wrong.png
│
│── main.py
│── README.md
```

## How It Works

1. A random **French word** appears on the card.
2. After **2 seconds**, the card flips automatically to show the **English meaning**.
3. Click:
   - ✅ **Right button** → Mark word as known and remove it from future sessions.
   - ❌ **Wrong button** → Keep the word for future practice.

## Technologies Used
- **Python**
- **Tkinter** (GUI)
- **Pandas** (CSV handling)
- **Random** (word selection)

## Future Improvements
- Add pronunciation support.
- Support multiple languages.
- Add progress tracking.
