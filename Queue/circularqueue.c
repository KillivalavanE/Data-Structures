#include<stdio.h>
#include<stdlib.h>
#define q_size 100
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full");
        exit(1);
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->front == q->rear){
        printf("Queue is empty");
        exit(1);
    }
    else{
        q->front = (q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int frontele(struct Queue q){
    int i=q.front+1;
    return q.Q[i];
}

void display(struct Queue q){
    int i=q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

int main(){
    
 struct Queue q;

 create(&q,q_size);
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
                            enqueue(&q,data);
                            break;
                        }
                case 2:
                        {
                            data=dequeue(&q);
                            printf("Element Dequeued: %d",data);
                            break;
                        }
                case 3:
                        {
                            printf("Front element: %d",frontele(q));
                            break;
                        }
                case 4:
                        {
                            display(q);
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