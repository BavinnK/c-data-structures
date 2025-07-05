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



int main(void){
    struct node* tail=NULL;
    #if 0
    tail = addToEmpty(tail, 10);
    tail = add_node_beg(tail, 20);
    tail = add_node_beg(tail, 30);
    tail=add_node_end(tail,40);
    tail=add_node_end(tail,100);
    tail=add_node_end(tail,20);
    print(tail);
    #endif
    tail=create_list(tail);
    print(tail);
    return 0;
}