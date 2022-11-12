#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ump unordered_map
#define ff first
#define ss second
#define gi greater<int>
const int N = 1e5 + 2;
const int X = 1e3 + 2;

void printAdj(ump<int, vii> &adj)
{
    for (auto i : adj)
    {
        cout << i.first << " ";
        for (auto j : adj[i.first])
            cout << "(" << j.first << " " << j.second << ") ";
        cout << "\n";
    }
    cout << "\n";
}

void dijkstra(ump<int, vii> &adj, int v, int e)
{
    int src = 0;
    vi dist(v, INT_MAX);
    dist[src] = 0;
    set<pii> s;
    s.insert({0, src});

    while (!s.empty())
    {
        auto topNode = *(s.begin());
        int top = topNode.second;
        int d = topNode.first;
        s.erase(s.begin());
        
        for (auto i : adj[top])
        {
            if (d + i.second < dist[i.first])
            {
                auto record = s.find({dist[i.first], i.first});
                if (record != s.end())
                    s.erase(record);
                dist[i.first] = d + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }
    for (auto i : dist)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    int v, e;
    cin >> v >> e;

    ump<int, vii> adj(v);

    for (int i = 0; i < e; i++)
    {
        // <->edge weight
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    printAdj(adj);
    dijkstra(adj, v, e);

    return 0;
}