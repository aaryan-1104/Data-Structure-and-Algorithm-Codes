#include<iostream>
using namespace std;
#include<map>
#include<vector>

int main(){
    int n;cin>>n;cout<<endl;

    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    cout<<endl;

    map<int,int> frequency;
    for (int i = 0; i < n; i++)
    {
        frequency[v[i]]++;
    }

    map<int,int> :: iterator it;
    for ( it = frequency.begin(); it !=frequency.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    
}