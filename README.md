## Code Overview

This repository contains a program that implements a stack and a queue data structure, offering various operations for managing and interacting with these data structures. Whether you're new to programming or an experienced developer, this program provides a user-friendly way to understand and work with stacks and queues.

### Main Features

- **Stack Operations**: Push values onto the stack, search for values, find the smallest and largest values, and pop elements.
- **Queue Operations**: Enqueue values into the queue, search for values, find the smallest and largest values, and dequeue elements.
- **Input Validation**: Input is carefully validated to ensure it meets the required conditions, promoting a smooth and error-free user experience.
- **Modular Structure**: The code is organized into modular functions, each responsible for specific operations, making it easy to understand, maintain, and extend.

## Getting Started

To use the program, follow these steps:

1. **Compilation**: Compile the program using a C++ compiler. If you're using a terminal, navigate to the program directory and run `g++ program.cpp -o program`.

2. **Execution**: Run the compiled program by executing `./program` in the terminal.

3. **Main Menu**: The program will display a main menu with options to choose from. Select either "Pila" (Stack) or "Cola" (Queue).

4. **Interaction**: Depending on your choice, follow the step-by-step instructions to interact with the stack or queue. You can push, pop, search for values, and more.

5. **Exiting**: To exit the program, choose the "Salir" (Exit) option from the main menu.

## Function Descriptions

- `pushtoPila()`, `encolar()`: Pushes values onto the stack or queue after validating their positivity, parity, and uniqueness.
- `buscarPila()`, `buscarCola()`: Searches for a specified value within the stack or queue and provides its position if found.
- `menorPila()`, `menorCola()`: Finds and displays the smallest value in the stack or queue along with its position.
- `mayorPila()`, `mayorCola()`: Finds and displays the largest value in the stack or queue along with its position.
- `popPila()`, `popCola()`: Removes elements from the stack or queue while providing details about the removed values.

## Examples

For instance, to add values to the stack:

1. Choose the "Pila" option from the main menu.
2. Select the "Apilar valor" (Push value) option.
3. Follow the prompts to enter valid positive, even, and unique values.
