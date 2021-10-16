#include <iostream>
using namespace std;
#include <vector>
#include <map>

class node
{
public:
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void verticalTraversal(node *root, int height, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }

    m[height].push_back(root->data);
    verticalTraversal(root->left, height - 1, m);
    verticalTraversal(root->right, height + 1, m);
}

int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(1);

    root->right->left = new node(7);
    root->right->right = new node(9);

    map<int, vector<int>> m;

    verticalTraversal(root, 0, m);

    map<int, vector<int>> :: iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        for (auto i : it->second)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}