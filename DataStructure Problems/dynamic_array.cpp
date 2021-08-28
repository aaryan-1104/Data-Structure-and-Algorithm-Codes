#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

// int dynamicArray(int n,string queries[][]){

//     int lastAnswer=0;
//     int arr[n];
//     int idx;
//     int ans=0;
//     int y;
//     for(int i=0;i<;i++){
//         y=queries[i][4];
//         idx=((queries[i][2]^lastAnswer)%n);
//         if(queries[i][0]==1){
//             queries[idx]=y;
//         }
//         else if(queries[i][0]==2){
//             lastAnswer= queries[idx][y%size(queries[idx])];
//         }
//         else{
//             return 0;
//         }
//         ans[i]=lastAnswer;      
//     }
// }

int main(){
    int n,q;
    string queries[q];
    cin>>n>>q;



    for(int i=0;i<q;i++){
        for(int j=0;j<3;j++){
            cin>>queries[i][j];
        }
        
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<3;j++){
            cout<<queries[i][j];
        }
    }
   



    int lastAnswer=0;
    int arr[n];
    int idx;
    int ans[q];
    int i;
    int y;
    for(int i=0;i<q;i++){
        y=queries[i][2];
        idx=((queries[i][1]^lastAnswer)%n);
        if(queries[i][0]==1){
            queries[idx]=y;
        }
        else if(queries[i][0]==2){
            lastAnswer= queries[idx][y%queries[idx].size()];
            ans[i]=lastAnswer;
            cout<<ans[i];
        }
        else{
            return 0;
        }
              
    }

    //dynamicArray(n,queries);
}