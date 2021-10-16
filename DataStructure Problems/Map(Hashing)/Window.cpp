#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<climits>

int main(){
    int n,k;cin>>n>>k;cout<<endl;
    
    vector<int> v(n);

    for(auto &i:v){
        cin>>i;
    }

    int ans=INT_MAX,sum=0;

    for(int i=0;i<k;i++){
        sum+=v[i];
    }

    ans=min(ans,sum);

    for(int i=1;i<n-k+1;i++){
        sum=sum-v[i-1];
        sum=sum+v[i+k-1];
        ans=min(ans,sum);
    }

    cout<<ans;
}