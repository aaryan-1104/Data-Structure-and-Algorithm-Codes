#include <iostream>
using namespace std;
#include <vector>
//optimized solution
void swap(vector<int>& nums,int start, int end){
    while(start<=end){
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
    
}

void rotate1(vector<int>& nums, int k)     //Optimized solution for for any no. of input 
{
    int size = nums.size();
    k=k%size;

    swap(nums,0,size-1);
    swap(nums,0,k-1);
    swap(nums,k,size-1);
}

//unoptimzed solution;  timeout error possible and suittable for less range of input
void rotate(vector<int>& nums, int k)    
{
    int size = nums.size();
    int j = 0;
    while (j <(k>size?k+1:size-k))
    {
        int first = nums[0];
        for (int i = 1; i <size; i++)
        {   
            nums[i-1]=nums[i];
        }
        nums[size-1]=first;
        j++;
    }
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
    // rotate(nums, k);
    rotate1(nums,k);

    for (int i = 0; i <nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }

}