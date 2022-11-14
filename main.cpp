#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char ch)
{
    if (ch == '^')
        return 4;

    else if (ch == '/' || ch == '*')
        return 3;

    else if (ch == '+' || ch == '-')
        return 2;

    return 1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            ans.push_back(s[i]);
        else if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        char ch = st.top();
        if (
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9') ||
            (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-'))
            ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    string ans = infixToPostfix(s);
    reverse(ans.begin(), ans.end());
    return ans;
}

bool balancedParenthesis(string s)
{
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (st.empty())
                return 0;
            if (s[i] == ')' && st.top() != '(')
                return 0;
            if (s[i] == '}' && st.top() != '{')
                return 0;
            if (s[i] == ']' && st.top() != '[')
                return 0;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    // string s = "(a-b/c)*(a/k-l)";
    string s;
    cin >> s;
    // cout << "Prefix => " << infixToPrefix(s) << "\n\n";
    // cout << "Postfix => " << infixToPostfix(s) << "\n";
    cout << balancedParenthesis(s);

    return 0;
}