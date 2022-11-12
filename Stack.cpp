#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}
// reverse a stack
void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(top);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;
    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);
}

// Prefix evaluation in stack
int prefixEval(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '-':
                st.push(op1 - op2);
                break;

            case '+':
                st.push(op1 + op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}

// Postfix evaluation
int postfixEval(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '-':
                st.push(op1 - op2);
                break;

            case '+':
                st.push(op1 + op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}

// infix to postfix
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixtoPostfix(string s)
{
    stack<char> st;
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            result += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

// infix to prefix
string infixtoPrefix(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    stack<char> st;
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            result += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

// balanced parenthesis
bool balancedParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (st.top() == '(')
                st.pop();
            else
                return 0;
        }
        else if (s[i] == '}')
        {
            if (st.top() == '{')
                st.pop();
            else
                return 0;
        }
        else if (s[i] == ']')
        {
            if (st.top() == '[')
                st.pop();
            else
                return 0;
        }
    }
    return st.empty();
}
// Queue using 2 stacks
class que
{
    stack<int> st1;
    stack<int> st2;

public:
    void push(int x)
    {
        st1.push(x);
    }
    void pop()
    {
        if (st1.empty() && st2.empty())
        {
            cout << "No elements in queue\n";
            return;
        }
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int peek()
    {
        if (st1.empty())
        {
            cout << "Queue Empty\n";
            return -1;
        }
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int x = st2.top();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }

    bool empty()
    {
        return st1.empty();
    }
};

int main()
{
    stack<int> st;
    cout << prefixEval("+-*^225*/623^42") << "\n";
    cout << postfixEval("22^5*62/3*-42^+") << "\n";
    cout << infixtoPostfix("(a-b/c)*(a/k-l)") << "\n";
    cout << infixtoPrefix("(a-b/c)*(a/k-l)") << "\n";
    cout << balancedParenthesis("({)}");

    que q;
    q.push(1);
    q.push(6);
    q.push(9);
    q.push(3);
    q.push(8);
    while (!q.empty())
    {
        cout << q.peek() << " ";
        q.pop();
    }

    return 0;
}