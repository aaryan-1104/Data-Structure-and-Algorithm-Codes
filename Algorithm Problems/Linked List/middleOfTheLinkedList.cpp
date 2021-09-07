#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

node *middleNode(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    int h = count / 2;
    if (count % 2 != 0)
    {
        while (count != h + 1)
        {
            temp = temp->next;
            count--;
        }
    }
    else
    {
        while (count != h)
        {
            temp = temp->next;
            count--;
        }
    }
    return temp;
}