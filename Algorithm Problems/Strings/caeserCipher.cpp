// #include<iostream>
// using namespace std;
// #include<string>
// void caeserCipher(int n,string s, int k){  
//     for(int i=0;i<s.length();i++){
//         if(s[i]>=65 && s[i]<=90){
//             if((s[i]+k>90)&&(s[i]+k<=116)){
//                 s[i]=s[i]+k-26;
//             }
//             else{
//                 s[i]=s[i]+k;
//             }   
//         }
//         else if(s[i]>=97 && s[i]<=122){
//             if(s[i]+k>122){
//                 s[i]=s[i]+k-26;
//             }
//             else{
//                 s[i]=s[i]+k;
//             } 
//         }
//         else{
//             s[i]=s[i];
//         }
//     }
//     cout<<s;
// }

// int main(){
//     int n;
//     cin>>n;
   
//     string s;
//     cin>>s;

//     int k;
//     cin>>k;


//     caeserCipher(n,s,k);

//     return 0;
// }

// ekdum gadhe jaisa sawaal


#include<iostream>
using namespace std;
#include<string>
void caeserCipher(int n,string s, int k){  
    for(int i=0;i<s.length();i++){
        if(k>26){
            k=k%26;
        }
        if(s[i]>=65 && s[i]<=90){
            if(s[i]+k>90){
                s[i]=s[i]+k-26;
            }
            else{
                s[i]=s[i]+k;
            }   
        }
        else if(s[i]>=97 && s[i]<=122){
            if(s[i]+k>122){
                s[i]=s[i]+k-26;
            }
            else{
                s[i]=s[i]+k;
            } 
        }
        else{
            s[i]=s[i];
        }
    }
    cout<<s;
}

int main(){
    int n;
    cin>>n;
   
    string s;
    cin>>s;

    int k;
    cin>>k;


    caeserCipher(n,s,k);

    return 0;
}


// #include<iostream>
// using namespace std;
// #include<string>
// void caeserCipher(int n,string s, int k){  
//     int x;
//     x=x%26;
//     for(int i=0;i<s.length();i++){
//         if(s[i]>='A' && s[i]<='Z'){
//             if((s[i]+k>'Z')&&(s[i]+k<=116)){
//             s[i]=s[i]+k-26;
//             }
//             else if((s[i]+k>'Z')&&(s[i]+k>116)){
//                 s[i]=s[i]+x;
//             }
//             else{
//                 s[i]=s[i]+k;
//             }   
//         }
//         else if(s[i]>='a' && s[i]<='z'){
//             if((s[i]+k>'z')&&(s[i]+k<=148)){
//             s[i]=s[i]+k-26;
//             }
//             else if((s[i]+k>'z')&&(s[i]+k>148)){
//                 s[i]=s[i]+x; 
//             }
//             else{
//                 s[i]=s[i]+k;
//             } 
//         }
//         else{
//             s[i]=s[i];
//         }
//     }
//     cout<<s;
// }

// int main(){
//     int n;
//     cin>>n;
   
//     string s;
//     cin>>s;

//     int k;
//     cin>>k;

//     caeserCipher(n,s,k);
//     return 0;
// }