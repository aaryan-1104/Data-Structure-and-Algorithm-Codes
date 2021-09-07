#include <iostream>
using namespace std;
#define N 200
class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[N];
        front = -1;
        back = -1;
    }

    void push(int x)
    {
        if (front == N - 1)
        {
            cout << "Queue overflow";
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue underflow";
            return;
        }
        front++;
    }

    int peep()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue overflow";
            return;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout << q.peep();
    cout << q.empty();
}