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

struct node * del_specific(struct node *tail,int pos){
    struct node *temp=tail->next;
    if(tail==NULL){
        return tail;
    }
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    int p=pos;
    int p1=pos-1;
    if(p!=2){
        while(p>p1){
        temp=temp->next;
        p--;
    }
    }
    struct node *temp2;
    temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail){
        tail=temp;
    }
    free(temp2);
    temp2=NULL;
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
    int pos=2;
    printf("List before deleting node at specific position...");
    print(tail);
    tail=del_specific(tail,pos);
    printf("List after deleting node at specific position...");
    print(tail);
    return 0;
}
