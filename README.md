# Variable Manager

Variable Manager is a simple C program designed to manage variables and their data types within a program. It provides functionality to add, display, search for, and delete variables in a linked list data structure.

## Description

The program utilizes a linked list data structure to store variables and their corresponding data types. Each variable is represented as a node in the linked list, containing fields for the variable name and its data type. The provided functions allow users to interact with the list by adding, displaying, searching for, and deleting variables.

## Usage

### Compilation

Compile the `main.c` file using a C compiler:

```
gcc -o variable_manager main.c
```

### Execution

Run the compiled executable:

```
./variable_manager
```

### Functions

- **Add Variable:** `add_variable(&list, "variable_name", "data_type")`
  - Adds a new variable with the specified name and data type to the list.
- **Display List:** `show_list(list)`
  - Displays the current list of variables and their data types.
- **Search Variable:** `variable_in_list(list, "variable_name")`
  - Searches for a variable by name within the list.
- **Delete List:** `delete_list(&list)`
  - Deletes all variables from the list.

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

- **Variable Type Checking:** Implement functionality to perform type checking for variables, ensuring compatibility between operations.
- **User Input Handling:** Allow users to input variables and data types interactively, providing a more user-friendly interface.
- **File I/O Support:** Enable reading variables and data types from files and writing them back, facilitating data persistence.
- **Dynamic Memory Management:** Implement dynamic memory management techniques to optimize memory usage and performance.

## License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details.
