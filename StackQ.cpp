#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Stock Span Problem
void stockSpan()
{
    // Get all elements in array
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<pair<int, int>> st;
    vector<int> ans;
    // Check previous greater
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first <= a[i])
            st.pop();
        if (st.empty())
            ans.push_back(i + 1);
        else
            ans.push_back(i - st.top().second);

        st.push({a[i], i});
    }
    // output
    for (auto i : ans)
        cout << i << " ";
}

int main()
{
    stockSpan();

    return 0;
}