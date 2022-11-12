#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int N = 1e5 + 2;
const int X = 1e3 + 2;
long long int t[X][N] = {0};

// matrix chain multiplication => return the minimum cost to multiply the matrix
int solve(int a[], int i, int j)
{
    int mini = INT_MAX;
    if (i >= j)
        return 0;
    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = solve(a, i, k) + solve(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        mini = min(mini, tempAns);
    }
    return mini;
}

// matrix chain memoization
int matrixChain(int a[], int i, int j)
{
    if (t[i][j] != -1)
        return t[i][j];
    int mini = INT_MAX;
    if (i >= j)
        return 0;
    for (int k = i; k <= j - 1; k++)
    {
        if (t[i][j] != -1)
            return t[i][j];
        int tempAns = t[i][j] = solve(a, i, k) + solve(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        mini = min(mini, tempAns);
    }
    return t[i][j] = mini;
}

int main()
{
    // int a[] = {40, 20, 30, 10, 30};
    memset(t, -1, sizeof(t));
    int a[] = {1, 2, 3, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << solve(a, 1, n - 1) << "\n";
    cout << matrixChain(a, 1, n - 1) << "\n";

    return 0;
}