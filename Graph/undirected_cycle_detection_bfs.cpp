#include <bits/stdc++.h>
using namespace std;

// Undirected Graph Cycle Detection (BFS)
bool bfs(int src, vector<int> adj[], vector<bool> &visited)
{
    queue<pair<int, int>> q;
    q.push({src, -1});
    visited[src] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                visited[nbr] = true;
                q.push({nbr, node});
            }
            else if (nbr != parent)
            {
                return true;
            }
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
            if (bfs(i, adj, visited))
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
