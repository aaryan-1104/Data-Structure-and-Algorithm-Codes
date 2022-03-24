#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << endl;

    vector<vector<int>> a;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << endl;
        a.push_back({start, end});
    }

    sort(a.begin(), a.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int activityTaken = 1;
    int end = a[0][1];

    for (int i = 1; i < n; i++)
    {
        if (end <= a[i][0])
        {
            activityTaken++;
            end = a[i][1];
        }
    }

    cout << activityTaken;
}