#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int data){
    struct node *t=malloc(sizeof(struct node));
    if(t==NULL){
        printf("Queue is full");
    }
    else{
        t->data=data;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    if(front==NULL){
        printf("Queue is empty");
    }
    else{
        struct node *t=front;
        x=t->data;
        front=front->next;
        free(t);
    }
    return x;
}

void print(){
    struct node *p=front;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    return 0;
}