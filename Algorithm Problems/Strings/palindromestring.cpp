//check palindrome
//character array
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char a[n];
    cin>>a;

    cout<<a<<"\n";
    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i]!=a[n-1-i]){
            flag=false;
        }
    }    
    if(flag)
        cout<<"it is palindrome";
    else
        cout<<"it is not palindrome";
}