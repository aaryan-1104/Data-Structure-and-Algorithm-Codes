#include<iostream>
using namespace std;

void compareTriplets(int a[3], int b[3]){
    int ans[2];

    for(int i=0;i<2;i++){
        ans[i]=0;
    }

    for(int i=0;i<3;i++){
        if(a[i]>b[i]){
            ans[0]++;
        }
        else if(b[i]>a[i]){
            ans[1]++;
        }
        else{
            continue;
        }
    }
    cout<<ans[0]<<" "<<ans[1];
}

int main(){

    int a[3];
    int b[3];

    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    cout<<endl;
    for(int i=0;i<3;i++){
        cin>>b[i];
    }
    compareTriplets(a,b);
    return 0;
}