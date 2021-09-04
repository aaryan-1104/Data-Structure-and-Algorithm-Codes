/*
s1.append(s2)
s1.compare(s2)
s.clear()
s1.empty()???\
s1.find("string word")
s1.delete(starting index, no. "character to be deleted")
s1.insert(starting index at, "string  to be inserted")
s1.size(),s1.length;
//s1.substr(starting index, no. of charcter)
stoi(s1)   //to convert string to integer
to_string(s1)  //to convert integer to string
*/

#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    string s= "sfogwlfihdudasjvkxcmbvi";
    

    sort(s.begin(),s.end());

    cout<<s<<endl;


     string s1= "sfogwlfihdudasjvkxcmbvi";
    //convert to upper case

   /* for(int i=0;i<s1.size();i++){
        if(s1[i]>='a'&& s1[i]<='z'){
            s1[i]-=32;
        }
    }
    cout<<s1;

    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A'&& s1[i]<='Z'){
            s1[i]+=32;
        }
    }
    */
   transform(s1.begin(), s1.end(), s1.begin(), ::toupper);   //tolower
   cout<<s1<<endl;

    string s2="487233572573984";
    sort(s2.begin(), s2.end(), greater<int>());  /* greater is used for descending order*/ 

    cout<<s2;
}
