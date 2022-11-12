#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

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

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node(int val, Node *l)
    {
        data = val;
        left = l;
        right = NULL;
    }

    Node(int val, Node *l, Node *r)
    {
        data = val;
        left = l;
        right = r;
    }
};

// preorder traversal
void preorder(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal
void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// postorder traversal
void postorder(Node *root)
{
    if (!root)
    {
        return;
    }
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

Node *insertBST(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);
    return root;
}

bool searchBST(Node *root, int key)
{
    if (!root)
        return 0;
    if (root->data == key)
        return 1;

    else if (key < root->data)
        return searchBST(root->left, key);

    else if (key > root->data)
        return searchBST(root->right, key);
}

Node *inordersucc(Node *root)
{
    Node *temp = root;
    while (temp && temp->left)
        temp = temp->left;
    return temp;
}

Node *deleteBST(Node *root, int key)
{
    if (key < root->data)
        root->left = deleteBST(root->left, key);

    else if (key > root->data)
        root->right = deleteBST(root->right, key);

    else
    {
        if (!root->left)
        {
            Node *temp = root->right;
            // delete root;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            // delete root;
            free(root);
            return temp;
        }
        Node *temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

bool isBST(Node *root)
{
    static Node *prev = NULL;
    if (root)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        if (!isBST(root->right))
            return 0;
        // return isBST(root->right);
    }
    else
        return 1;
}

// balanced BST from array
Node *ArrayToBST(int a[], int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    Node *root = new Node(a[mid]);
    root->left = ArrayToBST(a, l, mid - 1);
    root->right = ArrayToBST(a, mid + 1, r);
    return root;
}

void zigzag(Node *root)
{
    if (!root)
        return;

    stack<Node *> st1;
    stack<Node *> st2;
    int ltr = 1;
    st1.push(root);
    while (!st1.empty() || !st2.empty())
    {
        if (ltr)
        {
            while (!st1.empty())
            {
                cout << st1.top()->data << " ";
                if (st1.top()->left)
                    st2.push(st1.top()->left);
                if (st1.top()->right)
                    st2.push(st1.top()->right);
                st1.pop();
            }
            cout << "\n";
            ltr = 0;
        }
        else
        {
            while (!st2.empty())
            {
                cout << st2.top()->data << " ";
                if (st2.top()->right)
                    st1.push(st2.top()->right);
                if (st2.top()->left)
                    st1.push(st2.top()->left);
                st2.pop();
            }
            cout << "\n";
            ltr = 1;
        }
    }
    cout << "\n";
}

int main()
{
    // Node *root = new Node(7);
    // root->left = new Node(5);
    // root->right = new Node(8);
    // root->left->left = new Node(0);
    // root->left->right = new Node(6);
    // root->right->right = new Node(9);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right = new Node(5);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left = new Node(6);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right = new Node(7);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int a[] = {1, 2, 3, 4, 5};
    // Node *root = NULL;
    // for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    //     root = insertBST(root, a[i]);
    // Node *root = ArrayToBST(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    // cout << isBST(root) << "\n";
    // cout<<root->data<<"\n";
    // levelorder(root);
    zigzag(root);
    // preorder(root);

    return 0;
}