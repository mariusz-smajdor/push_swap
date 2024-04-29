# Push_swap

## Description
push_swap is a project developed as part of the curriculum at 42 school. The goal of this project is to sort a stack of integers using a limited set of instructions, with the fewest possible operations. The project aims to explore sorting algorithms, data structures, and algorithm optimization techniques.

## Features
- Sorts a stack of integers using a limited set of instructions
- Optimizes the sorting process to minimize the number of operations performed
- Handles large sets of integers efficiently
- Bonus: Includes a visualizer to visualize the sorting process

## Usage
To use push_swap, compile the program using the provided Makefile. Then, run the program with a list of integers as arguments to be sorted. The program will output a series of instructions to sort the integers.

Example:
```bash
make
./push_swap 5 3 1 4 2
```

To compile the bonus part (including the visualizer), use make bonus:
```bash
make bonus
```

To use the visualizer, pipe the output of push_swap into the checker program as follows:
```bash
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2
```
The visualizer will display the stack states and performed operations.

## Instructions
- sa : swap a - swap the first 2 elements at the top of stack a
- sb : swap b - swap the first 2 elements at the top of stack b
- ss : sa and sb at the same time
- pa : push a - take the first element at the top of b and put it at the top of a
- pb : push b - take the first element at the top of a and put it at the top of b
- ra : rotate a - shift up all elements of stack a by 1
- rb : rotate b - shift up all elements of stack b by 1
- rr : ra and rb at the same time
- rra : reverse rotate a - shift down all elements of stack a by 1
- rrb : reverse rotate b - shift down all elements of stack b by 1
- rrr : rra and rrb at the same time

# Contributing
Contributions to the push_swap project are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request on the GitHub repository.
