#include "stdio.h"
#include "stdlib.h"
#include "typedef.h"


                                 //* PRINT LIST *//

void printList(node_t *head)
{
   node_t *temp = head;

   while(temp != NULL)
   {
    printf("%d\n", temp->data);
    temp=temp->next;
   }
   printf("NULL\n");

   return;
}

                       //* ADD NODE FROM THE LAST *//

void AddLast(node_t **head, u8_t data)
{
   node_t *newnode;
   newnode = (node_t*) malloc(sizeof(node_t));
   newnode->data = data;
   newnode->next = NULL;

   if (*head == NULL)
   {
     *head = newnode;
   }
   else
   {
    node_t *lastnode = *head;

    while(lastnode->next != NULL)
    {
        lastnode = lastnode->next;
    }

    lastnode->next = newnode;
    return ;
   }
    
}

                        //* DELETE NODE FROM LAST *//

void DeleteLast(void)
{
    
    node_t *temp_1 = head;
    node_t *temp_2 = NULL;

    while(((*temp_1).next) != NULL){
        temp_2 = temp_1;
        temp_1 = (*temp_1).next;
    }

    free(temp_1);
    (*temp_2).next=NULL;

    return;
}
                     
                     //* ADD NODE FROM ANY POSITION *//
void add_at_position(node_t *head, u8_t data, u8_t pos)
{
    node_t *ptr = head;
    node_t *ptr2 = malloc(sizeof(node_t));

    ptr2->data = data;
    ptr2->next = NULL;

    pos --;
    while(pos != 1)
    {
        ptr = ptr->next;
        pos --;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
    
    return;
}

                    //* DELETE NODE FROM ANY POSITION *//

void Delete_at_position(node_t **head, u8_t pos)
{
    node_t *current = *head;
    node_t *prev = *head;

    if(*head == NULL)
    {
        printf("\nthe list is empty\n");
    }
    else if(pos == 1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while(pos != 1)
        {
            prev = current;
            current = current->next;
            pos --;
        }
        prev->next = current->next;
        free(current);
        current = NULL;
    }
    return;
}

