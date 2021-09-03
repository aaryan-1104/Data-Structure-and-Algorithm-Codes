#include <iostream>
using namespace std;
#include <vector>
void reverse(vector<char>& s) {
        int l=s.size();
        int low=0;
        int high=l-1;
        while(low<=high){
            int temp=s[low];
            s[low]=s[high];
            s[high]=temp;
            low++;
            high--;
        }
        
}

int main(){
    int n;
    vector<char> s;
    cin >> n;
    char val;
    for (int i = 0; i < n; ++i)
    {
        cin>>val;
        s.push_back(val);
        cout << endl;
    }
    reverse(s);
    return 0;
}