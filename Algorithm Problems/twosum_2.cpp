#include <iostream>
using namespace std;
#include <vector>

vector<int> twoSum(vector<int>& numbers, int target){
            int start = 0, end = (numbers.size() - 1);
            while (start < end)
            {
                if ((numbers[start] + numbers[end]) > target){ 
                    end--;
                }
                else if ((numbers[start] + numbers[end]) < target){
                    start++;
                }
                else {
                    return {start+1, end+1};
                }
            }
            return {};
    }


    int main()
{

    int n;
    vector<int> nums;
    cin >> n;
    cout << endl;
    int target;
    cin >> target;
    cout << endl;
    int val;
    for (int i = 0; i < n; ++i)
    {
        cin>>val;
        nums.push_back(val);
        cout << endl;
    }
    
    vector<int> c=twoSum(nums,target);
    cout<<c[0]<<" "<<c[1];
    return 0;
}