#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void dfsCall(int node, unordered_map<int, vector<int>> adj, unordered_map<int, bool> &visited)
{
    // preorder
    visited[node] = 1;
    cout << node << " ";
    for (auto j : adj[node])
    {
        if (!visited[j])
            dfsCall(j, adj, visited);
    }
    // postorder
    // visited[node] = 1;
}

void DFS(unordered_map<int, vector<int>> adj)
{
    unordered_map<int, bool> visited;
    for (auto i : adj)
    {
        if (!visited[i.first])
            dfsCall(i.first, adj, visited);
    }
}

void BFS(unordered_map<int, vector<int>> adj)
{
    unordered_map<int, bool> visited;
    for (auto i : adj)
    {
        if (!visited[i.first])
        {
            queue<int> q;
            q.push(i.first);
            visited[i.first] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                cout << node << " ";
                for (auto j : adj[node])
                {
                    if (!visited[j])
                    {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
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

    cout << "Adjacency List:\n";
    for (auto i : adj)
    {
        cout << i.first << " -> ";
        for (auto j : adj[i.first])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";

    BFS(adj);
    cout << "\n";
    DFS(adj);

    return 0;
}