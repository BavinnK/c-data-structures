//Double linked list 
#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node*next;
  struct node*prev;
};
struct node* add_data_beg(struct node*head,int data){
  struct node*ptr1=head;
  struct node*ptr2=(struct node*)malloc(sizeof(struct node));
  ptr2->data=data;
  ptr2->next=NULL;
  ptr2->prev=NULL;
  if(ptr1==NULL){
    head=ptr2;
    return head;}
  else{
  ptr2->next=head;
    head->prev=ptr2;
    head=ptr2;
    
    
  }
  return head;
  
  
  
}
struct node* add_data_end(struct node* head,int data){
  struct node*ptr1=head;
  struct node*ptr2=(struct node*)malloc(sizeof(struct node));
  ptr2->data=data;
  ptr2->next=NULL;
  ptr2->prev=NULL;
  if(ptr1==NULL){
    head=ptr2;
    return head;}
  while(ptr1->next!=NULL){
    ptr1=ptr1->next;
  }
  ptr1->next=ptr2;
  ptr2->prev=ptr1;
  ptr2->next=NULL;
  return head;

  
}
void print(struct node *head) {
  struct node *ptr = NULL;
  if (head == NULL) {
    printf("no data to print");
  }
  ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

int main(void) {
  struct node*head=NULL;
  head=add_data_beg(head, 10);
  head=add_data_end(head, 67);
  head=add_data_end(head, 90);
  head=add_data_end(head, 30);
  head=add_data_beg(head, 20);
  head=add_data_beg(head, 880);
  print(head);
  
  return 0;
}