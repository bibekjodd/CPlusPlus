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

int main()
{
    set<pair<int, int>, greater<int>> s;
    s.insert({2, 3});
    s.insert({4, 7});
    s.insert({0, 1});
    s.insert({6, 5});
    s.insert({7, 9});

    set<int> s1;
    s1.insert(7);
    s1.insert(2);
    s1.insert(3);

    // for (auto i : s)
    // cout << i.first << " " << i.second << "\n";
    // auto x = s.find({7, 9});
    // cout << x->first << " " << x->second << "\n";

    const auto y = s1.find(7);
    cout << *y;

    return 0;
}