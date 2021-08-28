#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
        cout<<endl;
    }

    int l=0;
    int r=0;
    for(int i=0;i<n;i++){
        l+=a[i][i];
        r+=a[i][n-i-1];
    }
    if(l>r){
        cout<<l-r;
    }
    else{
        cout<<r-l;
    }  
return 0;
}