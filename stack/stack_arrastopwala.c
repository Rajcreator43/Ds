#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int first=-1;

void push(int data){
    first=first+1;
    for(int i=first;i>0;i--){
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}

int pop(){
    int value=stack_arr[0];
    for(int i=0;i<first;i++){
        stack_arr[i]=stack_arr[i+1];
    }
    first=first-1;
    return value;
}

void printStack(){
    if(first==-1){
        printf("Stack Empty\n");
    }
    for(int i=0;i<=first;i++){
        printf("%d ",stack_arr[i]);
    }
}
int main(){
    push(1);
    push(2);
    push(3); 
    push(4);
    pop();

    push(1);
    printStack();
    return 0;
}
