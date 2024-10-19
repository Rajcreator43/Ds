#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q) {
    if (q->r == q->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct Queue *q) {
    if (q->r == q->f) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(struct Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow \n");
        exit(1);
    } else {
        q->r++;  // Increment rear
        q->arr[q->r] = val;
        printf("%d enqueued to the queue.\n", val);
    }
}

int dequeue(struct Queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue Underflow \n");
        exit(1);
    } else {
        q->f++;  // Increment front
        a = q->arr[q->f];
        printf("%d dequeued from the queue.\n", a);
    }
    return a;
}

void print(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->f + 1; i <= q->r; i++) {  // Fixed the loop to start from f + 1
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 100;
    q->f = -1;
    q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    while (1) {  // Infinite loop until the user chooses to exit
        printf("\nQueue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(q, val);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                print(q);
                break;
            case 4:
                printf("Exiting...\n");
                free(q->arr);
                free(q);
                exit(0);  // Exit the program safely
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
