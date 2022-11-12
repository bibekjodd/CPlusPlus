#include <iostream>
#include <climits>
using namespace std;

const int N = 1e5 + 2;
const int x = 1e2, y = 1e3;
int t[x][y];

bool subsetSum(int a[], int n, int sum)
{
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                t[i][j] = t[i - 1][j - a[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

// Equal sum partitioo
// 1 5 11 5  => 1+5+5=11 // True
int equalSumPartition(int a[], int n, int sum)
{
    if (!sum)
        return 1;

    if (!n)
    {
        if (!sum)
            return 1;
        return 0;
    }

    if (t[n][sum] != -1)
        return t[n][sum];

    int ans1 = equalSumPartition(a, n - 1, sum - a[n - 1]);
    int ans2 = equalSumPartition(a, n - 1, sum);
    if (ans1 == 1 || ans2 == 1)
        t[n][sum] = 1;
    else
        t[n][sum] = 0;
    return t[n][sum];
}

// count of subsets sum with a given sum n=6 elements= 2 3 5 6 8 10 count= 3 // 2+3+5 2+8 10
int countsubsets(int a[], int n, int sum)
{
    if (!sum)
        return 1;
    if (!n || sum < 0)
        return 0;

    if (t[n][sum] != -1)
        return t[n][sum];

    if (a[n - 1] <= sum)
        return t[n][sum] = countsubsets(a, n - 1, sum - a[n - 1]) + countsubsets(a, n - 1, sum);

    return t[n][sum] = countsubsets(a, n - 1, sum);
}

// count subsets sum bottom up
int countSubsets(int a[], int n, int sum)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i - 1][j - a[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

// minimum subset sum difference // 1 6 11 5  ans => 1+5+6-11 = 1
int minSubsetSumDiff(int a[], int n, int range)
{
    if (n == 1)
        return range;

    if (t[n][range] != -1)
        return t[n][range];
}

int main()
{

    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            t[i][j] = -1;

    // subset sum
    // cout << subsetSum(a, n, sum) << "\n";

    //
    // equal sum partition
    // if (sum & 1)
    //     cout << 0 << "\n";
    // else
    //     cout << equalSumPartition(a, n, sum / 2) << "\n";
    // //

    //
    // count subsets sum with given sum
    // cin >> sum;
    // cout << countsubsets(a, n, sum) << "\n";
    // cout << countSubsets(a, n, sum) << "\n";

    // minimum subset sum difference
    cout << minSubsetSumDiff(a, n, sum) << "\n";

    return 0;
}