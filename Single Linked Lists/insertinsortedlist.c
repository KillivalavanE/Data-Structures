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

struct node * insertinsorted(struct node *head,int num){
    struct node *t=malloc(sizeof(struct node));
    t->data=num;
    t->next=NULL;
    struct node *p=head,*q=NULL;
    if(head==NULL){
        head=t;
    }
    else{
        while(p && p->data<num){
            q=p;
            p=p->next;
        }
        if(p==head){
            t->next=head;
            head=t;
        }
        else{
            t->next=q->next;
            q->next=t;            
        }
    }
    return head;
}

void print(struct node *head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    struct node *head=createlist();
    int num;
    printf("Enter the number to be inserted in the sorted list: ");
    scanf("%d",&num);
    head=insertinsorted(head,num);
    print(head);
    return 0;
}