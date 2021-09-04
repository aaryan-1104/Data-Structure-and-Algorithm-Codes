/*sum of each subarray*/
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
    int sum=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            /*
            sum=0;
            for(int k=i;k<j;k++){
                sum=sum+a[k];
            }
            maxsum=max(maxsum,a[k])*/
            sum=sum+a[j];
            cout<<sum<<endl;
        }
    }
    return 0;
}