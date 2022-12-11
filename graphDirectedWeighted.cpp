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

void printVector(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
}

// ---------------------------print adjacency list---------------------------
void printAdj(ump<int, vii> &adjList)
{
    for (auto i : adjList)
    {
        cout << i.first << ":  ";
        for (auto j : i.second)
            cout << j.first << " " << j.second << "   ";
        cout << "\n";
    }
    cout << "\n";
}
// --------------------------------------------------------------------------------------------

// ---------------------------Topological Sort---------------------------
void callTopologicalSort(int node, ump<int, vii> &adjList, ump<int, bool> &visited, stack<int> &ans)
{
    visited[node] = true;
    for (auto i : adjList[node])
    {
        if (!visited[i.second])
            callTopologicalSort(i.second, adjList, visited, ans);
    }
    ans.push(node);
}

stack<int> topologicalSort(ump<int, vii> &adjList)
{
    stack<int> ans;
    ump<int, bool> visited;
    for (auto i : adjList)
    {
        if (!visited[i.first])
            callTopologicalSort(i.first, adjList, visited, ans);
    }
    return ans;
}
// --------------------------------------------------------------------------------------------

// ---------------------------shortest path in DAG Weighted---------------------------
void shortestPathDAG(ump<int, vii> &adjList)
{
    int src = 1;
    vi ans;
    stack<int> topo = topologicalSort(adjList);
    ump<int, int> dist;

    for (auto i : adjList)
    {
        dist[i.first] = INT_MAX;
        for (auto j : i.second)
            dist[j.second] = INT_MAX;
    }
    dist[src] = 0;

    while (!topo.empty())
    {
        int top = topo.top();
        topo.pop();
        if (dist[top] == INT_MAX)
            continue;

        for (auto i : adjList[top])
        {
            int currDist = dist[i.second];
            int totalDist = dist[top] + i.first;

            if (totalDist < currDist)
                dist[i.second] = totalDist;
        }
    }

    for (auto i : dist)
        cout << i.first << " " << i.second << "\n";
}
// --------------------------------------------------------------------------------------------

int main()
{
    int edges;
    cin >> edges;
    ump<int, vii> adjList;

    for (int i = 0; i < edges; i++)
    {
        int u, w, v;
        cin >> u >> w >> v;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, v});
        adjList[v].pop_back();
    }
    printAdj(adjList);
    // topologicalSort(adjList);
    shortestPathDAG(adjList);

    return 0;
}