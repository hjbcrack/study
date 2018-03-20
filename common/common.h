
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
/*
struct TreeNode* createTreeNode(int value);

void connectTreeNode(TreeNode* pParent, TreeNode* pLeftChild,
                     TreeNode* pRightChild);

void printTreeFromTopToBottom(TreeNode* pRoot);

*/
