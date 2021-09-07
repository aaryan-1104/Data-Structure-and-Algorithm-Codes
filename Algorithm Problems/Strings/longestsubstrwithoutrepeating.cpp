#include <iostream>
using namespace std;
#include <string>

int lengthOfLongestSubstring(string s)
{
    int arr[127];
    int len;
    int sum = 0;

    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i]] = 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        len = 0;
        int j = i;

        while (j < s.length())
        {
            arr[s[j]]++;
            if (arr[s[j]] > 1)
            {
                for (int i = 0; i <=j; i++)
                {
                    arr[s[i]] = 0;
                }
                break;
            }

            len++;
            j++;
        }
        sum = max(sum, len);
    }
    return sum;
}

// bool isDistinct(char k,arr[]){
//     if(k)
// }

int lengthOfLongestSubstringRecursion(string s){

}

int main()
{
    string s = 
    // "abcabcbb";
// "bbbbb";
"pwwkew";
// "";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}