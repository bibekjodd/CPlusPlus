#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// #1 Coin Change Problem
int coinChange(int x)
{
    // Get all the available coins in vector
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(5);
    a.push_back(10);
    a.push_back(20);
    a.push_back(50);
    a.push_back(100);
    a.push_back(500);
    a.push_back(1000);

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans += x / a[i];
        x -= x / a[i] * a[i];
    }
    return ans;
}

// #2 Activity Selection Problem
int activitySelection()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int take = 1;
    int end = v[0].second;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first > end)
        {
            end = v[i].second;
            take++;
        }
    }
    return take;
}

// 

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // --------------------------------------------------------------------------
    // #1 coin change problem
    // cout<<coinChange(7);
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // #2 Activity Selection Problem
    cout << activitySelection() << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // #3 Wine buying and selling problem
    
    // --------------------------------------------------------------------------

    return 0;
}