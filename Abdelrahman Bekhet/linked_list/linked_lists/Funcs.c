#include<stdio.h>
#include"datatypes.h"
#include<stdlib.h>


void Add_last_Node(node** head, node** newNode)
{
    node* current = *head;
    int index = 0;
	while (current != NULL)
	{
		current = current->next;
		index++;
	}

		node* prevOfAdded = *head;

		for (int i = 1; i < index; i++)
			prevOfAdded = prevOfAdded->next;

		(* newNode)->next = prevOfAdded->next;
		prevOfAdded->next = *newNode;

	return;
    
}

void Delete_last_Node(node** head)
{
    node* current = *head;
    int index = -1;
	while (current != NULL)
	{
		current = current->next;
		index++;
	}


		node* prev = *head;

		for (int i = 1; i < index; i++)
			prev = prev->next;

		node* after  = prev->next;
		prev->next = after->next;
		free(after);

	return;

}

void Delete_Node(node** head, int index)
{
	if (index == 0)
	{
		node* temp = *head;
		*head = (*head)->next;
		free(temp);
	
	}

	else
	{
		node* prev = *head;

		for (int i = 1; i < index; i++)
			prev = prev->next;

		node* after  = prev->next;
		prev->next = after->next;
		free(after);

	}
	return;
}


//New node is added just before the index
void Add_Node(node** head, node** newNode, int index)
{
	
	if (index == 0)
	{
		(* newNode)->next = *head;
		*head = *newNode;



	}

	
	else
	{
		node* prevOfAdded = *head;

		for (int i = 1; i < index; i++)
			prevOfAdded = prevOfAdded->next;

		(* newNode)->next = prevOfAdded->next;
		prevOfAdded->next = *newNode;

	}
	return;
}

