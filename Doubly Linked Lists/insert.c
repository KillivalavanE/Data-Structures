#include<stdio.h>
#include<stdlib.h>
struct node{
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

int length(struct node *head){
    int len=0;
    while (head)
    {
        len++;
        head=head->next;
    }
    return len;
}

void print(struct node *head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

struct node * insert(struct node *head,int index,int x){
    struct node *t=malloc(sizeof(struct node));
    struct node *p=head;
    t->data=x;
    if(index <0 || index > length(head)){
        printf("Invalid Index");
        return 0;
    }
    if(index==0){
        t->prev=NULL;
        t->next=head;
        head->prev=t;
        head=t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->prev=p;
        t->next=p->next;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;

    }
    return head;
}

int main(){
    struct node *head=createlist(head);
    int index,data;
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    printf("Enter the index for which the data to be inserted: ");
    scanf("%d",&index);
    head=insert(head,index,data);
    if(head)
        print(head);
    return 0;
} 