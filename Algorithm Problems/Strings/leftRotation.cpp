#include<iostream>
using namespace std;

int leftRotation(int d, int a[], int n){
    if(d>n){
        return -1;
    }
    int temp;
    for(int i=0;i<d;i++){
        temp=a[0];
        for(int j=1;j<n;j++){
            
            a[j-1]=a[j]; 

        }
        a[n-1]=temp;
        
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
int main(){
    int n, d;
    cin>>n>>d;
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    leftRotation(d,a,n);
    return 0;
}