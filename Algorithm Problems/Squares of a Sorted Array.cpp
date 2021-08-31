#include <iostream>
using namespace std;
#include <vector>


// the interval from [s to m] and [m+1 to e] in v are sorted
// the function will merge both of these intervals
// such the interval from [s to e] in v becomes sorted
void MergeSortedIntervals(vector<int>& v, int s, int mid, int e) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;

	int i, j;
	i = s;
	j = mid + 1;

	while (i <= mid && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			i++;
		}
		else {
			temp.push_back(v[j]);
			j++;
		}

	}

	while (i <= mid) {
		temp.push_back(v[i]);
		i++;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		j++;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		MergeSort(v, s, mid);
		MergeSort(v, mid + 1, e);
		MergeSortedIntervals(v, s, mid, e);
	}
}

int main() {

	int n;
	vector<int> v;
	v=vector<int>(n);
	cin >> n;
	cout<<endl;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
        cout<<endl;
	}
    for(int i=0;i<n;i++){
        v[i]=v[i]*v[i];
    }
	MergeSort(v, 0, n - 1);

	cout << "\nVector Obtained After Sorting: ";
	for (int i = 0; i < n; ++i) {
		cout << v[i] << ' ';
	}
}