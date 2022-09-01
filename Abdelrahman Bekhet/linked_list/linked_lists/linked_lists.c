#include<stdio.h>
#include<stdlib.h>

#include"datatypes.h"
#include"header.h"

//This progam creates 4 lists with index start 0


int main()
{ //Making 4 lists
	node* head = (node*)malloc(sizeof(node)); //0
	node* one = (node*)malloc(sizeof(node)); //1
	node* two = (node*)malloc(sizeof(node)); //2
	node* three = (node*)malloc(sizeof(node)); //3

	head->next = one;
	one->next = two;
	two->next = three;
	three->next = NULL;

	node* newNode= (node*)malloc(sizeof(node)); //new node

	head->data = 0;
	one->data = 1;
	two->data = 2;
	three->data = 3;
	newNode->data = -5;


	//Add_Node(&head,&newNode, 4);
	//Add_last_Node(&head,&newNode);
	Delete_last_Node(&head);	
	//Delete_Node(&head,3);


//printing list after edit:
	node* current = head;
	int counter = 0;
	while (current != NULL)
	{
		printf("data in list:%d is: %d \n", counter, current->data);
		current = current->next;
		counter++;
	}
	return 0;
}