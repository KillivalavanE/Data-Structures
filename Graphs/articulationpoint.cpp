#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{                                                                                                                                                           
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

void APUtil(vector<int> adj[], int u, bool visited[],
			int disc[], int low[], int& time, int parent,
			bool isAP[])
{
	int children = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;
	for (auto v : adj[u]) {
		if (!visited[v]) {
			children++;
			APUtil(adj, v, visited, disc, low, time, u, isAP);
			low[u] = min(low[u], low[v]);
			if (parent != -1 && low[v] >= disc[u])
				isAP[u] = true;
		}
		else if (v != parent)
			low[u] = min(low[u], disc[v]);
	}
	if (parent == -1 && children > 1)
		isAP[u] = true;
}

void AP(vector<int> adj[], int V)
{
	int disc[V] = { 0 };
	int low[V];
	bool visited[V] = { false };
	bool isAP[V] = { false };
	int time = 0, par = -1;
	for (int u = 0; u < V; u++)
		if (!visited[u])
			APUtil(adj, u, visited, disc, low,time, par, isAP);
	for (int u = 0; u < V; u++)
		if (isAP[u] == true)
			cout << u << " ";
}

int main()
{
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
    printf("Articulation Points of the graph are: ");
    AP(adj,n);
	return 0;
}
