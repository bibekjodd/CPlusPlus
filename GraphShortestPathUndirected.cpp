#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> shortestPath(unordered_map<int, vector<int>> &adj, int x, int y)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    parent[x] = -1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = node;
            }
        }
    }
    vector<int> path;
    path.push_back(y);
    int curr = y;

    while (curr != x)
    {
        curr = parent[curr];
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    return path;
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
        adj[y].push_back(x);
    }
    int x, y;
    cin >> x >> y;
    cout << "Adjacency List:\n";
    for (auto i : adj)
    {
        cout << i.first << " -> ";
        for (auto j : adj[i.first])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
    vector<int> path = shortestPath(adj, x, y);
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i];
        if(i!=path.size()-1)
        cout<<" -> ";
    }

    return 0;
}