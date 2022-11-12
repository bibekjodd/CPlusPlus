#include <iostream>
#include <array>
using namespace std;
int main()
{

    array<int, 0> a;
    cout << "Is Empty -> " << a.empty() << "\n";
    for (auto &i : a)
        cin >> i;
    cout << "Is Empty -> " << a.empty() << "\n";
    cout << "Front -> " << a.front() << "\n";
    cout << "Back -> " << a.back() << "\n";

    return 0;
}