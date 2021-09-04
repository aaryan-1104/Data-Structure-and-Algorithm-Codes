#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int strongPassword(string password, int n){
    
    string number("0123456789");
    string l_case("abcdefghijklmnopqrstuvwxyz");
    string u_case("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string special_char("!@#$%^&*()-+");

    int a[4]={0,0,0,0};
    int count =0;
    for(int i=0;i<password.length();i++){
        for(int j=0;j<number.length();j++){
            if(password[i]==number[j] && a[0]==0){
                a[0]=1;
            }
        }
        for(int j=0;j<l_case.length();j++){
            if(password[i]==l_case[j] && a[1]==0){
                a[1]=1;
            }
        }
        for(int j=0;j<u_case.length();j++){
            if(password[i]==u_case[j] && a[2]==0){
                a[2]=1;
            }
        }
        for(int j=0;j<special_char.length();j++){
            if(password[i]==special_char[j] && a[3]==0){
                a[3]=1;
            }
        }
    }
   
    for(int i=0;i<4;i++){
        if(a[i]==1){
            count++;
        }
    }
    
    int c=6-password.length();
    int d=4-count;
    if(count<4)
    {
        if(d>=c){
        cout<<d;
        }
        else if(d<=c){
        cout<<c;
        }
        else{
            cout<<0;
        }
    }
    else if(n<6){
            if(d>=c){
                cout<<d;
            }
            else if(d<=c){
                cout<<c;
            }
            else{
                cout<<0;
            }
    }
    return 0;  
}

int main(){
    int n;
    cin>>n;
    string password;
    cin>>password;

    strongPassword(password,n);

    return 0;
}
