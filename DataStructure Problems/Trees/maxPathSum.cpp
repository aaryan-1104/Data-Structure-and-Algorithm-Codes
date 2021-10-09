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
//*Stuff Function to find sum until the current node from bootom to top approach
int maxPathSumUntil(node* root,int &ans){
    if(root==NULL){
        return 0;
    }

    int left=(maxPathSumUntil(root->left,ans));     //* sum of left subTree nodes
    int right=(maxPathSumUntil(root->right,ans));   //* sum of right subTree nodes

    //?find 4 parameters and compare them for current node and compare max of 5 with the previous answer
    /**
     * *1.node value
     * *2.node+left
     * *3.node+right
     * *4.node+right+left
    */
    int nodemax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans=max(ans,nodemax);

    //* return max of 1, 2, 3 parameters which is to choose whether to consider right node or left node or none of them(i.e. node itself) 
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