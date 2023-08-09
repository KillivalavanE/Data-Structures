#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node * del_entire_list(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
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

    head=del_entire_list(head);
    if(head==NULL){
        printf("Linked list is deleted succesfully");
    }
    return 0;

}