#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;

int size=0;

void push(int x){
    struct node *t=malloc(sizeof(struct node));
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
        struct node *p=top;
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

    int getsize(){
        return size;
    }

    void display(){
        struct node *p=top;
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
            printf("\n1. Push");
            printf("\n2. Pop");
            printf("\n3. Top");
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
                            push(data);
                            break;
                        }
                case 2:
                        {
                            data=pop();
                            printf("Element popped: %d",data);
                            break;
                        }
                case 3:
                        {
                            printf("Topmost element: %d",topele());
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