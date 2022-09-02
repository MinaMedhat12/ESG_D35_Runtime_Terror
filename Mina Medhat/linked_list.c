#include "stdio.h"
#include "stdlib.h"
#include "Std_Types.h"
#include "linked_list.h"

node_t *head= NULL ;

int main(void){
 
   // add_node(2,1);
    add_node_at_end(10);
    add_node_at_end(20);
    add_node_at_end(90);


    delete_last_node();

    print_linked(head);
  
    return 0;
}





