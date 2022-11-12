#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool detectCycle(int node, unordered_map<int, vector<int>> adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
{
    visited[node] = 1;
    dfsVisited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            if (detectCycle(i, adj, visited, dfsVisited))
                return 1;
        }
        else if (dfsVisited[i])
            return 1;
    }
    dfsVisited[node] = 0;
    return 0;
}

bool cycle(unordered_map<int, vector<int>> adj)
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (auto i : adj)
    {
        if (!visited[i.first])
            return detectCycle(i.first, adj, visited, dfsVisited);
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cout << "Adjacency list:\n";
    for (auto i : adj)
    {
        cout << i.first << " -> ";
        for (auto j : adj[i.first])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
    cycle(adj) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}