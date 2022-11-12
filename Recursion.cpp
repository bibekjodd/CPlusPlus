#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
vector<vector<int>> ans;

// Move all x characters to the end of the string
string moveX(string s)
{
    if (!s.length())
        return "";
    if (s[0] == 'x')
        return moveX(s.substr(1)) + 'x';
    else
        return s[0] + moveX(s.substr(1));
}

// Remove consecutive duplicates of a string
string removeDup(string s)
{
    if (!s.length())
        return "";

    string ans = removeDup(s.substr(1));
    if (s[0] != ans[0])
        return s[0] + ans;
    return ans;
}

// cout number of possible paths from start to end point in game board
int countPath(int s, int e)
{
    if (s == e)
        return 1;

    if (s > e)
        return 0;
    int count = 0;
    for (int i = 1; i <= 6; i++)
        count += countPath(s + i, e);
    return count;
}

int tilingWays(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return tilingWays(n - 1) + tilingWays(n - 2);
}

int friendsPairing(int n)
{
    if (!n || n == 1 || n == 2)
        return n;

    return friendsPairing(n - 1) + friendsPairing(n - 2) * (n - 1);
}

int knapsack(int value[], int wt[], int n, int w)
{
    if (!n || !w)
        return 0;

    if (wt[n - 1] > w)
        return knapsack(value, wt, n - 1, w);

    return max(knapsack(value, wt, n - 1, w - wt[n - 1]) + value[n - 1], knapsack(value, wt, n - 1, w));
}

// Return all possible permutations
void permute(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permute(a, idx + 1);
        swap(a[i], a[idx]);
    }
    return;
}

// kth symbol in grammar
bool kthGrammar(int n, int k)
{
    if (k > pow(2, n - 1))
        return 0;
    if (n == 1 && k == 1)
        return 0;

    int mid = pow(2, n - 1) / 2;
    if (k <= mid)
        return kthGrammar(n - 1, k);
    return !(kthGrammar(n - 1, k - mid));
}

// n-bit binary numbers having 1's more than 0's for any prefix
void nbitBinary(int n, string ans, bool take)
{
    if (!n)
    {
        cout << ans << "\n";
        return;
    }
    if (take)
        nbitBinary(n - 1, ans + '1', 0);
    else
    {
        nbitBinary(n - 1, ans + '1', 0);
        nbitBinary(n - 1, ans + '0', 1);
    }
}

int main()
{
    // cout << moveX("xabxc")<<"\n";
    // cout << removeDup("aabbccdccc") << "\n";
    // cout << countPath(0, 5) << "\n";
    // cout << tilingWays(6) << "\n";
    // cout << friendsPairing(3) << "\n";
    // int value[] = {100, 50, 150};
    // int wt[] = {10, 20, 30};
    // cout << knapsack(value, wt, 3, 50) << "\n";

    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(0);
    // sort(a.begin(), a.end());
    // do
    // {
    //     ans.push_back(a);
    // } while (next_permutation(a.begin(), a.end()));

    permute(a, 0);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}