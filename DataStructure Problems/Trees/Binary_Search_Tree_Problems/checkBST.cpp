#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class treeNode
{
public:
    int data;
    treeNode *left;
    treeNode *right;

    treeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool checkBST(treeNode *root, treeNode *min = NULL, treeNode *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }

    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftbst = checkBST(root->left, min, root);
    bool rightbst = checkBST(root->right, root, max);

    return leftbst and rightbst;
}

int main()
{
    int a1;cin>>a1;
    int a2;cin>>a2;
    int a3;cin>>a3;

    treeNode *root = new treeNode(a1);
    root->left = new treeNode(a2);
    root->right = new treeNode(a3);

    if (checkBST(root, NULL, NULL))
    {
        cout << "Valid BST!";
    }
    else
    {
        cout << "Invalid BST!";
    }
}