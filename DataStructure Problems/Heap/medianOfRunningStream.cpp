#include <iostream>
using namespace std;
#include <vector>
#include <queue>

priority_queue<int, vector<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void insert(int val)
{
    if (minHeap.size() == maxHeap.size())
    {
        if (maxHeap.size() == 0)
        {
            maxHeap.push(val);
            return;
        }

        if (val < maxHeap.top())
        {
            maxHeap.push(val);
        }
        else
        {
            minHeap.push(val);
        }
    }

    else
    {
        if (maxHeap.size() > minHeap.size())
        {
            if (val < maxHeap.top())
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(val);
                minHeap.push(temp);
            }
            else
            {
                minHeap.push(val);
            }
        }

        else
        {
            if (val > minHeap.top())
            {
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(val);
                maxHeap.push(temp);
            }
            else
            {
                maxHeap.push(val);
            }
        }
    }
}

double findMedian()
{
    if (minHeap.size() == maxHeap.size())
    {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    else if (maxHeap.size() > minHeap.size())
    {
        return maxHeap.top();
    }
    else
    {
        return minHeap.top();
    }
}

int main()
{

    insert(10);
    insert(20);
    insert(25);
    insert(40);

    cout << findMedian() << " ";

}