
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

int sum(struct node *head,int x){
    if(head==NULL){
        return 0;
    }
    else{
        if(head->data%x==0){
            return head->data+sum(head->link,x);
        }
        else{
            sum(head->link,x);
        }
    }
}

int main(){
    struct node *head=createlist();
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n%d",sum(head,2));
    return 0;
}