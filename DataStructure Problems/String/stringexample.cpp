#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
   string s ="usddhfodfvsdvlsfdjbldjlj";
   int f[26];

   for(int i=0;i<26;i++){
       f[i]=0;
   }

   for(int i=0;i<s.size();i++){
       f[s[i]-'a']++;
   }

   char ans= 'a';
   int max=0;

   for(int i=0;i<26;i++){
       if(f[i]>max){
           max=f[i];
           ans=i+'a';
       }
   }

   cout<<"character"<<" "<<ans<<" "<<"max"<<" "<<max<<endl;


}