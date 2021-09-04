#include<iostream>
using namespace std;
#include<climits>

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int curr =2;;
    int pd=a[1]-a[0];
    int mx=2;

    for(int j =2;j<n;j++){
        if(a[j]-a[j-1]==pd){
            curr++;
        }
        else{
            pd=a[j]-a[j-1];
            curr=2;
        }
        mx=max(mx,curr);

    }
    cout<<mx;
    return 0;
}