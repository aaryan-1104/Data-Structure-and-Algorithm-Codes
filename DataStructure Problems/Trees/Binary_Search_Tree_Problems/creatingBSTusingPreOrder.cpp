#include <iostream>
using namespace std;
#include <vector>
#include<climits>

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

treeNode *constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    treeNode *root = NULL;
    if (key > min && key < max)
    {
        root = new treeNode(key);

        *preorderIdx= *preorderIdx+1;
        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}

void preOrder(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int preorder[] = {10,2,1,13,11};
    int preorderIdx = 0;
    int n = 5;

    treeNode *root1 = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    preOrder(root1);
}