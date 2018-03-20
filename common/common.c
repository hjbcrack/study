
#include "common.h"

#include <stdio.h>
#include <queue>
#include <iostream>


using namespace std;

/*
TreeNode* createTreeNode(int value)
{
    TreeNode* pNode = new TreeNode();
    pNode->val = value;
    pNode->left = NULL;
    pNode->right = NULL;
    return pNode;
}

void connectTreeNode(TreeNode* pParent, TreeNode* pLeftChild,
                     TreeNode* pRightChild)
{
    // it is ok if left or right is NULL, no child
    if(!pParent)
        return;

    pParent->left = pLeftChild;
    pParent->right = pRightChild;
}

void printTreeFromTopToBottom(TreeNode* pRoot)
{
    int nextlevel = 0;
    int curlevel = 0;

    if(pRoot == NULL)
        return;
    queue<TreeNode*> btnQueue;
    btnQueue.push(pRoot);
    curlevel++;
    while(!btnQueue.empty())
    {
        TreeNode* pTemp = btnQueue.front();
        btnQueue.pop();
        if(pTemp->left) {
            btnQueue.push(pTemp->left);
            nextlevel++;
        }
        if(pTemp->right) {
            btnQueue.push(pTemp->right);
            nextlevel++;
        }
        cout << pTemp->val << "\t";
        curlevel--;
        if (curlevel == 0) {
            curlevel = nextlevel;
            nextlevel = 0;
            cout << endl;
        }
    }
    cout << endl;
}
*/

