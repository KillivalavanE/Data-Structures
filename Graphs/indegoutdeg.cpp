#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cout << "Enter the number of vertices : ";
        cin >> n;
        int arr[n][n];
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        arr[i][j]=0;
                }
        }
        int in[n]={0},out[n]={0};
        int ch = 1;
        int u, v;
        if (n != 1)
        {
                while (ch)
                {
                        cout << "Enter the adjacent vertex : ";
                        cin >> u >> v;
                        in[v]++;
                        out[u]++;
                        arr[u][v] = 1;
                        cout << "Enter 1 to continue (0 to quit) : ";
                        cin >> ch;
                }
        }
        printf("Adjacency matrix of the graph\n");
        cout << "    ";

        for (int i = 0; i < n; i++)
                cout << i << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
                cout << i << " | ";
                for (int j = 0; j < n; j++)
                {
                        cout << arr[i][j] << " ";
                }
                cout << endl;
        }
    for(int i=0;i<n;i++)
    {
        cout << "In and out degree of " << i << " is : ";
        cout << in[i] << " " << out[i] << endl;
    }
    return 0;
}