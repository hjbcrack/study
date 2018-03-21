
#define TIMU    61

#include "common.h"

#if (TIMU == 1)
// 1. 赋值运算符函数
/*
赋值运算符函数，注意四点：

1、是否将返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用，即*this。只有返回一个引用，才可以允许连续赋值。

2、是否把传入参数的类型声明为常量引用。如果传入的参数不是引用而是实例，那么从形参到实参会调用一次复制构造函数，把参数声明为引用可以避免这样的无谓消耗，能提高代码的效率。同时，在赋值运算符函数中不会改变传入的实例的状态，因此应该为传入的引用参数加上const关键字。

3、是否释放实例自身已有的内存，如果忘记在分配新内存之前释放自身已有的空间，程序将出现内存泄露。

4、避免自赋值。是否判断传入的参数和当前实例*this是不是同一个实例。如果是同一个，则不进行赋值操作，直接返回。

5、注意浅拷贝和深拷贝

更多考虑：异常安全性等。

*/

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator = (const CMyString& str);
    friend ostream& operator << (ostream & stream,const CMyString str)
    {
        return stream<<str.m_pData<<endl;
    }
    char* getData() { return this->m_pData; };

private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if(NULL == pData){
        m_pData = new char[1];
        m_pData[0] = '\0';
    } else {
        m_pData = new char[strlen(pData)+1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str)
{
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData,str.m_pData);
}

CMyString::~CMyString(void)
{
    delete [] m_pData;
    m_pData = NULL;
}

CMyString& CMyString::operator = (const CMyString& str)
{
/*
    // 
    if(this == &str)
        return *this;

    delete []m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData, str.m_pData);

    return *this;
*/
    // 先通过拷贝构造函数创建一个临时对象, 再交换临时对象和自身的m_data
    if(this != &str)
    {
        CMyString strtmp(str);
        char* ptmp = strtmp.m_pData;
        strtmp.m_pData = this->m_pData;
        this->m_pData = ptmp;
    }

    return *this;
}

int main()
{
    char a[]="hello";
    CMyString str(a);
    CMyString str1(str);
    CMyString str2;
    CMyString str3;
    str3=str2=str;
    cout << str<< endl;
    cout << str1<< endl;
    cout << str2<< endl;
    cout << str3<< endl;

    return 0;
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if (TIMU == 3)

// 3. 二位数组查找

//二维数组的查找（右上角版本）  
bool find(int* matrix, int rows, int columns, int number)  //传入一维数繿 
{  
    if(matrix != NULL && rows >0 && columns >0)            //指针判空以及边界判断  
    {  
        int row = 0;  
        int column = columns - 1;               //从矩阵的右上角开始判政 
        while(row < rows && column >= 0)  
        {  
            if(matrix[row*columns+column] == number)  
                return true;  
            else if(matrix[row*columns+column] > number)  
                --column;  
            else
                ++row;  
        }  
    }  
    return false;  
}  
     
//左下角版本
bool find2(int* matrix, int rows, int columns, int number)  
{
    if(matrix != NULL && rows > 0 && columns > 0)  
    {  
        int row = rows - 1;  
        int column = 0;  
        while(row >= 0 && column < columns)  
        {  
            if(matrix[row*columns+column] == number)  
                return true;  
            else if(matrix[row*columns+column] > number)  
                --row;  
            else  
                ++column;  
        }  
    }  
    return false;  
}

int main()   
{  
    int matrix[16] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};  
    if(find(matrix, 4, 4, 9))  
        cout << "ok!" << endl;  
    else  
        cout << "none!" << endl;  
    return 0;  
}  

#endif


#if (TIMU == 4)

// 4. 替换空格


// 自编代码
void replace_blank(char array[], int length)
{
    int blank_number = 0;
    int new_number = 0;
    int index = 0;
    int str_length = 0;

    for (int i = 0; i < length; i++) {
        if (array[i] == '\0')
            break;
        if (array[i] == ' ')
            blank_number++;
        str_length++;
    }

    new_number = str_length + blank_number*2;
    if (new_number > length) {
        cout << "the array is too lenght" << endl;
        return;
    }

    index = new_number-1;
    for (int i = str_length-1; i >= 0; i--) {
        if (array[i] == ' ') {
            array[index--] = '#';
            array[index--] = '#';
            array[index--] = '#';
        } else {
            array[index--] = array[i];
        }
    }
}

// length为字符数组string的总容量
void ReplaceBlank(char string[], int length)
{
    if(string == NULL || length <= 0)
        return;
 
    // originalLength为字符串string的实际长度
    int originalLength = 0;  
    int numberOfBlank = 0;  
    int i = 0;  
    while(string[i] != '\0')  
    {  
        ++originalLength;  
        if(string[i] == ' ')  
            ++numberOfBlank;  
        ++i;  
    }  
 
    // newLength为把空格替换成?20’之后的长度
    int newLength = originalLength + 2*numberOfBlank;  
    if(newLength > length)  
        return;  
   
    int indexOfOriginal = originalLength - 1;  
    int indexOfNew = newLength - 1;  
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)  
    {  
        if(string[indexOfOriginal] == ' ')  
        {  
            string[indexOfNew--] = '0';  
            string[indexOfNew--] = '2';  
            string[indexOfNew--] = '%';  
        }  
        else  
            string[indexOfNew--] = string[indexOfOriginal];  
        indexOfOriginal--;  
    }  
}

void test1()  
{  
    cout << "测试用例1：输入的字符串中包含空格" << endl;  
    char test1[20] = " wearehappy";
    char test2[20] = "wearehappy ";
    char test3[20] = "we arehappy";
    char test4[20] = "we  arehappy";
    char test5[20] = "wearehappy";
    char test6[20] = " ";
    char test7[20] = "   ";

    replace_blank(test1, 20);  
    replace_blank(test2, 20);  
    replace_blank(test3, 20);  
    replace_blank(test4, 20);  
    replace_blank(test5, 20);  
    replace_blank(test6, 20);  
    replace_blank(test7, 20); 

    cout << "my code:" << endl;
    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    cout << test4 << endl;
    cout << test5 << endl;
    cout << test6 << endl;
    cout << test7 << endl;

    char test11[20] = " wearehappy";
    char test12[20] = "wearehappy ";
    char test13[20] = "we arehappy";
    char test14[20] = "we  arehappy";
    char test15[20] = "wearehappy";
    char test16[20] = " ";
    char test17[20] = "   ";

    ReplaceBlank(test11, 20);  
    ReplaceBlank(test12, 20);  
    ReplaceBlank(test13, 20);  
    ReplaceBlank(test14, 20);  
    ReplaceBlank(test15, 20);  
    ReplaceBlank(test16, 20);  
    ReplaceBlank(test17, 20);
 
    cout << "ref code:" << endl;
    cout << test11 << endl;  
    cout << test12 << endl;  
    cout << test13 << endl;  
    cout << test14 << endl;
    cout << test15 << endl;
    cout << test16 << endl;
    cout << test17 << endl;
}  

int main()
{
    test1();

    return 1; 
}


#endif



#if (TIMU == 5)

// 5. 从尾到头打印链表

void printNode(ListNode* pHead)
{
    if (pHead == NULL) {
        return;
    }

    printNode(pHead->next);
    cout << pHead->val << endl;
}

void printListFromTailToHead(ListNode* pHead)
{
    if (pHead == NULL) {
        return;
    }

    printNode(pHead);
}

// 用栈
void printListFromTailToHead1(ListNode* pHead)
{
    stack<ListNode*> stack;

    if (pHead == NULL) {
        return;
    }

    while(pHead != NULL) {
        stack.push(pHead);
        pHead = pHead->next;
    }

    while(!stack.empty()) {
        cout << stack.top()->val << endl;
        stack.pop();
    }
}


int main()
{
    int length = 10;
    ListNode *head = new ListNode();

    create_linklist(head, length);

    cout << "recursion:" << endl;
    printListFromTailToHead(head);

    cout << "stack:" << endl;
    printListFromTailToHead1(head);

    return 0;
}

/*
// 参考代码


typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t* create_list(int number)
{
    node_t *head = NULL;
    node_t *node = NULL;
    node_t *node1 = NULL;

    head = new node_t;
    if (head == NULL) {
        return NULL;
    }

    node = new node_t;
    if (node == NULL) {
        return head;
    }
    node->val = 0;
    node->next = NULL;
    head->next = node;

    for (int i = 1; i < number; i++) {
        node1 = new node_t;
        if (node1 == NULL) {
            return head;
        } else {
            node1->val = i;
            node1->next = NULL;
            node->next = node1;
            node = node1;
        }
    }

    return head;
}


// 自己写，方法1 递归
void printlist(node_t *node)
{
    if (node != NULL) {
        if (node->next != NULL) {
            printlist(node->next);
        }
        cout << node->val << endl;
    }
}

// 方法2 利用栈先入后出的特点
void PrintListReversingly(node* L)  
{  
    stack<node*> nodes;

    //数据入栈
    node* pNode;
    pNode = L;
    while(pNode)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    //打印
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->val << " ";
        nodes.pop();
    }
    cout << endl;
}

int main()
{
    int number = 10;
    node_t *head = NULL;

    head = create_list(number);
    cout << "create list ok" << endl;

    printlist(head->next);

    PrintListReversingly(head->next);
}

*/


#endif

////////////////////////////////////////////////////////////////////////////////

#if (TIMU == 6)

// 6. 重建二叉树

/*
在二叉树的先序遍历序列中，第一个数总是数的根结点的值，后面依次是是左子树结点的值、右子树结点的值；
在二叉树的中序遍历序列中，根节点位于序列中间，根节点左边为左子树，右边为右子树。
根据上述信息，我们可以：
先通过先序遍历序列找到根节点，
然后在中序遍历序列中找到根节点，这样就可以确定左子树和右子树。
接着再回到先序遍历序列中找到左子树和右子树，重复上述步骤（递归）。
*/

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
{
    TreeNode* node = new TreeNode();
    vector<int> pre_left, in_left, pre_right, in_right;

    if (pre.size() == 0 || in.size() == 0) {
        return NULL;
    }
    node->val = pre[0];

    int index = 0;
    while(in[index] != pre[0]) {
        in_left.push_back(in[index++]);
    }
    index++;
    while(index < in.size()) {
        in_right.push_back(in[index++]);
    }

    index = 1;
    while(index < pre.size()) {
        int i;
        for (i = 0; i < in_left.size(); i++) {
            if (pre[index] == in_left[i]) {
                pre_left.push_back(pre[index++]);
                break;
            }
        }
        if (i == in_left.size()) {
            break;
        }
    }

    while(index < pre.size()) {
        pre_right.push_back(pre[index++]);
    }

    node->left = reConstructBinaryTree(pre_left, in_left);
    node->right = reConstructBinaryTree(pre_right, in_right);
    return node;
}

// 参考代码
/*
前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}

i-starin 是在计算当前节点左子树节点个数;
i-starin+starpre 是确定当前节点左子树在pre里的位置;
左子树的中序遍历即为 startIn 到 i-1, 右子树的中序遍历即为 i+1 到 endIn;
根据中序遍历+前序遍历的特点, pre[starpre+1]就是当前节点的左子节点, pre[i-starin+starpre+1]就是当前节点的右子节点;
巧妙的是那个判定条件, 越界即左右子节点不存在

*/

TreeNode* reConstructBinaryTree2(vector<int> pre,int startPre,int endPre,vector<int> in,int startIn,int endIn)
{
    if(startPre>endPre||startIn>endIn)
        return NULL;
    TreeNode* root = new TreeNode();
    root->val = pre[startPre];

    printf("index = %d, %d, %d, %d \n", startPre, endPre, startIn, endIn);
    for(int i = startIn; i <= endIn; i++)
        if(in[i] == pre[startPre]){
            root->left = reConstructBinaryTree2(pre, startPre+1, startPre+i-startIn, in, startIn, i-1);
            root->right = reConstructBinaryTree2(pre, i-startIn+startPre+1, endPre, in, i+1, endIn);
            break;
        }

    return root;
}

TreeNode* reConstructBinaryTree1(vector<int> pre, vector<int> in)
{
    TreeNode* root = reConstructBinaryTree2(pre, 0, pre.size()-1, in, 0, in.size()-1);
    return root;
}

int main()
{
    int a_pre[]={1,2,4,7,3,5,6,8};
    int a_in[]={4,7,2,1,5,3,8,6};
    int length = sizeof(a_pre)/sizeof(int);
    vector<int> pre(a_pre, a_pre+length);
    vector<int> in(a_in, a_in+length);
    TreeNode* node = NULL;

    node = reConstructBinaryTree(pre, in);
    printTreeFromTopToBottom(node);

    TreeNode* node1 = NULL;
    node1 = reConstructBinaryTree1(pre, in);
    printTreeFromTopToBottom(node1);

    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

#if (TIMU == 7)

// 7. 用两个栈实现队列

// 自编代码
class CQueue {
public:
    //CQueue();
    //~CQueue();
    bool pop_head();
    bool push_tail(int node);
    int head();
    int tail();

private:
    stack<int> stack_in;
    stack<int> stack_out;
};

bool CQueue::pop_head()
{
    int data;

    if (!stack_out.empty()) {
        stack_out.pop();
    } else if (!stack_in.empty()){
        while(!stack_in.empty()) {
            data = stack_in.top();
            stack_out.push(data);
            stack_in.pop();
        }
        stack_out.pop();
    } else {
        cout << "the queue is empty" << endl;
        return false;
    }

    return true;
}

bool CQueue::push_tail(int node)
{
    stack_in.push(node);
}

int CQueue::head()
{
    return stack_out.top();
}

int CQueue::tail()
{
    return stack_in.top();
}

int main()
{
    CQueue queue;

    cout << "push queue" << endl;
    queue.push_tail(1);
    queue.push_tail(2);
    queue.push_tail(3);
    queue.push_tail(4);
    queue.push_tail(5);

    cout << "queue tail:" << queue.tail() << endl;

    cout << "pop queue" << endl;
    queue.pop_head();

    cout << "queue head:" << queue.head() << endl;

    return 0;
}

#endif

// 参考代码

/*
template <typename T>
class CQueue {
public:
    void appendTail(const T& node);
    T deleteHead();
    T head();
    T tail();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& element) {
    stack1.push(element);
}

template<typename T>
T CQueue<T>::deleteHead() {
    if(stack2.size() <= 0) {
        while(stack1.size() > 0) {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    T head=stack2.top();
    stack2.pop();
    return head;
}

template<typename T>
T CQueue<T>::head()
{
    return stack2.top();
}

template<typename T>
T CQueue<T>::tail()
{
    return stack1.top();
}

int main()
{
    CQueue<int> queue;

    cout << "push queue" << endl;
    queue.appendTail(1);
    queue.appendTail(2);
    queue.appendTail(3);
    queue.appendTail(4);
    queue.appendTail(5);

    cout << "queue tail:" << queue.tail() << endl;

    cout << "pop queue" << endl;
    queue.deleteHead();

    cout << "queue head:" << queue.head() << endl;

    return 0;
}

*/

////////////////////////////////////////////////////////////////////////////////


#if (TIMU == 8)

// 8. 旋转数组的最小数字
/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
*/

int minNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.empty())
        return -1;

    int i = 0;
    for (; i<rotateArray.size()-1; i++)
    {
        if (rotateArray[i] > rotateArray[i+1])
            break;
    }
    return rotateArray[i+1];
}

int minNumberInRotateArray2(vector<int> rotateArray, int begin, int end)
{
    int rc = -1;
    if (rotateArray.empty())
        return -1;

    printf("begin = %d, end = %d: %d, %d \n", begin, end, rotateArray[begin], rotateArray[end]);

    if (begin+1 == end) {
        if (rotateArray[begin] > rotateArray[end]) {
            return rotateArray[end];
        } else {
            return -1;
        }
    }

    rc = minNumberInRotateArray2(rotateArray, begin, (begin+end)/2);
    if (rc != -1) {
        return rc;
    }

    rc = minNumberInRotateArray2(rotateArray, (begin+end)/2, end);
    if (rc != -1) {
        return rc;
    }

    return -1;
}

int minNumberInRotateArray1(vector<int> rotateArray)
{
    int rc = 0;
    if (rotateArray.empty() || rotateArray.size() < 2)
        return -1;

    rc = minNumberInRotateArray2(rotateArray, 0, (rotateArray.size()-1)/2);
    if (rc != -1) {
        return rc;
    }

    rc = minNumberInRotateArray2(rotateArray, (rotateArray.size()-1)/2, rotateArray.size()-1);
    if (rc != -1) {
        return rc;
    }

    return -1;
}

// 参考代码
int MinInOrder(const vector<int> &arr,int left,int right){
    int result=arr[left];
    for(int i=left+1;i<=right;i++){
        if(result>arr[i])
            result=arr[i];
    }
    return result;
}

int minNumberInRotateArray3(vector<int> rotateArray) {
    int len=rotateArray.size();
    if(len==0)
        return 0;
    int left=0;
    int right=len-1;
    int mid=left;
    //if(rotateArray[left]<rotateArray[right]);
    //  return rotateArray[left];
    while(rotateArray[left]>=rotateArray[right]){
        if(right-left==1){
            mid=right;
            break;
        }
        mid=left+((right-left)>>1);
        if(rotateArray[left]==rotateArray[right] && rotateArray[left]==rotateArray[mid])
            return MinInOrder(rotateArray,left,right);
        if(rotateArray[mid]>=rotateArray[left])
            left=mid;
        else
            right=mid;
    }
    return rotateArray[mid];
}

int main()
{
    int array[]={3,4,5,6,7,8,9,1,2};
    int length = sizeof(array)/sizeof(int);
    vector<int> input(array, array+length);
    cout << "min: " << minNumberInRotateArray(input) << endl;

    cout << "min1: " << minNumberInRotateArray1(input) << endl;

    cout << "min2: " << minNumberInRotateArray3(input) << endl;

    return 0;
}

#endif



////////////////////////////////////////////////////////////////////////////////


#if (TIMU == 9)

// 9. 斐波那契数列

// 自编代码
int fun(int n)
{
    if (n == 0 || n == 1) {
        return n;
    } else {
        return (fun(n-1) + fun(n-2));
    }
}

// 延伸: 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶，求该青蛙跳上一个n级台阶总共有多少种跳法？
int tiao(int n)
{
    if (n == 1 || n == 27) {
        return n;
    } else {
        return (tiao(n-1) + tiao(n-2));
    }
}


int main()
{
    cout << "shulie: " << fun(5) << endl;

    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

#if (TIMU == 10)

// 10. 二进制中1的个数

// 自编代码
int fun(int value)
{
    int number = 0;

    while (value) {
        if (value & 1)
            number++;
        value >>= 1;
    }

    return number;
}

// 参考代码
int NumberOf1(int n){
    int count=0;
    while(n){
        if(n&1)
            count++;
        n=n>>1;
    }
    return count;
}

/*
4、位运算相关题目

    用一条语句判断一个整数是不是2的整数次方。

if(n&(n-1)==0) return true;

    输入两个整数m,n,计算需要改变m的二进制表示中的多少位才能得到n？

int x=m^n; return NumberOf1(x);　　

*/

bool multipleof2(int value)
{
    if (value & 1)
        return false;

    return true;
}


int main()
{
    cout << "Number of 1: " << fun(0xff0f) << endl;

    cout << "Is multiple of 2: " << multipleof2(0xff0e) << endl;

    return 0;
}

#endif


#if (TIMU == 11)

// 11. 数值的整数次方

double Power(double base, int exponent) {
    double result = 1;
    if (exponent > 1) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    } else {
        for (int i = 0; i < -exponent; i++) {
            result *= 1 / base;
            if (result < 0.00000001) {
                return result;
            }
        }
    }
    
    return result;
}

int main()
{
    cout << Power(2, -3) << endl;

    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

#if (TIMU == 12)

// 12. 打印1到最大的n位数

// 参考自编代码
/*
n位所有十进制数其实就是n个从0到9的全排列。即把数字的每一位都从0到9排列一遍，就得到了所有的十进制数。

全排列用递归很容易实现，数字的每一位都可能是0-9的一个，然后设置下一位。递归的结束条件是我们已经设置了数字的最后一位。

*/

void PrintNumber(char* number){
    int i=0;
    int length = strlen(number);
    while(number[i] == '0')
        i++;
    for(int j = i; j < length; j++)
        cout << number[j];
    cout << "\t";
}

void printfun(char *ch, int n, int index)
{
    if (n == index) {
        PrintNumber(ch);
        return;
    }

    for (int i = 0; i < 10; i++) {
        ch[index] = '0' + i;
        printfun(ch, n, index+1);
    }
}

void fun(int n)
{
    if(n <= 0)
        return;

    char *ch = new char[n+1];
    ch[n] = '\0';

    printfun(ch, n, 0);
    cout << endl;

    return;
}

int main()
{
    fun(2);
    return 0;
}

#endif

/*

// 参考代码 1
bool Increment(char* number){
    bool isOverflow=false;
    int nTakeOver=0;
    int nLength=strlen(number);
    int nSum;
 
    for(int i=nLength-1;i>=0;i--){
        nSum=number[i]-'0'+nTakeOver;
        if(i==nLength-1)
            nSum++;
        if(nSum>=10){
            if(i==0)
                isOverflow=true;
            else{
                nSum=nSum-10;
                nTakeOver=1;
                number[i]='0'+nSum;
            }
        }
        else{
            number[i]='0'+nSum;
            break;
        }
    }
    return isOverflow;
}
 
void PrintNumber(char* number){
    int i=0;
    int length=strlen(number);
    while(number[i]=='0')
        i++;
    for(int j=i;j<length;j++)
        cout<<number[j];
    cout<<"\t";
}
 
void Print1ToMaxOfNDigits(int n){
    if(n<=0)
        return;
    char* number=new char[n+1];
    memset(number,'0',n);
    number[n]='\0';
 
    while(!Increment(number))
        PrintNumber(number);
 
    delete number;
}
 
void Print1ToMaxOfNDigits_1(int n){
    int number=1;
    for(int i=0;i<n;i++)
        number=10*number;
    for(int i=1;i<number;i++)
        cout<<i<<"\t";
    cout<<endl;
}
 
int main()
{
    Print1ToMaxOfNDigits(3);
    return 0;
}

*/


/*

// 参考代码 2

void PrintNumber(char* number){
    int i=0;
    int length=strlen(number);
    while(number[i]=='0')
        i++;
    for(int j=i;j<length;j++)
        cout<<number[j];
    cout<<"\t";
}
 
void Print1ToMaxOfNDigits_recursively(char* number,int length,int index){
    if(index==length){
        PrintNumber(number);
        return;
    }
    for(int i=0;i<10;i++){
        number[index]='0'+i;
        Print1ToMaxOfNDigits_recursively(number,length,index+1);
    }
}

void Print1ToMaxOfNDigits_2(int n){
    if(n<=0)
        return;
    char* number=new char[n+1];
    number[n]='\0';
    Print1ToMaxOfNDigits_recursively(number,n,0);
    delete number;
}
 
int main()
{
    Print1ToMaxOfNDigits_2(3);
    return 0;
}

*/

#if (TIMU == 13)

// 13. 在O(1)时间内删除链表结点

/*
在给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间内删除该结点。链表结点与函数的定义如下：
struct ListNode{
int val;
ListNode* next;
};

void deleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
*/

void deleteList(ListNode *p)
{
    ListNode *next = NULL;
    while(p != NULL)
    {
        cout << p->val << endl;
        next = p->next;
        delete p;
        p = NULL;
        p = next;
    }
}

bool deleteNode(ListNode **head, ListNode *p)
{
    if(!p || !head)
        return false;

    if(p->next != NULL)
    {
        //删除非尾节点
        ListNode *del = p->next;
        p->val = del->val;
        p->next = del->next;
        delete del;
        del = NULL;
    }
    else if(*head == p)
    {
        //只有一个节点
        delete p;
        *head = NULL;
    }
    else
    {
        //最后一种，删除节点是尾节点
        ListNode *tmp = NULL, *pre = *head;
        while(pre->next != p)
        {
            pre = pre->next;
        }
        delete p;
        p = NULL;
        pre->next = NULL;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode();
    create_linklist(head, 10);
    ListNode *p = head->next->next;
    deleteNode(&head, p);
    deleteList(head);
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if (TIMU == 14)

// 14. 调整数组顺序使奇数位于偶数前面

// 自编代码
void ReOrderOddEven(int array[], int number)
{
    int *tmpArr = new int(number*sizeof(int));
    int index = 0;

    for (int i = 0; i < number; i++){
        if (array[i]&1) {
            tmpArr[index] = array[i];
            index++;
        }
    }

    for (int i = 0; i < number; i++){
        if (!(array[i]&1)) {
            tmpArr[index] = array[i];
            index++;
        }
    }

    memcpy(array, tmpArr, number*sizeof(int));
}

// 自编代码 1
void reOrderArray1(vector<int> &array)
{
    int number = (int)array.size();
    vector<int> array1;

    for (int i = 0; i < number; i++){
        if (array[i]&1) {
            array1.push_back(array[i]);
        }
    }

    for (int i = 0; i < number; i++){
        if (!(array[i]&1)) {
            array1.push_back(array[i]);
        }
    }

    for (int i = 0; i < number; i++){
        array[i] = array1[i];
    }
}

// 参考代码
void reOrderArray(vector<int> &array)
{
    if(array.size() <= 0)
        return;

    vector<int> odds;
    vector<int> evens;
    unsigned int i;
    for(i=0;i<array.size();i++){
        if((array[i]&0x1)!=0)
            odds.push_back(array[i]);
        else
            evens.push_back(array[i]);
    }

    for(i=0;i<odds.size();i++)
        array[i]=odds[i];
    int k=i;
    for(i=0;i<evens.size();i++)
        array[k++]=evens[i];
}

int main()
{
    int array[] = {1,4,6,2,8,9,4,5,7,2,11,65,32,17};
    int number = sizeof(array)/sizeof(int);

    //ReOrderOddEven(array, number);

    vector<int> vArray;
    for (int i = 0; i < number; i++){
        vArray.push_back(array[i]);
    }
    //reOrderArray(vArray);

    reOrderArray1(vArray);

    for (int i = 0; i < number; i++){
        cout << vArray[i] << " ";
    }
    cout << endl;
}

#endif

/*
// not changed the relative position
void ReOrderOddEven_1(vector<int> &array){
    if(array.size()<=0)
        return;
    vector<int> odds;
    vector<int> evens;
    unsigned int i;
    for(i=0;i<array.size();i++){
        if((array[i]&0x1)!=0)
            odds.push_back(array[i]);
        else
            evens.push_back(array[i]);
    }
    for(i=0;i<odds.size();i++)
        array[i]=odds[i];
    int k=i;
    for(i=0;i<evens.size();i++)
        array[k++]=evens[i];
}
 
// changed the relative position
void ReOrderOddEven_2(int *pdata,unsigned int length){
    if(pdata==NULL || length<=0)
        return;
    int *pBegin=pdata;
    int *pEnd=pdata+length-1;
 
    while(pBegin<pEnd){
        while(pBegin<pEnd && (*pBegin&0x1)!=0)
            pBegin++;
        while(pBegin<pEnd && (*pEnd&0x1)==0)
            pEnd--;
        if(pBegin<pEnd){
            int tmp=*pBegin;
            *pBegin=*pEnd;
            *pEnd=tmp;
        }
    }
}
 
bool isEven(int n){
    return (n&1)==0;
}
 
// more expansible
void ReOrderOddEven_3(int *pdata,unsigned int length,bool (*func)(int)){
    if(pdata==NULL || length<=0)
        return;
    int *pBegin=pdata;
    int *pEnd=pdata+length-1;
 
    while(pBegin<pEnd){
        while(pBegin<pEnd && !func(*pBegin))
            pBegin++;
        while(pBegin<pEnd && func(*pEnd))
            pEnd--;
        if(pBegin<pEnd){
            int tmp=*pBegin;
            *pBegin=*pEnd;
            *pEnd=tmp;
        }
    }
}
 
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9};
    int length=sizeof(A)/sizeof(A[0]);
    ReOrderOddEven_2(A,length);
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
    cout<<endl;
 
    int B[]={1,2,3,4,5,6,7,8,9};
    vector<int> C(B,B+length);
    ReOrderOddEven_1(C);
    for(int i=0;i<length;i++)
        cout<<C[i]<<" ";
    cout<<endl;
 
    ReOrderOddEven_3(B,length,isEven);
    for(int i=0;i<length;i++)
        cout<<B[i]<<" ";
    cout<<endl;
    return 0;
}


*/


#if (TIMU == 15)

// 15. 链表中倒数第k个结点

// 自编代码
ListNode* FindKthToTail(ListNode* head, int k)
{
    int number = 0;
    int pos = 0;

    if (head == NULL || head->next == NULL) {
        cout << "The list is empty!" << endl;
        return NULL;
    }

    ListNode* node = head;
    while (node) {
        number++;
        node = node->next;
    }

    if (number < k) {
        cout << "k is less than list number " << number << endl;
        return NULL;
    }

    node = head;
    while(node) {
        if (pos == (number-k)) {
            return node;
        }
        node = node->next;
        pos++;
    }

    return NULL;
}

// 参考代码
ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k) {
    if(pListHead == NULL || k <= 0)
        return NULL;

    ListNode* pAhead = pListHead;
    for(unsigned int i = 1; i < k; i++){
        if(pAhead -> next!=NULL)
            pAhead = pAhead->next;
        else
            return NULL;
    }

    ListNode *pBehind = pListHead;
    while(pAhead->next != NULL){
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;
}


int main(){
    int length = 10;
    ListNode *head = new ListNode();
    ListNode *k_node = NULL;

    create_linklist(head, length);

    k_node = FindKthToTail(head, 2);
    if (k_node != NULL) {
        cout << "1. tail k data is " << k_node->val << endl;
    }

    k_node = FindKthToTail1(head, 2);
    if (k_node != NULL) {
        cout << "2. tail k data is " << k_node->val << endl;
    }

    return 0;
}

#endif


#if (TIMU == 16)

// 16. 反转链表

// 参考代码

ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReverseHead;
    ListNode* pCur = pHead;
    ListNode* pPrev = NULL;
    ListNode* tmp;

    while(pCur != NULL){
        tmp = pCur->next;
        if (tmp == NULL)
            pReverseHead = pCur;
        pCur->next = pPrev;
        pPrev = pCur;
        pCur = tmp;
    }

    return pReverseHead;
}

ListNode* ReverseList1(ListNode* pHead)
{
    ListNode* tmp;
    ListNode* pCur = pHead;
    ListNode* pPrev = NULL;

    while(pCur){
        tmp = pCur->next;
        pCur->next = pPrev;
        pPrev = pCur;
        pCur = tmp;
    }
    return pPrev;
}

int main(){
    int length = 10;
    ListNode *head = new ListNode();
    ListNode *tail = NULL;

    create_linklist(head, length);

    tail = ReverseList1(head);
    for (tail; tail != NULL; tail = tail->next) {
        cout << tail->val << " ";
    }
    cout << endl;

    return 0;
}

#endif

#if (TIMU == 17)

// 17. 合并两个排序的链表

// 自编代码

ListNode* merge(ListNode* head1, ListNode* head2)
{
    ListNode* node = new ListNode();
    ListNode* head = node;

    if(head1 == NULL && head2 == NULL) {
        cout << "the list is empty" << endl;
        return NULL;
    }

    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    while(head1 != NULL && head2 != NULL) {
        if (head1->val > head2->val) {
            node->next = head2;
            head2 = head2->next;
        } else {
            node->next = head1;
            head1 = head1->next;
        }
        node = node->next;
    }

    if (head1 != NULL) {
        node->next = head1;
    }

    if (head2 != NULL) {
        node->next = head2;
    }

    return head;
}

int main()
{
    int number = 10;
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head = NULL;

    head1 = create_beginlist(1, number);
    head2 = create_beginlist(5, number);

    print_linklist(head1->next);
    print_linklist(head2->next);

    head = merge(head1->next, head2->next);
    print_linklist(head->next);

}


#endif

#if (TIMU == 18)

// 18. 树的子结构

TreeNode* FindTheFirst(TreeNode* pRoot1, int data)
{
    TreeNode *node;

    if (pRoot1 == NULL) {
        return NULL;
    }

    if (pRoot1->val == data) {
        return pRoot1;
    }

    if ((node=FindTheFirst(pRoot1->left, data)) != NULL) {
        return node;
    } else if ((node=FindTheFirst(pRoot1->right, data)) != NULL) {
        return node;
    }

    return node;
}

bool HasSubtreeUnit(TreeNode* pRoot1, TreeNode* pRoot2, bool start)
{
    TreeNode* node = NULL;

    if (pRoot1 == NULL || pRoot2 == NULL) {
        return true;
    }

    if (pRoot1->val == pRoot2->val) {
        return (HasSubtreeUnit(pRoot1->left, pRoot2->left, true) &&
                    HasSubtreeUnit(pRoot1->right, pRoot2->right, true));
    } else {
        if (start == true) {
            return false;
        }
    }

    return (HasSubtreeUnit(pRoot1->left, pRoot2->left, false) &&
            HasSubtreeUnit(pRoot1->right, pRoot2->right, false));
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    TreeNode* node = NULL;

    if (pRoot1 == NULL || pRoot2 == NULL) {
        return false;
    }

    node = FindTheFirst(pRoot1, pRoot2->val);
    if (node != NULL) {
        return HasSubtreeUnit(node, pRoot2, false);
    }

    return false;
}

int main()
{
    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(3);
    TreeNode* pNode4 = createTreeNode(4);
    TreeNode* pNode5 = createTreeNode(5);
    TreeNode* pNode6 = createTreeNode(6);
    TreeNode* pNode7 = createTreeNode(7);

    TreeNode* pNode8 = createTreeNode(5);
    TreeNode* pNode9 = createTreeNode(6);
    TreeNode* pNode10 = createTreeNode(7);

    connectTreeNode(pNode1, pNode2, pNode3);
    connectTreeNode(pNode2, pNode4, pNode5);
    connectTreeNode(pNode5, pNode6, pNode7);

    connectTreeNode(pNode8, pNode9, pNode10);

    cout << HasSubtree(pNode1, pNode8) << endl;
    /*测试用例:
    {8,8,7,9,2,#,#,#,#,4,7},{8,9,2}
    
    对应输出应该?
    
    true
    
    你的输出?
    
    false
    */

    return 0;
}

#endif

#if (TIMU == 19)

// 19. 二叉树的镜像

// 自编代码
void Mirror(TreeNode *pRoot)
{
    TreeNode* node = NULL;

    if (pRoot == NULL) {
        return;
    }

    node = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = node;

    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

int main()
{
    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(3);
    TreeNode* pNode4 = createTreeNode(4);
    TreeNode* pNode5 = createTreeNode(5);
    TreeNode* pNode6 = createTreeNode(6);
    TreeNode* pNode7 = createTreeNode(7);

    connectTreeNode(pNode1, pNode2, pNode3);
    connectTreeNode(pNode2, pNode4, pNode5);
    connectTreeNode(pNode5, pNode6, NULL);

    printTreeFromTopToBottom(pNode1);

    Mirror(pNode1);

    printTreeFromTopToBottom(pNode1);

    return 0;
}

#endif

#if (TIMU == 20)

// 20. 顺时针打印矩阵


// 自编代码
void print_array(int array[][4], int row, int column)
{
    int rindex = 0;
    int cindex = 0;
    int count = 0;
    int direction = 0;

    while (count < row*column) {
        if (rindex >= 0 && rindex < row && cindex >= 0 && cindex < column &&
            array[rindex][cindex] != -1) {
            cout << array[rindex][cindex] << "\t"<< endl;
            array[rindex][cindex] = -1;
            count++;
            switch (direction) {
                case 0:
                    cindex++;
                    break;
                case 1:
                    rindex++;
                    break;
                case 2:
                    cindex--;
                    break;
                case 3:
                    rindex--;
                    break;
                default:
                    break;
            }
        } else {
            switch (direction) {
                case 0:
                    cindex--;
                    rindex++;
                    break;
                case 1:
                    rindex--;
                    cindex--;
                    break;
                case 2:
                    cindex++;
                    rindex--;
                    break;
                case 3:
                    rindex++;
                    cindex++;
                    break;
                default:
                    break;
            }
            direction = (direction < 3) ? (direction+1) : 0;
        }
    }
}

int main()
{
    int array[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    print_array(array, 4, 4);

    return 0;
}


#endif


#if (TIMU == 21)

// 21. 包含min函数的栈

template<typename T>
class CStackwithmin{
public:
    void push(const T& data);
    void pop();
    T min();

private:
    stack<T> m_data;
    stack<T> m_min;
};

template<typename T>
void CStackwithmin<T>::push(const T& value)
{
    m_data.push(value);

    if(m_min.empty() || value<m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template<typename T>
void CStackwithmin<T>::pop()
{
    m_data.pop();
    m_min.pop();
}

template<typename T>
T CStackwithmin<T>::min()
{
    return m_min.top();
}

int main(){
    CStackwithmin<int> stack;

    cout << "push stack" << endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(1);
    stack.push(1);

    cout << "stack min:" << stack.min() << endl;

    stack.pop();
    cout << "stack min 1:" << stack.min() << endl;

    stack.pop();
    cout << "stack min 2:" << stack.min() << endl;

    stack.pop();
    cout << "stack min 3:" << stack.min() << endl;

    stack.pop();
    cout << "stack min 4:" << stack.min() << endl;

    stack.pop();
    cout << "stack min 5:" << stack.min() << endl;

    return 0;
}

#endif

#if (TIMU == 22)

// 22. 栈的压入、弹出序列

bool IsPopOrder(const int* push, const int* pop, int length)
{
    int rc = false;
    int index1 = 0;
    int index2 = 0;
    stack<int> stack;

    if (push == NULL || pop == NULL) {
        return false;
    }

    while(index2 < length) {
        while (stack.empty() || pop[index2] != stack.top()) {
            if (index1 >= length) {
                break;
            }
            stack.push(push[index1]);
            index1++;
        }
        if(stack.top() != pop[index2])
            break;
        stack.pop();
        index2++;
    }
    if (stack.empty() && index2 == length) {
        rc = true;
    }

    return rc;

/*    bool bPossible=false;
    if(push!=NULL && pop!=NULL && length>0){
        std::stack<int> stackData;
        int i=0;
        int j=0;
        while(j<length){
            while(stackData.empty() || stackData.top()!=pop[j]){
                if(i>length-1)
                    break;
                stackData.push(push[i]);
                ++i;
            }
            if(stackData.top()!=pop[j])
                break;
            stackData.pop();
            ++j;
        }
        if(stackData.empty() && j==length)
            bPossible=true;
    }
    return bPossible;*/
}

int main(){
    int array1[] = {1,2,3,4,5};
    int array2[] = {5,4,3,2,1};

    bool rc = IsPopOrder(array1, array2, 5);

    cout << "is pop order:" << rc << endl;

    return 0;
}

#endif

#if (TIMU == 23)

// 23. 从上到下打印二叉树


// queue是单向队列，deque（double-ended-queue）是双向队列
// 自编代码

void PrintFromTopToBottom(TreeNode* root)
{
    queue<TreeNode*> list;
    TreeNode* node = root;

    if (root == NULL)
        return;

    list.push(root);
    while(!list.empty()) {
        node = list.front();
        cout << node->val << endl;
        list.pop();
        if (node->left != NULL) {
            list.push(node->left);
        }
        if (node->right != NULL) {
            list.push(node->right);
        }
    }
}

/*
// 参考代码
void PrintFromTopToBottom(TreeNode* root){
    if(root==NULL)
        return;
    std::deque<TreeNode*> dequeTree;
    dequeTree.push_back(root);
    TreeNode* node;
    while(!dequeTree.empty()){
        node=dequeTree.front();
        dequeTree.pop_front();
        printf("%d ",node->val);
 
        if(root->left)
            dequeTree.push_back(root->left);
        if(root->right)
            dequeTree.push_back(root->right);
    }
}
*/
int main()
{
    TreeNode* root = new TreeNode();
    root->val = 1;
    root->left = new TreeNode();
    root->left->val = 2;
    root->left->left = new TreeNode();
    root->left->left->val = 3;
    root->left->right = new TreeNode();
    root->left->right->val = 4;
    root->right = new TreeNode();
    root->right->val = 5;
    root->right->left = new TreeNode();
    root->right->left->val = 6;
    root->right->right = new TreeNode();
    root->right->right->val = 7;
    PrintFromTopToBottom(root);

    return 0;
}


#endif


#if (TIMU == 24)

// 24. 二叉搜索树的后序遍历序列
/* 输入一个整数数组，判断该数组是不是某个二叉搜索树的后序遍历的结果
   假设输入的数组的任意两个数字都互不相同。
   二叉搜索树: 
      1 空树
      2 left < root < right
*/

// 自编代码
bool VerifySquence(vector<int> sequence, int begin, int end)
{
    int index = begin;
    int mid = 0;
    int rc = true;

    if (begin >= end) {
        return true;
    }
    while (index < end) {
        if (sequence[index] > sequence[end]) {
            break;
        }
        index++;
    }
    mid = index;

    while (index < end) {
        if (sequence[index] < sequence[end]) {
            return false;;
        }
        index++;
    }

    return (VerifySquence(sequence, begin, mid-1) &&
            VerifySquence(sequence, mid, end-1));
}

// 自编代码
bool VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.empty()) {
        return false;
    }
    return VerifySquence(sequence, 0, sequence.size()-1);
}

int main()
{
    //int array[] = {1,3,2,4,5};
    int array[] = {5,4,6,9,11,10,8};
    int number = sizeof(array)/sizeof(int);
    vector<int> sequence(array, array+number);

    cout << VerifySquenceOfBST(sequence) << endl;

    return 0;
}

#endif


#if (TIMU == 27)
// 有问题
// 27. 二叉搜索树与双向链表

/* 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
   要求不能创建任何新的结点，只能调整树中结点指针的指向
*/

// queue是单向队列，deque（double-ended-queue）是双向队列?

// 自编代码

void PrintFromTopToBottom(TreeNode* root)
{
    queue<TreeNode*> list;
    TreeNode* node = root;

    if (root == NULL)
        return;

    list.push(root);
    while(!list.empty()) {
        node = list.front();
        cout << node->val << endl;
        list.pop();
        if (node->left != NULL) {
            list.push(node->left);
        }
        if (node->right != NULL) {
            list.push(node->right);
        }
    }
}
/*
// 参考代码

void PrintFromTopToBottom(TreeNode* root){
    if(root==NULL)
        return;
    std::deque<TreeNode*> dequeTree;
    dequeTree.push_back(root);
    TreeNode* node;
    while(!dequeTree.empty()){
        node=dequeTree.front();
        dequeTree.pop_front();
        printf("%d ",node->val);
 
        if(root->left)
            dequeTree.push_back(root->left);
        if(root->right)
            dequeTree.push_back(root->right);
    }
}
*/
int main()
{
    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(3);
    TreeNode* pNode4 = createTreeNode(4);
    TreeNode* pNode5 = createTreeNode(5);
    TreeNode* pNode6 = createTreeNode(6);
    TreeNode* pNode7 = createTreeNode(7);

    connectTreeNode(pNode1, pNode2, pNode3);
    connectTreeNode(pNode2, pNode4, pNode5);
    connectTreeNode(pNode5, pNode6, pNode7);

    printTreeFromTopToBottom(pNode1);

    PrintFromTopToBottom(pNode1);

    return 0;
}

#endif

#if (TIMU == 28)
// 28. 字符串的排列

/*
一个字符串看成两部分组成：第一部分为第一个字符，第二部分为后面的所有字符
求整个字符串的排列，可以看出两步：首先求所有可能出现在第一个位置的字符，
即把第一个字符和后面的所有字符交换；然后固定第一个字符，求后面所有字符的排序
此时仍把后面的字符看成两部分，第一个字符和后面的字符，然后重复上述步骤。（递归)
类似问题：N皇后问题
*/

void swap(char* c1,char* c2){
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}
 
void Permutation(string &str, int begin, vector<string> &result){
    int len = str.length();
    if(begin == len-1)
        result.push_back(str);
    else{
        for(int i = begin; i < len; i++){
            if(i == begin || str[i] != str[begin]){
                swap(&str[begin], &str[i]);
                Permutation(str, begin+1, result);
                swap(&str[begin], &str[i]);  
            }
        }
    }
}
 
vector<string> Permutation(string str) {
    vector<string> result;
    if(str.length() > 0){
        Permutation(str, 0, result);
        sort(result.begin(), result.end());
    }
    return result;
}

int main()
{
    string str = "abc";
    vector<string> output;

    output = Permutation(str);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }

    return 0;
}

#endif

#if (TIMU == 29)

// 29. 数组中出现次数超过一半的数字
/*
1、方法1 先排序，然后找中位数;
时间复杂度O(nlogn)

2、方法2 基于Partition函数的O(n)算法，即寻找第k（k=n/2）大的数, 平均时间复杂度：O(n)

3、方法3 根据数组特点，采用Moore-Vote方法?由于该数字的出现次数比所有其他数字出现次数的和还要多，
因此可以考虑在遍历数组时保存两个值：一个是数组中的一个数字，一个是次数，
当遍历到下一个数字时，如果下一个数字与之前保存的数字相同，则次数加1，如果不同，
则次数减1，如果次数为0，则需要保存下一个数字，并把次数设定?。由于我们要找的数字
出现的次数比其他所有数字的出现次数之和还要大，则要找的数字肯定是组后一次把次数设为1时对应的数字?
时间复杂度为O(n)，空间复杂度为O(1)*/

int MoreThanHalfNum(int* numbers, int length)
{
    int num = 0;
    int count = 0;

    if (numbers == NULL || length == 0) {
        return 0;
    }

    num = numbers[0];
    for (int i = 0; i < length; i++) {
        if (num == numbers[i]) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            num = numbers[i];
            count = 1;
        }
        cout << count << ", " << num << endl;
    }

    return (count > 1 ? num : 0);
}
 
 
int main()
{
    //int array[] = {1, 3, 1, 3, 3, 3, 3, 4, 5, 3};
    int array[] = {1,2,3,2,4,2,5,2,3};
    int number = sizeof(array) / sizeof(int);

    for (int i = 0; i < number; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;

    cout << MoreThanHalfNum(array, number) << endl;

    return 0;
}

#endif


#if (TIMU == 30)

// 30. 最小的k个数

// Partition
int Partition(int* numbers,int start,int end){
    int key=numbers[start];
    int i=start;
    int j=end;
    while(i<j){
        while(i<j && numbers[j]>=key)
            --j;
        if(i<j) numbers[i++]=numbers[j];
 
        while(i<j && numbers[i]<=key)
            ++i;
        if(i<j) numbers[j--]=numbers[i];
    }
    numbers[i]=key;
    return i;
}
 
void GetLeastNumbers(int* input,int n,int* output,int k){
    if(input==NULL || output==NULL || k>n || n<=0 || k<=0)
        return;
    int start=0;
    int end=n-1;
    int index=Partition(input,start,end);
    while(index!=k-1){
        if(index>k-1){
            end=index-1;
            index=Partition(input,start,end);
        }
        else{
            start=index+1;
            index=Partition(input,start,end);
        }
    }
 
    for(int i=0;i<k;i++)
        output[i]=input[i];
}

// 参考代码
void GetLeastNumbers_1(const vector<int> &data, set<int> &leastNumbers,
                       unsigned int k)
{
    leastNumbers.clear();
 
    if(k<1 || data.size()<k)
        return;
 
    vector<int>::const_iterator it=data.begin();
    for(;it!=data.end();it++){
        if(leastNumbers.size()<k)
            leastNumbers.insert(*it);
        else{
            set<int>::const_iterator iterGreatest=leastNumbers.begin();
            if(*it<*iterGreatest){
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*it);
            }
        }
    }
}

int main()
{
    int array[] = {4,5,1,6,2,7,3,8,0};;
    int number = sizeof(array) / sizeof(int);
    int k=4;
    int minK[4];

    for (int i = 0; i < number; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;

    GetLeastNumbers(array, number, minK, k);

    for (int i = 0; i < k; i++) {
        cout << minK[i] << "\t";
    }
    cout << endl;

    // 大顶堆
    vector<int> data(array, array+number);

    set<int> leastNumbers;
    GetLeastNumbers_1(data, leastNumbers, k);

    for(set<int>::const_iterator it=leastNumbers.begin();
        it!=leastNumbers.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    return 0;
}


#endif


#if (TIMU == 31)

// 31. 连续子数组的最大和

// 自编代码

int findGreatestSumOfSubArray(int *pData, int nLength)
{
    int sum = 0;
    int maxSum = 0;
    int index = 0;

    if (pData == NULL) {
        return 0;
    }

    while (index < nLength) {
        if (sum + pData[index] < 0) {
            sum = 0;
        } else {
            sum += pData[index];
        }
        maxSum = (maxSum <= sum) ? sum : maxSum;
        index++;
    }

    return maxSum;
}

// 参考代码
bool g_InvalidInput=false;
int findGreatestSumOfSubArray1(int *pData,int nLength){
    if(pData==NULL || nLength<=0){
        g_InvalidInput=true;
        return 0;
    }
    g_InvalidInput=false;
    int nCurSum=0;
    int nGreatestSum=0x80000000;
 
    for(int i=0;i<nLength;i++){
        if(nCurSum<=0)
            nCurSum=pData[i];
        else
            nCurSum+=pData[i];
        if(nCurSum>nGreatestSum)
            nGreatestSum=nCurSum;
    }
 
    return nGreatestSum;
}

int main()
{
    int array[] = {1,-2,3,10,-4,7,2,-5, 100};
    int number = sizeof(array) / sizeof(int);

    for (int i = 0; i < number; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;

    cout << findGreatestSumOfSubArray(array, number) << endl;

    cout << findGreatestSumOfSubArray1(array, number) << endl;

    return 0;
}


#endif

#if (TIMU == 32)

// 32. 从1到n整数中1出现的次数

// 参考代码
int numberOf1(int n){
    int count = 0;
    while(n) {
        if(n %10 == 1)
            count++;
        n = n / 10;
    }
    return count;
}
 
int numberOf1Between1AndN(unsigned int n){
    int count = 0;
    for(unsigned int i = 1; i <= n ; i++){
        count += numberOf1(i);
    }
    return count;
}

int main()
{
    int count = 0;

    cout << numberOf1Between1AndN(99) << endl;

    return 0;
}


#endif


#if (TIMU == 33)

// 33. 把数组排成最小的数

/*
1、全排列

求出数组中所有数字的全排列，然后把每个全排列拼起来，求出拼出来的数字的最大值。

2、定义新的排序规则

如果两个数字m,n拼接成mn和nm，如果mn<nm，那么m应该排在n的前面，我们定义此时m小于n，如果mn=nm，我们定义m等于n。
可以考虑将数字转成字符串，一来防止数字拼接时的溢出，二来字符串的拼接和比较容易实现。
由于把数字m和n拼接起来得到mn和nm，它们的位数一定是相同的，因此比较它们的大小只需按照字符串大小的比较规则即可。

*/

bool compare(int a,int b)
{
    string strNum1=to_string(a);
    string strNum2=to_string(b);
    return (strNum1+strNum2)<(strNum2+strNum1);
}

string PrintMinNumber(vector<int> numbers)
{
    string result;
    if(numbers.empty())
        return result;
    sort(numbers.begin(),numbers.end(),compare);
    for(unsigned int i=0;i<numbers.size();i++)
        result+=to_string(numbers[i]);
    return result;
}


int main()
{
    int array[] = {3, 32, 321};

    cout << PrintMinNumber(array) << endl;

    return 0;
}

#endif


#if (TIMU == 34)

// 34. 丑数
// 求按从小到大的顺序的第N个丑数。

// 自编代码
// 问题: 运行超时
bool isUglyNumber(int index) {
    if (index == 1 || index == 0) {
        return true;
    }

    if (index % 2 == 0) {
        return isUglyNumber(index / 2);
    } else if (index % 3 == 0) {
        return isUglyNumber(index / 3);
    } if (index % 5 == 0) {
        return isUglyNumber(index / 5);
    } else {
        return false;
    }

    return false;
}

int getUglyNumber(int index)
{
    int count = 0;
    int n = 1;

    while (count < index) {
        if (isUglyNumber(n)) {
            count++;
        }
        n++;
    }

    return n-1;
}

// 参考代码

int min_3(int num1,int num2,int num3){
    num1=(num1<num2)?num1:num2;
    num1=(num1<num3)?num1:num3;
    return num1;
}

int GetUglyNumber_Solution(int index)
{
    if(index<=0)
        return 0;
    int uglyNumbers[index];
    uglyNumbers[0]=1;
    int nextIndex=1;
    int index_2=0;
    int index_3=0;
    int index_5=0;

    while(nextIndex<index){
        uglyNumbers[nextIndex]=min_3(uglyNumbers[index_2]*2,uglyNumbers[index_3]*3,uglyNumbers[index_5]*5);
        while(uglyNumbers[index_2]*2<=uglyNumbers[nextIndex]) ++index_2;
        while(uglyNumbers[index_3]*3<=uglyNumbers[nextIndex]) ++index_3;
        while(uglyNumbers[index_5]*5<=uglyNumbers[nextIndex]) ++index_5;
        ++nextIndex;
    }
    return uglyNumbers[index-1];
}

int main()
{
    int number = 20;

    //getUglyNumber(number);
    for (int i = 1; i < 100; i++) {
        cout << "index" << i << " = " << getUglyNumber(i) << endl;
    }
    cout << endl;

    cout << "ref method" << endl;
    for (int i = 1; i < 100; i++) {
        cout << "index" << i << " = " << GetUglyNumber_Solution(i) << endl;
    }

    //cout << "ugly number 1" << number << " = " << getUglyNumber(number) << endl;
    //cout << "ugly number 2" << number << " = " << GetUglyNumber_Solution(number) << endl;

    return 0;
}

#endif


#if (TIMU == 35)

// 35. 第一个只出现一次的字符

// 自编代码
char firstNotRepeatingChar(char* pString)
{
    int counts[256] = {0};
    int index = 0;

    if (pString == NULL) {
        return -1;
    }

    while (pString[index] != '\0') {
        counts[pString[index]]++;
        index++;
    }

    index = 0;
    while (pString[index] != '\0') {
        if (counts[pString[index]] == 1) {
            return pString[index];
        }
        index++;
    }

    return -1;
}

int main()
{
    char str[] = "abbaccdeff";

    cout << firstNotRepeatingChar(str) << endl;

    return 0;
}

#endif


#if (TIMU == 36)

// 36. 数组中的逆序对

int InversePairs(vector<int> data)
{
    int number = 0;

    for (int i = 0; i < data.size()-1; i++) {
        if (data[i] > data[i+1]) {
            number++;
        }
    }

    return number;
}

int main()
{
    int array[] = {1, 3, 2, 3, 4, 5, 3, 7, 8, 9};
    int number = sizeof(array) / sizeof(int);
    vector<int> data(array, array+number);

    cout << InversePairs(data) << endl;

    return 0;
}

#endif


#if (TIMU == 37)

// 37. 两个链表的第一个公共结点

void create_reflist(ListNode** pHead1, ListNode** pHead2)
{
    ListNode *node = NULL;
    ListNode *node1 = NULL;
    ListNode *node2 = NULL;

    *pHead1 = new ListNode();
    if (pHead1 == NULL) {
        return; 
    }

    node1 = new ListNode(0);
    if (node1 == NULL) {
        return;
    }
    (*pHead1)->next = node1;

    for (int i = 1; i < 5; i++) {
        node = new ListNode(i);
        if (node == NULL) {
            return;
        } else {
            node1->next = node;
            node1 = node;
        }
    }

    *pHead2 = new ListNode();
    if (pHead2 == NULL) {
        return; 
    }

    node2 = new ListNode(100);
    if (node2 == NULL) {
        return;
    }
    (*pHead2)->next = node2;

    for (int i = 101; i < 103; i++) {
        node = new ListNode(i);
        if (node == NULL) {
            return;
        } else {
            node2->next = node;
            node2 = node;
        }
    }

    for (int i = 10; i < 15; i++) {
        node = new ListNode(i);
        if (node == NULL) {
            return;
        } else {
            node1->next = node;
            node1 = node;
            node2->next = node;
            node2 = node;
        }
    }
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    stack<ListNode*> stack1;
    stack<ListNode*> stack2;

    if (pHead1 == NULL || pHead2 == NULL) {
        return NULL;
    }

    while (pHead1 != NULL) {
        stack1.push(pHead1);
        pHead1 = pHead1->next;
    }

    while (pHead2 != NULL) {
        stack2.push(pHead2);
        pHead2 = pHead2->next;
    }

    while (!stack1.empty() && !stack2.empty() && stack1.top() == stack2.top()) {
        stack1.pop();
        stack2.pop();
    }

    return stack1.top()->next;
}

int main()
{
    int number = 10;
    ListNode *pHead1 = NULL;
    ListNode *pHead2 = NULL;
    ListNode *pHead = NULL;

    create_reflist(&pHead1, &pHead2);
    cout << "create list ok" << endl;
    
    pHead = pHead1;
    while (pHead != NULL) {
        cout << pHead->val << "\t";
        pHead = pHead->next;
    }
    cout << endl;

    pHead = pHead2;
    while (pHead != NULL) {
        cout << pHead->val << "\t";
        pHead = pHead->next;
    }
    cout << endl;

    pHead = FindFirstCommonNode(pHead1->next, pHead2->next);
    if (pHead != NULL) {
        cout << "start node val = " << pHead->val << endl;
    }

    return 0;
}

#endif

#if (TIMU == 38)

// 38. 数字在排序数组中出现的次数
// 二分查找到其中一个，然后前后搜索

int getNumberOfK(int* data, int length, int k)
{
    int head = 0;
    int tail = length-1;
    int index = -1;

    if (data == NULL || length == 0) {
        return 0;
    }

    while (head <= tail) {
        if (data[(head+tail)/2] > k) {
            tail = (head+tail)/2-1;
        } else if (data[(head+tail)/2] < k){
            head = (head+tail)/2+1;
        } else {
            index = (head+tail)/2;
            break;
        }
    }

    if (index == -1) {
        return 0;
    }

    head = tail = index;
    while (data[head] == k || data[tail] == k) {
        if (data[head] == k) {
            head--;
        }
        if (data[tail] == k) {
            tail++;
        }
    }

    return (tail-head-1);
}
 
 
int main()
{
    int array[] = {1, 1, 1, 3, 3, 3, 3, 4, 5, 6};
    int array1[] = {3, 3, 3, 3};
    int number = sizeof(array) / sizeof(int);

    cout << getNumberOfK(array, number, 2) << endl;
    cout << getNumberOfK(array, number, 3) << endl;
    cout << getNumberOfK(array1, number, 3) << endl;
    cout << getNumberOfK(array1, number, 2) << endl;

    return 0;
}

#endif


#if (TIMU == 39)

// 39. 二叉树的深度

/*
对于树的问题基本都可以通过递归来解决。
一棵二叉树的深度，等于它的左子树深度和右子树深度的较大者+1；
递归的结束条件就是：该结点为空，深度为0；
*/

int TreeDepth(TreeNode* pRoot){
    if(pRoot == NULL)
        return 0;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    return left > right ? (left+1) : (right+1);
}

int main()
{
    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(3);
    TreeNode* pNode4 = createTreeNode(4);
    TreeNode* pNode5 = createTreeNode(5);
    TreeNode* pNode6 = createTreeNode(6);
    TreeNode* pNode7 = createTreeNode(7);

    connectTreeNode(pNode1, pNode2, pNode3);
    connectTreeNode(pNode2, pNode4, pNode5);
    connectTreeNode(pNode3, pNode6, pNode7);

    cout << TreeDepth(pNode1) << endl;

    return 0;
}

#endif


#if (TIMU == 40)

// 40. 判断平衡二叉树

/*
对于树的问题基本都可以通过递归来解决。
一棵二叉树的深度，等于它的左子树深度和右子树深度的较大者+1；
递归的结束条件就是：该结点为空，深度为0；
*/

// 参考代码 1: 重复遍历结点
int TreeDepth(TreeNode* pRoot){
    if(pRoot == NULL)
        return 0;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    return left > right ? (left+1) : (right+1);
}

bool IsBalanced(TreeNode* pRoot)
{
    if(pRoot == NULL)
        return true;
    int left = TreeDepth(pRoot->left);
    int right = TreeDepth(pRoot->right);
    int diff = left-right;
    if (diff > 1 || diff < -1) {
        return false;
    }
    return IsBalanced(pRoot->left) && IsBalanced(pRoot->right);
}

// 参考代码 2: 遍历一遍结点
bool IsBalanced_1(TreeNode* pRoot, int& depth){
    if(pRoot == NULL){
        depth = 0;
        return true;
    }
    int left,right;
    int diff;
    if(IsBalanced_1(pRoot->left, left) && IsBalanced_1(pRoot->right, right)){
        diff = left - right;
        if(diff <= 1 && diff >= -1){
            depth = left > right ? left+1 : right+1;
            return true;
        }
    }

    return false;
}
 
bool IsBalancedTree(TreeNode* pRoot){
    int depth=0;
    return IsBalanced_1(pRoot, depth);
}

int main()
{

    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(3);
    TreeNode* pNode4 = createTreeNode(4);
    TreeNode* pNode5 = createTreeNode(5);
    TreeNode* pNode6 = createTreeNode(6);
    TreeNode* pNode7 = createTreeNode(7);


    connectTreeNode(pNode1, pNode2, pNode3);
    connectTreeNode(pNode2, pNode4, pNode5);
    connectTreeNode(pNode5, pNode6, pNode7);

    cout << IsBalanced(pNode1) << endl;

    cout << IsBalancedTree(pNode1) << endl;

    return 0;
}

#endif

#if (TIMU == 411)
// 41.1 和为s的两个数字

// 自编代码

vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    vector<int> numbers;
    int head = 0;
    int tail = array.size()-1;

    if (tail == 0) {
        return numbers;
    }

    while (head < tail) {
        if (array[head] + array[tail] == sum) {
            numbers.push_back(array[head]);
            numbers.push_back(array[tail]);
            break;
        } else if (array[head] + array[tail] > sum) {
            tail--;
        } else {
            head++;
        }
    }

    return numbers;
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> vec(array, array+sizeof(array)/sizeof(int));
    vector<int> numbers;

    for (int i = 0; i < vec.size(); i++) {
        cout << i << ":" << vec[i] << endl;
    }

    numbers = FindNumbersWithSum(vec, 11);
    if (numbers.empty()) {
        cout << "numbers is empty!" << endl;
    } else {
        cout << "numbers = " << numbers[0] << "," << numbers[1] << endl;
    }

    return 0;
}


#endif


#if (TIMU == 412)
// 41.2 和为s的连续正数序列

// 自编代码
vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    vector<int> numbers;
    int length = array.size();
    int head = 0;
    int tail = 0;
    int sum1 = 0;

    if (array.empty()) {
        return numbers;
    }

    while (head < length) {
        sum1 += array[tail];
        if (sum1 == sum) {
            while (head <= tail) {
                numbers.push_back(array[head++]);
            }
            numbers.push_back(-1);
            head++;
            tail=head;
            sum1=0;
        } else if (sum1 > sum) {
            head++;
            tail=head;
            sum1=0;
        } else {
            if (tail >= length) {
                head++;
                tail=head;
                sum1=0;
            }
            tail++;
        }
    }

    return numbers;
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> vec(array, array+sizeof(array)/sizeof(int));
    vector<int> numbers;
    int index = 0;

    for (int i = 0; i < vec.size(); i++) {
        cout << i << ":" << vec[i] << endl;
    }

    numbers = FindNumbersWithSum(vec, 15);
    if (numbers.empty()) {
        cout << "numbers is empty!" << endl;
    } else {
        while (index < numbers.size()) {
            cout << numbers[index++] << ", ";
        }
        cout << endl;
    }

    return 0;
}


#endif

#if (TIMU == 42)

// 42. 翻转单词顺序

void Reverse(char* pBegin,char* pEnd){
    if(pBegin==NULL || pEnd==NULL)
        return;
    char tmp;
    while(pBegin<pEnd){
        tmp=*pBegin;
        *pBegin=*pEnd;
        *pEnd=tmp;
        pBegin++;
        pEnd--;
    }
}
 
char* ReverseSentence(char* pData){
    if(pData==NULL)
        return NULL;
 
    char* pBegin = pData;
    /*
    char* pEnd=pData;
    while(*pEnd!='\0')
        pEnd++;
    pEnd--;
    */
    int len = strlen(pData);
    char* pEnd = pData + len-1;
 
    Reverse(pBegin,pEnd);
 
    pBegin=pEnd=pData;
    while(*pBegin!='\0'){
        if(*pBegin==' '){
            pBegin++;
            pEnd++;
        }
        else if(*pEnd==' ' || *pEnd=='\0'){
            Reverse(pBegin,--pEnd);
            pBegin=++pEnd;
        }
        else{
            pEnd++;
        }
    }
 
    return pData;
}

int main()
{
    char str[] = "I am a student.";
    char *str_rev;

    str_rev = reverse(str);

    return 0;
}


#endif


#if (TIMU == 43)

// 43. n个骰子的点数
// 把n个骰子仍在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

// 自编代码
void PrintProbability(int n)
{
}

int main()
{
    
    return 0;
}

#endif



#if (TIMU == 44)

// 44. 扑克牌的顺子
// 从扑克牌中随机抽5张牌，判断是不是一个顺子


// 自编代码

bool IsContinuous(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end());

    if ((numbers[1]-numbers[0]==1 || numbers[0]-numbers[1]==12) &&
        (numbers[2]-numbers[1]==1 || numbers[1]-numbers[2]==12) &&
        (numbers[3]-numbers[2]==1 || numbers[2]-numbers[3]==12) &&
        (numbers[4]-numbers[3]==1 || numbers[4]-numbers[0]==12)) {
        return true;
    }

    return false;
}

int main()
{
    int array[] = {1,2,3,4,5};
    vector<int> numbers(array, array+sizeof(array)/sizeof(int));

    cout << IsContinuous(numbers) << endl;

    return 0;
}

#endif


#if (TIMU == 46)

// 46. 求1+2+3+....+n
// 求1+2+3+...+n，要求不能使用乘除法，for,while,if,else,switch,case等关键字及条件判断语句(a?b:c)。
/*
1、构造函数
在类中定义静态成员变量N和sum，在构造函数中++N,sum+=N；如此一来，创建n个该类型的实例，就会调用n次构造函数，对应的静态变量也就随着更新。

2、虚函数
使用递归时，既然不能再一个函数中判断是不是终止递归，那么不妨定义两个函数，一个函数充当递归函数，一个负责处理递归的结束条件；
需要解决的问题就是如何在两个函数中二选一，自然是通过bool变量。如果对n连续做两次反运算，即!!n，那么非零的n转换为true，0转换为false。

3、函数指针
在纯C语言中，不能使用虚函数，此时可以使用函数指针来模拟。

4、模板类型
让编译器帮助完成类似于递归的计算。
*/

// 参考代码

class Sum{
public:
    Sum(){ ++N; sum+=N; };
    static void reset(){ N=0; sum=0;};
    static unsigned int getSum(){ return sum; };
private:
    static unsigned int N;
    static unsigned int sum;
};
 
unsigned int Sum::N=0;
unsigned int Sum::sum=0;
 
int Sum_Solution(int n)
{
    Sum::reset();
    Sum* a=new Sum[n];
    delete[] a;
    a=NULL;

    return Sum::getSum();
}

int main()
{
    cout << Sum_Solution(5) << endl;

    return 0;
}

#endif

#if (TIMU == 47)

// 47. 不用加减乘除做加法
// 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

void print_2(int val2)
{
    unsigned char *p = (unsigned char*)&val2 + 3; //从低位到高位,低端字节计算机
    for(int k = 0; k <= 3; k++)
    {
        int val2 = *(p-k);
        for (int i = 7; i >= 0; i--)
        {
            if(val2 & (1 << i))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }
}

// 自编代码
int Add(int num1, int num2)
{
    int bit = 1;
    int bit_start = 1;
    int carry = 0;
    int num = 0;

    while(bit != 0) {
        if ((num1&bit) && (num2&bit)) {
            if (carry) {
                num = num | bit;
            }
            carry = 1;
        } else if ((num1&bit) || (num2&bit)) {
            if (carry == 0) {
                num = num | bit;
            }
        } else {
            if (carry) {
                num = num | bit;
            }
            carry = 0;
        }
        bit = bit << 1;
    }

    return num;
}

// 参考代码
// non-recursive
int BitAdd(int num1,int num2)
{
    int sum = 0;
    int carry = 0;
    while(num2 != 0){
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    return num1;
}

// recursive
int BitAdd_1(int &num1,int &num2)
{
    if(num2 == 0)
        return num1;
    if(num1 == 0)
        return num2;
    int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;
    return BitAdd(sum, carry);
}


int main()
{
    //int num1 = 123456789;
    //int num2 = 123456789;
    int num1 = -1;
    int num2 = -1112;

    cout << num1 << " + " << num2 << " = " << Add(num1, num2) << endl;

    return 0;
}

#endif


#if (TIMU == 48)

// 48. 不能被继承的类
/*
1、把构造函数设为私有函数

在C++中子类的构造函数会自动调用父类的构造函数，子类的析构函数也会自动调用父类的构造函数，要想一个类不能被继承，只要把它的构造函数和析构函数都定义为私有函数。

当一个类试图从它那继承的时候，必然会由于调用构造函数、析构函数而导致编译错误。

但如果构造函数 、析构函数都为私有函数，怎么得到该类型的实例呢？可以通过定义公有的静态函数来创建和释放类的实例。

这样我们只能得到位于堆上的实例，而得不到栈上的实例。

*/

class SealedClass{
public:
    static SealedClass* GetInstance(){
        return new SealedClass();
    }
 
    static void DeleteInstance(SealedClass* pInstance){
        delete pInstance;
    }
private:
    SealedClass(){};
    ~SealedClass(){};
};


int main()
{

    return 0;
}

#endif


#if (TIMU == 49)
// 49. 把字符串转换为整数
// 考虑+-、空格、非数字字符，以及溢出问题

long long str2int(const char* str)
{
    int flag = 1;
    bool number = false;
    bool pre = false;
    long long iNumber = 0;
    int index = 0;

    if (str == NULL) {
        return 0;
    }

    while (str[index] != '\0') {
        if (str[index] ==' ') {
            ;
        } else if (str[index] == '+') {
            flag = 1;
            pre = true;
            if (number == true) {
                return 0;
            }
        } else if (str[index] == '-') {
            flag = -1;
            pre = true;
            if (number == true) {
                return 0;
            }
        } else if (str[index] >= '0' && str[index] <= '9') {
            number = true;
        } else {
            return 0;
        }
        index++;
    }

    index = 0;
    while (str[index] != '\0') {
        if (str[index] >= '0' && str[index] <= '9') {
            iNumber = 10*iNumber + flag*(str[index] - '0');
            if ((flag == 1 && iNumber > 0x7fffffff) ||
                (flag == -1 && (signed int)iNumber < 0x80000000) ) {
                return 0;
            }
        }
        index++;
    }

    return iNumber;
}

int main()
{
    long long number = 0;

    number = str2int("12345");
    cout << "str = " << "12345" << ", number = "<< number << endl;

    number = str2int("-12345");
    cout << "str = " << "-12345" << ", number = "<< number << endl;

    return 0;
}


#endif


#if 0

// 参考代码

 
 
enum Status {kValid=0,kInvalid};
int g_nStatus=kInvalid;
 
long long StrToIntCore(const char* str,bool minus){
    long long num=0;
    int flag=minus?-1:1;
 
    while(*str!='\0'){
        if(*str>='0' && *str<='9'){
            num=num*10+flag*(*str-'0');
            if((!minus && num>0x7fffffff) || (minus && (signed int)num<0x80000000)){
                num=0;
                break;
            }
            str++;
        }
        else{
            num=0;
            break;
        }
    }
    if(*str=='\0')
        g_nStatus=kValid;
 
    return num;
}
 
int StrToInt(const char* str){
    g_nStatus=kInvalid;
    long long num=0;
 
    bool minus=false;
 
    if(str!=NULL && *str!='\0'){
        while(*str==' '){
            str++;
            if(str==NULL)
                return 0;
        }
        if(*str=='+')
            str++;
        if(*str=='-'){
            str++;
            minus=true;
        }
        if(*str!='\0')
            num=StrToIntCore(str,minus);
    }
 
    return (int)num;
}
 
 
int main()
{
    cout << StrToInt("  -998") << endl;
    cout << g_nStatus <<endl;
    cout << StrToInt("123") << endl;
    return 0;
}

#endif


#if (TIMU == 51)

// 51. 数组中重复的数字
/*在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
*/
 
bool duplicate(int numbers[], int length, int* duplication)
{
    if (length <= 1) {
        duplication = NULL;
        return false;
    }

    for (int i = 0; i < length; i++) {
        while (numbers[i] != i) {
            if (numbers[numbers[i]] == numbers[i]) {
                *duplication = numbers[i];
                return true;
            }
            int tmp = numbers[i];
            numbers[i] = numbers[tmp];
            numbers[tmp] = tmp;
        }
    }
 
    return false;
}

int main()
{
    int array[] = {1, 3, 4, 5, 7, 2, 4};
    int length = sizeof(array)/sizeof(int);
    int duplication = -1;

    bool rc = duplicate(array, length, &duplication);
    cout << "rc = " << rc << ", duplication = "<< duplication << endl;

    return 0;
}


#endif


#if 0

// 参考代码
 
 
enum Status {kValid=0,kInvalid};
int g_nStatus=kInvalid;
 
long long StrToIntCore(const char* str,bool minus){
    long long num=0;
    int flag=minus?-1:1;
 
    while(*str!='\0'){
        if(*str>='0' && *str<='9'){
            num=num*10+flag*(*str-'0');
            if((!minus && num>0x7fffffff) || (minus && (signed int)num<0x80000000)){
                num=0;
                break;
            }
            str++;
        }
        else{
            num=0;
            break;
        }
    }
    if(*str=='\0')
        g_nStatus=kValid;
 
    return num;
}
 
int StrToInt(const char* str){
    g_nStatus=kInvalid;
    long long num=0;
 
    bool minus=false;
 
    if(str!=NULL && *str!='\0'){
        while(*str==' '){
            str++;
            if(str==NULL)
                return 0;
        }
        if(*str=='+')
            str++;
        if(*str=='-'){
            str++;
            minus=true;
        }
        if(*str!='\0')
            num=StrToIntCore(str,minus);
    }
 
    return (int)num;
}
 
 
int main()
{
    cout << StrToInt("  -998") << endl;
    cout << g_nStatus <<endl;
    cout << StrToInt("123") << endl;
    return 0;
}

#endif

#if (TIMU == 52)

// 52. 构建乘积数组
/* 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
   其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

// 自编代码
vector<int> multiply(const vector<int>& A)
{
    int length = A.size();
    int multi = 1;
    vector<int> B;

    for (int i = 0; i < length; i++) {
        multi = 1;
        for (int j = 0; j < i; j++) {
            multi *= A[j];
        }
        for (int j = i+1; j < length; j++) {
            multi *= A[j];
        }
        B.push_back(multi);
    }

    return B;
}

// 参考代码
vector<int> multiply1(const vector<int>& A)
{
    int len=A.size();
    if(len<1)
        return vector<int>();
    vector<int> B(len,1);
    vector<int> front(len,1);
    vector<int> back(len,1);

    for(int i=1;i<len;i++){
        front[i]=front[i-1]*A[i-1];
    }

    for(int i=len-2;i>=0;i--){
        back[i]=back[i+1]*A[i+1];
    }

    for(int i=0;i<len;i++)
        B[i]=front[i]*back[i];

    return B;   
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array)/sizeof(int);
    vector<int> vecA(array, array+length);
    vector<int> vecB;

    for (int i = 0; i < length; i++) {
        cout << vecA[i] << endl;
    }

    vecB = multiply(vecA);

    cout << "my code:" << endl;
    for (int i = 0; i < length; i++) {
        cout << vecB[i] << endl;
    }

    vecB.clear();
    vecB = multiply1(vecA);

    cout << "ref code:" << endl;
    for (int i = 0; i < length; i++) {
        cout << vecB[i] << endl;
    }

    return 0;
}

#endif

#if (TIMU == 53)

// 53. 正则表达式匹配
/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有
字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

// 参考代码
bool matchCore(char* str,char* pattern)
{
    if(*str=='\0' && *pattern=='\0')
        return true;
    if(*str!='\0' && *pattern=='\0')
        return false;

    if(*(pattern+1)=='*'){
        if(*str==*pattern || (*str!='\0' && *pattern=='.'))
            return matchCore(str, pattern+2) || matchCore(str+1, pattern+2) || 
                   matchCore(str+1, pattern);
        else
            return matchCore(str, pattern+2);
    }

    if(*str==*pattern || (*str!='\0' && *pattern=='.'))
        return matchCore(str+1, pattern+1);

    return false;
}

bool match(char* str, char* pattern)
{
    if(str==NULL || pattern==NULL)
        return false;
    return matchCore(str, pattern);
}

int main()
{
    char str[] = "aaa";
    char pattern[256] = {0}; 

    strcpy(pattern, "a.a");
    cout << match(str, pattern) << endl;
    strcpy(pattern, "ab*ac*a");
    cout << match(str, pattern) << endl;
    strcpy(pattern, "aa.a");
    cout << match(str, pattern) << endl;
    strcpy(pattern, "ab*a");
    cout << match(str, pattern) << endl;

    return 0;
}

#endif


#if (TIMU == 55)

// 55. 字符流中第一个不重复的字符
// 字符流：像流水一样的字符，一去不复返，意味着只能访问一次。所以要将字符流保存起来进行处理

/*
class Solution
{
private:
    string str;
    int count[256]={0};
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        str+=ch;
        count[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len=str.size();
        for(int i=0;i<len;i++){
            if(count[str[i]]==1)
                return str[i];
        }
        return '#';
    }
 
};
*/

char getfirstsingle(char* str){
    int length = strlen(str)+1;
    int pCount[256] = {0};

    for(int i = 0; i < length; i++) {
        pCount[str[i]]++;
    }

    for(int i = 0; i < length; i++) {
        if (pCount[str[i]] == 1) {
            return str[i];
        }
    }

    return 0;
}

int main()
{
    char str[] = "I am a student!I am happy!";
    char single;

    single = getfirstsingle(str);
    cout << "single = " << single << endl;

    return 0;
}

#endif

#if (TIMU == 56)

// 56. 链表中环的入口结点
/*
1、哈希表

遍历整个链表，并将链表结点存入哈希表中（这里我们使用容器set），如果遍历到某个链表结点已经在set中，那么该点即为环的入口结点；

2、两个指针

如果链表存在环，那么计算出环的长度n，然后准备两个指针pSlow，pFast，pFast先走n步，然后pSlow和pFase一块走，当两者相遇时，即为环的入口处；

3、改进

如果链表存在环，我们无需计算环的长度n，只需在相遇时，让一个指针在相遇点出发，另一个指针在链表首部出发，然后两个指针一次走一步，当它们相遇时，就是环的入口处。（这里就不说明为什么这样做是正确的，大家可以在纸上推导一下公式）

*/

ListNode* findLoopNode(ListNode* pHead)
{
    ListNode* node1;
    ListNode* node2;

    if (pHead == NULL) {
        return NULL;
    }

    node1 = pHead;
    node2 = pHead;
    while(node1 != NULL && node2 != NULL){
        if (node1->next == NULL || node2->next == NULL ||
            node2->next->next == NULL) {
            return NULL;
        }
        node1 = node1->next;
        node2 = node2->next->next;
        if (node1 == node2) {
            break;
        }
    }

    if(node2 != NULL){
        node1 = pHead;
        while(node1 != node2){
            node1 = node1->next;
            node2 = node2->next;
        }
    }

    return node1;
}

int main(){
    int length = 10;
    ListNode *head = new ListNode();
    ListNode *node;
    int index = 0;

    create_linklist(head, length);
    node = head->next;
    while(node != NULL && index++ < 20) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    node = findLoopNode(head->next);
    if (node != NULL) {
        cout << "nodeLoop = " << node->val << " " << endl;
    } else {
        cout << "no loop" << endl;
    }
    
    return 0;
}

#endif


#if (TIMU == 57)

// 57. 删除链表中的重复结点

ListNode* deleteDuplication(ListNode* pHead)
{
    ListNode* node;
    ListNode* tmp_node;

    if (pHead == NULL) {
        return NULL;
    }

    node = pHead;
    while(pHead->next != NULL){
        if (pHead->val == pHead->next->val) {
            tmp_node = pHead->next;
            pHead->next = pHead->next->next;
            delete tmp_node;
        } else {
            pHead = pHead->next;
        }
    }

    return node;
}

int main(){
    int length = 10;
    ListNode *head = new ListNode();
    ListNode *node;

    create_linklist(head, length);
    node = head->next;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    node = deleteDuplication(head->next);
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}

#endif


#if (TIMU == 58)

// 58. 二叉树的下一个结点: 中序遍历的下一个结点

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode == NULL)
        return NULL;
    cout << "Y :" << pNode->val << endl;

    if(pNode->right != NULL) {
        TreeLinkNode* pTmp = pNode->right;
        while(pTmp->left != NULL){
            pTmp = pTmp->left;
        }
        return pTmp;
    } else {
        while(pNode->next != NULL) {
            if(pNode == pNode->next->left)
                return pNode->next;
            pNode = pNode->next;
            
            cout << "X :" << pNode->val << endl;
        }
        return NULL;
    }
}

TreeLinkNode* GetNext1(TreeLinkNode* pNode)
{
    TreeLinkNode* curNode = NULL;

    //第一步：判断是否有右孩子
    if(pNode->right != NULL){
        curNode = pNode->right;
        while(curNode->left != NULL)
            curNode = curNode->left;
        return curNode;
    }
    //第二步：判断是否是其父节点的左孩子
    if(pNode->next == NULL)
        return NULL;
    if(pNode == pNode->next->left) {
        return pNode->next;
    }
    //第三步：向上找其父节点，直到父节点是其父节点的父节点的左孩子
    curNode = pNode->next;
    while(curNode->next != NULL){
        if(curNode == curNode->next->left) {
            return curNode->next;
        }
        //继续向上找父节点
        curNode = curNode->next;
    }
    return NULL;
}

// 自编代码
TreeLinkNode* GetNext2(TreeLinkNode* pNode)
{
    TreeLinkNode* curNode = NULL;

    if (pNode->right != NULL) {
        curNode = pNode->right;
        while(curNode->left != NULL) {
            curNode = curNode->left;
        }
        return curNode;
    } else if (pNode->next == NULL) {
        return NULL;
    } else if (pNode == pNode->next->left){
        return pNode->next;
    } else {
        curNode = pNode->next;
        while(curNode->next != NULL) {
            if (curNode == curNode->next->left) {
                return curNode->next;
            }
            curNode = curNode->next;
        }
    }
    return NULL;
}

int main()
{
    TreeLinkNode* pNode;

    TreeLinkNode* pNode1 = createTreeLinkNode(1);
    TreeLinkNode* pNode2 = createTreeLinkNode(2);
    TreeLinkNode* pNode3 = createTreeLinkNode(3);
    TreeLinkNode* pNode4 = createTreeLinkNode(4);
    TreeLinkNode* pNode5 = createTreeLinkNode(5);
    TreeLinkNode* pNode6 = createTreeLinkNode(6);
    TreeLinkNode* pNode7 = createTreeLinkNode(7);

    connectTreeLinkNode(pNode1, pNode2, pNode3);
    connectTreeLinkNode(pNode2, pNode4, pNode5);
    connectTreeLinkNode(pNode3, pNode6, pNode7);
    cout << "         8\n     6      10\n  5    7  9    11\n" << endl;

/*
    pNode = GetNext(pNode1);
    cout << pNode1->val << "\t"<< pNode->val << endl;
    pNode = GetNext(pNode2);
    cout << pNode2->val << "\t"<< pNode->val << endl;
    pNode = GetNext(pNode3);
    cout << pNode3->val << "\t"<< pNode->val << endl;
    pNode = GetNext(pNode4);
    cout << pNode4->val << "\t"<< pNode->val << endl;
    pNode = GetNext(pNode5);
    cout << pNode5->val << "\t"<< pNode->val << endl;
    pNode = GetNext(pNode6);
    cout << pNode6->val << "\t"<< pNode->val << endl;
    pNode = GetNext(pNode7);
    cout << pNode7->val << "\t"<< pNode->val << endl << endl;
*/
/*
    pNode = GetNext1(pNode1);
    cout << pNode1->val << "\t"<< pNode->val << endl;
    pNode = GetNext1(pNode2);
    cout << pNode2->val << "\t"<< pNode->val << endl;
    pNode = GetNext1(pNode3);
    cout << pNode3->val << "\t"<< pNode->val << endl;
    pNode = GetNext1(pNode4);
    cout << pNode4->val << "\t"<< pNode->val << endl;
    pNode = GetNext1(pNode5);
    cout << pNode5->val << "\t"<< pNode->val << endl;
    pNode = GetNext1(pNode6);
    cout << pNode6->val << "\t"<< pNode->val << endl;
    pNode = GetNext1(pNode7);
    cout << pNode7->val << "\t"<< pNode->val << endl;
*/

    pNode = GetNext2(pNode1);
    cout << pNode1->val << "\t"<< pNode->val << endl;
    pNode = GetNext2(pNode2);
    cout << pNode2->val << "\t"<< pNode->val << endl;
    pNode = GetNext2(pNode3);
    cout << pNode3->val << "\t"<< pNode->val << endl;
    pNode = GetNext2(pNode4);
    cout << pNode4->val << "\t"<< pNode->val << endl;
    pNode = GetNext2(pNode5);
    cout << pNode5->val << "\t"<< pNode->val << endl;
    pNode = GetNext2(pNode6);
    cout << pNode6->val << "\t"<< pNode->val << endl;
    pNode = GetNext2(pNode7);
    cout << pNode7->val << "\t"<< pNode->val << endl;

    return 0;
}


#endif


#if (TIMU == 59)

// 59. 对称的二叉树: 判断二叉树是否对称


// 自编代码
bool Symetrical(TreeNode* pLeft,TreeNode* pRight){
    if(pLeft==NULL && pRight==NULL)
        return true;
    if(pLeft==NULL || pRight==NULL)
        return false;
    if(pLeft->val != pRight->val)
        return false;
    return Symetrical(pLeft->left,pRight->right) && Symetrical(pLeft->right,pRight->left);
}

bool isSymmetrical(TreeNode* pRoot)
{
    return Symetrical(pRoot, pRoot);
}

int main()
{
/*
    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(3);
    TreeNode* pNode4 = createTreeNode(4);
    TreeNode* pNode5 = createTreeNode(5);
    TreeNode* pNode6 = createTreeNode(6);
    TreeNode* pNode7 = createTreeNode(7);
*/

    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(2);
    TreeNode* pNode4 = createTreeNode(3);
    TreeNode* pNode5 = createTreeNode(4);
    TreeNode* pNode6 = createTreeNode(4);
    TreeNode* pNode7 = createTreeNode(3);

    connectTreeNode(pNode1, pNode2, pNode3);
    connectTreeNode(pNode2, pNode4, pNode5);
    connectTreeNode(pNode3, pNode6, pNode7);

    cout << isSymmetrical(pNode1) << endl;

    return 0;
}

#endif


#if (TIMU == 60)

// 60. 把二叉树打印成多行

void printTreeFromTopToBottom1(TreeNode* pRoot)
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

int main()
{
    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(3);
    TreeNode* pNode4 = createTreeNode(4);
    TreeNode* pNode5 = createTreeNode(5);
    TreeNode* pNode6 = createTreeNode(6);
    TreeNode* pNode7 = createTreeNode(7);

    connectTreeNode(pNode1, pNode2, pNode3);
    connectTreeNode(pNode2, pNode4, pNode5);
    connectTreeNode(pNode3, pNode6, pNode7);

    printTreeFromTopToBottom1(pNode1);

    return 0;
}

#endif


#if (TIMU == 61)

// 61. 按之字形顺序打印二叉树
/* 
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

vector<vector<int> > Print(TreeNode* pRoot)
{
    int direct = 0;
    vector<int> vec;
    vector<vector<int> > vec_list;
    if(pRoot == NULL)
        return vec_list;
    stack<TreeNode*> rStack;
    queue<TreeNode*> btnQueue;
    btnQueue.push(pRoot);
    while(!btnQueue.empty() || !rStack.empty())
    {
        TreeNode* pTemp;
        while(!btnQueue.empty()) {
            rStack.push(btnQueue.front());
            btnQueue.pop();
        }
        while(!rStack.empty()) {
            pTemp = rStack.top();
            rStack.pop();
            if (direct) {
                if(pTemp->right) {
                    btnQueue.push(pTemp->right);
                }
                if(pTemp->left) {
                    btnQueue.push(pTemp->left);
                }
            } else {
                if(pTemp->left) {
                    btnQueue.push(pTemp->left);
                }
                if(pTemp->right) {
                    btnQueue.push(pTemp->right);
                }
            }
            vec.push_back(pTemp->val);
        }
        direct = !direct;
        vec_list.push_back(vec);
        vec.clear();
    }

    return vec_list;
}

int main()
{
    TreeNode* pNode1 = createTreeNode(1);
    TreeNode* pNode2 = createTreeNode(2);
    TreeNode* pNode3 = createTreeNode(3);
    TreeNode* pNode4 = createTreeNode(4);
    TreeNode* pNode5 = createTreeNode(5);
    TreeNode* pNode6 = createTreeNode(6);
    TreeNode* pNode7 = createTreeNode(7);

    vector<vector<int> > vec_list;

    connectTreeNode(pNode1, pNode2, pNode3);
    connectTreeNode(pNode2, pNode4, pNode5);
    connectTreeNode(pNode3, pNode6, pNode7);

    printTreeFromTopToBottom(pNode1);

    vec_list = Print(pNode1);
    int i = 0, j = 0;
    while(i < vec_list.size()) {
        while(j < vec_list[i].size()) {
            cout << vec_list[i][j] << "\t";
            j++;
        }
        cout << endl;
        j = 0;
        i++;
    }

    return 0;
}

#endif


