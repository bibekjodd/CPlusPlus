#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int infixEvalution(string s)
{
    stack<int> st;
    int n = s.length() - 1;
    for (int i = n; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else
        {
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '-':
                st.push(n1 - n2);
                break;
            case '+':
                st.push(n1 + n2);
                break;
            case '*':
                st.push(n1 * n2);
                break;
            case '/':
                st.push(n1 / n2);
                break;
            case '^':
                st.push(pow(n1, n2));
                break;
            }
        }
    }
    int ans = 0;
    if (st.empty())
        return ans;
    return st.top();
}

int postfixEvaluation(string s)
{
    stack<int> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else
        {
            int n2 = st.top();
            st.pop();
            int n1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '-':
                st.push(n1 - n2);
                break;
            case '+':
                st.push(n1 + n2);
                break;
            case '*':
                st.push(n1 * n2);
                break;
            case '/':
                st.push(n1 / n2);
                break;
            case '^':
                st.push(n1 ^ n2);
                break;
            }
        }
    }
    if (st.empty())
        return 0;
    return st.top();
}

int main()
{
    // -+7*45+20
    // string s = "-+7*45+20";
    // string s = "+4*23";
    // string s = "";
    // cout << infixEvalution(s) << "\n";

    string s = "46+2/5*7+";
    cout << postfixEvaluation(s) << "\n";

    return 0;
}