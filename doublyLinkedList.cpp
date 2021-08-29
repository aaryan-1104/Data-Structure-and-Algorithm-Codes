#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int val)
    {
        data = val;
        prev = NULL;
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
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void addNodeToSortedList(node *&head, int val)  //Assuming that the given DoublyLinkedList is sorted already 
{                                               //and that DoublyLinkedList remain sorted after insertion of a new node
    node* n = new node(val);                     
    node *temp = head;
    if (temp == NULL)
    {
        return;
    }
    if (n->data < temp->data)
    {
        temp->prev = n;
        n->next = temp;
        head = n;
        return;
    }
    while (temp->next != NULL)
    {
        if (n->data < temp->next->data)
        {
            n->next = temp->next;
            n->prev = temp;
            temp->next = n;
            temp->next->prev = n;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp->next == NULL)
    {
        temp->next = n;
    }
    return;
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
    display(head);
    return 0;
}