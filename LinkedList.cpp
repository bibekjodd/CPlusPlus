#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    if (!head)
    {
        head = n;
        return;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (!head)
    {
        head = n;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
    }
}

void llTravesal(Node *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "NULL\n";
}

void deleteHead(Node *&head)
{
    Node *temp = head->next;
    delete head;
    head = temp;
}

void deleteK(Node *&head, int k)
{
    Node *temp = head;

    while (temp->next->val != k)
    {
        temp = temp->next;
        if (!temp->next)
            return;
    }

    Node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

Node *reverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt;

    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

Node *llReverse(Node *&head)
{
    if (!head || !head->next)
        return head;
    cout << "Current head val is " << head->val << "\n";
    Node *newHead = llReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void makeCycle(Node *&head, int k)
{
    Node *temp = head;
    while (temp->val != k)
        temp = temp->next;

    Node *last = temp;
    while (last->next)
        last = last->next;
    last->next = temp;
}

bool detectCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

void removeCycle(Node *&head)
{
    Node *fast = head;
    Node *slow = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int length(Node *head)
{
    int l = 0;
    while (head)
    {
        head = head->next;
        l++;
    }
    return l;
}

Node *kAppend(Node *&head, int k)
{
    Node *newHead;
    Node *tail = head;
    Node *newTail = head;
    int l = length(head);
    int count = 1;

    while (tail->next)
        tail = tail->next;

    while (count != l - k)
    {
        newTail = newTail->next;
        count++;
    }
    newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1);
    Node *head = dummyNode;
    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            head->next = head1;
            head1 = head1->next;
        }
        else
        {
            head->next = head2;
            head2 = head2->next;
        }
        head = head->next;
    }

    while (head1)
    {
        head->next = head1;
        head1 = head1->next;
        head = head->next;
    }
    while (head2)
    {
        head->next = head2;
        head2 = head2->next;
        head = head->next;
    }

    return dummyNode->next;
}

Node *mergeSortedLL(Node *&head1, Node *&head2)
{
    if (!head1)
        return head2;

    if (!head2)
        return head1;

    Node *result;
    if (head1->val < head2->val)
    {
        result = head1;
        result->next = mergeSortedLL(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeTwoSortedLL(head1, head2->next);
    }
    return result;
}

void putEvenAfterOdd(Node *&head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenStart = even;
    while (odd->next && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if (odd->next == NULL)
        even->next = NULL;
}

// palindrome linked list
Node *middle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(Node *head)
{
    Node *x = middle(head);
    Node *newhead = reverseLL(x);
    while (newhead)
    {
        if (newhead->val != head->val)
            return 0;
        newhead = newhead->next;
        head = head->next;
    }
    return 1;
}

// Reverse k nodes
Node *reverseK(Node *head, int k)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nxt;
    int count = 0;
    while (curr != NULL && count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    if (nxt)
        head->next = reverseK(curr, k);
    return prev;
}

Node *inPlace(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newhead = new Node(0);
    Node *temp = newhead;
    while (slow)
    {
        Node *insert = slow;
        insert->next = temp->next;
        temp->next = insert;
        temp = temp->next->next;
        slow = slow->next;
    }
    return newhead->next;
}

int main()
{
    Node *head = NULL;
    int a[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        insertAtTail(head, a[i]);

    llTravesal(head);
    // putEvenAfterOdd(head);
    head = inPlace(head);
    llTravesal(head);

    return 0;
}