#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *link;
};
struct node *add_data_end(struct node *head, int data) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  struct node *ptr = NULL;
  newnode->data = data;
  newnode->link = NULL;
  if (head == NULL) {
    return newnode;
  }
  ptr = head;
  while (ptr->link != NULL) {
    ptr = ptr->link;
  }
  ptr->link = newnode;
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
    ptr = ptr->link;
  }
}

struct node *add_data_beg(struct node *head, int data) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->link = head;

  return newnode;
}
struct node *delete_final_node(struct node *head) {
  struct node *ptr1 = NULL;
  if (head == NULL) {
    printf("no data to delete!!");
    return NULL;
  }
  else if(head->link==NULL){
    free(head);
    head=NULL;
    return head;
  }

  ptr1 = head;

  while (ptr1->link->link != NULL) {
    ptr1 = ptr1->link;
  }

  free(ptr1->link);
  ptr1->link = NULL;
  return head;
}
struct node * delete_first_node(struct node * head){
struct node* ptr=NULL;
  if(head==NULL){
    printf("no data to delete! ");
    return head;
  }
  else if(head->link==NULL){
    free(head);
    head=NULL;
    return head;
  }
  
    ptr=head;
    head=head->link;
    ptr->link=NULL;
    free(ptr);
    ptr=NULL;
   


  
   return head;

}
struct node *add_data_certain_pos(struct node *head, int data, int pos) {
  if(pos==1){
    head=add_data_beg(head,data);
    return head;
  }
  struct node *ptr1 = head;
  struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
  ptr2->link = NULL;
  ptr2->data = data;
  int i;
  for (i = 0; i < pos -2; i++) {
    if (ptr1 == NULL ||head->link==NULL) {
      printf("invalid position");
      free(ptr2);
      return head;
    }
    ptr1 = ptr1->link;
  }
  ptr2->link = ptr1->link;
  ptr1->link = ptr2;
  return head;
}
struct node *delete_entire_list(struct node *head){
  struct node* ptr=NULL;
  if(head==NULL){
    printf("no data to delete");
    return head;
  }
  else if(head->link==NULL){
    free(head);
    head=NULL; // we do this everytime because of dangling pointer becarful!!!!!!!!!!!!!!!
    return head;
  
  }
  ptr=head;
  while(head->link!=NULL){
    head=head->link;
    free(ptr);
    ptr=head;
  }
  free(head);
  head=NULL;
  ptr=NULL;
  return head;
  

}

int main(void) {
  struct node *head = NULL;
  printf("before\n ");
  head = add_data_end(head, 10);
  head = add_data_end(head, 20);
  head = add_data_end(head, 30);
  head = add_data_end(head, 40);
  head = add_data_beg(head, 100);
  head = add_data_beg(head, 200);
  head = add_data_end(head, 500);
  head = add_data_certain_pos(head, 6, 6);

  
  print(head);
  
printf("\nafter\n ");
head=delete_entire_list(head);
  
  print(head);

  return 0;
}