#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>>& dist)
{
    int V = dist.size();

    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    int V = 3;
    vector<vector<int>> dist = {{0, 5, 1}, {3, 0, 1}, {INT_MAX, 6, 0}};
    floydWarshall(dist);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}