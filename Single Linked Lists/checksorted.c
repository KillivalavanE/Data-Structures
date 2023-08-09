#include<stdio.h>
#include<stdlib.h>
struct node {
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

int checksorted(struct node *head){
    struct node *p=head->link;
    struct node *q=head;
    while(q && p){
        if(p->data<q->data){
            return 0;
        }
        q=q->link;
        p=p->link;
    }
    return 1;
}

int main(){
    struct node *head=createlist();
    int result=checksorted(head);
    if(result){
        printf("Linked list is sorted");
    }
    else{
        printf("Linked list is'nt sorted");
    }
    return 0;
}