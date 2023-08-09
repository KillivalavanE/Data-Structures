#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int data){
    struct node *t=malloc(sizeof(struct node));
    if(t==NULL){
        printf("Stack is full");
    }
    t->data=data;
    t->next=top;
    top=t;
}

int pop(){
    int x;
    struct node *t=top;
    if(top==NULL){
        printf("Stack is empty");
    }
    x=t->data;
    top=top->next;
    free(t);
    return x;
}

int topele(){
    if(top==NULL){
        printf("Stack is empty");
    }
    return top->data;
}

int isEmpty(){
    return (top==NULL)?1:0;
}

void print(){
    struct node *p=top;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    return 0;
}