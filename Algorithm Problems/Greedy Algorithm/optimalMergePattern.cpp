#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
    int n;cin>>n;cout<<endl;
    vi a(n);
    loop(i,0,n){
        cin>>a[i];
    }

    priority_queue<int, vi, greater<int>> minHeap;
    loop(i,0,n){
        minHeap.push(a[i]);
    }

    int ans=0;
    while(minHeap.size()>1){
        int a=minHeap.top();
        minHeap.pop();
        int b=minHeap.top();
        minHeap.pop();

        ans+=a+b;
        minHeap.push(a+b);
    }

    cout<<ans;
}