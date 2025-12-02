#include <bits/stdc++.h>
using namespace std;

// Directed Graph Cycle Detection (BFS - Kahn’s Algorithm)
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
        for (int nbr : adj[i])
            indegree[nbr]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;

        for (int nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return count != V; // If not all nodes processed, cycle exists
}

int main() {
    int V = 4; // Number of vertices
    vector<int> adj[V];

    // Example Graph 1 (with cycle)
    // 0 → 1 → 2
    //      ↑   ↓
    //      ←---3
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    if (isCyclic(V, adj))
        cout << "Directed graph contains a cycle" << endl;
    else
        cout << "Directed graph does not contain a cycle" << endl;

    return 0;
}
