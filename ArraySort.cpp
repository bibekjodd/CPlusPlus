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
    printArray(a, n);
    return 0;
}