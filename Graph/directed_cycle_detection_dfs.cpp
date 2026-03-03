#include <bits/stdc++.h>
using namespace std;

// Directed Graph Cycle Detection (DFS + Recursion Stack)
bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack)
{
    visited[node] = true;
    recStack[node] = true;

    for (int nbr : adj[node])
    {
        if (!visited[nbr])
        {
            if (dfs(nbr, adj, visited, recStack))
                return true;
        }
        else if (recStack[nbr])
        {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

int main()
{
    int V = 4; // Number of vertices
    vector<int> adj[V];

    // Example Graph 1 (with cycle)
    // 0 → 1 → 2
    //     ↑   ↓
    //     ←---3
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    bool hasCycle = false;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, recStack))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "Directed graph contains a cycle" << endl;
    else
        cout << "Directed graph does not contain a cycle" << endl;

    return 0;
}
