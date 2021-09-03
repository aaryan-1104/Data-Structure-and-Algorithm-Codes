#include <iostream>
using namespace std;
#include <string>
void reverseString(vector<char>& s) {
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
    vector<char> nums;
    cin >> n;
    cout << endl;
    int val;
    for (int i = 0; i < n; ++i)
    {
        cin>>val;
        nums.push_back(val);
        cout << endl;
    }
    reverse(nums,target);
    retrun 0;
}