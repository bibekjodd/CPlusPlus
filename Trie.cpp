#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    bool isTerminal;
    Node *children[26];
    Node(char ch)
    {
        data = ch;
        isTerminal = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insertUtil(Node *root, string word)
    {
        if (!word.length())
        {
            root->isTerminal = 1;
            return;
        }

        int index = word[0] - 'a';
        Node *child;
        if (root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            child = new Node(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(Node *root, string word)
    {
        if (!word.length())
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        Node *child;

        if (root->children[index])
            child = root->children[index];
        else
            return false;

        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    void removeUtil(Node *root, string word)
    {
        if (!word.length())
            return;

        if (word.length() == 1)
            (root->children[word[0] - 'a'])->isTerminal = 0;

        int index = word[0] - 'a';
        Node *child;
        if (root->children[index])
            child = root->children[index];
        else
            return;
        removeUtil(root, word.substr(1));
    }

    void removeWord(string word)
    {
        removeUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("hello");
    t->insert("bibek");
    t->insert("bhattarai");
    t->insert("how");
    t->insert("are");
    t->insert("you");
    if (t->search("hello"))
        cout << "hello is present\n";
    else
        cout << "hello is not present\n";

    if (t->search("bibek"))
        cout << "bibek is present\n";
    else
        cout << "bibek is not present\n";

    if (t->search("you"))
        cout << "you is present\n";
    else
        cout << "you is not present\n";

    if (t->search("are"))
        cout << "are is present\n";
    else
        cout << "are is not present\n";

    if (t->search("area"))
        cout << "area is present\n";
    else
        cout << "area is not present\n";

    if (t->search("how"))
        cout << "how is present\n";
    else
        cout << "how is not present\n";

    if (t->search("bhattarai"))
        cout << "bhattarai is present\n";
    else
        cout << "bhattarai is not present\n";

    cout << "\nAfter some insertion and deletion\n\n";
    t->removeWord("hello");
    t->insert("area");
    t->removeWord("bibek");

    if (t->search("hello"))
        cout << "hello is present\n";
    else
        cout << "hello is not present\n";

    if (t->search("bibek"))
        cout << "bibek is present\n";
    else
        cout << "bibek is not present\n";

    if (t->search("you"))
        cout << "you is present\n";
    else
        cout << "you is not present\n";

    if (t->search("are"))
        cout << "are is present\n";
    else
        cout << "are is not present\n";

    if (t->search("area"))
        cout << "area is present\n";
    else
        cout << "area is not present\n";

    if (t->search("how"))
        cout << "how is present\n";
    else
        cout << "how is not present\n";

    if (t->search("bhattarai"))
        cout << "bhattarai is present\n";
    else
        cout << "bhattarai is not present\n";

    // cout << t->search("hello") << "\n";
    // cout << t->search("bibek") << "\n";j
    // cout << t->search("you") << "\n";
    // cout << t->search("are") << "\n";
    // cout << t->search("area") << "\n";
    // cout << t->search("how") << "\n";
    // cout << t->search("bhattarai") << "\n";
    return 0;
}