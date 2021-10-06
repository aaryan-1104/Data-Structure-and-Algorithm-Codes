#include <iostream>
using namespace std;
#include <algorithm>

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
treeNode *insertBst(treeNode *root, int value)
{
    if (root == NULL)
    {
        return new treeNode(value);
    }
    if (value < root->data)
    {
        root->left = insertBst(root->left, value);
    }
    else
    {
        root->right = insertBst(root->right, value);
    }
    return root;
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

treeNode *search(treeNode *root, int key)
{
    if(root==NULL){
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return search(root->left,key);
    }

    return search(root->right,key);
}
//inOrderSuccessor is the left-most node from from right sub-tree of the node(to be deleted) 
treeNode* inOrderSuccessor(treeNode* root){
    treeNode* temp=root;
    while( temp&& temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

treeNode* deleteBST(treeNode* root, int key){
    if(key<root->data){
        root->left=deleteBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteBST(root->right,key);
    }
    else{

    //case:1&2 - To be deleted node has one(right) or zero child(leafNode) 
        if(root->left==NULL){
            treeNode* curr=root->right;
            free(root);
            return curr;
        }

    //case:1&2 - To be deleted node has one(left) or zero child(leafNode) 
        if(root->right==NULL){
            treeNode* curr=root->left;
            free(root);
            return curr;
        }
    //case:3 - To be deleted node has both child 
        treeNode* curr=inOrderSuccessor(root->right);   //find inOrderSuccessor
        root->data=curr->data;                          //replace the data with inOrderSuccessor
        root->right=deleteBST(root->right,curr->data);  //recursive call for deleting the node until it doesn't fall under case 1 or 2
    }
    return root;
}

int main()
{
    treeNode *root = new treeNode(5);
    insertBst(root, 4);
    insertBst(root, 1);
    insertBst(root, 3);
    insertBst(root, 2);
    insertBst(root, 6);

    //Inorder traversal of BST presents the sorted data of the nodes 
    cout<<"Inorder BST"<<endl;
    inOrder(root);

    if(search(root,5)==NULL){
        cout<<endl<<endl<<"Key doesn't exist!"<<endl;
    }
    else{
        cout<<endl<<endl<<"Key exist!"<<endl;
    }

    deleteBST(root,6);

    cout<<endl<<"After deleting the node"<<endl; 
    inOrder(root);

}