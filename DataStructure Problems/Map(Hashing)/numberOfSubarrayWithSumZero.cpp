#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <map>

int main()
{
    int n;cin>>n;cout<<endl;

    vector<int> v(n);

    for (auto &i : v)
    {
        cin >> i;
    }

    map<int,int> m;

    int prefixSum=0;
    for(auto i:v){
        prefixSum+=i;
        m[prefixSum]++;
    }

    int ans=0;

    map<int,int> :: iterator i;

    for(i=m.begin();i!=m.end();i++){
        int c=i->second;
        ans+=(c*(c-1))/2;

        if(i->first==0){
            ans+=i->second;
        }
    }

    cout<<ans;
}