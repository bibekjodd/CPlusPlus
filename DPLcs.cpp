#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
const int N = 1e5 + 2;
const int X = 1e2 + 2;
long long int t[X][N] = {0};

// long common subsequence memoization
int lcs(string &s1, string &s2, int n, int m)
{
    if (!m || !n)
        return 0;

    if (t[n][m] != -1)
        return t[n][m];

    if (s1[n - 1] == s2[m - 1])
        return t[n][m] = lcs(s1, s2, n - 1, m - 1) + 1;
    return t[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}

// longest common subsequence tabulation bottom up
int LCS(string &s1, string &s2, int n, int m)
{
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[n][m];
}

string printLCS(string &s1, string &s2, int n, int m)
{
    int length = LCS(s1, s2, n, m);
    string ans = "";
    while (n && m)
    {
        if (s1[n - 1] == s2[m - 1])
        {
            ans = s1[n - 1] + ans;
            n--;
            m--;
            continue;
        }

        if (t[n - 1][m] > t[n][m - 1])
            n--;
        else
            m--;
    }
    return ans;
}

// longest common substring
// recursive code memoization
int lcsubstr(string s1, string s2, int n, int m)
{
    static int ans = 0;
    if (!n || !m)
        return ans = t[n][m] = 0;
    if (s1[n - 1] == s2[m - 1])
        return ans = t[n][m] = max(ans, lcsubstr(s1, s2, n - 1, m - 1)) + 1;
    t[n][m] = 0;
    return ans = max(ans, max(lcsubstr(s1, s2, n, m - 1), lcsubstr(s1, s2, n - 1, m)));
}

// int longestCommonSubstr()
int LCsubstr(string s1, string s2, int n, int m)
{
    memset(t, 0, sizeof(t));
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = 0;
            if (t[i][j] > ans)
                ans = t[i][j];
        }
    }
    return ans;
}

// longest common supersequence
int lcsupseq(string &s1, string &s2, int n, int m)
{
    return (m + n - LCS(s1, s2, n, m));
}

// minimum number of insertion and deletion to make s1->s2  heap->pea delete h,p insert p d=2 i=1
pair<int, int> minInsDel(string s1, string s2, int n, int m)
{
    int lcsLength = lcs(s1, s2, n, m);
    int insertion = m - lcsLength;
    int deletion = n - lcsLength;
    return {deletion, insertion};
}

// longest palindromic subsequence
int lpalsubseq(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    return lcs(s, s2, s.length(), s.length());
}

// minimum number of deletion in a string to make it palindrome
int mindelpal(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int lcslength = lcs(s, s2, s2.length(), s2.length());
    return s.length() - lcslength;
}

// print shortest common supersequence
string printLCsupseq(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int lcsLength = LCS(s1, s2, n, m);

    string ans = "";
    while (n && m)
    {
        if (s1[n - 1] == s2[m - 1])
        {
            ans = s1[n - 1] + ans;
            n--;
            m--;
            continue;
        }
        if (t[n - 1][m] > t[n][m - 1])
        {
            ans = s1[n - 1] + ans;
            n--;
        }
        else
        {
            ans = s2[m - 1] + ans;
            m--;
        }
    }
    return ans;
}

// longest repeating subsequence
int LRsubseq(string s1)
{
    int n = s1.length();
    string s2 = s1;
    // int lcslength = LCS(s1, s2, n, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1] && i != j)
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }
    return t[n][n];
}

// is string s subsequence of string t
bool issubseq(string s, string t)
{
    int lcslength = LCS(s, t, s.length(), t.length());
    return lcslength == s.length();
}

// minimum number of insertion in a string to make it palindrome
int minInsPal(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int lcslength = LCS(s, s2, s.length(), s.length());
    return s.length() - lcslength;
}

int main()
{
    string s1 = "aabebcdd";
    string s2 = "aabebcdd";
    memset(t, -1, sizeof(t));

    // --------------------------------------------------------------------------
    // longest common subsequece
    // cout << lcs(s1, s2, s1.length(), s2.length()) << "\n";
    // cout << LCS(s1, s2, s1.length(), s2.length()) << "\n";
    // cout << printLCS(s1, s2, s1.length(), s2.length()) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // longest common substring
    // cout << lcsubstr(s1, s2, s1.length(), s2.length()) << "\n";
    // cout << LCsubstr(s1, s2, s1.length(), s2.length()) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // longest common supersequence
    // cout << lcsupseq(s1, s2, s1.length(), s2.length()) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // minimum insertion and deletion to make a->b heap -> pea
    // pair<int, int> minInsAndDel = minInsDel(s1, s2, s1.length(), s2.length());
    // cout << minInsAndDel.first << " " << minInsAndDel.second << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // longest palindromic subsequence
    // cout << lpalsubseq("abcba") << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // minimum number of deletion to make string palindrome
    // cout << mindelpal("agbcba") << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // print longest common supersequence
    // cout << printLCsupseq(s1, s2) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // longest repeating subsequence
    // cout << LRsubseq("abcaa") << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // sequence pattern matching is s subsequence of t
    // cout << issubseq("ab", "cdxaby") << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // Minimum number of insertion to make a string palindrome
    string s="hello";
    cout << minInsPal(s) << "\n";
    cout << mindelpal(s) << "\n";
    // --------------------------------------------------------------------------

    return 0;
}
