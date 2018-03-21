
#define TIMU    61

#include "common.h"

#if (TIMU == 1)
// 1. ��ֵ���������
/*
��ֵ�����������ע���ĵ㣺

1���Ƿ񽫷���ֵ����������Ϊ�����͵����ã����ں�������ǰ����ʵ����������ã���*this��ֻ�з���һ�����ã��ſ�������������ֵ��

2���Ƿ�Ѵ����������������Ϊ�������á��������Ĳ����������ö���ʵ������ô���βε�ʵ�λ����һ�θ��ƹ��캯�����Ѳ�������Ϊ���ÿ��Ա�����������ν���ģ�����ߴ����Ч�ʡ�ͬʱ���ڸ�ֵ����������в���ı䴫���ʵ����״̬�����Ӧ��Ϊ��������ò�������const�ؼ��֡�

3���Ƿ��ͷ�ʵ���������е��ڴ棬��������ڷ������ڴ�֮ǰ�ͷ��������еĿռ䣬���򽫳����ڴ�й¶��

4�������Ը�ֵ���Ƿ��жϴ���Ĳ����͵�ǰʵ��*this�ǲ���ͬһ��ʵ���������ͬһ�����򲻽��и�ֵ������ֱ�ӷ��ء�

5��ע��ǳ���������

���࿼�ǣ��쳣��ȫ�Եȡ�

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
    // ��ͨ���������캯������һ����ʱ����, �ٽ�����ʱ����������m_data
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

// 3. ��λ�������

//��ά����Ĳ��ң����Ͻǰ汾��  
bool find(int* matrix, int rows, int columns, int number)  //����һά���a 
{  
    if(matrix != NULL && rows >0 && columns >0)            //ָ���п��Լ��߽��ж�  
    {  
        int row = 0;  
        int column = columns - 1;               //�Ӿ�������Ͻǿ�ʼ���� 
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
     
//���½ǰ汾
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

// 4. �滻�ո�


// �Ա����
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

// lengthΪ�ַ�����string��������
void ReplaceBlank(char string[], int length)
{
    if(string == NULL || length <= 0)
        return;
 
    // originalLengthΪ�ַ���string��ʵ�ʳ���
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
 
    // newLengthΪ�ѿո��滻��?20��֮��ĳ���
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
    cout << "��������1��������ַ����а����ո�" << endl;  
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

// 5. ��β��ͷ��ӡ����

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

// ��ջ
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
// �ο�����


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


// �Լ�д������1 �ݹ�
void printlist(node_t *node)
{
    if (node != NULL) {
        if (node->next != NULL) {
            printlist(node->next);
        }
        cout << node->val << endl;
    }
}

// ����2 ����ջ���������ص�
void PrintListReversingly(node* L)  
{  
    stack<node*> nodes;

    //������ջ
    node* pNode;
    pNode = L;
    while(pNode)
    {
        nodes.push(pNode);
        pNode = pNode->next;
    }
    //��ӡ
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

// 6. �ؽ�������

/*
�ڶ�������������������У���һ�����������ĸ�����ֵ������������������������ֵ������������ֵ��
�ڶ�������������������У����ڵ�λ�������м䣬���ڵ����Ϊ���������ұ�Ϊ��������
����������Ϣ�����ǿ��ԣ�
��ͨ��������������ҵ����ڵ㣬
Ȼ������������������ҵ����ڵ㣬�����Ϳ���ȷ������������������
�����ٻص���������������ҵ������������������ظ��������裨�ݹ飩��
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

// �ο�����
/*
ǰ�����{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}

i-starin ���ڼ��㵱ǰ�ڵ��������ڵ����;
i-starin+starpre ��ȷ����ǰ�ڵ���������pre���λ��;
�����������������Ϊ startIn �� i-1, �����������������Ϊ i+1 �� endIn;
�����������+ǰ��������ص�, pre[starpre+1]���ǵ�ǰ�ڵ�����ӽڵ�, pre[i-starin+starpre+1]���ǵ�ǰ�ڵ�����ӽڵ�;
��������Ǹ��ж�����, Խ�缴�����ӽڵ㲻����

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

// 7. ������ջʵ�ֶ���

// �Ա����
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

// �ο�����

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

// 8. ��ת�������С����
/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
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

// �ο�����
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

// 9. 쳲���������

// �Ա����
int fun(int n)
{
    if (n == 0 || n == 1) {
        return n;
    } else {
        return (fun(n-1) + fun(n-2));
    }
}

// ����: һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ף������������һ��n��̨���ܹ��ж�����������
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

// 10. ��������1�ĸ���

// �Ա����
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

// �ο�����
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
4��λ���������Ŀ

    ��һ������ж�һ�������ǲ���2�������η���

if(n&(n-1)==0) return true;

    ������������m,n,������Ҫ�ı�m�Ķ����Ʊ�ʾ�еĶ���λ���ܵõ�n��

int x=m^n; return NumberOf1(x);����

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

// 11. ��ֵ�������η�

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

// 12. ��ӡ1������nλ��

// �ο��Ա����
/*
nλ����ʮ��������ʵ����n����0��9��ȫ���С��������ֵ�ÿһλ����0��9����һ�飬�͵õ������е�ʮ��������

ȫ�����õݹ������ʵ�֣����ֵ�ÿһλ��������0-9��һ����Ȼ��������һλ���ݹ�Ľ��������������Ѿ����������ֵ����һλ��

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

// �ο����� 1
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

// �ο����� 2

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

// 13. ��O(1)ʱ����ɾ��������

/*
�ڸ������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ����ɾ���ý�㡣�������뺯���Ķ������£�
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
        //ɾ����β�ڵ�
        ListNode *del = p->next;
        p->val = del->val;
        p->next = del->next;
        delete del;
        del = NULL;
    }
    else if(*head == p)
    {
        //ֻ��һ���ڵ�
        delete p;
        *head = NULL;
    }
    else
    {
        //���һ�֣�ɾ���ڵ���β�ڵ�
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

// 14. ��������˳��ʹ����λ��ż��ǰ��

// �Ա����
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

// �Ա���� 1
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

// �ο�����
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

// 15. �����е�����k�����

// �Ա����
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

// �ο�����
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

// 16. ��ת����

// �ο�����

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

// 17. �ϲ��������������

// �Ա����

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

// 18. �����ӽṹ

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
    /*��������:
    {8,8,7,9,2,#,#,#,#,4,7},{8,9,2}
    
    ��Ӧ���Ӧ��?
    
    true
    
    ������?
    
    false
    */

    return 0;
}

#endif

#if (TIMU == 19)

// 19. �������ľ���

// �Ա����
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

// 20. ˳ʱ���ӡ����


// �Ա����
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

// 21. ����min������ջ

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

// 22. ջ��ѹ�롢��������

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

// 23. ���ϵ��´�ӡ������


// queue�ǵ�����У�deque��double-ended-queue����˫�����
// �Ա����

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
// �ο�����
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

// 24. �����������ĺ����������
/* ����һ���������飬�жϸ������ǲ���ĳ�������������ĺ�������Ľ��
   �������������������������ֶ�������ͬ��
   ����������: 
      1 ����
      2 left < root < right
*/

// �Ա����
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

// �Ա����
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
// ������
// 27. ������������˫������

/* ����һ�ö��������������ö���������ת����һ�������˫������
   Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/

// queue�ǵ�����У�deque��double-ended-queue����˫�����?

// �Ա����

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
// �ο�����

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
// 28. �ַ���������

/*
һ���ַ���������������ɣ���һ����Ϊ��һ���ַ����ڶ�����Ϊ����������ַ�
�������ַ��������У����Կ������������������п��ܳ����ڵ�һ��λ�õ��ַ���
���ѵ�һ���ַ��ͺ���������ַ�������Ȼ��̶���һ���ַ�������������ַ�������
��ʱ�԰Ѻ�����ַ����������֣���һ���ַ��ͺ�����ַ���Ȼ���ظ��������衣���ݹ�)
�������⣺N�ʺ�����
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

// 29. �����г��ִ�������һ�������
/*
1������1 ������Ȼ������λ��;
ʱ�临�Ӷ�O(nlogn)

2������2 ����Partition������O(n)�㷨����Ѱ�ҵ�k��k=n/2�������, ƽ��ʱ�临�Ӷȣ�O(n)

3������3 ���������ص㣬����Moore-Vote����?���ڸ����ֵĳ��ִ����������������ֳ��ִ����ĺͻ�Ҫ�࣬
��˿��Կ����ڱ�������ʱ��������ֵ��һ���������е�һ�����֣�һ���Ǵ�����
����������һ������ʱ�������һ��������֮ǰ�����������ͬ���������1�������ͬ��
�������1���������Ϊ0������Ҫ������һ�����֣����Ѵ����趨?����������Ҫ�ҵ�����
���ֵĴ����������������ֵĳ��ִ���֮�ͻ�Ҫ����Ҫ�ҵ����ֿ϶������һ�ΰѴ�����Ϊ1ʱ��Ӧ������?
ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)*/

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

// 30. ��С��k����

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

// �ο�����
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

    // �󶥶�
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

// 31. ���������������

// �Ա����

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

// �ο�����
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

// 32. ��1��n������1���ֵĴ���

// �ο�����
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

// 33. �������ų���С����

/*
1��ȫ����

����������������ֵ�ȫ���У�Ȼ���ÿ��ȫ����ƴ���������ƴ���������ֵ����ֵ��

2�������µ��������

�����������m,nƴ�ӳ�mn��nm�����mn<nm����ômӦ������n��ǰ�棬���Ƕ����ʱmС��n�����mn=nm�����Ƕ���m����n��
���Կ��ǽ�����ת���ַ�����һ����ֹ����ƴ��ʱ������������ַ�����ƴ�ӺͱȽ�����ʵ�֡�
���ڰ�����m��nƴ�������õ�mn��nm�����ǵ�λ��һ������ͬ�ģ���˱Ƚ����ǵĴ�Сֻ�谴���ַ�����С�ıȽϹ��򼴿ɡ�

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

// 34. ����
// �󰴴�С�����˳��ĵ�N��������

// �Ա����
// ����: ���г�ʱ
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

// �ο�����

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

// 35. ��һ��ֻ����һ�ε��ַ�

// �Ա����
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

// 36. �����е������

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

// 37. ��������ĵ�һ���������

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

// 38. ���������������г��ֵĴ���
// ���ֲ��ҵ�����һ����Ȼ��ǰ������

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

// 39. �����������

/*
���������������������ͨ���ݹ��������
һ�ö���������ȣ�����������������Ⱥ���������ȵĽϴ���+1��
�ݹ�Ľ����������ǣ��ý��Ϊ�գ����Ϊ0��
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

// 40. �ж�ƽ�������

/*
���������������������ͨ���ݹ��������
һ�ö���������ȣ�����������������Ⱥ���������ȵĽϴ���+1��
�ݹ�Ľ����������ǣ��ý��Ϊ�գ����Ϊ0��
*/

// �ο����� 1: �ظ��������
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

// �ο����� 2: ����һ����
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
// 41.1 ��Ϊs����������

// �Ա����

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
// 41.2 ��Ϊs��������������

// �Ա����
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

// 42. ��ת����˳��

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

// 43. n�����ӵĵ���
// ��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�

// �Ա����
void PrintProbability(int n)
{
}

int main()
{
    
    return 0;
}

#endif



#if (TIMU == 44)

// 44. �˿��Ƶ�˳��
// ���˿����������5���ƣ��ж��ǲ���һ��˳��


// �Ա����

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

// 46. ��1+2+3+....+n
// ��1+2+3+...+n��Ҫ����ʹ�ó˳�����for,while,if,else,switch,case�ȹؼ��ּ������ж����(a?b:c)��
/*
1�����캯��
�����ж��徲̬��Ա����N��sum���ڹ��캯����++N,sum+=N�����һ��������n�������͵�ʵ�����ͻ����n�ι��캯������Ӧ�ľ�̬����Ҳ�����Ÿ��¡�

2���麯��
ʹ�õݹ�ʱ����Ȼ������һ���������ж��ǲ�����ֹ�ݹ飬��ô������������������һ�������䵱�ݹ麯����һ��������ݹ�Ľ���������
��Ҫ��������������������������ж�ѡһ����Ȼ��ͨ��bool�����������n���������η����㣬��!!n����ô�����nת��Ϊtrue��0ת��Ϊfalse��

3������ָ��
�ڴ�C�����У�����ʹ���麯������ʱ����ʹ�ú���ָ����ģ�⡣

4��ģ������
�ñ�����������������ڵݹ�ļ��㡣
*/

// �ο�����

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

// 47. ���üӼ��˳����ӷ�
// дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�

void print_2(int val2)
{
    unsigned char *p = (unsigned char*)&val2 + 3; //�ӵ�λ����λ,�Ͷ��ֽڼ����
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

// �Ա����
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

// �ο�����
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

// 48. ���ܱ��̳е���
/*
1���ѹ��캯����Ϊ˽�к���

��C++������Ĺ��캯�����Զ����ø���Ĺ��캯�����������������Ҳ���Զ����ø���Ĺ��캯����Ҫ��һ���಻�ܱ��̳У�ֻҪ�����Ĺ��캯������������������Ϊ˽�к�����

��һ������ͼ�����Ǽ̳е�ʱ�򣬱�Ȼ�����ڵ��ù��캯�����������������±������

��������캯�� ������������Ϊ˽�к�������ô�õ������͵�ʵ���أ�����ͨ�����幫�еľ�̬�������������ͷ����ʵ����

��������ֻ�ܵõ�λ�ڶ��ϵ�ʵ�������ò���ջ�ϵ�ʵ����

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
// 49. ���ַ���ת��Ϊ����
// ����+-���ո񡢷������ַ����Լ��������

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

// �ο�����

 
 
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

// 51. �������ظ�������
/*��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�
����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3��
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

// �ο�����
 
 
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

// 52. �����˻�����
/* ����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
   ����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
*/

// �Ա����
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

// �ο�����
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

// 53. ������ʽƥ��
/*
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� �ڱ����У�ƥ����ָ�ַ���������
�ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
*/

// �ο�����
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

// 55. �ַ����е�һ�����ظ����ַ�
// �ַ���������ˮһ�����ַ���һȥ����������ζ��ֻ�ܷ���һ�Ρ�����Ҫ���ַ��������������д���

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

// 56. �����л�����ڽ��
/*
1����ϣ��

��������������������������ϣ���У���������ʹ������set�������������ĳ���������Ѿ���set�У���ô�õ㼴Ϊ������ڽ�㣻

2������ָ��

���������ڻ�����ô��������ĳ���n��Ȼ��׼������ָ��pSlow��pFast��pFast����n����Ȼ��pSlow��pFaseһ���ߣ�����������ʱ����Ϊ������ڴ���

3���Ľ�

���������ڻ�������������㻷�ĳ���n��ֻ��������ʱ����һ��ָ�����������������һ��ָ���������ײ�������Ȼ������ָ��һ����һ��������������ʱ�����ǻ�����ڴ���������Ͳ�˵��Ϊʲô����������ȷ�ģ���ҿ�����ֽ���Ƶ�һ�¹�ʽ��

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

// 57. ɾ�������е��ظ����

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

// 58. ����������һ�����: �����������һ�����

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

    //��һ�����ж��Ƿ����Һ���
    if(pNode->right != NULL){
        curNode = pNode->right;
        while(curNode->left != NULL)
            curNode = curNode->left;
        return curNode;
    }
    //�ڶ������ж��Ƿ����丸�ڵ������
    if(pNode->next == NULL)
        return NULL;
    if(pNode == pNode->next->left) {
        return pNode->next;
    }
    //���������������丸�ڵ㣬ֱ�����ڵ����丸�ڵ�ĸ��ڵ������
    curNode = pNode->next;
    while(curNode->next != NULL){
        if(curNode == curNode->next->left) {
            return curNode->next;
        }
        //���������Ҹ��ڵ�
        curNode = curNode->next;
    }
    return NULL;
}

// �Ա����
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

// 59. �ԳƵĶ�����: �ж϶������Ƿ�Գ�


// �Ա����
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

// 60. �Ѷ�������ӡ�ɶ���

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

// 61. ��֮����˳���ӡ������
/* 
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
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


