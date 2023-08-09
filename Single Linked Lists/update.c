#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *create_node(int x){
    struct node *t=malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    return t;
}

struct node *createlist(){
    int data;
    printf("Enter the data: ");
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

struct node *update(struct node *head,int pos,int data){
    struct node *p=head;
    if(pos==0){
        head->data=data;
        return head;
    }
    if(pos==-1){
        while(p->next!=NULL){
            p=p->next;
        }
        p->data=data;
        return head;
    }
    else{
        for(int i=0;i<pos;i++){
            p=p->next;
        }
        p->data=data;
        return head;
    }
}

void print(struct node *head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    struct node *head=createlist();
    int pos,data;
    printf("Enter the position to be updated (-1 to update last node): ");
    scanf("%d",&pos);
    printf("Enter the data to be updated: ");
    scanf("%d",&data);
    head=update(head,pos,data);
    print(head);
    return 0;
}