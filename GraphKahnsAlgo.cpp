#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

vector<int> kahnsAlgo(unordered_map<int, vector<int>> &adj, int v, int e)
{
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : adj[i.first])
            indegree[j]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indegree[i])
            q.push(i);
    }

    vector<int> ans;
 
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto i : adj[front])
        {
            indegree[i]--;
            if (!indegree[i])
                q.push(i);
        }
    }

    return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    cout << "Adjacency List:\n";

    for (auto i : adj)
    {
        cout << i.first << " -> ";
        for (auto j : adj[i.first])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    vector<int> ans = kahnsAlgo(adj, v, e);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}