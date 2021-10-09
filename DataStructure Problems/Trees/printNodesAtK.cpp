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
//* case 1: In this case k is reduced by 1 as it go on next level nodes in both right and left childnodes
void printSubTreeNodesAtK(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubTreeNodesAtK(root->left, k - 1);
    printSubTreeNodesAtK(root->right, k - 1);
}
// * *case2: In this case first the distance from root to the target node is calculated and then reducing that distance from total distance
// * *and then the same process happens as in "case1"

int printNodesAtK(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        printSubTreeNodesAtK(root, k);
        return 0;
    }
    //*Apply the same for left subTree to search the target node in it.
    int rootToTargetDistance = printNodesAtK(root->left, target, k);

    //?if it exits
    if (rootToTargetDistance != -1)
    {
        // *to check if root node is at k distance from the target node and print root data if it is.
        if (rootToTargetDistance + 1 == k)
        {
            cout << root->data << " ";
        }
        /**
         * *Else go for case 1 upto k-d-2 level  
         * todo: Where 2: 1 level for comming back to root from right + 1 level for going to left node  
         */
        else
        {
            printSubTreeNodesAtK(root->right, k - rootToTargetDistance - 2);
        }
        return rootToTargetDistance + 1;  //* return increemented distance if it not at present level in left subtree
    }

    //*Apply the same for right subTree to search the target node in it.
    int rootToTargetDistanceRight = printNodesAtK(root->right, target, k);

    //? to check the target node in right subTree if it exits or not
    if (rootToTargetDistanceRight != -1)
    {
        // *to check if root node is at k distance from the target node and print root data if it is.
        if (rootToTargetDistanceRight + 1 == k)
        {
            cout << root->data << " ";
        }

        /**
         * *Else go for case 1 upto k-d-2 level  
         * todo: Where 2: 1 level for comming back to root from right + 1 level for going to left node  
         */
        else
        {
            printSubTreeNodesAtK(root->left, k - rootToTargetDistanceRight - 2);
        } 
        return rootToTargetDistanceRight + 1;  //* return increemented distance if it not at present level in right subtree 
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

    printNodesAtK(root, root->left, 1);
}

/**
 * *
 * ?
 * !
 * todo
*/