#include <iostream>
#include <vector>
#include <utility>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
using namespace std;
const int N = 1e5 + 2, MOD = 1e9 + 7;
vi adj[N];

// adjacency matrix
vvi adjM(int n, int m)
{
    vvi adjm(n, vi(n, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    return adjm;
}

void adjList(int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // vvi adjm(n, vi(n));
    // adjm = adjM(n, m);
    adjList(n, m);

    cout << "Adjancecy list of the above graph is given by:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int x : adj[i])
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}