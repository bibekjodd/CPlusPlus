#include <iostream>
#include <climits>
using namespace std;

// binary search
int binarySearch(int a[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int binarySearch(int a[], int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

// search int reverse sorted array
int searchReverseSorted(int a[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == key)
            return mid;

        else if (a[mid] > key)
            start = mid + 1;

        else
            end = mid - 1;
    }
    return -1;
}

int searchReverseSorted(int a[], int start, int end, int key)
{
    // int start = 0;
    // int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == key)
            return mid;

        else if (a[mid] > key)
            start = mid + 1;

        else
            end = mid - 1;
    }
    return -1;
}

// return the first occurrenc of the key
int firstOcc(int a[], int start, int end, int key)
{
    if (a[start] == key)
        return start;
    static int ans = -1;
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            if (a[mid - 1] == key)
                return firstOcc(a, start, mid - 1, key);
            return mid;
        }
        else if (key < a[mid])
            return firstOcc(a, start, mid - 1, key);
        return firstOcc(a, mid + 1, end, key);
    }
    return ans;
}

// return the last occurrenc of the key
int lastOcc(int a[], int start, int end, int key)
{
    if (a[end] == key)
        return end;
    static int ans = -1;
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            if (a[mid + 1] == key)
                return lastOcc(a, mid + 1, end, key);
            return mid;
        }
        else if (key < a[mid])
            return lastOcc(a, start, mid - 1, key);
        return lastOcc(a, mid + 1, end, key);
    }
    return ans;
}

// return the count of the element in a sorted array
int countSorted(int a[], int n, int key)
{
    int firstocc = firstOcc(a, 0, n - 1, key);
    if (firstocc == -1)
        return 0;

    int lastocc = lastOcc(a, 0, n - 1, key);
    return (lastocc - firstocc + 1);
}

// how many times a sorted array is rotated
int timesRotated(int a[], int start, int end)
{
    if ((a[start] < a[end]) || (start == end))
        return start;

    int mid = (start + end) / 2;
    if (mid == start)
        return start + 1;

    if (mid == end)
        return end;

    if (a[mid - 1] > a[mid] && a[mid] < a[mid + 1])
        return mid;

    if (a[mid] < a[end])
        return timesRotated(a, start, mid - 1);
    return timesRotated(a, mid + 1, end);
}

// search in sorted and rotated array
int searchSortedRotated(int a[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = end - (end - start) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] > a[start])
        {
            if (a[start] <= key && key < a[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if (a[mid] < a[end])
        {
            if (a[mid] < key && key <= a[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
// nearly sorted a[n] and exist in a[n-1]||a[n]||a[n+1]
int nearlySorted(int a[], int start, int end, int key)
{
    int n = end;
    while (start <= end)
    {
        int mid = end - (end - start) / 2;
        if (a[mid] == key)
            return mid;
        else if ((mid - 1) > 0 && a[mid - 1] == key)
            return mid - 1;
        else if ((mid + 1) <= n && a[mid + 1] == key)
            return mid + 1;
        else if (key < a[mid])
            end = mid - 2;
        else
            start = mid + 2;
    }
    return -1;
}

// return floor of the key
int floor(int a[], int start, int end, int key)
{
    if (a[end] < key)
        return end;

    static int ans = -1;
    if (a[start] >= key)
        return ans;

    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] < key)
        {
            ans = mid;
            return floor(a, mid + 1, end, key);
        }
        return floor(a, start, mid - 1, key);
    }
    return ans;
}

// return ceil of the key
int ceil(int a[], int start, int end, int key)
{
    if (a[start] > key)
        return start;

    static int ans = -1;
    if (a[end] < key)
        return ans;
    if (start <= end)
    {
        int mid = end - (end - start) / 2;
        if (a[mid] > key)
        {
            ans = mid;
            return ceil(a, start, mid - 1, key);
        }
        return ceil(a, mid + 1, end, key);
    }
    return ans;
}

// next aphabetical letter in an array
char nextLetter(char a[], int start, int end, char k)
{
    if (a[start] > k)
        return a[start];

    static char ans = '0';
    if (a[end] <= k)
        return ans;
    if (start <= end)
    {
        int mid = end - (end - start) / 2;
        if (a[mid] > k)
        {
            ans = a[mid];
            return nextLetter(a, start, mid - 1, k);
        }
        return nextLetter(a, mid + 1, start, k);
    }
    return ans;
}
// search in an infinite sorted array
int searchInfiniteSorted(int a[], int start, int n, int key)
{
    int end = 1;
    if (key < a[start] && key > a[end])
        return -1;

    while (a[end] < key && end <= n)
    {
        start = end;
        end *= 2;
    }
    return binarySearch(a, start, end, key);
}

// index of first 1 in binary infinite sorted array
int first1(int a[], int start, int n)
{
    int ans = -1;
    int end = 1;
    while (end < n && a[end] < 1)
    {
        start = end;
        end *= 2;
    }
    while (start <= end)
    {
        if (a[start])
            return start;

        if (!a[end])
            return ans;

        int mid = end - (end - start) / 2;
        if (a[mid] == 0)
            start = mid + 1;
        else if (a[mid] == 1)
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

// minimum difference element in a sorted array for k {1,3,8,10,15} k=12 min=12-10 ans=10
int minDifference(int a[], int n, int key)
{
    if (!n)
        return -1;
    int idxkey = binarySearch(a, 0, n - 1, 12);
    if (idxkey != -1)
        return key;

    int fl = floor(a, 0, n - 1, key);
    int cl = ceil(a, 0, n - 1, key);

    if (fl == -1)
        return a[cl];

    if (cl == -1)
        return a[fl];

    if ((key - a[fl]) < (a[cl] - key))
        return a[fl];
    return a[cl];
}

int mindiff(int a[], int start, int end, int key)
{
    int n = end;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == key)
            return key;

        else if (a[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if (start > n)
        return a[end];

    if (end < 0)
        return a[start];

    if (abs(key - a[start]) < abs(key - a[end]))
        return a[start];

    return a[end];
}

// find peak element element greater than previous and next a[-1]=a[n]=INT_MIN
int peakElement(int a[], int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int prev = INT_MIN;
        int next = INT_MIN;
        if (mid - 1 >= 0)
            prev = a[mid - 1];
        if (mid + 1 <= end)
            next = a[mid + 1];
        if (prev < a[mid] && a[mid] > next)
            return mid;
        if (next > a[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

// max element in bitonic array
int maxInBitonic(int a[], int n)
{
    int start = 0, end = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
            return mid;

        if (a[mid + 1] > a[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return n;
}

// search in bitonic array
int searchBitonic(int a[], int n, int key)
{
    n++;
    int idx = maxInBitonic(a, n);
    // int idx1 = binarySearch(a, n, key);
    int idx1 = binarySearch(a, 0, idx, key);
    if (idx1 != -1)
        return idx1;
    int idx2 = searchReverseSorted(a, idx, n, key);
    return idx2;
}

// search in row and column wise sorted 2d matrix
pair<int, int> searchRowColSorted(int **a, int x, int y, int key)
{
    int row = 0, col = y;
    while (row <= x && col >= 0)
    {
        if (key == a[row][col])
            return {row, col};
        else if (key < a[row][col])
            col--;
        else
            row++;
    }
    return {-1, -1};
}

int main()
{
    // int n;
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    int key = 3;
    // cin >> key;
    cout << "...\n";

    // --------------------------------------------------------------------------
    // binary search
    // cout << binarySearch(a, n, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // search in a reverse sorted array
    // cout << searchReverseSorted(a, n, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // Return the first and last occurrence of the key in a sorted array
    // cout << firstOcc(a, 0, n - 1, key) << "\n";
    // cout << lastOcc(a, 0,n-1, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // Return the count of the key in the sorted array
    // cout << countSorted(a, n, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // how many times a sorted array is rotated
    // cout << timesRotated(a, 0, n - 1) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // cout << searchSortedRotated(a, n, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // search key in nearly sorted array
    // cout << nearlySorted(a, 0, n - 1, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // find the floor and ceil of the given value
    // int fl = floor(a, 0, n - 1, key);
    // int cl = ceil(a, 0, n - 1, key);
    // (fl != -1) ? cout << a[fl] << "\n" : cout << "-1\n";
    // (cl != -1) ? cout << a[fl] << "\n" : cout << "-1\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // next alphabetical letter of target in an array
    // char arr[n];
    // for (auto &i : arr)
    //     cin >> i;
    // char k;
    // cin >> k;
    // cout<<nextLetter(arr, 0, n - 1, k)<<"\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // search in an infinite sorted array
    // cout << searchInfiniteSorted(a, 0, n - 1, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // index of first 1 in binary infinite sorted array
    // cout << first1(a, 0, n - 1) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // minimum difference element in a sorted array for k {1,3,8,10,15} k=12 min=12-10 ans=10
    // cout << minDifference(a, n, key) << "\n";
    // cout << mindiff(a, 0, n, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // find peak element
    // cout << peakElement(a, 0, n - 1) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // find peak element in bitonic array
    // cout << maxInBitonic(a, n - 1) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // search in bitonic array
    // cin >> key;
    // cout << searchBitonic(a, n - 1, key) << "\n";
    // int idx = maxInBitonic(a, n - 1);
    // cout << idx << "\n";
    // cout << searchReverseSorted(a, 0, n - 1, key) << "\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // search in row and column wise sorted matrix
    int x, y;
    cin >> x >> y;
    int **arr = new int *[x];
    for (int i = 0; i < x; i++)
    {
        arr[i] = new int[y];
        for (int j = 0; j < y; j++)
            cin >> arr[i][j];
    }
    cin >> key;
    pair<int, int> p = searchRowColSorted(arr, x - 1, y - 1, key);
    cout << p.first << " " << p.second << "\n";
    // --------------------------------------------------------------------------

    return 0;
}