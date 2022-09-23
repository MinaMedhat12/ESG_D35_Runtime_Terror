#include "stdio.h"
#include "stdlib.h"
#include "LinkedList.h"
#include "typedef.h"

node_t *head = NULL;

int main()
{
     

     
     
     AddLast(&head,10);
     AddLast(&head,20);
     AddLast(&head,30);

     
     printf("\n Data entered in the list are: \n");		
     printList(head);

     DeleteLast();
     printf("\n The new list after deletion the last node are  : \n");	
     printList(head);
     
     add_at_position(head, 25, 3);
     printf("\n The new list after adding the node in position you entered is: \n");
     printList(head);
     

     Delete_at_position(&head, 2);
     printf("\nThe list after deleting node in postion you entered is: \n");
     printList(head);

     return 0;
}
