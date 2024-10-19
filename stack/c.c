#include<stdio.h>
#include<stdlib.h>

#define MAX 4

int stack_arr[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Empty Stack\n");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}

void printStack(){
    if(top==-1){
        printf("Empty Stack\n");
        exit(1);
    }
    for(int i=top;i>=0;i--){
        printf("%d \n",stack_arr[i]);
    }
}

int peek(){
    if(isEmpty()){
        printf("Empty Stack");
    }
    else{
        return stack_arr[top];
    }

}

int main(){
      int choice;
    int data;

    while (1) {
        printf("\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Top Element\n");
        printf("4. Is stack empty?\n");
        printf("5. Is stack full?\n");
        printf("6. Show Elements\n");
        printf("7. Exit\n");

        printf("\nEnter your choice to perform operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
             printf("\n - Enter the element to push data into the stack: ");
            scanf("%d", &data);
            push(data);
            break;
        
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            exit(1);
        
        default:
            printf("Enter valid number\n");
            break;
        }
}
return 0;
}