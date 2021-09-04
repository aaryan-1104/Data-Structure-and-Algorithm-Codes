#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool isprime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int a,b;
    cin>>a>>b;
    for(int j=a;j<=b;j++){
        if(isprime(j)==true){
            cout<<j<<endl;
        }
    }
    return 0;
}