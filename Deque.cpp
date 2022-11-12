#include <iostream>
#include <deque>
#include <vector>
using namespace std;
// insertion and deletion from both end
// dynamic
// random access possible

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(0);
    dq.push_back(7);
    dq.push_back(9);
    dq.push_back(6);
    dq.push_front(3);
    dq.push_front(17);

    for (auto i : dq)
        cout << i << " ";
    cout << "\n";

    dq.pop_back();
    dq.pop_front();

    for (auto i : dq)
        cout << i << " ";
    cout << "\n";

    // cout << dq.front() << "\n";
    // cout << dq.back() << "\n";
    // cout << dq.at(2) << "\n";

    // dq.erase(dq.begin(), dq.begin() + 2);
    dq.erase(dq.end(), dq.end() + 2);

    for (auto i : dq)
        cout << i << " ";
    cout << "\n";

    return 0;
}