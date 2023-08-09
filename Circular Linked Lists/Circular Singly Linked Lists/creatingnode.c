#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node * create_circular_Singly(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

int main(){
    struct node *tail;
    int data=69;
    tail=create_circular_Singly(data);
    printf("%d",head->data);
    return 0;
}