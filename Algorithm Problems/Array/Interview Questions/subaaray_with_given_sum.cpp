#include<iostream>
using namespace std;
#include<climits>

int main(){
    int n;
    cin>>n;
    int s;
    cin>>s;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int sum=0;
    int i=0, j=0;
    while(j<n &&sum+a[j]<=s){
        sum=sum+a[j];
        j++;
    }
    if(sum==s){
        cout<<i+1<<j<<endl;
    }
    while(j<n){
        sum=sum+a[j];
        while(sum>s){
            sum=sum-a[i];
            i++;
        }
        if(s==sum){
            cout<<i+1<<j+1<<endl;
            break;
        }
        j++;
    }
    return 0;
}