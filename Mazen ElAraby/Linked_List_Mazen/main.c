#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

//printing data of linked list to see modification
void print_linked_list(node** head)
{
	node* current = *head;
	for (int i=0;current != NULL;i++)
	{
		printf("data in list:%d is: %d \n", i, current->data);
		current = current->next_ptr;
	}
	return;
}

//Driver Code
int main(void)
{
    //initializing 4 nodes
	node* head = (node*)malloc(sizeof(node)); 
	node* one = (node*)malloc(sizeof(node)); 
	node* two = (node*)malloc(sizeof(node)); 
	node* tail = (node*)malloc(sizeof(node)); 

	head->next_ptr = one;
	one->next_ptr = two;
	two->next_ptr = tail;
	tail->next_ptr = NULL;

	node* new_node= (node*)malloc(sizeof(node)); //new node

	head->data = 5;
	one->data = 6;
	two->data = 7;
	tail->data = 8;
	new_node->data = 9;

    //testing
	//if the prints return nothing, check that you provided a key within bounds
	int x = 0;
	//testing the add node function
	printf("Please enter an index for which the node will be placed just before it.\n");
    scanf("%d",&x);
	add_node(&head, &new_node, x);
	print_linked_list(&head);
	//testing the delete node function
	printf("Please enter an index of the node to be deleted\n");
    scanf("%d",&x);
	delete_node(&head, x);
	print_linked_list(&head);
	//testing the delete last node function
	printf("deleting the last node\n");
	delete_last_node(&head);
	print_linked_list(&head);
	//testing the add last node function
	printf("adding to the end of the linked list.\n");
	node* new_node_1= (node*)malloc(sizeof(node)); //new node
	add_last_node(&head, &new_node_1);
	new_node_1->data = 10;
	print_linked_list(&head);
}