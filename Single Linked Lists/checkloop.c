#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node * create_node(int data){  
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
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
            temp->next=newnode;
            temp=newnode;
            
        }
        printf("Enter data (-1 to quit) :");
        scanf("%d",&data);
    }while(data!=-1);
    return head;
}

int checkloop(struct node *head){
    struct node *p,*q;
    p=q=head;
    do{
        p=p->next;
        q=q->next;
        q ? q=q->next : q;
    }while(p && q && p!=q);
    if(p==q)
        return 1;
    else
        return 0;
}

int main(){
    struct node *head=createlist();
    struct node *t1,*t2;
    t1=head->next->next;
    t2=head->next->next->next->next;
    t2->next=t1;
    int res=checkloop(head);
    (res==1) ? printf("Loop is present") : printf("Loop is absent");
    return 0;
}
