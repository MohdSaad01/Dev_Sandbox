use std::io;

struct Todo {
    title: String,
    completed: bool,
}

fn main() {
    let mut todos: Vec<Todo> = Vec::new();

    loop {
        print_menu();

        let choice = get_input("Enter your choice: ");

        match choice.trim() {
            "1" => add_task(&mut todos),
            "2" => view_tasks(&todos),
            "3" => complete_task(&mut todos),
            "4" => delete_task(&mut todos),
            "5" => {
                println!("\nGoodbye!");
                break;
            }
            _ => println!("\nInvalid choice!\n"),
        }
    }
}

fn print_menu() {
    println!("\n==========================");
    println!("        TODO APP");
    println!("==========================");
    println!("1. Add Task");
    println!("2. View Tasks");
    println!("3. Complete Task");
    println!("4. Delete Task");
    println!("5. Exit");
    println!("==========================");
}

fn add_task(todos: &mut Vec<Todo>) {
    let title = get_input("Enter task: ");

    todos.push(Todo {
        title,
        completed: false,
    });

    println!("Task added successfully.");
}

fn view_tasks(todos: &Vec<Todo>) {
    if todos.is_empty() {
        println!("\nNo tasks found.");
        return;
    }

    println!("\nYour Tasks:");

    for (index, todo) in todos.iter().enumerate() {
        let status = if todo.completed { "✓" } else { " " };

        println!("{}. [{}] {}", index + 1, status, todo.title);
    }
}

fn complete_task(todos: &mut Vec<Todo>) {
    if todos.is_empty() {
        println!("\nNo tasks to complete.");
        return;
    }

    view_tasks(todos);

    let input = get_input("\nEnter task number: ");

    match input.trim().parse::<usize>() {
        Ok(num) if num >= 1 && num <= todos.len() => {
            todos[num - 1].completed = true;
            println!("Task marked as completed.");
        }
        _ => println!("Invalid task number."),
    }
}

fn delete_task(todos: &mut Vec<Todo>) {
    if todos.is_empty() {
        println!("\nNo tasks to delete.");
        return;
    }

    view_tasks(todos);

    let input = get_input("\nEnter task number: ");

    match input.trim().parse::<usize>() {
        Ok(num) if num >= 1 && num <= todos.len() => {
            todos.remove(num - 1);
            println!("Task deleted.");
        }
        _ => println!("Invalid task number."),
    }
}

fn get_input(prompt: &str) -> String {
    println!("{}", prompt);

    let mut input = String::new();

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read input");

    input.trim().to_string()
}