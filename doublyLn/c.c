#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* add_to_empty(struct node* head,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

struct node* insert_at_first(struct node* head,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

void add_at_end(struct node*head,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct node* ptr;
    ptr=head;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    temp->prev=ptr;
    ptr->next=temp;
}
struct node* add_After_Pos(struct node* head,int data,int pos){
    struct node* temp=head;
    struct node* newP=NULL;
    struct node* temp2=NULL;
    newP=add_to_empty(newP,data);
    while(pos !=1){     
        temp=temp->next;
        pos--;
    }   
    temp2=temp->next;
    if(temp2->next=NULL){
        newP->prev=temp2;
        temp2->next=newP;
    }
    else{
        newP->prev=temp;
        newP->next=temp2;
        temp2->prev=newP;
        temp->next=newP;
    }
    return head;
}

struct node* add_bef_pos(struct node* head,int data,int pos){
    struct node* temp=head;
    struct node* newP=NULL;
    struct node* temp2=NULL;
    newP=add_to_empty(newP,data);
    while (pos>2)
    {
        temp=temp->next;
        pos--;
    }
    
        temp2=temp->next;

    if(pos==1){
        head=insert_at_first(head,data);
    }
    
    else{
        newP->prev=temp;
        newP->next=temp2;
        temp2->prev=newP;
        temp->next=newP;
    }
    return head;


}



int main(){
    struct node* head=NULL;
    struct node* ptr=NULL;
    head=add_to_empty(head,45);
    head=insert_at_first(head,33);
    add_at_end(head,18);
    head=add_After_Pos(head,23,2);
    head=add_bef_pos(head,7,4);
    ptr=head;
    while (ptr !=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}