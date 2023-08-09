//TIME COMPLEXITY IS O(n)
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void print_data(struct node *head){
    /*if(head==NULL){
        printf("Linked list is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }*/

    struct node *p=head;
    if(p!=NULL){
        print_data(p->link);
        printf("%d ",p->data);
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=2;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data = 3;
    current->link=NULL;
    head->link->link=current;
    print_data(head);
    return 0;
}