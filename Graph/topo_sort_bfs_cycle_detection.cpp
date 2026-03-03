#include <bits/stdc++.h>
using namespace std;

// Topological Sort with Cycle Detection (BFS - Kahn's Algorithm)
bool topoSortKahn(int V, vector<vector<int>> &adj, vector<int> &result)
{
    vector<int> indegree(V, 0);

    // Calculate indegree of each node
    for (int i = 0; i < V; i++)
    {
        for (int nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    // Push nodes with indegree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Decrease indegree of neighbors
        for (int nbr : adj[node])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return (result.size() == V); // if not all nodes processed → cycle exists
}

int main()
{
    int V = 6;
    vector<vector<int>> adj = {
        {2, 3}, // 0 -> 2,3
        {3, 4}, // 1 -> 3,4
        {5},    // 2 -> 5
        {5},    // 3 -> 5
        {},     // 4
        {}      // 5
    };

    vector<int> result;
    if (topoSortKahn(V, adj, result))
    {
        cout << "Topological Order (Kahn's BFS): ";
        for (int x : result)
            cout << x << " ";
    }
    else
    {
        cout << "Cycle detected!";
    }
}
