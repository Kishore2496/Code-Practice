#include<iostream>
#include<vector>
#include<list>

using namespace std;
bool visited[5];
vector<int> adj[5];

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int v)
{
    visited[v] = true;
    cout << v << " ";

    for(auto itr = adj[v].begin(); itr != adj[v].end(); itr++){
        if(!visited[*itr])
            DFS(*itr);
    }
}


int main()
{

    for(int i = 0; i < 5; i++)
        visited[i] = false;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 3);

    DFS(2);
    return 0;
}