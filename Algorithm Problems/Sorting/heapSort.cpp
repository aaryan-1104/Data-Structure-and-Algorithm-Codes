#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void heapify(vector<int> &v, int i, int n)
{

    int currIdx = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //? If left is greater than current assign left to currIdx
    if (left < n && v[left] > v[currIdx])
    {
        currIdx = left;
    }

    //? If right is greater than current assign right to currIdx
    if (right < n && v[right] > v[currIdx])
    {
        currIdx = right;
    }

    //? If currIdx is changed to left or right due inequality then swap changed currIdx value with last index value and call heapify recursively 
    if (currIdx != i)
    {
        swap(v[i], v[currIdx]);

        heapify(v, currIdx, n);
    }
}

void heapSort(vector<int> &v)
{
    int n = v.size();


/**
 * *apply heapify in order to make max heap from element stored stored in normal tree order i.e. If "i" is a node then 
 * *i*2+1 is considered the left child and i*2+2 is considered the right child.

 * * i : It is the starting index; i.e. last non leaf element. And as more element will come i's value will decrease 
 * * until all elemnt are stored in heap manner.
 * * n = size of array 
*/
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, i, n);
    }

/** 
 * * *apply heapify after swapping first element(max element) with last element reduce the size of vector by 1
 * * as it is get stored in sorted manner.
 
 * * 0 = starting index of array
 * * i = size of array 
*/
    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);

        heapify(v, 0, i); 
    }
}

int main()
{

    int n;
    cin >> n;
    cout<<endl;
    vector<int> v(n);
    
    for (auto &i : v)
    {
        cin >> i;
    }

    heapSort(v);

    for (auto i : v)
    {
        cout << i << " ";
    }
}