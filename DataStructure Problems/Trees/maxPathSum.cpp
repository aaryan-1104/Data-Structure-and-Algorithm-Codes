#include <iostream>
using namespace std;
#include <queue>
#include<climits>

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

int maxPathSumUntil(node* root,int &ans){
    if(root==NULL){
        return 0;
    }

    int left=(maxPathSumUntil(root->left,ans));
    int right=(maxPathSumUntil(root->right,ans));

    int nodemax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans=max(ans,nodemax);
    int singlePathMax=max(root->data,max(root->data+left,root->data+right));

    return singlePathMax;
}

int maxSumPath(node* root){
    int ans=INT_MIN;

    maxPathSumUntil(root,ans);

    return ans;
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

    cout<<maxSumPath(root);
}