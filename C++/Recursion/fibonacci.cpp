#include<iostream>
using namespace std;
#include<vector>

int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n-2)+fib(n-1);
}

int main(){
int n;
cin>>n;

cout<<fib(n);

return 0;
}