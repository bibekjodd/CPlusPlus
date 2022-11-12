#include <iostream>
using namespace std;

// rat in a maze
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1

bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y])
        return 1;
    return 0;
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArr)
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return 1;
    }

    if (isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;
        if (ratInMaze(arr, x, y + 1, n, solArr))
            return 1;

        if (ratInMaze(arr, x + 1, y, n, solArr))
            return 1;

        solArr[x][y] = 0;
        return 0;
    }

    return 0;
}

// N-Queen Problem
bool isQueenSafe(int **arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
            return 0;
    }

    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return 0;
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return 0;
        row--;
        col++;
    }
    return 1;
}

bool nQueen(int **arr, int x, int n)
{
    if (x == n)
        return 1;

    for (int col = 0; col < n; col++)
    {
        if (isQueenSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
                return 1;
            arr[x][col] = 0;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
            solArr[i][j] = 0;
        }
    }

    // --------------------------------------------------------------------------
    // Rat In Maze
    // if (ratInMaze(arr, 0, 0, n, solArr))
    // {
    //     cout << "Path\n";
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //             cout << solArr[i][j] << " ";
    //         cout << "\n";
    //     }
    // }
    // else
    //     cout << "Path Not found\n";
    // --------------------------------------------------------------------------

    // --------------------------------------------------------------------------
    // N Queen Problem
    if (nQueen(solArr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (solArr[i][j] == 1)
                    cout << "Q ";
                else
                    cout << "* ";
            cout << "\n";
        }
    }
    else
        cout << "Queen can't be placed\n";
    // --------------------------------------------------------------------------

    return 0;
}