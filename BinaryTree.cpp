#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// --------------------------------Tree------------------------------------------
class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }

    Node(int x, Node *l)
    {
        data = x;
        left = l;
        right = NULL;
    }

    Node(int x, Node *l, Node *r)
    {
        data = x;
        left = l;
        right = r;
    }
};
// --------------------------------Tree End------------------------------------------

// -------------------------------Tree Traversal-------------------------------------------
// preorder traversal
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// postorder traversal
void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


// level order traversal
void levelorder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *fr = q.front();
        q.pop();
        if (fr)
        {
            cout << fr->data << " ";
            if (fr->left)
                q.push(fr->left);
            if (fr->right)
                q.push(fr->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
    cout << "\n";
}
// -------------------------------Tree Traversal End-------------------------------------------


// build tree from preorder and inorder
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }
    return -1;
}
Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;

    if (start > end)
        return NULL;

    int curr = preorder[idx];
    idx++;
    Node *root = new Node(curr);

    if (start == end)
        return root;

    int pos = search(inorder, start, end, curr);
    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);
}


// sum at kth level
int sumAtK(Node *root, int k)
{
    if (!root)
        return 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 1;
    int sum = 0;
    while (!q.empty())
    {
        Node *fr = q.front();
        q.pop();
        if (fr)
        {
            if (level == k)
                sum += fr->data;
            if (fr->left)
                q.push(fr->left);
            if (fr->right)
                q.push(fr->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int height(Node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// int calcDiameter(Node *root)
// {
//     if (root == NULL)
//         return 0;
//     int lHeight = calcDiameter(root->left);
//     int rHeight = calcDiameter(root->right);
//     int currDiameter = lHeight + rHeight + 1;
//     int lDiameter = calcDiameter(root->left);
//     int rDiameter = calcDiameter(root->right);

//     return max(currDiameter, lDiameter, rDiameter);
// }

int sumOfAllNodes(Node *root)
{
    if (!root)
        return 0;
    return sumOfAllNodes(root->left) + sumOfAllNodes(root->right) + root->data;
}

void sumReplacement(Node *root)
{
    if (!root)
        return;
    sumReplacement(root->left);
    sumReplacement(root->right);
    if (root->left)
        root->data += root->left->data;
    if (root->right)
        root->data += root->right->data;
}

bool balancedHeight(Node *root, int *height)
{
    if (!root)
        return 1;
    int lh = 0, rh = 0;
    if (!balancedHeight(root->left, &lh) || !balancedHeight(root->right, &rh))
        return 0;
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
        return 1;
    return 0;
}

void rightView(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << q.front()->data << " ";
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }
    cout << "\n";
}

void leftView(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                cout << q.front()->data << " ";
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }

    cout << "\n";
}

Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left && right)
        return root;

    if (!left && !right)
        return NULL;

    return left != NULL ? left : right;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(7);
    levelorder(root);
    rightView(root);
    leftView(root);
    cout << lca(root, 4, 10)->data;

    return 0;
}