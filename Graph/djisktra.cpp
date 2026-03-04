#include <bits/stdc++.h>
using namespace std;
void dijkstra(int n, vector<vector<pair<int, int>>> &adj, int src, vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist.assign(n, INT_MAX);
    dist[src] = 0;

    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto &it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});

    vector<int> dist;

    dijkstra(n, adj, 0, dist);

    for(auto it : dist)cout << it << " ";
    
    return 0;
}