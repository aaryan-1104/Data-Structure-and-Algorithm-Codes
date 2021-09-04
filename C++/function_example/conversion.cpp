#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int decimalToBinary(int num){
    int temp = 1;
    int ans = 0;
    while(temp<=num){
        temp=temp*2;
    }
    temp=temp/2;

    while(temp>0)
    {
        int lastdigit=num/temp;
        num=num-lastdigit*temp;
        temp=temp/2;
        ans=ans*10+lastdigit;
    }
    return ans;
}

int decimalToOctal(int num){
    int temp = 1;
    int ans = 0;
    while(temp<=num){
        temp=temp*8;
    }
    temp=temp/8;

    while(temp>0)
    {
        int lastdigit=num/temp;
        num=num-lastdigit*temp;
        temp=temp/8;
        ans=ans*10+lastdigit;
    }
    return ans;
}

string decimalToHexadecimal(int num){
    int temp = 1;
    string ans = " ";
    while(temp<=num){
        temp=temp*2;
    }
    temp=temp/2;

    while(temp>0)
    {
        int lastdigit=num/temp;
        num=num-lastdigit*temp;
        temp=temp/2;
        if(lastdigit<=9){
        ans=ans+to_string(lastdigit);
        }
        else{
            char c ='A'+lastdigit-10;
            ans.push_back(c);
        }
    }
    return ans;
}

int binaryTohexadecimal(string num){
    int ans=0;
    int temp=1;

    int s =num.size();
    for(int i=s-1;i>=0;i--){
        if(num[i]>='0' && num[i]<=9){
            ans = ans+temp*(num[i]-'0');
        }
        else if(num[i]>='A'&&num[i]<='F'){
            ans = ans+temp*(num[i]-'A'+10);
        }
        temp=temp*16;
    }
}
int binaryTooctal(int num){
    int ans=0;
    int temp=1;
    while(num>0){
        int y=num%10;
        ans = ans+temp*y;
        temp=temp*8;
        num=num/10;
    }
    return ans;
}
int binaryTodecimal(int num){
    int ans=0;
    int temp=1;
    while(num>0){
        int y=num%10;
        ans = ans+temp*y;
        temp=temp*2;
        num=num/10;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<decimalToBinary(n);
    return 0;
}

