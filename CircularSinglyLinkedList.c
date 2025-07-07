#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
// this function is used when the list has no node 
struct node* addToEmpty(struct node* tail,int data){
    
    struct node * ptr1=(struct node *)malloc(sizeof(struct node));
    ptr1->next=ptr1;
    ptr1->data=data;
    tail=ptr1;
    return tail;
    
    
}
// adding a node at the begginning
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
// printing the entire list
void  print(struct node* tail)
{
    struct node* ptr1=NULL;
    if (tail==NULL)
    {
        printf("no data to print!");
        return;
    }
    else{
        ptr1=tail->next;
        do
        {
            printf("%d ",ptr1->data);
            ptr1=ptr1->next;
            
        } while (ptr1!=tail->next);
        
        
    }
    

}
// adding a node at the ned of the list
struct node* add_node_end(struct node* tail,int data){
    
    if (tail==NULL)
    {
        tail=addToEmpty(tail,data);
        return tail;
    }
    struct node* ptr1=(struct node*)malloc(sizeof(struct node));
    ptr1->data=data;
    ptr1->next=NULL;
    
        ptr1->next=tail->next;
        tail->next=ptr1;
        tail=tail->next;
        return tail;
    
    
}
// list creation
struct node* create_list(struct node* tail){
    int n,data;
    printf("how many nodes you want to add: ");
    scanf("%d",&n);
    printf("\n enter number 1: ");
    scanf("%d",&data);
    tail=addToEmpty(tail,data);
    for (int i = 1; i < n; i++)
    {
        printf("\n enter number %d: ",(1+i));
        scanf("%d",&data);
        tail=add_node_end(tail,data);
        
    }
    return tail;
    
}
// deleting the first node
struct node* delete_beg_node(struct node* tail){
    if(tail==NULL){
        printf("there is no data to delete");
        return tail;
    }
    else if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    else {
        struct node* ptr=tail->next;
        tail->next=ptr->next;
        free(ptr);
        ptr=NULL; // becareful we have to give it null cuz of dangling pointer
        return tail;

    }
}
//deleting the last node of the list
struct node* delete_end_node(struct node* tail){
    if(tail==NULL){
        printf("there is no data to delete");
        return tail;
    }
    else if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    else{
        struct node * ptr=tail->next;
        while (ptr->next!=tail)
        {
            ptr=ptr->next;
        }
        ptr->next=tail->next;
        free(tail);
        tail=ptr;
        return tail;
        
    }
}
//this function deletes a specific node given by the user
struct node* delete_at_pos(struct node* tail,int pos){
    if(tail==NULL){
        printf("there is no data to delete");
        return tail;
    }
    else if(pos==1){
        tail=delete_beg_node(tail);
        return tail;
    }
    else{

        struct node * ptr1=tail->next;
        struct node * ptr2=NULL;
        
        while (pos>2)
        {
            ptr1=ptr1->next;
            pos--;
            
        }
        ptr2=ptr1->next;
        ptr1->next=ptr2->next;
        free(ptr2);
        ptr2=NULL;
        return tail;

        

    }


}

int main(void){
    struct node* tail=NULL;
    #if 1
    printf("\nbefore delete\n");
    tail = addToEmpty(tail, 10);
    tail = add_node_beg(tail, 20);
    tail = add_node_beg(tail, 30);
    tail=add_node_end(tail,40);
    tail=add_node_end(tail,100);
    tail=add_node_end(tail,20);
    tail=add_node_end(tail,99);
    
    print(tail);
    printf("\nafter delete\n");
   // tail=delete_beg_node(tail);
   //tail=delete_end_node(tail);
   //tail=delete_at_pos(tail,7);
   //tail=delete_at_pos(tail,3);
   tail=delete_at_pos(tail,30);
    print(tail);


    #endif
    //tail=create_list(tail);
    //print(tail);
    return 0;
}