#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node * add_to_emptylist(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

struct node * addAtEnd(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    return head;
}

struct node * createlist(struct node *head){
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n==0){
        return head;
    }
    printf("Enter the element of node 1: ");
    scanf("%d",&data);
    head= add_to_emptylist(head,data);

    for(int i=1;i<n;i++){
        printf("Enter the element of node %d: ",i+1);
        scanf("%d",&data);
        head=addAtEnd(head,data);
    }
    return head;

}
int main(){
    struct node *head=NULL;
    head=createlist(head);
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}



