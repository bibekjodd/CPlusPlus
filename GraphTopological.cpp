#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

void topologicalDFS(int node, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, stack<int> &st)
{
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            topologicalDFS(i, adj, visited, st);
        }
    }
    st.push(node);
}

stack<int> topologicalSortDFS(unordered_map<int, vector<int>> &adj)
{
    unordered_map<int, bool> visited;
    stack<int> st;
    // for (auto i : adj)
    // {
    //     if (!visited[i.first])
    //         topologicalDFS(i.first, adj, visited, st);
    // }
    topologicalDFS(1, adj, visited, st);
    return st;
}

// Topological sort using Kahn's algorithm

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

    cout << "Adjacency List:\n";
    for (auto i : adj)
    {
        cout << i.first << " -> ";
        for (auto j : adj[i.first])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";

    stack<int> st = topologicalSortDFS(adj);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}