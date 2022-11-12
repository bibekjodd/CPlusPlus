#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;

    m.insert({7, "Vladimir"});
    m.insert({9, "Oora"});
    m.insert({6, "Putin"});
    m.insert({6, "duplicate"});

    for (auto i : m)
        cout << i.first << " " << i.second << "\n";
    cout << "\n";

    m.erase(6);

    for (auto i : m)
        cout << i.first << " " << i.second << "\n";
    cout << "\n";

    auto it = m.find(7);
    for (auto i = it; i != m.end(); i++)
        cout << (*i).first << "\n";
        // cout << m.count(3) << "\n";

        return 0;
}