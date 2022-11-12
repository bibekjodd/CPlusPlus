#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// maps -> key-value pair 
// insertion O(log(n))
// accessing O(log(n))
// erase O(log(n))
// Implemented using Red-Black Trees

// unordered maps -> key-value pair
// insertion O(1) average
// accessing O(1)
// erase O(n)
// Implemented using Hash Tables (basically array of buckets)

int main()
{
    unordered_map<string, int> m;
    // map<string, int> m;

    pair<string, int> p2("bhattarai", 2);
    m.insert(p2);

    pair<string, int> p1 = make_pair("bibek", 1);
    m.insert(p1);

    m["hello"] = 3;

    for (auto i : m)
        cout << i.first << " " << i.second << "\n";

    // cout << m["bibekk"];
    // cout << m.at("bibekk");
    // cout<<m.count("bibek")<<"\n";  // 1
    // cout<<m.count("bibekk")<<"\n";  // 0

    cout << "\n";
    m.erase("bibek");

    // for (auto i : m)
    //     cout << i.first << " " << i.second << "\n";

    unordered_map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}