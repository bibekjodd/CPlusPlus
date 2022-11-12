#include <iostream>
using namespace std;
const int N = 1e5 + 2;
const int x = 1e2;
const int y = 1e5 + 2;
long long t[x][y] = {0};
int t1d[y];

// coin change problem => total ways coin can be changed for given sum
long long coinchange(int a[], int n, int sum)
{
    if (!n)
        return 0;

    if (!sum)
        return 1;

    if (t[n][sum] != -1)
        return t[n][sum];

    if (a[n - 1] <= sum)
        return t[n][sum] = coinchange(a, n, sum - a[n - 1]) + coinchange(a, n - 1, sum);

    return t[n][sum] = coinchange(a, n - 1, sum);
}

int mincoins(int coins[], int n, int sum)
{
    if (!n || !sum)
        return 0;

    if (t1d[sum] != -1)
        return t1d[sum];

    if (coins[n - 1] <= sum)
        return t1d[sum] = mincoins(coins, n, sum - coins[n - 1]) + 1;
    return t1d[sum] = mincoins(coins, n - 1, sum);
}

int main()
{
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            t[i][j] = -1, t1d[j] = -1;

    // int a[] = {1, 2, 3};
    int a[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 10000;
    // cout << coinchange(a, 3, sum) << "\n";
    cout << mincoins(a, n, 57) << "\n";
    return 0;
}