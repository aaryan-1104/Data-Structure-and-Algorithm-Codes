#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<double,double>
#define vii vector<pii>
#define loop(i, a, b) for(int i=a;i<b;i++)

int main(){
    int n;cin>>n;cout<<endl;

    vii a(n);
    loop(i,0,n){
        cin>>a[i].first>>a[i].second;        
    }
    sort(a.begin(),a.end(), [&](pii &a, pii &b){ return (a.first/a.second)>(b.first/b.second);});

    int w;cin>>w;cout<<endl;
    int ans=0;
    loop(i,0,n){
        if(w>a[i].second){
            w-=a[i].second;
            ans+=a[i].first;
        }else{
            ans=ans+(w*(a[i].first/a[i].second));
            w=0;
        }
    }

    cout<<ans;
}