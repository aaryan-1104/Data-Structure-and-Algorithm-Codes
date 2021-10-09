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
    //? check if root is NULL or left node and right node ids NULL
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    //?if left node exist then flatten the left subtree
    if (root->left != NULL)
    {
        flatten(root->left);

        node *temp = root->right;   //* keep the right subTree in temp variable
        root->right = root->left;   //* make left subTree the right SubTree
        root->left = NULL;          //* make left subTree to NULL

        node *oldleft = root->right;//* assign nnewly made right Subtree to a variable "oldLeft"

        //? Serach for the tail of "oldLeft"
        while (oldleft->right!= NULL)
        {
            oldleft = oldleft->right;
        }
        oldleft->right = temp;//* join the original right subTree(temp) at the tail(oldLeft->right) of the newly made right subTree
    }

    flatten(root->right);//* flatten the right Subtree
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