#include<iostream>
using namespace std;
#include<climits>


int main(){
    int n,m, key;
    cin>>n>>m>>key;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[i][j];//rows and column in ascending order
    }
    int r=0,c=n-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if(key==a[i][j]){
                    cout<<i<< " "<<j<<endl;
                }
                else if(key<a[i][j]){
                    c--;
                }
                else{
                    r++;
                }
        }
        
    }
return 0;
}