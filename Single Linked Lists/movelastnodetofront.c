//MAKING LAST NODE OF THE LIST AS FIRST NODE AND THE SECOND LAST NODE BECOMES THE LAST NODE
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};

struct node * move_to_front(struct node *head){
    struct node *p,*q;
    if((head==NULL) || (head->link==NULL)){
        return head;
    }
    q=NULL;
    p=head;
    while(p->link!=NULL){
        q=p;
        p=p->link;
    }
    q->link=NULL;
    p->link=head;
    head=p;
    return head;
}

int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;

    current=malloc(sizeof(struct node));
    current->data=69;
    current->link=NULL;
    head->link->link->link=current;
    head=move_to_front(head);

    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}