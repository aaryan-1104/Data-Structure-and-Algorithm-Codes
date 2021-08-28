#include<iostream>
#include<climits>
using namespace std;


int hourglassSum(int a[6][6]){
    int ans=INT_MIN;
    int sum=0;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sum=a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1] + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
            ans=max(ans,sum);
        }     
    }
    return ans;
}

int main(){
    int a[6][6];

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cin>>a[i][j];
            if(a[i][j]<-9||a[i][j]>9){
                break;
                cout<<"input must be in range from -9 to 9";
                return 0;
            }
        }
    }
    cout<<hourglassSum(a);
    return 0;
}