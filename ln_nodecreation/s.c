#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

int countNode(struct node *head){
    int count=0;
    if(head==NULL){
        printf("Linklist is empty\n");
        return 0;
    }
    struct node *ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    return count;
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

struct node *add_on_end(struct node *ptr,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
}

struct node *add_beg(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    temp->link=head;
    head=temp;
    return temp;
}

// void add_beg(struct node **head,int data){
//     struct node *temp=malloc(sizeof(struct node));
//     temp->data=data;
//     temp->link=NULL;

//     temp->link=*head;
//     *head=temp;
// }

void add_on_pos(struct node *head,int data,int pos){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    
    struct node *ptr=head;
    for (int i = 1; i <pos-1; i++)
    {
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    ptr->link=temp;
}

struct node *del_first(struct node *head){
    if(head==NULL){
        printf("List is empty \n");
    }
    else{
        struct node *temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    return head;
}

void del_last(struct node *head){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        struct node *temp2=head;

        while (temp->link!=NULL)
        {
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
        

    }
}

void del_lastusingOneP(struct node *head){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        while(temp->link->link !=NULL){
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
}

void delete_pos(struct node **head,int pos){
    struct node *current=*head;
    struct node *previous=*head;

    if(*head==NULL){
        printf("List is Empty");
    }

    else if(pos==1){
        *head=current->link;
        free(current);
        current->link=NULL;
    }

    else{
        while(pos!=1){
           previous=current;
           current=current->link;
           pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
}

struct node *del_List(struct node*head){
    struct node *temp=head;
    while (temp!=NULL)
    {
        temp=temp->link;
        free(head);
        head=temp;
    }
    return head;
}
struct node *reverse_List(struct node *head){
    struct node *prev=NULL;
    struct node *next=NULL;

    while(head !=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *ptr=head;
    ptr=add_on_end(ptr,18);
    ptr=add_on_end(ptr,35);
    head=add_beg(head,9);
    ptr=add_on_end(ptr,56);
    add_on_pos(head,79,4);
    head=del_first(head);
    del_last(head);
    // del_lastusingOneP(head);
    printLinkList(head);
    // delete_pos(&head,2);
    // head=del_List(head);
    head=reverse_List(head);
    printLinkList(head);
}