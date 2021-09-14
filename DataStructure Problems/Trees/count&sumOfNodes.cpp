#include <iostream>
using namespace std;
#include <queue>

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int count_sumOfNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return count_sumOfNodes(root->left) + count_sumOfNodes(root->right) + root->data;
    ; //to calculate the sum of the nodes
    return count_sumOfNodes(root->left) + count_sumOfNodes(root->right) + 1; //to count the no. of the nodes
}

int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << count_sumOfNodes(root);
}