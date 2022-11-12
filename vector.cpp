#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    cout << "Capacity -> " << v.capacity() << "\n";
    v.push_back(1);
    v.push_back(3);
    v.push_back(7);

    cout << "Capacity -> " << v.capacity() << "\n"; // memory assigned
    cout << "Size -> " << v.size() << "\n";         // total elements

    cout << v.front() << "\n";
    cout << v.back() << "\n";
    cout << v.at(1) << "\n";

    for (auto i : v)
        cout << i << " ";
    cout << "\n";

    vector<int> x(v);
    x.push_back(6);
    for (auto i : x)
        cout << i << " ";

    return 0;
}