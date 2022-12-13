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

// ---------------------------Dijkstra's Algorithm---------------------------
void dijkstrasAlgo(ump<int, vii> &adjList)
{
    ump<int, int> dist;
    for (auto i : adjList)
        dist[i.first] = INT_MAX;

    int src = 0;
    dist[src] = 0;
    set<pii> s;
    s.insert({0, src});

    while (!s.empty())
    {
        auto topNode = *s.begin();
        int top = topNode.second;
        int topdist = topNode.first;

        for (auto i : adjList[top])
        {
            int currdist = dist[i.second];
            int totaldist = topdist + i.first;

            if (totaldist < currdist)
            {
                auto find = s.find({currdist, i.first});
                if (find != s.end())
                    s.erase(find);

                dist[i.second] = totaldist;
                s.insert({totaldist, i.second});
            }
        }
        s.erase(s.begin());
    }

    for (auto i : dist)
        cout << i.first << " " << i.second << "\n";
    cout << "\n";
}
// --------------------------------------------------------------------------------------------

// ---------------------------Prims Algorithm for MST---------------------------
void primsAlgorithm(ump<int, vii> &adjList)
{
    int src = 0;
    ump<int, int> key;
    ump<int, bool> mst;
    ump<int, int> parent;
    int totalNodes = 0;
    for (auto i : adjList)
    {
        key[i.first] = INT_MAX;
        mst[i.first] = false;
        parent[i.first] = -1;
        totalNodes++;
    }
    key[src] = 0;
    totalNodes--;
    int totalEdges = 0;

    while (totalEdges != totalNodes)
    {

        int mini = INT_MAX;
        int node;
        for (auto i : key)
        {
            if (mst[i.first] == false && i.second < mini)
            {
                node = i.first;
                mini = i.second;
            }
        }

        mst[node] = true;
        totalEdges++;
        for (auto i : adjList[node])
        {
            if (mst[i.second] == false && i.first < key[i.second])
            {
                parent[i.second] = node;
                key[i.second] = i.first;
            }
        }
    }

    ump<int, vii> MST;
    int totalWeight = 0;
    for (auto i : parent)
    {
        if (i.second != -1)
        {
            MST[i.first].push_back({key[i.first], i.second});
            MST[i.second].push_back({key[i.first], i.first});
            totalWeight += key[i.first];
        }
    }
    printAdj(MST);
    cout << "Total weight is " << totalWeight << "\n";
}
// --------------------------------------------------------------------------------------------

int main()
{
    ump<int, vii> adjList;
    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, w, v;
        cin >> u >> w >> v;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }

    // printAdj(adjList);
    // dijkstrasAlgo(adjList);
    primsAlgorithm(adjList);

    return 0;
}