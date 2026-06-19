# TextScout

A simple command-line text search utility written in C.

TextScout searches through supported text-based files and displays every matching line along with its line number. The project is designed to demonstrate file handling, string processing, modular programming, and basic command-line interaction in C.

## Features

* Search for words, phrases, or text patterns
* Display matching lines with line numbers
* Show total lines checked
* Show total matches found
* Support for common text-based file formats
* Simple menu-driven interface
* Multi-file project structure

## Supported File Types

* `.txt`
* `.c`
* `.h`
* `.cpp`
* `.py`
* `.java`
* `.md`
* `.html`
* `.css`
* `.js`
* `.csv`

## Project Structure

```text
TextScout/
│
├── main.c
├── search.c
└── search.h
```

## Example

Input:

```text
Enter file name: about_saad.txt
Enter search text: Programming
```

Output:

```text
[Line 13] Programming is challenging, but programming is also rewarding.
[Line 22] - C Programming
[Line 23] - Python Programming
[Line 24] - Rust Programming

Lines Checked : 37
Matches Found : 4
```

## Purpose

This project was created as a learning exercise to practice:

* File I/O
* String handling
* Functions
* Header files
* Modular project organization
* Command-line programs
