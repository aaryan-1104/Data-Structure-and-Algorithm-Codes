#include <iostream>
using namespace std;
#include <vector>

void moveZeroes(vector<int> &nums)
{

    int zeroes = 0;
    int size = nums.size();
    int i = 0;
    while (i < size)
    {
        if (nums[i] != 0)
        {
            nums[zeroes] = nums[i];
            i++;
            zeroes++;
        }
        else
        {
            i++;
        }
    }
    while (zeroes != size)
    {
        nums[zeroes] = 0;
        zeroes++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}
int main()
{
    int n;
    vector<int> nums;
    cin >> n;
    cout << endl;
    int val;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        nums.push_back(val);
        cout << endl;
    }

    moveZeroes(nums);

    return 0;
}