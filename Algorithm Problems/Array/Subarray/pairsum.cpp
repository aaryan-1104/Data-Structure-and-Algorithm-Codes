#include<iostream>
#include<climits>
using namespace std;


bool pairsum(int a[], int n, int k){
    int low=0;
    int high=n-1;
    while(low<high){
        if(a[low]+a[high]==k){
            cout<<low<<" "<<high;
            return true;
        }
        else if(a[low]+a[high]<k){
            low++;
        }
        else{
            high--;
        }
        
    }
    return false;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<"enter elements in acsending order";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    pairsum(a,n,k);
    return 0;
}