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

struct node * merge(struct node *p,struct node *q){
    struct node *last,*third;
    if(p->data<q->data){
        last=third=p;
        p=p->link;
        third->link=NULL;
    }
    else{
        last=third=q;
        q=q->link;
        third->link=NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->link=p;
            last=p;
            p=p->link;
            last->link=NULL;
        }
        else{
            last->link=q;
            last=q;
            q=q->link;
            last->link=NULL;
        }
    }
    if(p){
        last->link=p;
    }
    else{
        last->link=q;
    }
    return third;
}

void print(struct node *head){
    struct node *p=head;
    while(p){
        printf("%d ",p->data);
        p=p->link;
    }
}

int main(){
    printf("Enter data for linked list 1: ");
    struct node *head1=createlist();
    printf("Linked list-1: ");
    print(head1);
    printf("Enter data for linked list 2: ");
    struct node *head2=createlist();
    printf("Linked list-2: ");
    print(head2);
    struct node *head=merge(head1,head2);
    printf("Linked list after merging two linked lists: ");
    print(head);
    return 0;
}