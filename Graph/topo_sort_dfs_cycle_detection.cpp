#include<bits/stdc++.h>
using namespace std;
//topological sort with cycle detection (dfs based)
bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
    visited[node] = 1; // 1 = currently in recursion stack

    for (int nbr : adj[node]) {
        if (visited[nbr] == 0) {
            if (!dfs(nbr, adj, visited, result)) return false;
        } else if (visited[nbr] == 1) {
            // back edge → cycle
            return false;
        }
    }

    visited[node] = 2; // 2 = fully processed
    result.push_back(node);
    return true;
}

bool topoSortDFS(int V, vector<vector<int>>& adj, vector<int>& result) {
    vector<int> visited(V, 0); // 0 = unvisited, 1 = visiting, 2 = visited

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, adj, visited, result)) {
                return false; // cycle detected
            }
        }
    }

    reverse(result.begin(), result.end()); // reverse to get topo order
    return true;
}

int main() {
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
    if (topoSortDFS(V, adj, result)) {
        cout << "Topological Order: ";
        for (int x : result) cout << x << " ";
    } else {
        cout << "Cycle detected!";
    }
}
