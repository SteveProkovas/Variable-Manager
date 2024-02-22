# Variable Manager

Variable Manager is a simple C program designed to manage variables and their data types within a program. It provides functionality to add, display, search for, and delete variables in a linked list data structure.


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
