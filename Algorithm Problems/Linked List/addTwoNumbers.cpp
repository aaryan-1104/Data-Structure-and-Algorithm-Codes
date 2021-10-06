#include <iostream>
using namespace std;
#include <algorithm>

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int value)
    {
        val = value;
        next = NULL;
    }
};

void insertAtTail(ListNode *&head, int val)
{
    ListNode *n = new ListNode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int c1 = 0;
    int c2 = 0;

    ListNode *h1 = l1;
    ListNode *h2 = l2;

    while (h1 != NULL)
    {
        c1++;
        h1 = h1->next;
    }

    while (h2 != NULL)
    {
        c2++;
        h2 = h2->next;
    }

    ListNode *head1 = l1;
    ListNode *head2 = l2;

    int carry = 0;
    int old;
    ListNode *oldLast;

    if (c1 < c2)
    {
        while (head1 != NULL)
        {

            int old = head2->val;

            head2->val = (head1->val + head2->val + carry) % 10;
            carry = (head1->val + old + carry) / 10;
// cout<<carry;
            oldLast = head2;
            head1 = head1->next;
            head2 = head2->next;
        }
        if (carry != 0)
        {
            while (head2 != NULL)
            {
                int old = head2->val;

                head2->val = (head2->val + carry) % 10;
                carry = (old + carry) / 10;
                oldLast = head2;
                head2 = head2->next;
            }
        }
        if (head2 == NULL && carry != 0)
        {
            ListNode *last = new ListNode(carry);
            oldLast->next = last;
        }
        return l2;
    }
    // int carry=0;
    
    
    while (head2 != NULL)
    {

        old = head1->val;

        head1->val = (head1->val + head2->val + carry) % 10;
        carry = (old + head2->val + carry) / 10;

        oldLast = head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (carry != 0)
    {
        while (head1 != NULL)
        {
            old = head1->val;

            head1->val = (head1->val + carry) % 10;
            carry = (old + carry) / 10;
            
            oldLast = head1;
            head1 = head1->next;
        }
    }
    if (head1 == NULL && carry != 0)
    {
        ListNode *last = new ListNode(carry);
        oldLast->next = last;
    }

    return l1;
}

void display(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int main()
{
    int n1, n2;
    int val;
    cin >> n1;
    cout << endl;
    ListNode *head1 = NULL;
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        // cout << endl;
        insertAtTail(head1, val);
    }
    cin >> n2;
    cout << endl;
    ListNode *head2 = NULL;
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        // cout << endl;
        insertAtTail(head2, val);
    }
    ListNode *result = addTwoNumbers(head1, head2);
    // display(head1);
    display(result);
    // display(head2);

    return 0;
}