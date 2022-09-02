#include "stdio.h"
#include "stdlib.h"
#include "Std_Types.h"

void add_node_at_end(u8 new_data)
{

    node_t * new_node =(node_t*) malloc(sizeof(node_t));
    node_t * temp = head;

    (*new_node).data = new_data;
    (*new_node).next = NULL;
    
    if(head==NULL){
       head=new_node;
    }
    else{
        while((*temp).next != NULL){
            temp = (*temp).next;
        }
            (*temp).next = new_node;
    }
    
}

void delete_last_node(void)
{
    node_t * temp = head;
    node_t * temp2 = NULL;

    while(((*temp).next) != NULL){
        temp2 = temp;
        temp = (*temp).next;
    }
    free(temp);
    (*temp2).next=NULL;

}

void add_node(u8 data, u8 position)
{
    node_t* new_node = (node_t*) malloc(sizeof(node_t));

    (*new_node).data=data;
    (*new_node).next=NULL;

    if(position==1){
        (*new_node).next=head;
        head=new_node;
    }
    else{
        node_t *temp = head;
        int i;

        for(i=1;i<position-1;i++){
            temp=(*temp).next;
        }
        (*new_node).next = (*temp).next;
        (*temp).next=new_node;
    }


}

void delete_node(int position)
{
    node_t *temp = head;
    node_t *temp2 = NULL;

    if(position==1){
        head = (*temp).next;    
        free(temp);

    }
    else{
    int i;
    for(i=1;i<position-1;i++){
        temp = (*temp).next;
    }
    temp2=(*temp).next ;
    (*temp).next = (*temp2).next;
    free(temp2);
    
    }
}

void print_linked(node_t *head)
{
    node_t *temp = head;
    while(temp!=NULL)
    {
        printf("%d \n" , (*temp).data);
        temp = (*temp).next;
    }

}
