#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if((q->r + 1)%q->size == q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("Queue Overflow \n");
        return;
    }
    else{
        q->r=(q->r + 1)%q->size;
        q->arr[q->r]=val;
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue Underflow \n");
        return a;
    }
    else{
        q->f=(q->f + 1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}

void print(struct queue *q){
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
     printf("Queue elements are: ");
    int i = (q->f + 1) % q->size;
    while (i != (q->r + 1) % q->size) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main(){
    struct queue *q=malloc(sizeof(struct queue));
    q->size=100;
    q->f=q->r=0;
    q->arr=(int*)malloc(q->size*sizeof(int));
    
    int choice,data;
    while (1)
    {

     printf("\nQueue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        
    
    printf("Enter the choice \n");
    scanf("%d",&choice);



    switch (choice)
    {
    
    case 1:
    printf("ENter the data to enter \n");
    scanf("%d",&data);
    enqueue(q,data);
    break;

    case 2:
    data=dequeue(q);
    printf("The dequeued element is %d \n",data);
    break;

    case 3:
    print(q);
    break;

    case 4:
    exit(0);
    break;

    default:
     printf("ENter valid operation \n");
    }
    }

    return 0;
}