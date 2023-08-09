#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node * create_node(int data){  
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
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
            temp->link=newnode;
            temp=newnode;
            
        }
        printf("Enter data (-1 to quit) :");
        scanf("%d",&data);
    }while(data!=-1);
    return head;
}

void rmduplicates(struct node *head){
    struct node *p=head;
    struct node *q=head->link;
    while(q){
        if(p->data!=q->data){
            p=q;
            q=q->link;
        }
        else{
            p->link=q->link;
            free(q);
            q=p->link;
        }
    }
}

void print(struct node *head){
    struct node *p=head;
    while(p){
        printf("%d ",p->data);
        p=p->link;
    }
}

int main(){
    struct node *head=createlist();
    rmduplicates(head);
    printf("Linked list after removing duplicate elements...");
    print(head);
    return 0;
}