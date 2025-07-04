#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* addToEmpty(struct node* tail,int data){
    
    struct node * ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->next=ptr1;
    ptr1->data=data;
    tail=ptr1;
    return tail;
    
    
}
struct node* add_node_beg(struct node* tail,int data){
    if(tail==NULL){
        tail=addToEmpty(tail,data);
        return tail;
    }
    else{
    struct node * ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->data=data;
    ptr1->next=tail->next;
    tail->next=ptr1;
    return tail;
    }

}

int main(void){
    struct node* tail=NULL;
    return 0;
}