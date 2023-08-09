#include<bits/stdc++.h> 
using namespace std; 

bool isCyclicConntected(vector<int> adj[], int s, int V, vector<bool>& visited) {
    // Set parent vertex for every vertex as -1.
    vector<int> parent(V, -1);
 
    queue<int> q;

    visited[s] = true;
    q.push(s);
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if(parent[u] != v)
                return true;
        }
    }
    return false;
}
 
 
bool isCyclicDisconntected(vector<int> adj[], int V) {
    
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for(int i = 0; i < V; i++)
        if(!visited[i] && isCyclicConntected(adj, i, V, visited))
            return true;
    return false;
}


void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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


int main(){
    int n;
    cout<<"Enter the no.of vertices: ";
    cin >> n;
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
    isCyclicDisconntected(adj,n)?printf("Graph has a cycle"):printf("Graph doesn't have a cycle");
    return 0;
}