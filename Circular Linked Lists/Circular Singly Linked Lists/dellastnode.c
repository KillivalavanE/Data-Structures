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
//TIME COMPLEXITY FOR DELETING THE LAST NODE OF A CIRCULAR SINGLY LINKED LIST IS O(n)
struct node * del_last(struct node *tail){
    struct node *temp=tail->next;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}

void print(struct node *tail){
    if(tail==NULL){
        printf("No Nodes in the list");
    }
    else{
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
    printf("List before deleting the last node...");
    print(tail);
    tail=del_last(tail);
    printf("List after deleting the last node...");
    print(tail);
    return 0;
}
