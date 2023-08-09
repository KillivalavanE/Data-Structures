#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node * create_node(int data){  
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

struct node * createlist(){
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    struct node *head=NULL;
    struct node *temp=NULL;
    do{
        struct node *newnode= create_node(data);
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter data (-1 to quit) :");
        scanf("%d",&data);
    }while(data!=-1);
    return head;
}

int length(struct node *head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}

int middle(struct node *head){
    struct node *p=head,*q=head;
    int len=length(head);
    while(q){
        q=q->next;
        if(q)
            q=q->next;
        if(q)
            p=p->next;
    }
    return p->data;
}

void print(struct node *head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    struct node *head=createlist();
    printf("Linked list is: ");
    print(head);
    printf("Middle Element of the linked list: %d",middle(head));
    return 0;
}