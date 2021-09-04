#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int savings;
    cin>>savings;

    if (savings>5000){
        if(savings>10000){
            cout<<"roadtrip with n\n";
        }
        else{
            cout<<"shopping with n\n";
        }
    }    
    else if(savings>2000){
        cout<<"r\n";
    }
    else{
        cout<<"friends\n";
    }
    return 0;
}