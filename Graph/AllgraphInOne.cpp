#include <bits/stdc++.h>
using namespace std;

//undirected graph cycle detection dfs
bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            if (dfs(nbr, node, adj, visited)) return true;
        } else if (nbr != parent) {
            return true;
        }
    }
    return false;
}

//undirected graph cycle detetion bfs
bool bfs(int src, vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> q;
    q.push({src, -1});
    visited[src] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push({nbr, node});
            } else if (nbr != parent) {
                return true;
            }
        }
    }
    return false;
}

//directed graph cycle detection dfs
bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            if (dfs(nbr, adj, visited, recStack)) return true;
        } else if (recStack[nbr]) {
            return true;
        }
    }
    recStack[node] = false;
    return false;
}

//directed graph cycle detection bfs(topological sort)
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

    return count != V;
}

//topologocal sort(dfs based)
void dfsTopo(int node, vector<bool>& visited, stack<int>& st, vector<vector<int>>& adj) {
    visited[node] = true;
    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            dfsTopo(nbr, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsTopo(i, visited, st, adj);
        }
    }
    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

//topological sort(bfs based)
vector<int> topoSortKahn(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int nbr : adj[i]) {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        topo.push_back(node);

        for (int nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) q.push(nbr);
        }
    }

    // if topo.size() != V, then graph has a cycle
    return topo;
}

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

//topological sort with cycle detection (bfs based)
bool topoSortKahn(int V, vector<vector<int>>& adj, vector<int>& result) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int nbr : adj[i]) {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front(); q.pop();
        result.push_back(node);

        for (int nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) q.push(nbr);
        }
    }

    return (result.size() == V); // if not all nodes processed → cycle exists
}
