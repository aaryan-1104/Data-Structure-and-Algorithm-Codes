#include <iostream>
using namespace std;
#include <queue>
#include <stack>
#include <vector>

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

void topView(node *root)
{

    if (root == NULL)
    {
        return;
    }
    //* This queue will maintain node and their horizontal distance in level traversal approach
    queue<pair<node *, int>> q;

    //* This Stack will maintain the nodes selcted for top view from left subTree
    //* and stack is used for purpose of storing data in reverse as first top view node will be the last node of left subTree and so on.
    stack<int> left;

    //* This Vector will maintain the nodes selcted for top view from right subTree
    vector<int> right;

    /**
     * *ht= horizontal distance from root node from the current node
     * *leftmin=  minimum horizontal distance of left child node of current node (value will be negative as it will decrement strat from 0)
     * *rightmax=  maximum horizontal distance of right child node of current node(value will be positve as will increment start from 0)
    */
    int ht = 0, leftmin = 0, rightmax = 0;

    q.push(make_pair(root, 0)); //* initialize with root with ht : 0

    while (!q.empty())
    {
        node *curr = q.front().first;
        int ht = q.front().second;

        if (ht < leftmin) //?If true, update left minimum distance and select node for left
        {
            leftmin = ht;
            left.push(curr->data);
        }
        if (ht > rightmax) //?If true, update right maximum distance and select node fro right
        {
            rightmax = ht;
            right.push_back(curr->data);
        }

        if (curr->left) //? If current Node's left node exists, push to queue and decrement horizontal distance
        {
            q.push(make_pair(curr->left, ht - 1));
        }
        if (curr->right) //? If current Node's right node exists, push to queue and increment horizontal distance
        {
            q.push(make_pair(curr->right, ht + 1));
        }
        q.pop(); //* Pop current node
    }

    //* Print left first
    while (!left.empty())
    {
        cout << left.top() << " ";
        left.pop();
    }

    //* then print root data
    cout << root->data << " ";

    //* then print right
    for (auto i : right)
    {
        cout << i << " ";
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->right->right = new node(6);

    /**
     * *          1
     * *         / \
     * *        2   3
     * *         \
     * *          4
     * *           \
     * *            5
     * *             \
     * *              6
     * 
     * todo: topView = 2 1 3 6
    */

    topView(root);

    cout << endl;
    return 0;
}