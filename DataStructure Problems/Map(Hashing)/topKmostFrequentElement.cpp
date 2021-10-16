#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<map>

int main(){
    int n,k;cin>>n>>k;cout<<endl;
    
    vector<int> v(n);

    for(auto &i:v){
        cin>>i;
    }

    map<int, int> m;

    for(int i=0;i<n;i++){

        int presentsize=m.size();
        if(presentsize==k&&m[v[i]]==0){
            break;
        }
        m[v[i]]++;
    }

    vector<pair<int,int>> ans;
    map<int,int>::iterator it;

    for(it=m.begin();it!=m.end();it++){
        if(it->second!=0){
            ans.push_back({it->first,it->second});
        }
    }

    sort(ans.begin(), ans.end(), greater<pair<int,int>>());

    vector<pair<int,int>>::iterator i;

    for(i=ans.begin();i!=ans.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }

}