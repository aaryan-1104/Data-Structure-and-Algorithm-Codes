#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;cout<<endl;
    while(t--){
        int n;cin>>n;cout<<endl;

        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i].first>>a[i].second;cout<<endl;
        }

        int l,p;
        cin>>l>>p;

        for (int i = 0; i < n; i++)
        {
            a[i].first=l-a[i].first;
        }

        sort(a.begin(),a.end());
        int ans=0, curr=p, flag=0;

        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < n; i++)
        {
            if(curr>l){
                break;
            }
            while(curr<a[i].first){
                if(pq.empty()){
                    flag=1;
                    break;
                }
                ans++;
                curr+=pq.top();
                pq.pop();
            }
            if(flag){
                break;
            }
            pq.push(a[i].second);
        }
        
        if(flag){
            cout<<"-1"<<endl;
            continue;
        }

        while(!pq.empty() && curr<l){
            curr+=pq.top();
            pq.pop();
            ans++;
        }
        
        if(curr<l){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;    
    }
}