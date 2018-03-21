
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; // node的父结点
    TreeLinkNode() {}
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

bool create_linklist(ListNode *head, int length);

ListNode* create_beginlist(int begin, int number);

bool create_huiwenlist(ListNode *head, int length);

void print_linklist(ListNode *node);

TreeNode* createTreeNode(int value);

void connectTreeNode(TreeNode* pParent, TreeNode* pLeftChild,
                     TreeNode* pRightChild);

// 打印二叉树程序
void printTreeFromTopToBottom(TreeNode* pRoot);

TreeLinkNode* createTreeLinkNode(int value);

void connectTreeLinkNode(TreeLinkNode* pParent, TreeLinkNode* pLeftChild,
                         TreeLinkNode* pRightChild);

