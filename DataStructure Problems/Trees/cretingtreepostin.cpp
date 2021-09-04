#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void printinorder(node* root){
    if(root==NULL){
        return;
    }
   printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);

}

int nsearch(int inorder[],int start, int end,int curr){
    for (int i = start; i <=end; i++)
    {
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node* maketree(int preorder[],int inorder[],int start,int end){
    if(start>end){
        return NULL;
    }
    static int index=4;
    int curr=preorder[index];
    index--;
    node* root=new node(curr);
    if(start==end){
        return root;
    }
    int position=nsearch(inorder,start,end,curr);
    root->right=maketree(preorder,inorder,position+1,end);
    root->left=maketree(preorder,inorder,start,position-1);

    return root;
}

int main(){
    int preorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    node* root=maketree(preorder,inorder,0,4);
    printinorder(root);

    return 0;
}