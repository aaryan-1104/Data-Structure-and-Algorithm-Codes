#include <iostream>
using namespace std;
#include <stack>
#define N 200
class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Empty!!";
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int toDelete = s2.top();
        s2.pop();
        cout << toDelete;
    }

    int peek()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Empty!!";
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
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
    cout << q.peek();
    q.pop();
    q.pop();
    cout << q.empty();
}
