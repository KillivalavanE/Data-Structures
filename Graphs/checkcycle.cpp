#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout<<i<<" -> ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << endl;                                                                                                                                       
    }
}

void topologicalSort(vector<int> adj[], int V) { 
    vector<int> in_degree(V, 0); 
  
    for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            in_degree[x]++; 
    } 
  
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

    int count=0;  
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
  
        for (int x: adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
        count++;
    } 
    if (count != V) 
        cout << "There exists a cycle in the graph\n"; 
    else
        cout << "There exists no cycle in the graph\n";
}


int main(){
    int n;
    cout<<"Enter the no.of vertices: ";
    cin>>n;
    vector<int> adj[n];
    int ch=1;
    int u,v;
    while(ch){
        cout << "Enter the adjacent vertices: ";
        cin >> u >> v;
        addEdge(adj,u,v);
        cout << "Enter 1 to continue (0 to exit): ";
        cin >> ch;
    }
    printf("Adjacency List of the matrix: ");
    printGraph(adj,n);
    topologicalSort(adj,n);
    return 0;
}
