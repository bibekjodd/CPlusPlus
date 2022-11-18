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
            Node *front = q.front();
            q.pop();
            if (!i)
                cout << front->val << " ";

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }
    }
    cout << "\n";
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
            Node *front = q.front();
            q.pop();
            if (i == n - 1)
                cout << front->val << " ";

            if (front->left)
                q.push(front->left);

            if (front->right)
                q.push(front->right);
        }
    }
    cout << "\n";
}

bool find(Node *root, int key)
{
    if (!root)
        return 0;

    if (root->val == key)
        return 1;

    if (find(root->left, key) || find(root->right, key))
        return 1;

    return 0;
}

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->val == n1 || root->val == n2)
        return root;

    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    if (leftLCA)
        return leftLCA;

    if (rightLCA)
        return rightLCA;

    return NULL;
}

// Binary Search Tree
Node *insertBST(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

bool searchBST(Node *root, int key)
{
    if (!root)
        return 0;

    if (root->val == key)
        return 1;

    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// delete in binary search tree

Node *inorderSucc(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteBST(Node *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->val)
        root->left = deleteBST(root->left, key);

    else if (key > root->val)
        root->right = deleteBST(root->right, key);

    else
    {
        if (!root->left)
            return root->right;

        else if (!root->right)
            return root->left;

        Node *temp = inorderSucc(root->right);
        root->val = temp->val;
        root->right = deleteBST(root->right, temp->val);
    }
    return root;
}

void zigzagTraversal(Node *root)
{
    if (!root)
        return;

    stack<Node *> st1;
    stack<Node *> st2;
    st1.push(root);
    bool leftToRight = true;

    while (!st1.empty() || !st2.empty())
    {
        if (leftToRight)
        {
            while (!st1.empty())
            {
                Node *top = st1.top();
                cout << top->val << " ";

                if (top->left)
                    st2.push(top->left);

                if (top->right)
                    st2.push(top->right);

                st1.pop();
            }
            leftToRight = false;
        }

        else
        {
            while (!st2.empty())
            {
                Node *top = st2.top();
                cout << top->val << " ";

                if (top->right)
                    st1.push(top->right);

                if (top->left)
                    st1.push(top->left);

                st2.pop();
            }
            leftToRight = true;
        }
    }
    cout << "\n";
}

// identical binary search tree
bool identicalBST(Node *root1, Node *root2)
{
    if (!root1 && root2)
        return false;

    if (root1 && !root2)
        return false;

    if (!root1 && !root2)
        return true;

    bool cond1 = (root1->val == root2->val);
    bool cond2 = identicalBST(root1->left, root2->left) && identicalBST(root1->right, root2->right);

    return cond1 && cond2;
}

int main()
{
    Node *root = NULL;
    // root = new Node(0);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->left->left->left=new Node(8);
    // root->left->left->right=new Node(9);
    // root->left->right->left=new Node(10);
    // root->left->right->right=new Node(11);
    // root->right->left->left = new Node(12);
    // root->right->left->right = new Node(13);
    // root->right->right->left = new Node(14);
    // root->right->right->right = new Node(15);

    // preorder(root);
    // cout << "\n";
    // inorder(root);
    // cout << "\n";
    // postorder(root);
    // cout << "\n";

    // levelorder(root);
    // sumReplacement(root);
    // cout << countNodes(root) << "\n";
    // cout << sumOfAllNodes(root) << "\n";

    // cout << height(root);

    // cout << balancedHeight(root) << "\n";
    // leftView(root);
    // rightView(root);
    // cout << find(root, 7) << "\n";
    // Node *lca = LCA(root, 6, 7);
    // if (lca)
    //     cout << lca->val << "\n";
    // else
    //     cout << "NO LCA exists for the node\n";

    // binary search tree
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     root = insertBST(root, a[i]);
    // }

    // levelorder(root);
    // inorder(root);
    // cout << "\n";
    // zigzagTraversal(root);

    // cout << searchBST(root, 9) << "\n";
    // cout << "\n";

    Node *root1 = new Node(2);
    root1->left = new Node(3);
    root1->right = new Node(4);
    root1->left->left = new Node(5);
    root1->left->left->left = new Node(8);

    Node *root2 = new Node(2);
    root2->left = new Node(3);
    root2->right = new Node(4);
    root2->left->left = new Node(5);
    root2->left->left->left = new Node(8);

    cout << identicalBST(root1, root2) << "\n";

    return 0;
}