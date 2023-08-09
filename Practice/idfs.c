#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int data){
    struct node *t=malloc(sizeof(struct node));
    if(t==NULL){
        printf("Stack is full");
    }
    t->data=data;
    t->next=top;
    top=t;
}

int pop(){
    int x;
    struct node *t=top;
    if(top==NULL){
        printf("Stack is empty");
    }
    x=t->data;
    top=top->next;
    free(t);
    return x;
}

int isEmpty(){
    return (top==NULL)?1:0;
}

void dfs(int v,int n,int visited[],int G[][n]){
    
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
    dfs(0,n,visited,G);
    return 0;
}