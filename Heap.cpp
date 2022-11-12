// Heap
// Complete Binary Tree
// Node addition left -> right
// Max Heap => parent is greater than it's child
// Min Heap => parent is lesser than it's child
// It can be implemented through pirority queue #include<queue>

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // heap h;
    // for (int i = 0; i < 10; i++)
    //     h.insert(2 * i);
    // h.del();
    // h.print();

    // priority_queue<int, vector<int>> pq;               // Max Heap
    priority_queue<int, vector<int>, greater<int>> pq; // Min Heap
    for (int i = 0; i < 20; i++)
        pq.push(2 * i);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

// class heap
// {
// public:
//     int a[100];
//     int size;
//     heap()
//     {
//         a[0] = -1;
//         size = 0;
//     }

//     void insert(int val)
//     {
//         size++;
//         int index = size;
//         a[index] = val;
//         while (index > 1)
//         {
//             int parent = index / 2;
//             if (a[parent] < a[index])
//             {
//                 swap(a[parent], a[index]);
//                 index = parent;
//             }
//             else
//                 return;
//         }
//     }

//     void del()
//     {
//         if (size == 0)
//             return;

//         a[1] = a[size];
//         size--;

//         int i = 1;
//         while (i < size)
//         {
//             int leftIndex = 2 * i;
//             int rightIndex = 2 * i + 1;

//             if (leftIndex < size && a[i] < a[leftIndex])
//             {
//                 swap(a[i], a[leftIndex]);
//                 i = leftIndex;
//             }
//             else if (rightIndex < size && a[i] < a[rightIndex])
//             {
//                 swap(a[i], a[rightIndex]);
//                 i = rightIndex;
//             }
//             else
//                 return;
//         }
//     }

//     void print()
//     {
//         for (int i = 1; i <= size; i++)
//             cout << a[i] << " ";
//         cout << "\n";
//     }
// };
