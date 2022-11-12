#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <climits>
#define vi vector<int>
using namespace std;

void maxF(int a[], int n)
{
    if (n == 0)
        return;
    map<int, int> m;
    int ans = 0;
    int maxF = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
        if (m[a[i]] > maxF)
        {
            ans = a[i];
            maxF = m[a[i]];
        }
    }
    cout << "The frequency of the elements are:\n";
    for (auto i : m)
        cout << i.first << " " << i.second << "\n";
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// print vertical order of tree
void getVerticalOrder(Node *root, int hdis, map<int, vector<int>> &m)
{
    if (!root)
        return;
    m[hdis].push_back(root->data);
    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}

int main()
{
    // int n;
    // cout << "Enter the  total elements:\n";
    // cin >> n;

    // int a[n];

    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    // maxF(a, n);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(6);
    root->left->right = new Node(7);
    root->right->left = new Node(9);
    root->right->right = new Node(-3);

    map<int, vector<int>> m;
    int hdis = 0;

    getVerticalOrder(root, hdis, m);
    for (auto i : m)
    {
        for (auto j : i.second)
            cout << j << " ";
        cout << "\n";
    }

    return 0;
}