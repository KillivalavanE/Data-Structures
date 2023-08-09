//PROGRAM TO CREATE AN ENTIRE CIRCULAR SINGLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node * addToEmpty(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node * addAtEnd(struct node *tail,int data){
    struct node *newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=NULL;

    newP->next=tail->next;
    tail->next=newP;
    tail=tail->next;
    return tail;
}

struct node * createList(struct node *tail){
    int data,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n==0){
        return tail;
    }
    printf("Enter the element 1: ");
    scanf("%d",&data);
    tail=addToEmpty(data);

    for(int i=1;i<n;i++){
        printf("Enter the element %d: ",i+1);
        scanf("%d",&data);
        tail=addAtEnd(tail,data);
    }
    return tail;
}

int search(struct node *tail,int num){
    struct node *temp=tail->next;
    int index=0;
    if(tail==NULL){
        return -2;
    }
    do{
        if(temp->data==num){
            return index;
        }
        temp=temp->next;
        index++;
    }while(temp!=tail->next);
    return -1;
}

void print(struct node *tail){
    if(tail==NULL){
        printf("No Nodes in the list");
    }
    else{
        printf("The Entire List Created is...");
        struct node *p=tail->next;
        do{
            printf("%d ",p->data);
            p=p->next;
        }while(p!=tail->next);
    printf("\n");
    }
}

int main(){
    struct node *tail=NULL;
    tail=createList(tail);
    print(tail);
    int num;
    printf("Enter the element to be searched in the list: ");
    scanf("%d",&num);
    int index=search(tail,num);
    if(index==-2){
        printf("Linked list is empty");
    }
    else if(index==-1){
        printf("Element is not found in the list");
    }
    else{
        printf("Element %d is found at position %d",num,index+1);
    }
    return 0;
}
