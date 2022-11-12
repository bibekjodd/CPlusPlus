// ordered set #include<set>
// unique elements  MultiSet -> can contain duplicates
// implemented using balanced BST
// elements are in sorted order
// random access not possible

// Time Complexities
// Insertion O(Log N)
// Deletion O(Log N)
// Lower/Upper_Bound O(Log N)

// unordered set #inclulde<unordered_set>
// unique elements
// implemented using hashing
// random access not possible

// Time Complexities
// insertion O(1) in avg case, O(N) in worst case
// Deletion O(1) in avg case, O(N) in worst case
// Lower/Upper_Bound -> NA
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // set<int> s;
    // // set<int, greater<int>> s;
    // s.insert(3);
    // s.insert(1);
    // s.insert(2);
    // s.insert(2);
    // s.insert(4);
    // s.insert(9);
    // s.insert(6);
    // s.insert(0);

    // for (auto i : s)
    //     cout << i << " ";
    // cout << "\n";
    // cout << s.size() << "\n";
    // // s.erase(s.begin());
    // // s.erase(2);
    // // for (auto i = s.rbegin(); i != s.rend(); i++)
    // for (auto i = s.begin(); i != s.end(); i++)
    //     cout << *i << " ";
    // cout << "\n";

    unordered_set<int> s;
    s.insert(1);
    s.insert(7);
    s.insert(2);
    s.insert(2);
    s.insert(9);
    s.insert(9);
    s.insert(9);
    s.insert(9);
    s.insert(4);
    s.insert(6);

    for (auto i : s)
        cout << i << " ";
    cout << "\n";

    cout << s.size() << "\n";

    // s.erase(2); // deletes all instance of element
    // s.erase(s.find(9)); // deletes only one instance

    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << "\n";
    // cout<<s.count(9);
    return 0;
}