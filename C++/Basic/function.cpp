#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int fact(int num){
    int factorial=1;
    for(int i=2;i<=num;i++){
        factorial=factorial*i;
    }
return factorial;    
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
return 0;
}

/*fibonnaci*/
/*primenumber*/
/*pascals triangle*/
