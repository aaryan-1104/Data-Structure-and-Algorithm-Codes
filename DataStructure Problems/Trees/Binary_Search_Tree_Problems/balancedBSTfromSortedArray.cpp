#include <iostream>
using namespace std;
#include <vector>

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

treeNode *balancedBST(int sorted[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;

    treeNode *root = new treeNode(sorted[mid]);
    root->left = balancedBST(sorted, start, mid - 1);
    root->right = balancedBST(sorted, mid + 1, end);

    return root;
}

int main()
{

    int sorted[] = {10, 20, 30, 40, 50};
    treeNode *root = balancedBST(sorted, 0, 4);
    preOrder(root);
}