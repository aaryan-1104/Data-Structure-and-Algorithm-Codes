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

void printSubTreeNodesAtK(node* root, int k){
    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printSubTreeNodesAtK(root->left,k-1);
    printSubTreeNodesAtK(root->right,k-1);
    
}
//* case 2

int printNodesAtK(node* root, node* target, int k){
    if(root==NULL){
        return -1;
    }

    if(root==target){
        printSubTreeNodesAtK(root,k);
        return 0;
    }

    int rootToTargetDistance=printNodesAtK(root->left,target,k);

    if(rootToTargetDistance!=-1){
        if(rootToTargetDistance+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubTreeNodesAtK(root->right, k-rootToTargetDistance-2);
        }
    return rootToTargetDistance+1;
    }

    
    int rootToTargetDistanceRight=printNodesAtK(root->right,target,k);

    if(rootToTargetDistanceRight!=-1){
        if(rootToTargetDistance+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSubTreeNodesAtK(root->left, k-rootToTargetDistanceRight-2);
        }
    return rootToTargetDistanceRight+1;
    }
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

    printNodesAtK(root,root->left,1);

}