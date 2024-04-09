# Variable Manager

Variable Manager is a simple C program that manages variables and their data types using a linked list data structure. It allows users to add variables, perform type checking, display the list of variables, and perform operations between variables.

## Features

- **Dynamic Memory Allocation**: Variable names and data types are stored using dynamic memory allocation, allowing for flexible lengths.
- **Error Handling**: Proper error handling is implemented for memory allocation to prevent memory leaks. Error messages are displayed if memory allocation fails.
- **Type Checking**: Global variables are used to perform type checking for operations between variables. Type checking functions are simplified and robust.
- **Enhanced List Management**: List deletion functions include checks to ensure that the list is not already empty before attempting to delete it. Memory for variable names and data types is properly deallocated during list deletion.
- **Enhanced Output Messages**: Output messages are refined to provide clearer information about the status of operations and error conditions.

## Usage

1. **Compilation**: Compile the `variable_manager.c` file using a C compiler. For example, using `gcc`:

   ```bash
   gcc variable_manager.c -o variable_manager
   ```

2. **Execution**: Run the compiled executable:

   ```bash
   ./variable_manager
   ```

3. **Example Usage**: The program demonstrates adding variables, performing operations, and displaying the list of variables. You can modify the `main` function to suit your specific use case.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definition of the node structure
typedef struct node {
    char* name; // Dynamic memory allocation for variable names
    char* data_type; // Dynamic memory allocation for data types
    struct node* next;
} node;

// Definition of the pointer to a node
typedef node* node_pointer;

// Global variables for type checking (1 for int, 2 for float)
int type_flag;

// Function prototypes
// (Add function prototypes here)

int main() {
    // Create a list
    node_pointer list = NULL;

    // Example usage: Add some variables
    add_variable_if_not_in_list(&list, "a", "int");
    add_variable_if_not_in_list(&list, "b", "float");
    add_variable_if_not_in_list(&list, "c", "char");

    // Display the list
    show_list(list);

    // Example usage: Perform an operation
    perform_operation(list, "a", "b", "add");

    // Clean up and exit
    delete_list(&list);
    return 0;
}
```

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or create a pull request on GitHub.

## License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details.
