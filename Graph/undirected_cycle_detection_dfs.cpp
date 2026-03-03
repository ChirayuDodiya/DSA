#include <bits/stdc++.h>
using namespace std;

// Undirected Graph Cycle Detection (DFS)
bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    for (int nbr : adj[node])
    {
        if (!visited[nbr])
        {
            if (dfs(nbr, node, adj, visited))
                return true;
        }
        else if (nbr != parent)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int V = 5; // Number of vertices
    vector<int> adj[V];

    // Example Graph 1 (with cycle)
    // 0 -- 1
    // |    |
    // 4 -- 2

    // 3 (isolated)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[4].push_back(0);
    adj[0].push_back(4);

    vector<bool> visited(V, false);
    bool hasCycle = false;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}
