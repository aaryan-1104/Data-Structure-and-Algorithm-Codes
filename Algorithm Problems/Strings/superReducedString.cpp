#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int superReducedString(string str){
    if(str.length()>100){
        return 0;
    }
    
     for(int i=1;i<str.length();i++){
        if(str[i-1]==str[i]){
            str.erase(i-1,2);
            i=0;
        }
    }

    if(str.length()==0){
        cout<<"Empty String";
    }

    else{
    cout<<str;
    }

    return 0;
}
int main(){
    string str;
    cin>>str;

   superReducedString(str);

   return 0;
}
