#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;
#define um unordered_map

void topologicalDFS(um<int, vector<pair<int, int>>> &adj, um<int, bool> &visited, int node, stack<int> &st)
{
    visited[node] = 1;

    for (auto i : adj[node])
    {
        if (!visited[i.first])
            topologicalDFS(adj, visited, i.first, st);
    }

    st.push(node);
}

void shortestPathDAG(um<int, vector<pair<int, int>>> &adj, int n, int src)
{
    um<int, bool> visited;
    stack<int> st;

    for (auto i : adj)
    {
        if (!visited[i.first])
            topologicalDFS(adj, visited, i.first, st);
    }
    vector<int> dist(n, INT_MAX);
    // src=1;
    dist[src] = 0;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (dist[top] != INT_MAX)
        {
            for (auto i : adj[top])
            {
                if (dist[top] + i.second < dist[i.first])
                    dist[i.first] = dist[top] + i.second;
            }
        }
    }
    for (auto i : dist)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    um<int, vector<pair<int, int>>> adj;

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    cout << "Enter the source:\n";
    int src;
    cin >> src;

    cout << "Adjacency List:\n";

    for (auto i : adj)
    {
        cout << i.first << " -> ";
        for (auto j : adj[i.first])
            cout << "(" << j.first << "," << j.second << "),"
                 << " ";
        cout << "\n";
    }
    cout << "\n";
    shortestPathDAG(adj, v, src);

    return 0;
}