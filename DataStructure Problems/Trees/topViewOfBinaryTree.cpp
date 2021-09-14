#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void topView(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    if (root->right != NULL)
    {
        topView(root->right);
    }
    else{
    topView(root->left);
    }
}

int main()
{
    node *root = new node(1);

    // root->left = new node(2);
    root->right = new node(2);

    // root->left->left = new node(4);
    // root->left->right = new node(5);

    // root->right->left = new node(6);
    root->right->right = new node(5);

    root->right->right->right = new node(6);

    root->right->right->left = new node(3);
    root->right->right->left->right = new node(4);

    // root->left->left->left = new node(8);
    // root->right->right->right = new node(14);


    node* root1=new node(1);
    // int val;
    root1->left=new node(2);
    root1->right=new node(3);
    root1->left->left=new node(4);
    root1->left->right=new node(5);
    root1->right->left=new node(6);
    root1->right->right=new node(7);

    topView(root1);
}