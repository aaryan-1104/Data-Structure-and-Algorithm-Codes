#include<iostream>
#include<climits>
using namespace std;

  /*Kadane's Algorithm*/
int kadane(int a[], int n){

 
    int currsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum<0){
            currsum=0;
        }
        maxsum=max(maxsum,currsum);
    }
    return maxsum;
}

int main(){
     int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int nonwrapsum;
    int wrapsum;

    nonwrapsum=kadane(a,n);

    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=a[i];
        a[i]=-a[i];
    }
    wrapsum=totalsum /*- -*/+ kadane(a,n);
    int m=max(wrapsum,nonwrapsum);
    cout<<m<<endl;


  /*  int currsum[n];
    currsum[0]=0;
    for(int i=1;i<n;i++){
        currsum[i]=currsum[i-1]+a[i-1];
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
    return 0;
}