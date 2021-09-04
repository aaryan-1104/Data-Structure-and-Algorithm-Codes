#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s[n];
    if(n>1000){
        return -1;
    }
    
    for(int i=0;i<n;i++){
        cin>>s[i];

    }

    
    int x;
    cin>>x;
    string q[x];
    if(x>1000){
        return -1;
    }
    for(int i=0;i<x;i++){
        cin>>q[i];

    }
    int ans[x];
    for(int i=0;i<x;i++){
        ans[i]=0;
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<n;j++){
            if(q[i]==s[j]){
                ans[i]++;
            }
        }
    }

    for(int i=0;i<x;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}