#include <bits/stdc++.h>
using namespace std;

// Topological Sort (Kahn’s Algorithm - BFS based)
vector<int> topoSortKahn(int V, vector<vector<int>> &adj)
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int nbr : adj[node])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return topo; // if topo.size() != V, graph has a cycle
}

int main()
{
    int V = 6;
    vector<vector<int>> adj(V);

    // Example DAG:
    // 5 → 2 → 3 → 1
    // 5 → 0
    // 4 → 0
    // 4 → 1
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = topoSortKahn(V, adj);

    cout << "Topological Order (BFS-based / Kahn’s): ";
    for (int node : topo)
        cout << node << " ";
    cout << endl;

    return 0;
}
