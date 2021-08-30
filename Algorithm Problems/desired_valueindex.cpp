#include <iostream>
using namespace std;
#include <vector>
int binarysearch(vector<int> &nums, int target)
{
    int low = 0;
    int high = (nums.size())-1;
    int mid;
    int position;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
// optimized solution
// int searchInsert(vector<int>& nums, int target) {
//         return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
//     }
int main()
{
    vector<int> nums = {0};
    int n;
    cin >> n;
    cout << endl;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
        cout << endl;
    }
    int key;
    cin >> key;
    cout << endl;
    cout << (binarysearch(nums, key)) - 1;

    return 0;
}
