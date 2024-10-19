#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void countNode(struct node *head){
    int count=0;
    if(head==NULL){
        printf("Linklist is empty\n");
        return;
    }
    struct node *ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    printf("lenght = %d\n",count);
}

void printLinkList(struct node *head){
    if(head==NULL){
        printf("Linklist is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");

}

void add_at_end(struct node *head,int data){
    struct node *ptr,*temp;
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    
}

int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=18;
    current->link=NULL;

    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=7;
    current->link=NULL;

    head->link->link=current;

    add_at_end(head,5);
    countNode(head);
    printLinkList(head);
    return 0;

}