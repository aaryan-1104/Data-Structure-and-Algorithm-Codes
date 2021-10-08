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
        left = NULL;
        right = NULL;
    }
};

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
    ;
}

bool checkHBT(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (!(checkHBT(root->left)))
    {
        return false;
    }

    if (!(checkHBT(root->left)))
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBalanced(node *root, int *height)
{

    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;

    if (!(isBalanced(root->left, &lh)))
    {
        return false;
    }

    if (!(isBalanced(root->right, &rh)))
    {
        return false;
    }

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->left->left=new node(3);
    // root->right = new node(4);

    int height = 0;

    if (isBalanced(root, &height))
    {
        cout << " balanced tree";
    }
    else
    {
        cout << " unbalaced tree";
    }
}