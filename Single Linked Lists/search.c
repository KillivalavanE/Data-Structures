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

int search(struct node *head,int num){
    struct node *p=head;
    while(p){
        if(num==p->data){
            return 1;
        }
    }
    return -1;
}

int main(){
    struct node *head=createlist();
    int num;
    printf("Enter the element to be searched: ");
    scanf("%d",&num);
    int result=search(head,num);
    (result == -1) ? printf("Element not found") : printf("Element %d is found in the linked list",num);
    return 0;
}