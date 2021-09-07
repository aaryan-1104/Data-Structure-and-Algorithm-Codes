#include <iostream>
using namespace std;

class node
{
public:
    int data;
    int *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
class queue
{
    int *front;
    int *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {
        node *n = new node(x);
        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue is underflow";
            return;
        }
        node *toDelete = front;
        front = front->next;
        delete toDelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue is underflow";
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};
int main(){
        queue q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.pop();
        cout<<q.peek();
        cout<<q.empty();
}