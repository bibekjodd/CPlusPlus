#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelorder(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front)
        {
            cout << front->val << " ";

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    cout << "\n";
}

// total nodes in a binary tree
int countNodes(Node *root)
{
    if (!root)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// sum of all nodes in a binary tree
int sumOfAllNodes(Node *root)
{
    if (!root)
        return 0;
    return sumOfAllNodes(root->left) + sumOfAllNodes(root->right) + root->val;
}

int height(Node *root)
{
    if (!root)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

void sumReplacement(Node *&root)
{
    if (!root)
        return;

    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left)
        root->val += root->left->val;

    if (root->right)
        root->val += root->right->val;
}

// balanced height in a binary tree
bool balancedHeight(Node *root)
{
    if (!root)
        return 1;
    if (!balancedHeight(root->left))
        return 0;

    if (!balancedHeight(root->right))
        return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if (abs(lHeight - rHeight) > 1)
        return 0;
    return 1;
}

int main()
{
    Node *root = NULL;
    root = new Node(0);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // preorder(root);
    // cout << "\n";
    // inorder(root);
    // cout << "\n";
    // postorder(root);
    // cout << "\n";

    levelorder(root);
    // sumReplacement(root);
    // cout << countNodes(root) << "\n";
    // cout << sumOfAllNodes(root) << "\n";

    // cout << height(root);

    cout << balancedHeight(root) << "\n";

    return 0;
}