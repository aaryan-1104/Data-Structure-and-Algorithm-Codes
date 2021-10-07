#include <iostream>
using namespace std;
#include <vector>
#include <stack>

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

bool isIdentical(treeNode *root1, treeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    else
    {
        bool a = (root1->data == root2->data);
        bool b = isIdentical(root1->left, root2->left);
        bool c = isIdentical(root1->right, root2->right);

        if (a && b && c)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    treeNode *root1 = new treeNode(2);
    root1->left = new treeNode(1);
    root1->right = new treeNode(3);

    treeNode *root2 = new treeNode(2);
    root2->left = new treeNode(1);
    root2->right = new treeNode(3);

    if(isIdentical(root1, root2)){
        cout<<"BSTs are identical!";
    }
    else{
        cout<<"BSTs are not identical!";
    }
}