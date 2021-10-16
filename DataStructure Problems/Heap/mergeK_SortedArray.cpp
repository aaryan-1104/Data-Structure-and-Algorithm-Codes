#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>

int main()
{
    int k;
    cin >> k;
    cout << endl;

    vector<vector<int>> v(k);
    for (int i = 0; i < k; i++)
    {
        int size;
        cin >> size;
        cout << endl;
        v[i] = vector<int>(size);

        for (auto &j : v[i])
        {
            cin >> j;
        }
        cout << endl;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    vector<int> index(k, 0); //* intialize with zero
    vector<int> ans;
    for (int i = 0; i < k; i++)
        minHeap.push({v[i][0], i});

    while (!minHeap.empty())
    {
        //todo: Step 1: take the value out and store in temp variable
        int temp = minHeap.top().first;
        int arraynum = minHeap.top().second;
        minHeap.pop();

        //todo: Step 2: push back the value into ans vector.
        ans.push_back(temp);

        /**
         * todo: Step 3: push next element of the array whose value just pushed int into ans vector if exist 
         * todo:         and update index of that array upto which element are pushed into it;
        */
        if (index[arraynum] + 1 < v[arraynum].size())
        {
            minHeap.push({v[arraynum][index[arraynum] + 1], arraynum});
        }
        index[arraynum]++;
    }

    for(auto i:ans){
        cout<<i<<" ";
    }
}