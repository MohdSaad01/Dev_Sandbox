# 📝 Rust Todo App

A simple command-line Todo application built with **Rust**. This project was created to practice the fundamentals of Rust while building something useful.

## ✨ Features

* ➕ Add new tasks
* 📋 View all tasks
* ✅ Mark tasks as completed
* 🗑️ Delete tasks
* 🚪 Exit the application

## 📁 Project Structure

```text
TodoApp/
│
├── Cargo.toml
├── README.md
└── src/
    └── main.rs
```

## 💻 Example

```text
==========================
        TODO APP
==========================
1. Add Task
2. View Tasks
3. Complete Task
4. Delete Task
5. Exit
==========================

Enter your choice: 1

Enter task:
Learn Rust

Task added successfully.

Enter your choice: 2

Your Tasks:
1. [ ] Learn Rust
```

After completing the task:

```text
Your Tasks:
1. [✓] Learn Rust
```