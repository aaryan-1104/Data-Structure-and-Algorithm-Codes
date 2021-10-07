#include <iostream>
using namespace std;
#include <vector>
#include <stack>

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
void zigZagTraverse(treeNode *root)
{
    stack<treeNode *> currLevel;
    stack<treeNode *> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);
    while (!currLevel.empty())
    {
        treeNode *currNode = currLevel.top();

        currLevel.pop();
        if (currNode)
        {
            cout << currNode->data << " ";

            if (leftToRight)
            {
                if (currNode->left)
                {
                    nextLevel.push(currNode->left);
                }
                if (currNode->right)
                {
                    nextLevel.push(currNode->right);
                }
            }
            else
            {
                if (currNode->right)
                {
                    nextLevel.push(currNode->right);
                }
                if (currNode->left)
                {
                    nextLevel.push(currNode->left);
                }
            }
        }
        if(currLevel.empty()){
            leftToRight=false;
            swap(currLevel, nextLevel);
        }
    }
    return;
}

int main(){
     treeNode* root=new treeNode(12);

     root->left=new treeNode(9);
     root->right=new treeNode(15);

     root->left->left=new treeNode(5);
     root->left->right=new treeNode(10);

     zigZagTraverse(root);
    
}