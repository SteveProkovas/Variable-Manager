#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definition of the node structure
typedef struct node
{
    char* name; // Changed to use dynamic memory allocation for variable names
    char data_type[6];
    struct node* next;
} node;

// Definition of the pointer to a node
typedef node* node_pointer;

// Global variable for type checking (1 for int, 2 for float)
int type_flag;

// Display the contents of a list on the screen
void show_list(node_pointer list)
{
    if (list == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\nList:\n====================\n");

    // Print each node in the list
    while (list != NULL)
    {
        printf("Name: %s, Data Type: %s\n", list->name, list->data_type);
        list = list->next;
    }

    printf("====================\n\n");
}

// Search if a variable exists in the list
bool variable_in_list(node_pointer list, const char* name)
{
    // Traverse the list to find the variable
    while (list != NULL)
    {
        if (strcmp(list->name, name) == 0)
            return true; // Variable found
        list = list->next;
    }
    return false; // Variable not found
}

// Add a new variable to the beginning of the list
void add_variable(node_pointer* list, const char* name, const char* data_type)
{
    // Allocate memory for the new node
    node_pointer new_node = (node_pointer)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Allocate memory for the name and copy it
    new_node->name = (char*)malloc(strlen(name) + 1);
    if (new_node->name == NULL)
    {
        printf("Memory allocation failed\n");
        free(new_node);
        return;
    }
    strcpy(new_node->name, name);

    // Fill in the data for the new node
    strcpy(new_node->data_type, data_type);
    new_node->next = *list;

    // Update the list to point to the new node
    *list = new_node;

    printf("Variable %s added successfully\n", name);
}

// Add a variable to the list if it does not already exist
bool add_variable_if_not_in_list(node_pointer* list, const char* name, const char* data_type)
{
    // Check for null pointers
    if (!list || !name || !data_type)
    {
        printf("Error: Invalid arguments passed to add_variable_if_not_in_list.\n");
        return false;
    }

    // Check if variable already exists
    if (variable_in_list(*list, name))
    {
        printf("Variable %s already declared.\n", name);
        return false;
    }

    // Allocate memory for new node and name
    node_pointer new_node = (node_pointer)malloc(sizeof(node));
    if (!new_node)
    {
        printf("Memory allocation failed for new variable.\n");
        return false;
    }
    new_node->name = (char*)malloc(strlen(name) + 1);
    if (!new_node->name)
    {
        free(new_node); // Free node memory in case name allocation fails
        printf("Memory allocation failed for variable name.\n");
        return false;
    }

    // Fill in data and add node to list (remaining code from original function)
    strcpy(new_node->name, name);
    strcpy(new_node->data_type, data_type);
    new_node->next = *list;
    *list = new_node;

    printf("Variable %s added successfully\n", name);

    return true; // Indicate successful addition
}

// Delete the list and free the memory
void delete_list(node_pointer* list)
{
    if (*list == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    node_pointer current = *list;
    node_pointer next;

    // Traverse the list and free each node
    while (current != NULL)
    {
        next = current->next;
        free(current->name); // Free memory for variable name
        free(current); // Free memory for node
        current = next;
    }

    // Reset the list pointer
    *list = NULL;

    printf("List erased successfully\n");
}

// Variable Type Checking: Check if a variable type matches the operation type
bool variable_type_check(const char* variable_type)
{
    if (type_flag == 1 && strcmp(variable_type, "int") == 0)
        return true; // Type check passed for integer
    else if (type_flag == 2 && strcmp(variable_type, "float") == 0)
        return true; // Type check passed for float
    else
        return false; // Type check failed
}

// Perform operation between two variables
void perform_operation(node_pointer list, const char* var1, const char* var2, const char* operation)
{
    // Type checking
    type_flag = 1;
    if (!variable_in_list(list, var1) || !variable_type_check(var1))
    {
        printf("Error: %s is not a valid integer variable\n", var1);
        return;
    }

    type_flag = 2;
    if (!variable_in_list(list, var2) || !variable_type_check(var2))
    {
        printf("Error: %s is not a valid floating-point variable\n", var2);
        return;
    }

    // Perform operation
    printf("Performing %s operation between %s and %s\n", operation, var1, var2);
}

int main()
{
    // Command to display Greek characters correctly
    system("chcp 1253>nul");

    // Create a list
    node_pointer list = NULL;

    // Add variables to the list
    add_variable_if_not_in_list(&list, "a", "int");
    add_variable_if_not_in_list(&list, "b", "int");
    add_variable_if_not_in_list(&list, "c", "float");
    add_variable_if_not_in_list(&list, "d", "int");
    add_variable_if_not_in_list(&list, "e", "int");
    add_variable_if_not_in_list(&list, "f", "float");
    add_variable_if_not_in_list(&list, "g", "int");
    add_variable_if_not_in_list(&list, "h", "float");
    add_variable_if_not_in_list(&list, "i", "float");
    show_list(list);

    // Variable Type Checking and Operation
    perform_operation(list, "a", "b", "add"); // Example operation

    // Delete the list
    delete_list(&list);
    show_list(list); // List should be empty now

    return 0;
}
