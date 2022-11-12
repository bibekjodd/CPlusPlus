#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

void insertAtHead(ListNode *&head, int val)
{
    ListNode *n = new ListNode(val);
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

void insertAtTail(ListNode *&head, int val)
{
    ListNode *n = new ListNode(val);
    if (!head)
    {
        head = n;
        return;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = n;
    }
}

void llTravesal(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "NULL\n";
}

void deleteHead(ListNode *&head)
{
    ListNode *temp = head->next;
    delete head;
    head = temp;
}

void deleteK(ListNode *&head, int k)
{
    ListNode *temp = head;

    while (temp->next->val != k)
    {
        temp = temp->next;
        if (!temp->next)
            return;
    }

    ListNode *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

ListNode *reverseLL(ListNode *&head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt;

    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

ListNode *llReverse(ListNode *&head)
{
    if (!head || !head->next)
        return head;
    cout << "Current head val is " << head->val << "\n";
    ListNode *newHead = llReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

void makeCycle(ListNode *&head, int k)
{
    ListNode *temp = head;
    while (temp->val != k)
        temp = temp->next;

    ListNode *last = temp;
    while (last->next)
        last = last->next;
    last->next = temp;
}

bool detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

void removeCycle(ListNode *&head)
{
    ListNode *fast = head;
    ListNode *slow = head;

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

int length(ListNode *head)
{
    int l = 0;
    while (head)
    {
        head = head->next;
        l++;
    }
    return l;
}

ListNode *kAppend(ListNode *&head, int k)
{
    ListNode *newHead;
    ListNode *tail = head;
    ListNode *newTail = head;
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

ListNode *mergeTwoSortedLL(ListNode *head1, ListNode *head2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *head = dummyNode;
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

ListNode *mergeSortedLL(ListNode *&head1, ListNode *&head2)
{
    if (!head1)
        return head2;

    if (!head2)
        return head1;

    ListNode *result;
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

void putEvenAfterOdd(ListNode *&head)
{
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenStart = even;
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
ListNode *middle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(ListNode *head)
{
    ListNode *x = middle(head);
    ListNode *newhead = reverseLL(x);
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
ListNode *reverseK(ListNode *head, int k)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt;
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

ListNode *inPlace(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newhead = new ListNode(0);
    ListNode *temp = newhead;
    while (slow)
    {
        ListNode *insert = slow;
        insert->next = temp->next;
        temp->next = insert;
        temp = temp->next->next;
        slow = slow->next;
    }
    return newhead->next;
}

int main()
{
    ListNode *head = NULL;
    int a[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        insertAtTail(head, a[i]);

    llTravesal(head);
    // putEvenAfterOdd(head);
    head = inPlace(head);
    llTravesal(head);

    return 0;
}