#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node * addToEmpty(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node * addAtBeg(struct node *tail,int data){
    struct node *newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=tail->next;
    tail->next=newP;
    return tail;
}

struct node * addAtEnd(struct node *tail,int data){
    struct node *newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=NULL;

    newP->next=tail->next;
    tail->next=newP;
    tail=tail->next;
    return tail;
}
//TIME COMPLEXTIY FOR INSERTION OF NODE AFTER POSITION IS O(n)
struct node * addAfterPos(struct node *tail,int data,int pos){
    struct node *newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=NULL;
    struct node *p=tail->next;
    while(pos!=1){
        p=p->next;
        pos--;
    }
    newP->next=p->next;
    p->next=newP;
    if(p==tail){
        tail=tail->next;
    }
    return tail;
}

void print(struct node *tail){
    struct node *p=tail->next;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=tail->next);
    printf("\n");
}

int main(){
    struct node *tail;
    tail=addToEmpty(69);
    tail=addAtBeg(tail,45);
    tail=addAtBeg(tail,56);
    tail=addAtEnd(tail,72);
    tail=addAtEnd(tail,89);
    printf("List before inserting element after particular position...");
    print(tail);
    tail=addAfterPos(tail,23,3);
    printf("List after inserting element after particular position...");
    print(tail);
    return 0;
}