#include<iostream>
using namespace std;
#include<string>

int marsExploration(string s){
    int k, count=0;
    k=(s.length()+1)/3;
    if(s.length()%3!=0){
       return 0; 
    }
    int i=0;
    for(int j=0;j<k;j++){
        if(s[i]!='S'){
            count++;
        }
        if(s[i+1]!='O'){
            count++;
        }
        if(s[i+2]!='S'){
            count++;
        }
        i=i+3;
        if(i>=s.length()){
            break;
        }   
    }
    cout<<count;
    return 0;
}
int main(){
    string s;
    cin>>s;

    marsExploration(s);

    return 0;
}