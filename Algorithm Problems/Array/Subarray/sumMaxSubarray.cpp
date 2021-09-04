#include<iostream>
#include<climits>
using namespace std;

int main(){
     int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

  /*  int currsum[n];
    currsum[0]=0;
    for(int i=1;i<n;i++){
        currsum[i]=currsum[-1]+a[i-1];
    }
    int maxsum=INT_MIN;
    for(int i=1;i<n;i++){
        int sum=0;
        for(int j=0;j<i;j++){
            sum=currsum[i]-currsum[j];
            maxsum=max(sum,maxsum);
        }
    }
    cout<<maxsum;*/

    
    /*Kadane's Algorithm*/
    int currsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum<0){
            currsum=0;
        }
        maxsum=max(maxsum,currsum);
    }
    cout<<maxsum<<endl;
    return 0;
}