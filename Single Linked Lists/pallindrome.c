#include<stdio.h>
#include<stdlib.h>
struct nodee{
    int data;
    struct nodee *next;
}*top=NULL;


int size=0;

void push(int x){
    struct nodee *t=malloc(sizeof(struct nodee));
    if(t==NULL){
        printf("Stack is full\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
    size++;
}

int pop(){
    int x;
    if(top==NULL){
        printf("Stack is empty\n");
    }
    else{
        struct nodee *p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    size--;
    return x;
}

    int isEmpty(){
        return (top==NULL)?1:0;
    }

    int topele(){
        if(isEmpty()){
            printf("Stack is empty");
        }
        return top->data;
}

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

int checkPali(struct node *head){
    
}

int main(){
    struct node*head=createlist();
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    int res=checkPali(head);
    (res==1)?printf("Yes"):printf("No");
    return 0;
}