#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Returns the new head in case the head changes
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->link = head;
    return newNode;  // Return the new head
}

void insertAtBack(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

void insertAfterPosition(struct Node* head, int pos, int data) {
    struct Node* temp = head;
    for (int i = 0; i < pos; i++) {
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            return;
        }
        temp = temp->link;
    }
    struct Node* newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
}

// Returns the new head in case the head changes
struct Node* insertBeforePosition(struct Node* head, int pos, int data) {
    if (pos <= 1) {
        return insertAtFront(head, data);  // Insert at front if position <= 1
    }
    
    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->link == NULL) {
            printf("Position out of bounds.\n");
            return head;  // Return the current head unchanged
        }
        temp = temp->link;
    }
    newNode->link = temp->link;
    temp->link = newNode;
    
    return head;  // Return the original head as it hasn't changed
}

// Returns the new head in case the head changes
struct Node* deleteFromFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->link;  // Update the head to the next node
    free(temp);
    return head;  // Return the new head
}

void deleteFromBack(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    if (prev != NULL) {
        prev->link = NULL;
    }
    free(temp);
}

void deleteAfterPosition(struct Node* head, int pos) {
    struct Node* temp = head;
    for (int i = 0; i < pos; i++) {
        if (temp == NULL || temp->link == NULL) {
            printf("Position out of bounds.\n");
            return;
        }
        temp = temp->link;
    }
    struct Node* nodeToDelete = temp->link;
    if (nodeToDelete == NULL) {
        printf("No node to delete.\n");
        return;
    }
    temp->link = nodeToDelete->link;
    free(nodeToDelete);
}

// Returns the new head in case the head changes
struct Node* deleteBeforePosition(struct Node* head, int pos) {
    if (pos <= 1 || head == NULL || head->link == NULL) {
        printf("No node before the given position.\n");
        return head;
    }

    if (pos == 2) {
        return deleteFromFront(head);  // Delete the front node if pos == 2
    }
    
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->link == NULL) {
            printf("Position out of bounds.\n");
            return head;
        }
        prev = temp;
        temp = temp->link;
    }
    if (prev != NULL) {
        prev->link = temp->link;
        free(temp);
    }
    return head;  // Return the head (unchanged in this case)
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

struct Node *reverse(struct Node *head){
    struct Node *temp=NULL;
    struct Node *temp2=NULL;
    while(head !=NULL){

    temp2=head->link;
    head->link=temp;
    temp=head;
    head=temp2;

    }
    head=temp;
    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    insertAtBack(head, 30);
    insertAfterPosition(head, 1, 25);
    head = insertBeforePosition(head, 3, 15);

    printf("List after insertions: ");
    printList(head);

    // head = deleteFromFront(head);
    // deleteFromBack(head);
    // deleteAfterPosition(head, 1);
    // head = deleteBeforePosition(head, 2);

    // printf("List after deletions: ");
    // printList(head);

    head=reverse(head);
    printList(head);

    return 0;
}
