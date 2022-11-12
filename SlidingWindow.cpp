#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define unmap unordered_map

// longest substring with k unique characters
int lsubstrK(string s, int k)
{
    unmap<char, int> m;
    int n = s.length();
    int i = 0, j = 0;
    int ans = 0;
    cout << "...\n";

    while (j < n)
    {
        m[s[j]]++;
        if (m.size() == k)
            ans = max(ans, j - i + 1);

        while (m.size() > k)
        {
            m[s[i]]--;
            if (m[s[i]] == 0)
                m.erase(s[i]);
            i++;
            if (m.size() == k)
                ans = max(ans, j - i + 1);
        }
        j++;
    }
    return ans;
}

// longest unique substring
int longestUniqueSubstring(string s)
{
    int n = s.length();
    int idx[256];
    for (int i = 0; i < 256; i++)
        idx[i] = -1;

    int ans = 0;
    int start = -1;
    for (int i = 0; i < n; i++)
    {
        if (idx[s[i]] != -1)
            start = idx[s[i]];
        idx[s[i]] = i;
        ans = max(ans, i - start);
    }
    return ans;
}

int main()
{
    // --------------------------------------------------------------------------
    // longest substring with k unique characters
    // string s = "aabacbebebe";
    // int k;
    // cin >> k;
    // cout << lsubstrK(s, k) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // longest unique substring
    // string s = "pwwkew";
    // cout << longestUniqueSubstring(s) << "\n";
    // --------------------------------------------------------------------------

    return 0;
}