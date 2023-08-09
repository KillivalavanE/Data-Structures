#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *t=malloc(sizeof(struct node));
    if(t==NULL){
        printf("Queue if Full");
    }
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    struct node *t;
    if(front==NULL){
        printf("Queue is empty");
    }
    else{
        t=front;
        front=front->next;
        x=t->data;
        free(t);
    }
    return x;
}

int frontele(){
    return front->data;
}

void display(){
    struct node *p=front;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    int ch,data;
        while(1)
        {
            printf("\n------------------------");
            printf("\n1. Enqueue");
            printf("\n2. Dequeue");
            printf("\n3. Front");
            printf("\n4. Print");
            printf("\n5. Quit");
            printf("\n------------------------");
            printf("\nEnter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                        {
                            printf("Enter element: ");
                            scanf("%d",&data);
                            enqueue(data);
                            break;
                        }
                case 2:
                        {
                            data=dequeue();
                            printf("Element Dequeued: %d",data);
                            break;
                        }
                case 3:
                        {
                            printf("Front element: %d",frontele());
                            break;
                        }
                case 4:
                        {
                            display();
                            break;
                        }
                case 5:
                        {
                           exit(1);
                        }
                default:
                        {
                            printf("Invalid choice!!");
                        }
                }
        }
    return 0;
}