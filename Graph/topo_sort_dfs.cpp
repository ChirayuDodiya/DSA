#include <bits/stdc++.h>
using namespace std;

// DFS helper for Topological Sort
void dfsTopo(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &adj)
{
    visited[node] = true;
    for (int nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfsTopo(nbr, visited, st, adj);
        }
    }
    st.push(node);
}

// Topological Sort (DFS based)
vector<int> topoSortDFS(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsTopo(i, visited, st, adj);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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

    vector<int> topo = topoSortDFS(V, adj);

    cout << "Topological Order (DFS-based): ";
    for (int node : topo)
        cout << node << " ";
    cout << endl;

    return 0;
}
