#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(9);
    v.push_back(6);
    v.push_back(2);
    v.push_back(7);
    v.push_back(3);
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
    // binary search return 1 or 0
    cout << binary_search(v.begin(), v.end(), 2) << "\n";

    // reverse(v.begin(), v.end());
    // rotate(v.begin(), v.begin() + 2, v.end());
    rotate(v.begin(), v.end() - 2, v.end());

    for (auto i : v)
        cout << i << " ";
    cout << "\n";

    // cout << "Lower Bound -> " << lower_bound(v.begin(), v.end(), 5) - v.begin() << "\n";
    // cout << "Upper Bound -> " << upper_bound(v.begin(), v.end(), 4) - v.begin() << "\n";

    return 0;
}