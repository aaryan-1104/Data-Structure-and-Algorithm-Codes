#include<iostream>
using namespace std;

void aVeryBigSum(long long a[],int n){
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    cout<<sum;
}
int main(){
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    aVeryBigSum(a,n);
return 0;
}