//Level wise traversal amd sum of the nodes at the Kth level

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
        right = NULL;
        left = NULL;
    }
};

int levelOrder(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<node *> q;                //making a queue to track node level wise
    q.push(root);                   //initializing the queue with root node with root and then NULL 
    q.push(NULL);                   //as root node is the only node at the 0th level of the tree

    int level = 0;
    int sum = 0;

    while (!q.empty())              //loop until queue is empty
    {

        node *Root = q.front();     //select the at the front of the queue

        q.pop();                    //after selecting node, remove it from the queue

        if (Root != NULL)
        {
            if (level == k)         //to calculate the sum of node at a particular given level
            {
                sum = sum + Root->data;
            }
            cout<<Root->data<<" ";  //traversing in tree level wise

            if (Root->left)         //if there is left child of a node then push into queue         
            {
                q.push(Root->left);
            }

            if (Root->right)        //if there is right child of a node then push into queue
            {
                q.push(Root->right);
            }
        }

        else if (!q.empty())        //if the node at the front of the queue is NULL but queue is not empty which means a level is completed
        {
            q.push(NULL);           //then push NULL in the queue to make it the starting of the next level
            level++;                //increment the level as it is explained in above comment
        }
    }
    return sum;                     //returning the sum of the node at the kth level
}

int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);
    // root->right->right->right = new node(9);

    cout<<levelOrder(root, 2);

    return 0;
}