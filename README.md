# Variable Manager




```c
// Definition of the node structure for the linked list
typedef struct node
{
    char name[25];
    char data_type[6];
    struct node *next;
} node;
```
This defines the structure `node` for a single node in the linked list. Each node contains the name of a variable (up to 25 characters), its data type (up to 6 characters), and a pointer to the next node in the list.

```c
// Definition of pointer to node for the linked list
typedef node* node_pointer;
```
This defines a pointer type `node_pointer`, which is a pointer to a `node` structure.

```c
// Display the contents of a list on the screen
void show_list(node_pointer list)
{
    printf("\nList:\n====================\n");
    while (list != NULL) {
        printf("Name: %s, Data Type: %s\n", list->name, list->data_type);
        list = list->next;
    }
    printf("====================\n\n");
}
```
This function `show_list` takes a pointer to the head of the linked list as input and prints out each node's name and data type until reaching the end of the list.

```c
// Search if a variable exists in the list
int variable_in_list(node_pointer list, char* name)
{
    while (list != NULL) {
        if (strcmp(list->name, name) == 0)
            return TRUE;
        list = list->next;
    }
    return FALSE;
}
```
This function `variable_in_list` searches for a variable with a given name in the linked list. It returns `TRUE` if the variable is found and `FALSE` otherwise.

```c
// Add a new variable to the beginning of the list
void add_variable(node_pointer* list, char* name, char* data_type)
{
    node_pointer new_node = (node_pointer)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->name, name);
    strcpy(new_node->data_type, data_type);
    new_node->next = *list;
    *list = new_node;
    printf("Variable %s added successfully\n", name);
}
```
This function `add_variable` adds a new variable to the beginning of the linked list. It allocates memory for a new node, copies the variable name and data type into the node, and updates the list's head pointer.

```c
// Add a variable to the list if it doesn't already exist
void add_variable_if_not_in_list(node_pointer* list, char* name, char* data_type)
{
    if (variable_in_list(*list, name) == FALSE) {
        add_variable(list, name, data_type);
    } else {
        printf("Variable %s already declared\n", name);
    }
}
```
This function `add_variable_if_not_in_list` adds a new variable to the list only if it doesn't already exist in the list. It first checks if the variable exists using `variable_in_list` function and then adds it using `add_variable` function if it doesn't exist.

```c
// Delete the list and free memory
void delete_list(node_pointer* list)
{
    while (*list != NULL) {
        node_pointer temp = *list;
        *list = (*list)->next;
        free(temp);
    }
    printf("List erased successfully\n");
}
```
This function `delete_list` deletes the entire linked list and frees the memory allocated for each node. It iterates through the list, freeing each node until the list is empty.

```c
int main()
{
    // Command to display Greek characters correctly
    system("chcp 1253>nul");

    // Creating a list
    node_pointer list;
    list = NULL;

    // Adding variables to the list
    add_variable(&list,"a","int");
    add_variable(&list,"b","int");
    add_variable(&list,"c","float");
    add_variable(&list,"d","int");
    add_variable(&list,"e","int");
    add_variable(&list,"f","float");
    add_variable(&list,"g","int");
    add_variable(&list,"h","float");
    add_variable(&list,"i","float");
    show_list(list);

    // Deleting the list
    delete_list(&list);
    show_list(list);

    // Adding variables to the list
    add_variable_if_not_in_list(&list,"a","int");
    add_variable_if_not_in_list(&list,"b","int");
    add_variable_if_not_in_list(&list,"a","float");  // Variable that already exists in the list
    add_variable_if_not_in_list(&list,"d","int");
    show_list(list);




Certainly! Let's expand on the README template to provide more detailed explanations:

---

# Variable Manager

Variable Manager is a simple C program designed to manage variables and their data types within a program. It provides functionality to add, display, search for, and delete variables in a linked list data structure.

## Features

- **Add Variable:** Add variables with their names and data types to the list. The program ensures that each variable is unique within the list.
- **Display List:** Display the current list of variables and their data types. This allows users to view all variables stored in the list at any point.
- **Search Variable:** Search for a variable by name within the list. This feature helps users determine whether a variable is already declared before adding it.
- **Delete List:** Delete all variables from the list. This feature is useful for clearing the list and freeing up memory when needed.

## Usage

1. **Compilation:**
   - Compile the `ypoergasia_4_template.c` file using a C compiler (e.g., gcc).
   ```
   gcc -o variable_manager ypoergasia_4_template.c
   ```

2. **Execution:**
   - Run the compiled executable.
   ```
   ./variable_manager
   ```

3. **Adding Variables:**
   - Use the `add_variable` function to add variables with their names and data types to the list.
   ```c
   add_variable(&list,"variable_name","data_type");
   ```
   - For example, `add_variable(&list,"a","int")` adds a variable named "a" with the data type "int" to the list.

4. **Displaying List:**
   - Use the `show_list` function to display the current list of variables and their data types.
   ```c
   show_list(list);
   ```
   - This function iterates through the list and prints each variable's name and data type.

5. **Searching for Variables:**
   - Use the `variable_in_list` function to search for a variable by name within the list.
   ```c
   variable_in_list(list, "variable_name");
   ```
   - This function returns `TRUE` if the variable is found in the list and `FALSE` otherwise.

6. **Deleting List:**
   - Use the `delete_list` function to delete all variables from the list and free memory.
   ```c
   delete_list(&list);
   ```
   - This function deallocates memory for each node in the list and sets the list's head pointer to NULL.

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

This example demonstrates how to use the functions provided by the Variable Manager to manage variables within a program. It adds variables "a", "b", and "c" to the list, displays the list, searches for variable "a", and then deletes the list.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

This expanded README provides a detailed overview of the Variable Manager project, including its features, usage instructions, an example usage in code, and licensing information. You can further customize it based on your project's specific needs.

    return 0;
}
```
This is the `main` function. It demonstrates how to use the provided functions:
- It adds several variables of different types to the list.
- It displays the list.
- It deletes the list.
- It adds variables again, including one that already exists.
- Finally, it displays the list again.

This is the overall structure and functionality of the provided code. It creates a linked list of variables and their data types, provides functions to manipulate the list, and demonstrates their usage in the `main` function.
