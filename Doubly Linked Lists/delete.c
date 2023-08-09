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

struct node * delete(struct node *head,int pos){
    struct node *p=head;
    if(pos <0 || pos > length(head)){
        printf("Invalid Index");
        return 0;
    }
    if(pos==0){
        head=head->next;
        free(p);
        if(head){
            head->prev=NULL;
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        free(p);
    }
    return head;
}

int main(){
    struct node *head=createlist(head);
    int pos;
    printf("Enter the position of the node to be deleted: ");
    scanf("%d",&pos);
    head=delete(head,pos);
    if(head)
        print(head);
    return 0;
} 