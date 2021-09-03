#include <iostream>
using namespace std;
#include <string>


void reverseWord(string s){
        int low=0;
        int high;
        
        for(int i=0;i<=(s.length());i++){
            if(s[i]==' '||s[i]=='\0'){
                high=i-1;
                while(low<=high){
                    char temp=s[low];
                    s[low]=s[high];
                    s[high]=temp;
                    low++;
                    high--;
                }
            low=i+1;
            }
        }
        for(int i=0;i<s.length();i++){
            cout<<s[i];
        }
}

int main(){
    int n;
    string s="my name is aryan";
    // cin >> n;
    // char val;
    // for (int i = 0; i < n; ++i)
    // {
    //     cin>>val;
    //     s.push_back(val);
    //     cout << endl;
    // }
    reverseWord(s);
    return 0;
}