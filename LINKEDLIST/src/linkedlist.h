#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Node structure for singly linked list.
 */
typedef struct sll_node {
    void* data;
    struct sll_node* next;
} sll_node;


/**
 * @brief Singly linked list structure.
 */
typedef struct sllist {
    struct sll_node* head;
    size_t data_size;
} sllist;


/**
 * @brief Creates a new singly linked list.
 *
 * This function initializes a new singly linked list with the specified data size for each node.
 *
 * @param data_size The size of the data to be stored in each node.
 * @return A pointer to the newly created singly linked list, or NULL if memory allocation fails.
 * 
 * @usage
 * sllist* my_list = sllist_create(sizeof(int));
 * if (my_list == NULL) {
 *     // Handle memory allocation failure
 * }
 */
sllist* sllist_create(size_t data_size);


/**
 * @brief Inserts a new node at the front of the singly linked list.
 *
 * This function creates a new node with the provided data and inserts it at the beginning of the list.
 *
 * @param list A pointer to the singly linked list.
 * @param data A pointer to the data to be stored in the new node.
 * 
 * @usage
 * int value = 42;
 * insert_front(my_list, &value);
 * insert_front(my_list, &(int){10}); // Insert 10 at the front
 */
void insert_front(sllist* list, void* data);


/**
 * @brief Inserts a new node at the end of the singly linked list.
 *
 * This function creates a new node with the provided data and inserts it at the end of the list.
 *
 * @param list A pointer to the singly linked list.
 * @param data A pointer to the data to be stored in the new node.
 * 
 * @usage
 * int value = 42;
 * insert_end(my_list, &value);
 * insert_end(my_list, &(int){10}); // Insert 10 at the end
 */
void insert_end(sllist* list, void* data);


/**
 * @brief Inserts a new node at the specified index in the singly linked list.
 *
 * This function creates a new node with the provided data and inserts it at the given index in the list.
 * If the index is 0, the node is inserted at the front. If the index is equal to the length of the list,
 * the node is inserted at the end. If the index is out of bounds, no insertion is performed.
 *
 * @param list A pointer to the singly linked list.
 * @param data A pointer to the data to be stored in the new node.
 * @param index The position at which to insert the new node (0-based).
 * 
 * @usage
 * int value = 42;
 * insert_at_index(my_list, &value, 2); // Insert 42 at index 2
 * insert_at_index(my_list, &(int){10}, 0); // Insert 10 at the front
 * insert_at_index(my_list, &(int){20}, sll_len(my_list)); // Insert 20 at the end
 */
void insert_at_index(sllist* list, void* data, size_t index);


/**
 * @brief Frees the entire singly linked list and its nodes.
 *
 * This function traverses the list, frees each node's data and the node itself, and finally frees the list structure.
 *
 * @param list A pointer to the singly linked list to be freed.
 * @usage
 * free_sllist(my_list);
 */
void free_sllist(sllist* list);


/**
 * @brief Frees the node at the front of the singly linked list.
 *
 * This function removes the node at the front of the list, frees its data and the node itself.
 *
 * @param list A pointer to the singly linked list.
 * @usage
 * free_at_front(my_list);
 */
void free_at_front(sllist* list);


/**
 * @brief Frees the node at the end of the singly linked list.
 *
 * This function removes the node at the end of the list, frees its data and the node itself.
 *
 * @param list A pointer to the singly linked list.
 * @usage
 * free_at_end(my_list);
 */
void free_at_end(sllist* list);


/**
 * @brief Frees the node at the specified index in the singly linked list.
 *
 * This function removes the node at the given index, frees its data and the node itself.
 * If the index is 0, the front node is removed. If the index is out of bounds, no removal is performed.
 *
 * @param list A pointer to the singly linked list.
 * @param index The position of the node to be removed (0-based).
 * 
 * @usage
 * free_at_index(my_list, 2); // Remove node at index 2
 * free_at_index(my_list, 0); // Remove front node
 */
void free_at_index(sllist* list, size_t index);


/**
 * @brief Returns the length of the singly linked list.
 *
 * This function traverses the list and counts the number of nodes.
 *
 * @param list A pointer to the singly linked list.
 * @return The number of nodes in the list.
 * 
 * @usage
 * size_t length = sll_len(my_list);
 */
size_t sll_len(sllist* list);


/**
 * @brief Prints the singly linked list.
 * This function traverses the list and prints each node's data using the provided print function.
 * @param list A pointer to the singly linked list.
 * @param print_func A function pointer to a function that takes a void pointer and prints the data.
 * @usage
 * void print_int(void* data) {
 *     printf("%d -> ", *(int*)data);
 * }
 * print_sllist(my_list, print_int);
 */
void print_sllist(sllist* list, void (*print_func)(void*));


#endif // LINKEDLIST_H
