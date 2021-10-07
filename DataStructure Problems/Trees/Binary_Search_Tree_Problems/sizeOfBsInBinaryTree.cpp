#include <iostream>
#include<climits>
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

Info largestBstInBT(treeNode* root){
    if(root==NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    if(root->left==NULL&& root->right==NULL){
        return {1, root->data, root->data, 1,true};
    }

    Info leftinfo= largestBstInBT(root->left);
    Info rightinfo= largestBstInBT(root->right);

    Info curr;
    curr.size= (1+ leftinfo.size + rightinfo.size);

    if(leftinfo.isBst&& rightinfo.isBst&& leftinfo.max<root->data&& rightinfo.min>root->data){

        curr.min=min(root->data,min(leftinfo.min,rightinfo.min));
        curr.min=max(root->data,max(leftinfo.max,rightinfo.max));

        curr.ans=curr.size;
        curr.isBst=true;

        return curr;
    }

    curr.ans=max(leftinfo.ans,rightinfo.ans);
    curr.isBst=false;
    return curr;
}

int main(){
    treeNode* root=new treeNode(15);

    root->left=new treeNode(20);
    root->right=new treeNode(30);
    root->left->left=new treeNode(5);
    cout<<largestBstInBT(root).ans<<" ";
}