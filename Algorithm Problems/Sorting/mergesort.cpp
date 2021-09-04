#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// void combine(int nums[], int start, int mid, int end)
// {
//     int i = 0;
//     int k = start;
//     int j = 0;

//     int n1 = mid - start + 1;
//     int n2 = end - mid;
//     int a[n1];
//     int b[n2];

//     for (int i = 0; i < n1; i++)
//     {
//         a[i] = nums[start + i];
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         b[i] = nums[mid + 1 + i];
//     }

//     while (i < n1 && j < n2)
//     {
//         if (a[i] <= b[j])
//         {
//             nums[k] = a[i];
//             i++;
//         }
//         else
//         {
//             nums[k] = b[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1)
//     {
//         nums[k] = a[i];
//         i++;
//         k++;
//     }
//     while (j < n2)
//     {
//         nums[k] = b[j];
//         j++;
//         k++;
//     }
    
// }
// void mergeSort(int nums[], int start, int end)
// {
//     int mid;
//     if (start >= end)
//     {
//         return;
//     }

//     mid = (start + end) / 2;
//     mergeSort(nums, start, mid);
//     mergeSort(nums, mid + 1, end);
//     combine(nums, start, mid, end);
// }



  void MergeSortedIntervals(vector<int>& v, int s, int m, int e) {
  vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			i++;
		}
		else {
			temp.push_back(v[j]);
			j++;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		i++;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		j++;
	}

	for (int i = s; i <= e; i++)
		v[i] = temp[i - s];

}


// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}
int main()
{
    // int nums[500];
    vector<int> nums;
    int n;
    int val;
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        cout << endl;
        // nums[i] = val;
        nums.push_back(val);
    }

    MergeSort(nums,0,nums.size()-1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i];
    }
    

    return 0;
}