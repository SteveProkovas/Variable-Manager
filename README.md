# Variable Manager

Variable Manager is a C program designed to manage variables and their data types within a program. It provides functionality to add, display, search for, and delete variables in a linked list data structure.

## Description

The program utilizes a linked list data structure to store variables and their corresponding data types. Each variable is represented as a node in the linked list, containing fields for the variable name and its data type. The provided functions allow users to interact with the list by adding, displaying, searching for, and deleting variables.

## Features

1. **Dynamic Memory Allocation**: Variable names are stored using dynamic memory allocation, allowing for variable names of any length.

2. **Error Handling**: Proper error handling is implemented for memory allocation to prevent memory leaks. Error messages are displayed if memory allocation fails.

3. **Type Checking**: Global variables are used to perform type checking for operations between variables. Type checking functions are simplified and robust.

4. **Improved List Management**: List deletion functions include checks to ensure that the list is not already empty before attempting to delete it. Memory for variable names and nodes is properly deallocated during list deletion.

5. **Enhanced Output Messages**: Output messages are refined to provide clearer information about the status of operations and error conditions.

## Usage

### Compilation

Compile the `main.c` file using a C compiler:

```bash
gcc -o variable_manager main.c
```

### Execution

Run the compiled executable:

```bash
./variable_manager
```

## Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Creating a list
    node_pointer list;
    list = NULL;

    // Adding variables to the list
    add_variable(&list,"a","int");
    add_variable(&list,"b","int");
    add_variable(&list,"c","float");

    // Displaying the list
    show_list(list);

    // Searching for a variable
    int found = variable_in_list(list, "a");
    if (found)
        printf("Variable found in the list\n");
    else
        printf("Variable not found in the list\n");

    // Deleting the list
    delete_list(&list);

    return 0;
}
```

## Future Extensions

- **Variable Type Checking:** Implement advanced functionality for type checking, ensuring compatibility between operations.

- **User Input Handling:** Allow users to interactively input variables and data types, providing a user-friendly interface.

- **File I/O Support:** Enable reading variables and data types from files and writing them back, facilitating data persistence.

- **Dynamic Memory Management:** Implement dynamic memory management techniques to optimize memory usage and performance.

## License

This project is licensed under the Apache License 2.0 - see the `LICENSE` file for details.
