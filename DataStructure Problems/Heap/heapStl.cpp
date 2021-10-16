#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main()
{
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(5);
    cout << "MaxHeap Top Element " << maxHeap.top() << endl;

    maxHeap.pop();

    cout << "MaxHeap Top Element after Pop operation " << maxHeap.top() << endl;

    minHeap.push(1);
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(5);
    cout << "MinHeap Top Element " << minHeap.top() << endl;

    minHeap.pop();

    cout << "MinHeap Top Element after Pop operation " << minHeap.top() << endl;
}