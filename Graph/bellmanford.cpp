#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int V, vector<vector<int>>& edges, int src)
{
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Relax edges V-1 times
    for(int i = 0; i < V - 1; i++)
    {
        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(dist[u] != 1e9 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    // Check negative cycle
    for(auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if(dist[u] != 1e9 && dist[u] + wt < dist[v])
        {
            cout << "Negative cycle detected\n";
            return;
        }
    }

    for(int i = 0; i < V; i++)
        cout << dist[i] << " ";
}

int main()
{
    // int V = 5; // Number of vertices
    // vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}};
    int V=3;
    vector<vector<int>> edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, 2}};
    bellmanFord(V, edges, 0);
    return 0;
}