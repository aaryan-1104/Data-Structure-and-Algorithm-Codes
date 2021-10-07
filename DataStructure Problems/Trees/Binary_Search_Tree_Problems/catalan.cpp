#include <iostream>
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

int catalan(int end)
{

    if (end <= 1)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < end; i++)
    {
        ans = ans + catalan(i) * catalan(end - i - 1);
    }

    return ans;
}

vector<treeNode *> makeTrees(int start, int end)
{
    vector<treeNode *> trees;

    //base case
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++) //the number of node which will be treated as root nodes which might be repeated as root node inside the loop for combination different node child node
    {
        vector<treeNode *> leftsubtree = makeTrees(start, i - 1); //left subtrees
        vector<treeNode *> rightsubtree = makeTrees(i + 1, end);  //right subtrees

        for (int j = 0; j < leftsubtree.size(); j++)
        {
            treeNode *left = leftsubtree[j]; //node to treated as left node

            for (int k = 0; k < rightsubtree.size(); k++)
            {
                //to make possible combination of nodes after selecting node i as root

                treeNode *right = rightsubtree[k]; //node to treated as right node

                treeNode *node = new treeNode(i); //creating the root node
                node->left = left;
                node->right = right;

                //to push the root node of every tree in this " trees " vector
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preOrder(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int n;
    cin >> n;
    cout << "First " << n << " Catalan numbers : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << catalan(i) << " ";
    }
    cout << endl
         << endl;

    vector<treeNode *> totalTrees = makeTrees(1, 4);

    //for all tree's preorder by accessing root nodes present in vector "trees"
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << i + 1 << " : ";
        preOrder(totalTrees[i]);
        cout << endl;
    }
}