#include <iostream>
using namespace std;
#include <vector>
void rotate(vector<int> nums, int k)
{
    int size = nums.size();
    int j = 0;
    while (j <(k>size?k+1:size-k))
    {
        int first = nums[0];
        for (int i = 1; i <size; i++)
        {   
            int c=nums[i];
            cout<<c;
            nums[i-1]=nums[i];
            cout<<"updated"<<nums[i-1]<<endl;
        }
        nums[size-1]=first;
        cout<<"next"<<nums[size-1]<<endl;
        j++;
// cout<<k;
    }
    // cout<<size<<endl;
    for (int i = 0; i <size; i++)
    {
        cout << nums[i] << ' ';
    }
}
int main()
{

    int n;
    vector<int> nums;
    cin >> n;
    cout << endl;
    int k;
    cin >> k;
    cout << endl;
    int val;
    for (int i = 0; i < n; ++i)
    {
        cin>>val;
        nums.push_back(val);
        cout << endl;
    }
    // cout<<nums.size();
    rotate(nums, k);

}