#include <stdio.h>
#include <stdlib.h> //this one is for the exit function in the pop function also in print
#define MAX 5
int stack_array[MAX];
int top=-1;

//this function checks if the array is overflow or not if its it returns 1 if not 0
int isFULL(){
    if (top==MAX-1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
//this function adds the data to the stack array
void push(int data){
    if (isFULL())
    {
        printf("stack overflow!");
        return;
    }
    top++;
    stack_array[top]=data;
 
}
//this function checks if the array is underflow or not if its it returns 1 if not 0
int isEMPTY(){
    if (top<0)
    {
        return 1;
    }
    else
        return 0;
    
}
//this function pops the top data in the array
int pop(){
    int result;
    if (isEMPTY())
    {
        printf("stack underflow!");
        exit(1);
    }
    result=stack_array[top];
    top--;
    return result;
    
}
void print_data(){
    if (isEMPTY())
    {
        printf("there is no data to print!");
        exit(1);
    }
    for (int i = top; i >=0; i--)
    {
        printf("%d ",stack_array[i]);
    }
    
    
}
void peek(){
    if(isEMPTY()){
        printf("no data to print! ");
    }
    
    printf("\nTop data-> %d",stack_array[top]);
}



int main(void){
    int data;
    push(3);
    push(7);
    push(8);
    push(26);
    data=pop();
    print_data();
    peek();
    
    return 0;
}