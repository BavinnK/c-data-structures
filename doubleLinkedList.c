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
    printf("\nno data to print\n");
  }
  ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}
void reverse_print(struct node* head){
  if(head==NULL){
    printf("there is no data to delete");
    return;
  }
  else if(head->next==NULL){
    printf("\n %d ",head->data);
    return;
  }
  else{
    while(head->next!=NULL){
      head=head->next;

    }
    while (head!=NULL)
    {
      printf("%d ",head->data);
      head=head->prev;
    }
    
    

    return;


  }
}
struct node* delete_last_node(struct node* head){
  struct node* ptr1=NULL;
  struct node* ptr2=NULL;
  if(head==NULL){
    printf("there is no data to delete");
    return head;
  }
  else if(head->next==NULL){
    free(head);
    head=NULL;
    return head;
  }
  else{
    ptr1=head;
    while(ptr1->next!=NULL){
      ptr1=ptr1->next;
    }
    ptr2=ptr1->prev;
    ptr2->next=NULL;
    free(ptr1);
    ptr1=NULL;
    
  }
  return head;

}
struct node* delete_first_node(struct node* head){
  struct node* ptr1=NULL;
  if(head==NULL){
    printf("no data to delete!");
    return head;
  }
  else if(head->next==NULL){
    free(head);
    head=NULL;
    return head;
  }
  else{
    ptr1=head;
    head=head->next;
    head->prev=NULL;
    ptr1->next=NULL;
    free(ptr1);
    ptr1=NULL;
    return head;
  }

}
struct node* delete_node_position(struct node* head,int position){
  struct node* ptr1=NULL; // i will try using one pointer instead doing with two i challenge mayself lol
  if(head==NULL){
    printf("no data to delete! ");
    return head;
  }
  else if (position==1){
    head=delete_first_node(head);
    return head;
  }
  else{
    ptr1=head;
    while (position>1)
    {
      ptr1=ptr1->next;
      position--;
      if(ptr1==NULL){
        printf("\nthat node position deosnt doesnt exist try again!\n ");
        ptr1=NULL;
        return head;
      }
      
    }
    if(ptr1->next==NULL){
        head=delete_last_node(head);
        return head;
      }
    ptr1->prev->next=ptr1->next;
    ptr1->next->prev=ptr1->prev;
    free(ptr1);
    ptr1=NULL;
    return head;
    

  }
}
struct node* free_entire_list(struct node *head){
  struct node* ptr1=NULL;
  if(head==NULL){
    printf("no data to free! ");
    return head;
  }
  else if(head->next==NULL){
    free(head);
    head=NULL;
    return head;
  }
  else{
    ptr1=head;
    while(head->next!=NULL){
      head=head->next;
      free(ptr1);
      ptr1=head;
    }
    head=NULL;
    ptr1=NULL;
    return head;
    
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
  head=add_data_end(head, 45);
  print(head);
  printf("\n");
  //reverse_print(head);
  #if 0
  head=delete_last_node(head);
  printf("\nafter deletion!\n");
  print(head);
  
  printf("\nafter deletion2!\n");
  head=delete_first_node(head);
  print(head);
  # endif
printf("\nafter deletion!\n");
 head=delete_node_position(head,9);
 print(head);
 head=free_entire_list(head);
 print(head);
  return 0;
}