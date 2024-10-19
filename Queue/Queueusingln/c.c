#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *f=NULL;
struct node *r=NULL;

int isFull(struct node *n){
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int val){
    struct node *n=malloc(sizeof(struct node));
    if(isFull(n)){
        printf("Queue OverFlow \n");
        return;
    }
    else{
        n->data=val;
        n->link=NULL;

        if(isEmpty()){
            f=r=n;
        }
        else{
            r->link=n;
            r=n;
        }
    }
}

int dequeue(){
    int a=-1;
    if(isEmpty()){
        printf("Queue UnderFlow \n");
        return a;
    }
    else{
        struct node *ptr;
        ptr=f;
        f=f->link;
        a=ptr->data;
        free(ptr);
        return a;
    }
}

void print(){
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = f;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){


    int choice, data;
    while (1) {
        printf("\nQueue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("The dequeued element is %d\n", data);
                }
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter a valid operation.\n");
        }
    }


    return 0;
}