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

void updateNodeData(node* root){
    if(root==NULL){
        return;
    }

    updateNodeData(root->left);
    updateNodeData(root->right);

    if(root->left!=NULL){
        root->data=root->data+root->left->data;
    }
    
    if(root->right!=NULL){
        root->data=root->data+root->right->data;
    }
}

void preOrder(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    
    node *root = new node(5);

    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);

    preOrder(root);
    cout<<endl<<endl;
    updateNodeData(root);
    preOrder(root);
}