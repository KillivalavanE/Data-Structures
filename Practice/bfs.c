#include<stdio.h>
#include<stdlib.h>
int G[100][100],visited[100],n;
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int data){
    struct node *t=malloc(sizeof(struct node));
    t->data=data;
    t->next=NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
}

int dequeue(){
    int x=-1;
    struct node *t=front;
    x=t->data;
    front=front->next;
    free(t);
    return x;
}

int isEmpty(){
    return (front==NULL)?1:0;
}

void bfs(int v,int n,int visited[],int G[][n]){
    int i=v,j;
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
    while(!isEmpty())
    {
        i=dequeue();
        for(int j=0;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the no.of vertices: ");
    scanf("%d",&n);
    int G[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=0;
        }
    }
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int ch=1;
    int u=0,v=0;
    if(n!=1){
        while(ch){
            printf("Enter the adjacent vertices: ");
            scanf("%d%d",&u,&v);
            G[u][v]=1;
            G[v][u]=1;
            printf("Enter 1 to continue (0 to quit) :");
            scanf("%d",&ch);
        }
    }
    printf("Adjacency Matrix of the Graph\n"); 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    bfs(1,n,visited,G);
    return 0;
}