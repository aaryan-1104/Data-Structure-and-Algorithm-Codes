#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main()
{
    int n, k;
    cin >> n >> k;
    cout<<endl;

    vector<int> v(n);

    for (auto &i : v)
    {
        cin >> i;
    }

    priority_queue<int, vector<int>> maxHeap;

    for(auto i:v){
        maxHeap.push(i);
    }

    int sum=0;
    int count=0;

    while(!maxHeap.empty()){
        sum+=maxHeap.top();
        maxHeap.pop();
        count++;
        if(sum>=k){
            cout<<count;
            return 0;
        }
    }

    return -1;
}