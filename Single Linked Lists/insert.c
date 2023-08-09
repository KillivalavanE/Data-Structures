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

struct node * insert(struct node *head,int x,int pos){
    struct node *t=malloc(sizeof(struct node));
    struct node *p=head;
    t->data=x;
    if(pos==0){
        t->link=head;
        head=t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->link;
        }
        t->link=p->link;
        p->link=t;
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
    int x,pos;
    printf("Enter the element to be inserted: ");
    scanf("%d",&x);
    printf("Enter the position to be inserted: ");
    scanf("%d",&pos);
    head=insert(head,x,pos);
    print(head);
    return 0;
}