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

struct node * delete(struct node *head,int pos){
    struct node *p=head,*q=NULL;
    if(pos==1){
        head=p->link;
        free(p);
        p=NULL;
    }
    else{
        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->link;
        }
        q->link=p->link;
        free(p);
        p=NULL;
    }
    return head;
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
    int pos;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    head=delete(head,pos);
    print(head);
    return 0;
}