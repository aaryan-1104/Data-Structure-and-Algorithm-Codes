#include <iostream>
#include <climits>
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

class Info
{
public:
    int size;
    int max;
    int min;
    int ans;
    bool isBst;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointer(treeNode *root, treeNode **first, treeNode **mid, treeNode **last, treeNode **prev)
{
    if (root == NULL)
    {
        return;
    }

    calcPointer(root->left, first, mid, last, prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointer(root->right, first, mid, last, prev);
}
void restoreBst(treeNode *root)
{
    treeNode *first, *mid, *last, *prev;
    first = NULL;
    last = NULL;
    last = NULL;
    prev = NULL;

    calcPointer(root, &first, &mid, &last, &prev);

    //case1
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }

    else if (first && mid)
    {
        swap(&(first->data), &(first->data));
    }
}

void inOrder(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    treeNode *root = new treeNode(6);
    root->left = new treeNode(9);
    root->right = new treeNode(3);
    root->left->left = new treeNode(1);
    root->left->right = new treeNode(4);
    root->right->right = new treeNode(13);
        /*
                    6
                   / \
                  9   3
                 / \   \
                1   4   13
        */
    inOrder(root);
    cout<<endl;

    restoreBst(root);

    inOrder(root);
}