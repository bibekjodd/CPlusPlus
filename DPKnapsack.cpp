#include <iostream>
using namespace std;

const int n = 7, w = 15;
int t[n + 1][w + 1] = {-1};

// knapsack memoization
int knapsack(int value[], int weight[], int n, int w)
{
    if (!n || !w)
        return 0;

    if (t[n][w] != -1)
        return t[n][w];

    if (weight[n - 1] > w)
        return t[n][w] = knapsack(value, weight, n - 1, w);
    return t[n][w] = max(knapsack(value, weight, n - 1, w - weight[n - 1]) + value[n - 1], knapsack(value, weight, n - 1, w));
}

// knapsack tabulation
int knapSack(int value[], int weight[], int n, int w)
{
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < w + 1; j++)
            t[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weight[i - 1] <= j)
                t[i][j] = max(value[i - 1] + t[i - 1][j - weight[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][w];
}

int main()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
            t[i][j] = -1;
    }

    // int value[] = {1, 4, 5, 7};
    // int weight[] = {1, 3, 4, 5};

    int value[] = {10, 5, 15, 7, 6, 18, 3};
    int weight[] = {2, 3, 5, 7, 1, 4, 1};

    // int n = 4, w = 7;
    // cout << knapsack(value, weight, n, w) << "\n"; // memoization top-down
    cout << knapSack(value, weight, n, w) << "\n"; // tabulation bottom-up
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
            cout << t[i][j] << " ";
        cout << "\n";
    }

    return 0;
}