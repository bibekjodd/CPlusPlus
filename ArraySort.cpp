#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// --------------------------------print array------------------------------------------
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void printVector(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << "\n";
}

// ----------------------------------------------Selection Sort----------------------------------------------
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
    }
}

// --------------------------------print array end------------------------------------------

void bubbleSort(int a[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);

        counter++;
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int curr = a[i];
        while (j >= 0 &&
               curr < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }
}

// ----------------------------------------------Merge Sort----------------------------------------------
void merge(int a[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a1[n1];
    int a2[n2];

    for (int i = 0; i < n1; i++)
        a1[i] = a[i + l];

    for (int j = 0; j < n2; j++)
        a2[j] = a[j + mid + 1];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a1[i] > a2[j])
            a[k++] = a2[j++];
        else
            a[k++] = a1[i++];
    }

    while (i < n1)
        a[k++] = a1[i++];
    while (j < n2)
        a[k++] = a2[j++];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

// ----------------------------------------------Quick Sort----------------------------------------------
int partition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l, j = r;
    while (i < j)
    {
        while (pivot >= a[i])
            i++;
        while (pivot < a[j])
            j--;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int pivotPoint = partition(a, l, r);
        quickSort(a, l, pivotPoint - 1);
        quickSort(a, pivotPoint + 1, r);
    }
}

// ---------------------------DNF Sort---------------------------
void DNFSort(int a[], int n)
{
    int s = 0, e = n - 1, m = 0;
    while (m <= e)
    {
        if (a[m] == 0)
            swap(a[m++], a[s++]);
        else if (a[m] == 1)
            m++;
        else if (a[m] == 2)
            swap(a[m], a[e--]);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // selectionSort(a, n);
    // bubbleSort(a, n);
    // insertionSort(a, n);
    // mergeSort(a, 0, n - 1);
    // quickSort(a, 0, n - 1);
    // DNFSort(a, n);
    printArray(a, n);
    return 0;
}