#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)//function to check a particular location is "safe to go" or not
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **ans)//main function
{
    if ((x == (n - 1)) && (y == (n - 1)))//base condition which denotes the end of the maze
    { 
        ans[x][y]=1;
        return true;
    }

    if (isSafe(arr, x, y, n))//to check if the cuurrent location safe or not
    { 
        ans[x][y] = 1;
        if (arr, x + 1, y, n, ans) //to check whether the right next location is safe or not
        {
            return true;
        }
        if (arr, x, y + 1, n, ans)////to check whether the bottom next location is safe or not
        { 
            return true;
        }
        ans[x][y] = 0; //backtracking if following the current choice there is no viable choice to go ahead
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << endl;
 
    int **arr = new int*[n]; 
    for (int i = 0; i < n; i++)//dynamically allocating memoery to array
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    { //input values in array
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }

    int **ans = new int *[n]; 
    for (int i = 0; i < n; i++)//dynamically initaialize the answer array to zero
    {
        ans[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = 0;
        }
    }

    if(ratInMaze(arr, 0, 0, n, ans)){
        for (int i = 0; i < n; i++)//printing the solution array "ans" of the maze if exist 
        { 
            for (int j = 0; j < n; j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
        }
    }
    // return 0;
}