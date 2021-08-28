#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int camelCase(string str){

    int count =0;
    if(str.length()==0){
        cout<<0;
        return 0;
    }
    else{
    count=1;
    }

     for(int i=0;i<str.length();i++){
        if(str[i]>='A' && str[i]<='Z'){
            count++;
        }
    }

    cout<<count;
    
    return 0;
}
int main(){
    string str;
    cin>>str;

   camelCase(str);

   return 0;
}
