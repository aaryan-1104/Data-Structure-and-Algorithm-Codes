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

node *removeNthFromEnd(node *head, int n)
{
    node *temp = head;

    int count = 0;

    while (temp != NULL)
    {

        count++;

        temp = temp->next;
    }

    int d = count - n;
    temp = head;
    if (count == 1)
    {
        return NULL;
    }
    if (count == n)
    {
        temp = temp->next;
        return temp;
    }
    int i = 0;
    node *nextn = head->next;
    while (i != d - 1)
    {
        temp = nextn;
        nextn = nextn->next;
        i++;
    }
    temp->next = nextn->next;

    return head;
}

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

int main()
{
    int n;
    cin >> n;
    cout << endl;
    int val;
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        cout << endl;
        insertAtTail(head, val);
    }
    int x;
    cin >> x;
    removeNthFromEnd(head, x);
}