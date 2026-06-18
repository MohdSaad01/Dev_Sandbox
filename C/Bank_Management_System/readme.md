# Bank Management System

A console-based banking management system written in C that supports account management, transactions, and persistent data storage.

The project demonstrates structured programming, modular design, file handling, data persistence, and robust user input validation in a multi-file C application.

---

## Features

- Create new bank accounts
- View account information
- Deposit funds
- Withdraw funds
- Transfer money between accounts
- Update account holder details
- Delete accounts
- List all accounts
- Persistent storage using binary files
- Input validation for user entries

---

## Project Structure

```text
.
├── main.c
├── bank.c
├── bank.h
├── accounts.dat
└── README.md
```

### File Overview

| File | Purpose |
|--------|---------|
| `main.c` | Application entry point and menu system |
| `bank.c` | Core banking operations and file handling |
| `bank.h` | Shared declarations, structures, and function prototypes |
| `accounts.dat` | Binary data file used for account persistence |

---

## Core Functionality

### Account Management

- Create accounts with unique account numbers
- Update account holder information
- Delete existing accounts
- View account details

### Transactions

- Deposit funds
- Withdraw funds
- Transfer money between accounts

### Data Persistence

Account data is automatically stored in a binary file and reloaded when the application starts, allowing information to persist between program executions.

### Input Validation

The application validates:

- Menu selections
- Numeric inputs
- Monetary values
- Empty names
- Invalid account numbers
- Insufficient balance conditions

---

## Build

### GCC

```bash
gcc main.c bank.c -o bank
```

### Run

Linux/macOS

```bash
./bank
```

Windows

```bash
bank.exe
```

---