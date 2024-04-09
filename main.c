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

// Enumeration for data types
typedef enum {
    INT,
    FLOAT,
    CHAR
} data_type_t;

// Global variables for type checking
data_type_t type_flag;

// Display the contents of a list on the screen
void show_list(node_pointer list) {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nList:\n====================\n");

    // Print each node in the list
    while (list != NULL) {
        printf("Name: %s, Data Type: %s\n", list->name, list->data_type);
        list = list->next;
    }

    printf("====================\n\n");
}

// Search if a variable exists in the list
bool variable_in_list(node_pointer list, const char* name) {
    // Traverse the list to find the variable
    while (list != NULL) {
        if (strcmp(list->name, name) == 0)
            return true; // Variable found
        list = list->next;
    }
    return false; // Variable not found
}

// Add a new variable to the beginning of the list
bool add_variable(node_pointer* list, const char* name, const char* data_type) {
    // Allocate memory for the new node
    node_pointer new_node = (node_pointer)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed for new variable.\n");
        return false;
    }

    // Allocate memory for the name and copy it
    new_node->name = (char*)malloc(strlen(name) + 1);
    if (new_node->name == NULL) {
        printf("Error: Memory allocation failed for variable name.\n");
        free(new_node);
        return false;
    }
    strcpy(new_node->name, name);

    // Allocate memory for the data type and copy it
    new_node->data_type = (char*)malloc(strlen(data_type) + 1);
    if (new_node->data_type == NULL) {
        printf("Error: Memory allocation failed for data type.\n");
        free(new_node->name);
        free(new_node);
        return false;
    }
    strcpy(new_node->data_type, data_type);

    // Set next pointer of the new node
    new_node->next = *list;

    // Update the list to point to the new node
    *list = new_node;

    printf("Variable '%s' of type '%s' added successfully.\n", name, data_type);
    return true;
}

// Add a variable to the list if it does not already exist
bool add_variable_if_not_in_list(node_pointer* list, const char* name, const char* data_type) {
    // Check for null pointers and empty strings
    if (!list || !name || !data_type || strlen(name) == 0 || strlen(data_type) == 0) {
        printf("Error: Invalid arguments passed to add_variable_if_not_in_list.\n");
        return false;
    }

    // Check if variable already exists
    if (variable_in_list(*list, name)) {
        printf("Error: Variable '%s' already declared.\n", name);
        return false;
    }

    // Add the variable to the list
    return add_variable(list, name, data_type);
}

// Delete the list and free the memory
void delete_list(node_pointer* list) {
    if (*list == NULL) {
        printf("List is already empty\n");
        return;
    }

    node_pointer current = *list;
    node_pointer next;

    // Traverse the list and free each node
    while (current != NULL) {
        next = current->next;
        free(current->name); // Free memory for variable name
        free(current->data_type); // Free memory for data type
        free(current); // Free memory for node
        current = next;
    }

    // Reset the list pointer
    *list = NULL;

    printf("List erased successfully.\n");
}

// Variable Type Checking: Check if a variable type matches the operation type
bool variable_type_check(const char* variable_type) {
    if (type_flag == INT && strcmp(variable_type, "int") == 0)
        return true; // Type check passed for integer
    else if (type_flag == FLOAT && strcmp(variable_type, "float") == 0)
        return true; // Type check passed for float
    else if (type_flag == CHAR && strcmp(variable_type, "char") == 0)
        return true; // Type check passed for char
    else
        return false; // Type check failed
}

// Perform operation between two variables
void perform_operation(node_pointer list, const char* var1, const char* var2, const char* operation) {
    // Type checking
    type_flag = INT;
    if (!variable_in_list(list, var1) || !variable_type_check(var1)) {
        printf("Error: Variable '%s' is not a valid integer.\n", var1);
        return;
    }

    type_flag = FLOAT;
    if (!variable_in_list(list, var2) || !variable_type_check(var2)) {
        printf("Error: Variable '%s' is not a valid floating-point.\n", var2);
        return;
    }

    // Perform operation
    printf("Performing %s operation between '%s' and '%s'.\n", operation, var1, var2);
}

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
