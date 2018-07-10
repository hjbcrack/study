
#include "common.h"

using namespace std;

// list

bool create_linklist(ListNode *head, int length)
{
    ListNode *node = NULL;
    ListNode *node1 = NULL;

    node = new ListNode(0);
    if (node == NULL) {
        return false;
    }
    head->next = node;

    for (int i = 1; i < length; i++) {
        node1 = new ListNode(i);
        if (node1 == NULL) {
            return false;
        }
        node->next = node1;
        node = node1;
    }

    return true;
}

ListNode* create_beginlist(int begin, int number)
{
    ListNode *head = NULL;
    ListNode *node = NULL;
    ListNode *node1 = NULL;

    head = new ListNode();
    if (head == NULL) {
        return NULL;
    }

    node = new ListNode(begin);
    if (node == NULL) {
        return head;
    }
    head->next = node;

    for (int i = begin+1; i < begin+number; i++) {
        node1 = new ListNode(i);
        if (node1 == NULL) {
            return head;
        } else {
            node->next = node1;
            node = node1;
        }
    }

    return head;
}

bool create_huiwenlist(ListNode *head, int length)
{
    ListNode *node = NULL;
    ListNode *node1 = NULL;

    node = new ListNode(0);
    if (node == NULL) {
        return false;
    }
    head->next = node;

    for (int i = 1; i < length/2; i++) {
        node1 = new ListNode(i);
        if (node1 == NULL) {
            return false;
        }
        node->next = node1;
        node = node1;
    }

    for (int i = length/2; i < length; i++) {
        node1 = new ListNode(length-1-i);
        if (node1 == NULL) {
            return false;
        }
        node->next = node1;
        node = node1;
    }

    return true;
}

bool create_linklist_with_array(ListNode *head, int array[], int length)
{
    ListNode *node = NULL;
    ListNode *node1 = NULL;

    node = new ListNode(array[0]);
    if (node == NULL) {
        return false;
    }
    head->next = node;

    for (int i = 1; i < length; i++) {
        node1 = new ListNode(array[i]);
        if (node1 == NULL) {
            return false;
        }
        node->next = node1;
        node = node1;
    }

    return true;
}

void print_linklist(ListNode *node)
{
    while (node != NULL) {
        cout << node->val << endl;
        node = node->next;
    }
}

// Ë«ÏòÁ´±í
bool create_dlinklist(DListNode *head, int length)
{
    DListNode *node = NULL;
    DListNode *node1 = NULL;

    node = new DListNode(0);
    if (node == NULL) {
        return false;
    }

    node->pre = head;
    head->next = node;

    for (int i = 1; i < length; i++) {
        node1 = new DListNode(i);
        if (node1 == NULL) {
            return false;
        }
        node1->pre = node;
        node->next = node1;
        node = node1;
    }

    return true;
}

void print_dlinklist(DListNode *node)
{
    while (node != NULL) {
        cout << node->val << endl;
        node = node->next;
    }
}

// tree

TreeNode* createTreeNode(int value)
{
    TreeNode* pNode = new TreeNode(value);
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

TreeLinkNode* createTreeLinkNode(int value)
{
    TreeLinkNode* pNode = new TreeLinkNode(value);
    return pNode;
}

void connectTreeLinkNode(TreeLinkNode* pParent, TreeLinkNode* pLeftChild,
                         TreeLinkNode* pRightChild)
{
    if(!pParent || !pLeftChild || !pRightChild)
        return;

    pParent->left = pLeftChild;
    pParent->right = pRightChild;
    pLeftChild->next = pParent;
    pRightChild->next = pParent;
}

unsigned long GetTickCount()
{
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

