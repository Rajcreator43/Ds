#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
} *top = NULL;

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data) {
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

int pop(){
    struct node* temp=top;
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    int val;
    val=temp->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}

int peek(){
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    return top->data;
}





void print() {
    struct node* temp = top;
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    printf("STACK: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("\nEnter your choice: \n1: Push\n2: Print\n3: pop\n4: peek\n5: Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your data: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                print();
                break;
            case 3:

                data=pop();
                printf("The deleted element is %d\n",data);
                break;
            case 4:
                printf("The topmost element is %d\n",peek());
                break;
            case 5:
                exit(1);
                break;

            default:
                printf("Wrong choice\n");
                break;
        }
    }

    return 0;
}
