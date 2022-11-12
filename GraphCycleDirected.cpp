#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

bool detectCycleBFS(unordered_map<int, vector<int>> adj, unordered_map<int, bool> &visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    unordered_map<int, int> parent;
    parent[node] = -1;
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = node;
            }
            else if (visited[i] && parent[node] != i)
                return 1;
        }
    }
    return 0;
}

bool cycleBFS(unordered_map<int, vector<int>> adj)
{
    unordered_map<int, bool> visited;
    unordered_map<int, vector<int>>::iterator it = adj.begin();
    int node = it->first;
    return detectCycleBFS(adj, visited, node);
}

bool detectCycleDFS(int node, int parent, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            if (detectCycleDFS(i, node, adj, visited))
                return 1;
        }
        else if (i != parent)
            return 1;
    }
}

bool cycleDFS(unordered_map<int, vector<int>> adj)
{
    unordered_map<int, bool> visited;
    for (auto i : adj)
    {
        if (!visited[i.first])
            return detectCycleDFS(i.first, -1, adj, visited);
    }
    return 0;
}

// cycle detection using BFS

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

    cout << "Adjacency List of the matrix is:\n";
    for (auto i : adj)
    {
        cout << i.first << " -> ";
        for (auto j : adj[i.first])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
    cycleBFS(adj) ? cout << "Yes" : cout << "No", cout << "\n";
    cycleDFS(adj) ? cout << "Yes" : cout << "No", cout << "\n";

    return 0;
}