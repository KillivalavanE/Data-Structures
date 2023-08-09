#include<stdio.h>
#include<stdlib.h>
int G[100][100],visited[100],n;
void dfs(int i,int n,int visited[],int G[][n]){
    int j;
    printf("%d ",i);
    visited[i]=1;
    for(int j=0;j<n;j++)
    {
        if(G[i][j]==1 && visited[j]==0){
            dfs(j,n,visited,G);
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
    dfs(0,n,visited,G);
    return 0;
}