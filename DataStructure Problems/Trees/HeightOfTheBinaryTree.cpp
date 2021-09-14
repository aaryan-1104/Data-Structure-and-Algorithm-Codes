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

int height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lh = height(root->left);        //to caluclate height of the left subtree  
    int rh = height(root->right);       //to caluclate height of the right subtree 
    return max(lh, rh) + 1;             //after calculating left and right subtree's height;  take max height among the both side along with adding 1 which willbe the root node
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
    root->right->right->right = new node(9);

    // root->left->left->left = new node(8);
    // root->right->right->right = new node(14);

    cout << height(root);
}