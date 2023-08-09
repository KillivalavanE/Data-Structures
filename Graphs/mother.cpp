#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int>* adj;
	void DFSUtil(int v, vector<bool>& visited);

public:
	Graph(int V);
	void addEdge(int v, int w);
	int findMother();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::DFSUtil(int v, vector<bool>& visited)
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

int Graph::findMother()
{
	vector<bool> visited(V, false);
	int v = 0;
	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			DFSUtil(i, visited);
			v = i;
		}
	}
	fill(visited.begin(), visited.end(), false);
	DFSUtil(v, visited);
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return -1;

	return v;
}

int main()
{
    int n;
    cout<<"Enter the no.of vetrices: ";
    cin>>n;
    Graph g(n);
    int ch=1;
    int u,v;
    while(ch){
        cout << "Enter the adjacent vertices: ";
        cin >> u >> v;
        g.addEdge(u,v);
        cout << "Enter 1 to continue (0 to exit): ";
        cin >> ch;
    }
	cout << "A mother vertex is " << g.findMother();
	return 0;
}
