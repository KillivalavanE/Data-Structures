//CREATING A NODE OF CIRCULAR DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node * create_circular_doubly(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=temp;
    temp->next=temp;
    return temp;
}

int main(){
    struct node *tail;
    int data=69;
    tail=create_circular_doubly(data);
    printf("%d",head->data);
    return 0;
}