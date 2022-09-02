#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct node
{
	int data;
	struct node* next_ptr; //a pointer to the next node
}node;

//pointer to struct for generic use
node* x;
//creating a linked list with the required number of nodes

//searching the linked list
node* search(node** head, int key)
{
    x = *head;
    if(x == NULL)
    {
        return NULL; //in case the list is empty
    }
    for(int i=0;i<key;i++)
    {
        if(x->next_ptr == NULL)
        {
            return NULL; //in case user entered a key out of bounds
        }
        x = x->next_ptr;
    }
    return x;
}

//adding a node where the specified key will be the new node's position (i.e before the given key)
void add_node(node** head, node** new_node, int key)
{
    if(key == 0)
    {
        (*new_node)->next_ptr = *head;
		*head = *new_node;
    }
    else
    {
        node* prev_to_new = search(head,key-1);
        (*new_node)->next_ptr = prev_to_new->next_ptr;
        prev_to_new->next_ptr = *new_node;
    }
    return;
}

//deleting the specified node
void delete_node(node** head, int key)
{
    if(key == 0)
    {
        *head = (*head)->next_ptr;
    }
    else
    {
        node* prev_to_del = search(head,key-1);
        node* after_del = prev_to_del->next_ptr;
        prev_to_del->next_ptr = after_del->next_ptr;
        free(after_del);
    }
}

//function that return that last key of a given linked list
int last_key(node** head)
{
    x = *head;
    int counter = 0;
    while(x->next_ptr != NULL)
    {
        x = x->next_ptr;
        counter++;
    }
    return counter;
}

//deletes last node in a given linked list
void delete_last_node(node** head)
{
    int key = last_key(head);
    delete_node(head, key);
}

//adds a node to the end of a given linked list
void add_last_node(node** head, node** new_node)
{
    int key = last_key(head);
    add_node(head, new_node, key+1);
}

#endif