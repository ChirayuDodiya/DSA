#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, size;
    
public:
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void joinNode(int u, int v)
    {
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        if (parent_u == parent_v)
            return;
        if (size[parent_u] < size[parent_v])
        {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else
        {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
    }
};
int main()
{
    DSU ds(7);
    ds.joinNode(1, 2);
    ds.joinNode(2, 3);
    ds.joinNode(4, 5);
    ds.joinNode(6, 7);
    ds.joinNode(5, 6);
    // if 3 and 7 same or not
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.joinNode(3, 7);

    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}
