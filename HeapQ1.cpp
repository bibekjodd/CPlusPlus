#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
#define pq priority_queue
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define gi greater<int>

class comp
{
public:
    bool operator()(const pii &a, const pii &b)
    {
        int x = abs(a.first);
        int y = abs(a.second);
        long long int d1 = x * x + y * y;
        x = abs(b.first);
        y = abs(b.second);
        long long int d2 = x * x + y * y;
        return d1 < d2;
    }
};

// --------------------------------print array------------------------------------------
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void printVector(vi v)
{
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
}
// --------------------------------print array end------------------------------------------

// #1 Return k largest elements
vi kLargests(int a[], int n, int k)
{
    vi ans;
    if (!k)
        return ans;
    pq<int, vi, gi> minh;

    for (int i = 0; i < n; i++)
    {
        if (i < k && k < n)
            minh.push(a[i]);
        else if (i >= k && a[i] > minh.top())
            minh.push(a[i]), minh.pop();
    }

    while (!minh.empty())
        ans.push_back(minh.top()), minh.pop();

    return ans;
}

// #2 sort nearly sorted array
void sortKSorted(int a[], int n, int k)
{
    pq<int, vi, gi> minh;
    for (int i = 0; i <= k; i++)
        minh.push(a[i]);

    a[0] = minh.top();
    minh.pop();

    for (int i = 1; i < n; i++)
    {
        if (i < n - k)
            minh.push(a[i + k]);
        a[i] = minh.top();
        minh.pop();
    }
    // a[n-1]=minh.top();
}

// #3 k closest numbers
vi kClosest(int a[], int n, int x, int k)
{
    vi ans;
    pq<pair<int, int>> maxh;
    for (int i = 0; i < n; i++)
    {
        maxh.push({abs(x - a[i]), a[i]});
        if (maxh.size() > k)
            maxh.pop();
    }
    while (!maxh.empty())
    {
        ans.push_back(maxh.top().second);
        maxh.pop();
    }
    cout << ans.size() << "\n";
    return ans;
}

// #4 top k frequent numbers
vi topKFrequent(int a[], int n, int k)
{
    vi ans;
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[a[i]]++;

    pq<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxh;
    for (auto i : m)
    {
        if (maxh.size() < k)
            maxh.push({i.second, i.first});
        else if (maxh.size() >= k && i.second > maxh.top().first)
        {
            maxh.pop();
            maxh.push({i.second, i.first});
        }
    }
    while (!maxh.empty())
    {
        ans.push_back(maxh.top().second);
        maxh.pop();
    }
    return ans;
}

// #5 frequence sort
void freqSort(int a[], int n)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[a[i]]++;
    pq<pii, vii> maxh;

    for (auto i : m)
        maxh.push({i.second, i.first});

    int i = 0;
    while (!maxh.empty())
    {
        int x = maxh.top().first;
        while (x--)
            a[i++] = maxh.top().second;
        maxh.pop();
    }
}

// #6 k closest points to origin
vii kClosestOrigin(set<pii, comp> &s, int k)
{
    vii ans;
    for (auto i : s)
        cout << i.first << " " << i.second << "\n";
    cout << "\n";
    set<pii>::iterator it = s.begin();
    for (int i = 0; i < k && i < s.size(); i++)
    {
        ans.push_back({it->first, it->second});
        it++;
    }
    return ans;
}

// #7 connect ropes to minimise the cost
int minCostRopes(int a[], int n)
{
    pq<int, vi, gi> minh;
    for (int i = 0; i < n; i++)
        minh.push(a[i]);

    while (minh.size() > 1)
    {
        int cost = 0;
        cost += minh.top();
        minh.pop();
        cost += minh.top();
        minh.pop();
        minh.push(cost);
    }

    return minh.top();
}

// sum of elements between k1 and k2 smallest numbers
int sumBetnKSmallest(int a[], int n, int k1, int k2)
{
    pq<int> maxh;
    if (k2 < k1)
        swap(k2, k1);

    for (int i = 0; i < n; i++)
    {
        if (i < k2)
            maxh.push(a[i]);
        else if (i >= k2 && a[i] < maxh.top())
        {
            maxh.pop();
            maxh.push(a[i]);
        }
    }
    int sum = 0;
    maxh.pop();

    while (maxh.size() > k1)
    {
        sum += maxh.top();
        maxh.pop();
    }

    return sum;
}

// Median of a running stream
void insertMedian(pq<int> &maxh, pq<int, vi, gi> &minh, int key)
{
    if (maxh.size() == 0 && minh.size() == 0)
    {
        maxh.push(key);
        return;
    }
    if (key > maxh.top())
    {
        minh.push(key);
        if (minh.size() - maxh.size() > 1)
        {
            maxh.push(minh.top());
            minh.pop();
        }
        return;
    }
    maxh.push(key);
    if (maxh.size() - minh.size() > 1)
    {
        minh.push(maxh.top());
        maxh.pop();
    }
}

long double findMedian(pq<int> &maxh, pq<int, vi, gi> &minh)
{
    if (maxh.size() > minh.size())
        return maxh.top();

    else if (minh.size() > maxh.size())
        return minh.top();

    return (maxh.top() + minh.top()) / 2.0;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // --------------------------------------------------------------------------
    // #1 return k largest elements
    // int k;
    // cin>>k;
    // vi ans = kLargests(a, n, k);
    // printVector(ans);
    // --------------------------------------------------------------------------
    // --------------------------------------------------------------------------
    // #2 sort nearly sorted array
    // int k;
    // cin >> k;
    // sortKSorted(a, n, k);
    // printArray(a, n);
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // #3 k closest numbers
    // int x, k;
    // cin >> x >> k;
    // vi ans = kClosest(a, n, x, k);
    // printVector(ans);
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // #4 top k frequent numbers
    // int k;
    // cin >> k;
    // vi ans = topKFrequent(a, n, k);
    // printVector(ans);
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // #5 frequency sort
    // freqSort(a, n);
    // printArray(a, n);
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // #6 k closest points to origin
    // int n;
    // cin >> n;
    // set<pii, comp> s;
    // for (int i = 0; i < n; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     s.insert({x, y});
    // }
    // int k;
    // cin >> k;
    // vii ans = kClosestOrigin(s, k);
    // for (auto i : ans)
    //     cout << i.first << " " << i.second << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // #7 connect ropes to minimise the cost
    // cout << minCostRopes(a, n);
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // sum of elements between k1 and k2 smallest numbers
    // int k1, k2;
    // cin >> k1 >> k2;
    // cout << sumBetnKSmallest(a, n, k1, k2);
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // Median of a running stream
    // pq<int> maxh;
    // pq<int, vi, gi> minh;
    // for (int i = 0; i < n; i++)
    //     insertMedian(maxh, minh, a[i]), cout << findMedian(maxh, minh) << "\n";

    // --------------------------------------------------------------------------

    return 0;
}