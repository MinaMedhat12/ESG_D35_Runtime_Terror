#include<stdio.h>
#include<stdlib.h>
#include"typedefs.h"


struct node{
    int data;
    struct node *link;
};

void insertNode(struct node* last, int value);
void addLast(struct node *head, int val);
void delLast(struct node* head);
void dell(struct node* head,u8_t pos);
void insert_any(struct node* head,u8_t pos,u8_t data );

int main(){
    u8_t num;
    u8_t pos;

    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third =NULL;
    struct node* fourth =NULL;

    
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head->data =45;
    head->link=second;

    second->data = 98;
    second->link =third;

    third->data = 100;
    third->link = NULL;



    printf("please enter the required operation as number from 1 : 5\n");
    scanf("%d",&num);

    if(num == 1){
        insertNode(third,88);
    }
    else if(num == 2){
        addLast(head,60);
    }
    else if(num == 3){
        delLast(head);
    }
    else if(num == 4){
        printf("please, enter the required position\n");
        scanf("%d",&pos);
        dell(head,pos);
    }
    else if(num == 5){
        printf("please, enter the required position\n");
        scanf("%d",&pos);
        insert_any(head,pos,50 );
    }
    else{}

    //printf("%d",->data);

    return 0;
}
void insertNode(struct node* prev_node, int value){
    struct node* next =NULL;
    next = (struct node*) malloc(sizeof(struct node));

    next->data = value;
    prev_node->link = next;
    next->link =NULL;
    printf("%d",next->data);

    return;


}
void addLast(struct node *head, int val){
    struct node *ptr,*end;
    ptr = head;
    end = (struct node*) malloc(sizeof(struct node));

    end->data =val;
    end->link =NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = end;

    printf("%d\n",end->data);

    return;

}
void delLast(struct node* head){
    if(head == NULL){
        printf("List is empty");
    }
    else if (head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *ptr, *ptr2 ;
        ptr = head;

        while(ptr->link != NULL){
            ptr2 = ptr;
            ptr = ptr->link;
        }
        ptr2-> link = NULL;
        printf("the delete data is %d\n",ptr->data);
        free(ptr);
        printf("%d\n",ptr->data);

        return ;

    }
    }
    void dell(struct node* head,u8_t pos){
        
        struct node* ptr = head;
        struct node* ptr1 = head;
        if(head == NULL){
            printf("empty\n");
        }
        else if(pos == 1 ){
            head->link = ptr->link;
            printf("%d\n",ptr->data);
            free(ptr);
            ptr = NULL;
            printf("%d\n",ptr->data);
        }
        else{
            while(pos != 1){
                ptr1 = ptr;
                ptr = ptr->link;
                pos--;

            }
            ptr1->link = ptr->link;
            printf("%d\n",ptr->data);
            free(ptr);
            ptr = NULL;
            printf("%d\n",ptr->data);
        }
           
        return;
    }
    void insert_any(struct node* head,u8_t pos,u8_t data ){
        struct node* ptr = head;
        struct node* ptr2;
        ptr2 = (struct node*)malloc(sizeof(struct node));
        ptr2->data=data;
        ptr2->link=NULL;

        pos--;
        while(pos != 1){
            ptr = ptr->link;
            pos--;
        }
        ptr2->link = ptr->link;
        ptr->link = ptr2;
        printf("%d",ptr2->data);


         
    }
        

    

