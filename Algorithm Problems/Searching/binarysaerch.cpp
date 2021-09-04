//binary search
//search_in_unknown_size_array
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int binarysearch(vector<int> &nums, int target)
{
    int low = 0;
    int high = (nums.size())-1;
    while (low <=high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums={0};
    int n;
    cin >> n;
    cout << endl;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
        cout<<endl;
    }
    int key;
    cin >> key;
    cout << endl;
    cout<<(binarysearch(nums, key))-1;

    return 0;
}
