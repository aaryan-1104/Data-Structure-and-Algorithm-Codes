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

node *LCA(node *root, int n1, int n2)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *leftlca = LCA(root->left, n1, n2);
    node *rightlca = LCA(root->right, n1, n2);

    if (leftlca != NULL && rightlca != NULL)
    {
        return root;
    }

    if (leftlca == NULL && rightlca == NULL)
    {
        return NULL;
    }

    if (leftlca != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findDistance(node *root, int key, int distance)
{
    if (root == NULL)
    {
        return -1;
    }

    //* if key is find on root data then return the current distance
    if (root->data == key)
    {
        return distance;
    }

    //?search for key in left subTree
    int leftDistance = findDistance(root->left, key, distance + 1);
    
    //* If leftDistance is not NULL then search in left again 
    if (leftDistance != -1)
    {
        return leftDistance;
    }
    //?Else search for key in right subTree
    return findDistance(root->right, key, distance + 1);
}

int distBetweenNodes(node *root, int n1, int n2)
{
    node *lca = LCA(root, n1, n2);//?find LCA 

    int d1 = findDistance(lca, n1, 0);//?find distance from LCA to n1
    int d2 = findDistance(lca, n2, 0);//?find distance from LCA to n2
    
    //*return total distance
    return d1 + d2;
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

    int ans=distBetweenNodes(root,2,9);

    cout<<ans;
}