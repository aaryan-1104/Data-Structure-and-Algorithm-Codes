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

int diameterOfTree(node *root, int *height)
{

    if (root == NULL)           //base condition
    {
        *height = 0;
        return 0;
    }

    int lh = 0;
    int rh = 0;
    int ldia = diameterOfTree(root->left, &lh);    //to calculate diameter(height) of left subtree
    int rdia = diameterOfTree(root->right, &rh);   //to calculate diameter(height) of right subtree 
    int currdia = rh + lh + 1;                     //to calculate total diameter by adding diameter of left(lh-height) and right(rh-height) subtree along with root node(1)
    *height = max(rh, lh) + 1;                     //height of the tree
    return max(currdia, max(ldia, rdia));          //returning maximum diameter from maximum of left or right and diamter including root
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

    int height=0;
    cout<<diameterOfTree(root,&height);
}