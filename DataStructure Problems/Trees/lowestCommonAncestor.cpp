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

// void preOrder(node* root){
//     if(root==NULL){
//         return;
//     }

//     cout<<root->data<<" ";
//     preOrder(root->left);
//     preOrder(root->right);
// }

//! LCA: the lowest common ancestor of two nodes
node *LCA(node *root, int n1, int n2)
{

    if(root==NULL){
        return NULL;
    }
    //* if one of two target nodes is the root node then LCA will the root node itself
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    //?Search for LCA in left and Right subTree
    node *leftlca = LCA(root->left, n1, n2);
    node *rightlca = LCA(root->right, n1, n2);

    //* If both n1 and n2 are found in left and right subTree then root node will the LCA
    if (leftlca && rightlca)
    {
        return root;
    }
    //* If But both left and right condition get false then check for LCA in left else in right 
    if (leftlca != NULL)
    {
        return leftlca;
    }
    return rightlca;
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


    node *lca = LCA(root, 2,9);

    cout << lca->data;
}