#include <iostream>
using namespace std;

class node                          //constructing  node
{
public:
    int data;
    node *prev;
    node *next;
    node(int val)                   //constructor which will set data value which is provided by user and both pointers to null
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
void insertAtTail(node *&head, int val)     //inserting new node at the end of the list
{
    node *n = new node(val);
    if (head == NULL)                      //if the list is empty
    {
        head = n;
        return;
    }
    node *temp = head;                     //iterating to last node of the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *&head)                  //print the data of all nodes of the list
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
    if (temp == NULL)                           //if list is null
    {
        return;
    }
    if (n->data < temp->data)                   //if node data is less than data of first node
    {
        temp->prev = n;
        n->next = temp;
        head = n;
        return;
    }
    while (temp->next != NULL)                  //comparing next n-1 node's data in the list using current and next pointers
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
    if (temp->next == NULL)                     //if the node'data is greater than data of all nodes in list i.e.insert at end
    {
        temp->next = n;
    }
    return;
}

node* reverse(node* &head) {
    
    node* temp=head;
    //for 1 or 0 node present in list
    if(head==NULL||head->next==NULL){
        return head;
    }
    //for next n-1 node in list
    node* previous=NULL;
    node* nextn=temp->next;
    while(temp->next!=NULL){
      temp->next=previous;
      temp->prev=nextn;
      previous=temp;
      temp=nextn;
      nextn=nextn->next;  
    }

    //for last node of the list
    temp->next=previous;
    temp->prev=NULL;
    head=temp;
    return head;
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
    reverse(head);
    display(head);
    return 0;
}