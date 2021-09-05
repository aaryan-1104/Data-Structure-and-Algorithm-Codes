#include <iostream>
using namespace std;
bool isSafe(int **arr, int x, int y, int n)
{
    for (int row = 0; row < x; row++)//to check if there is a queen in above columns of a particular position
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)//to check if there is queen on right diagonal of a prticular position
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)//to check if there is queen on right diagonal of a prticular position
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **ans, int x, int n)
{
    if (x >= n)//base condition if all rows are used 
    {
        return true;
    }
    for (int col = 0; col < n; col++)//to check the validity of every colums of a row by using "isSafe" function
    {
        if (isSafe(ans, x, col, n))//to check the validity of a position
        {
            ans[x][col] = 1;
            if (nQueen(ans, x + 1, n))//recursion to check whether that in the next row, a queen can be placed or not 
            {
                return true;
            }
            ans[x][col] = 0;//backtracking if there is no valid position for queen in next row
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << endl;

    int **ans = new int *[n];
    for (int i = 0; i < n; i++) //dynamically initaialize the answer array to zero
    {
        ans[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = 0;
        }
    }

    if (nQueen(ans, 0, n))
    {
        for (int i = 0; i < n; i++) //printing the solution array "ans" of the maze if exist
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}