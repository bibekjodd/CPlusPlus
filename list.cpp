#include <iostream>
#include <list>
using namespace std;
// list -> doubly linked list
// insertion and deletion form both end
int main()
{
    list<int> l;
    // list<int>l(3,100);
    l.push_back(1);
    l.push_back(4);
    l.push_back(7);
    l.push_front(0);
    for (auto i : l)
        cout << i << " ";
    cout << "\n";

    l.erase(l.begin());
    l.pop_back();
    l.pop_front();

    for (auto i : l)
        cout << i << " ";
    cout << "\n";

    return 0;
}