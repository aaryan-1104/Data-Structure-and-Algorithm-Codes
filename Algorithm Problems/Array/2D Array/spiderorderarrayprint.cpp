#include<iostream>
using namespace std;
#include<climits>


int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }

    int r_start=0, r_end=n-1, c_start=0, c_end=n-1;
   
    
    while(r_start<=r_end && c_start<=c_end){
         //rstart
        for(int i=c_start;i<=c_end;i++){
            cout<<a[r_start][i]<<" ";
        }
        r_start++;
        cout<<endl;
        //c_end
        for(int i=r_start;i<=r_end;i++){
            cout<<a[i][c_end]<<endl;
        }
        c_end--;
        //r_end
        for(int i=c_end;i>=c_start;i--){
            cout<<a[r_end][i]<<" ";
        }
        r_end--;
        cout<<endl;
        //c_start
        for(int i=r_end;i>=r_start;i--){
            cout<<a[i][c_start];
            cout<<endl;
        }
        c_start++;
    }
    return 0;
}