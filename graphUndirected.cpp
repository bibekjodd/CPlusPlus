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

// --------------------------------print array------------------------------------------
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void printVector(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
}
// --------------------------------print array end------------------------------------------

// --------------------------- print adjacency list ---------------------------
void printAdj(ump<int, vi> &adjList)
{
    for (auto i : adjList)
    {
        cout << i.first << " ";
        for (auto j : i.second)
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
}
// --------------------------------------------------------------------------------------------

// --------------------------- bfs ---------------------------
void BFS(ump<int, vi> &adjList)
{
    vi ans;
    ump<int, bool> visited;
    queue<int> q;
    for (auto i : adjList)
    {
        if (!visited[i.first])
        {
            q.push(i.first);
            visited[i.first] = true;
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto j : adjList[front])
            {
                if (!visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    printVector(ans);
}
// --------------------------------------------------------------------------------------------

// --------------------------- DFS ---------------------------
void callDFS(int node, ump<int, vi> &adjList, ump<int, bool> &visited, vi &ans)
{
    visited[node] = true;
    ans.push_back(node);
    for (auto i : adjList[node])
        if (!visited[i])
            callDFS(i, adjList, visited, ans);
}

void DFS(ump<int, vi> &adjList)
{
    vi ans;
    ump<int, bool> visited;

    for (auto i : adjList)
    {
        if (!visited[i.first])
            callDFS(i.first, adjList, visited, ans);
    }

    printVector(ans);
}
// --------------------------------------------------------------------------------------------

// ---------------------------cyce detection by using BFS---------------------------
bool detectCycleBFS(ump<int, vi> &adjList)
{
    ump<int, bool> visited;
    ump<int, int> parent;

    queue<int> q;
    for (auto i : adjList)
    {
        if (!visited[i.first])
        {
            q.push(i.first);
            visited[i.first] = true;
            parent[i.first] = -1;
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto j : adjList[front])
            {
                if (!visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                    parent[j] = front;
                }
                else if (visited[j] && j != parent[front])
                    return 1;
            }
        }
    }
    return 0;
}
// --------------------------------------------------------------------------------------------

// ---------------------------detect cycle by DFS---------------------------
bool callDetectCycleDFS(int node, ump<int, vi> &adjList, ump<int, bool> &visited, ump<int, bool> &dfsVisited, int parent)
{
    dfsVisited[node] = true;
    visited[node] = true;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            if (callDetectCycleDFS(i, adjList, visited, dfsVisited, node))
                return 1;
        }
        else if (dfsVisited[i] && i != parent)
            return 1;
    }
    dfsVisited[node] = false;
    return 0;
}

bool detectCycleDFS(ump<int, vi> &adjList)
{
    ump<int, bool> visited, dfsVisited;

    for (auto i : adjList)
    {
        if (!visited[i.first])
        {
            if (callDetectCycleDFS(i.first, adjList, visited, dfsVisited, -1))
                return 1;
        }
    }
    return 0;
}
// --------------------------------------------------------------------------------------------

int main()
{
    int edges;
    cin >> edges;

    ump<int, vi> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // printAdj(adjList);
    // BFS(adjList);
    // DFS(adjList);
    cout << detectCycleBFS(adjList) << "\n";
    cout << detectCycleDFS(adjList) << "\n";

    return 0;
}