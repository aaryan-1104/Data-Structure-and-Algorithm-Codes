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

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void flatten(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->left != NULL)
    {
        flatten(root->left);

        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *oldleft = root->right;

        while (oldleft->right!= NULL)
        {
            oldleft = oldleft->right;
        }
        oldleft->right = temp;
    }

    flatten(root->right);
}

int main()
{

    node *root = new node(5);

    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(8);
    root->right->right = new node(9);

    inOrder(root);
    cout<<endl<<endl;
    flatten(root);
    inOrder(root);
}