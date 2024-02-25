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
void add_variable_if_not_in_list(node_pointer* list, const char* name, const char* data_type)
{
    if (!variable_in_list(*list, name))
    {
        // Variable does not exist, add it to the list
        add_variable(list, name, data_type);
    }
    else
    {
        printf("Variable %s already declared\n", name);
    }
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

int main()
{
    // Command to display Greek characters correctly
    system("chcp 1253>nul");

    // Create a list
    node_pointer list = NULL;

    // Add variables to the list
    add_variable(&list, "a", "int");
    add_variable(&list, "b", "int");
    add_variable(&list, "c", "float");
    add_variable(&list, "d", "int");
    add_variable(&list, "e", "int");
    add_variable(&list, "f", "float");
    add_variable(&list, "g", "int");
    add_variable(&list, "h", "float");
    add_variable(&list, "i", "float");
    show_list(list);

    // Delete the list
    delete_list(&list);
    show_list(list);

    // Add variables to the list
    add_variable_if_not_in_list(&list, "a", "int");
    add_variable_if_not_in_list(&list, "b", "int");
    add_variable_if_not_in_list(&list, "a", "float");  // Variable that already exists in the list
    add_variable_if_not_in_list(&list, "d", "int");
    show_list(list);

    return 0;
}
