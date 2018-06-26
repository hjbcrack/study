#define A4_5

#include "common.h"


#ifdef A1_1

// 1.1 ȷ���ַ�����
/*
��ʵ��һ���㷨��ȷ��һ���ַ����������ַ��Ƿ�ȫ����ͬ��
��������Ҫ������ʹ�ö���Ĵ洢�ṹ��
*/

// my code
bool checkDifferent(string iniString) {
    int i;
    int j;

    for (i = 0; i < iniString.size(); i++) {
        for (j = i+1; j < iniString.size(); j++) {
            if (iniString[i] == iniString[j]) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string str("abcdefa");

    cout << checkDifferent(str) << endl;

    return 0;
}

#endif


#ifdef A1_2

// 1.2 ԭ����ת
/*
��ʵ��һ���㷨���ڲ�ʹ�ö������ݽṹ�ʹ���ռ������£�
��תһ���������ַ���(����ʹ�õ������̱���)��
*/

// my code
string reverseString(string iniString) {
    for (int i = 0; i < iniString.size()/2; i++) {
        char tmp = iniString[i];
        iniString[i] = iniString[iniString.size()-1-i];
        iniString[iniString.size()-1-i] = tmp;
    }

    return iniString;
}

int main()
{
    string str("abcdef1");

    cout << reverseString(str) << endl;

    return 0;
}

#endif

#ifdef A1_3

// 1.3 ȷ����������ͬ��
/*
���������ַ��������д����ȷ������һ���ַ������ַ��������к�
�ܷ�����һ���ַ���������涨��СдΪ��ͬ�ַ����ҿ����ַ����ص�ո�
*/

// my code
bool checkSam(string stringA, string stringB) {
    sort(stringA.begin(), stringA.end());
    sort(stringB.begin(), stringB.end());

    return stringA == stringB;
}

int main()
{
    string str1("abcdef1");
    string str2("ab1defc");

    cout << str1+" "+str2+" " << checkSam(str1, str2) << endl;

    string str3("abcdef13");
    string str4("ab1defc2");

    cout << str3+" "+str4+" " << checkSam(str3, str4) << endl;

    return 0;
}

#endif


#ifdef A1_4

// 1.4 �ո��滻

#endif


#ifdef A1_5

// 1.5 �����ַ���ѹ��
/*
�����ַ��ظ����ֵĴ�������дһ��������ʵ�ֻ������ַ���ѹ�����ܡ����磬�ַ���
��aabcccccaaa����ѹ�����ɡ�a2b1c5a3������ѹ������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ�����
*/

// my code
string zipString(string iniString) {
    string outstring;
    int i = 0;

    while (i < iniString.size()) {
        char ch = iniString[i];
        int count = 0;
        while (ch == iniString[i]) {
            i++;
            count++;
        }
        outstring += ch;
        outstring += to_string(count);
    }

    return (outstring.size() >= iniString.size() ? iniString : outstring);
}

int main()
{
    string str1("aabcccccaaa");

    cout << str1+" " << zipString(str1) << endl;

    string str2("qwertyuioplkjhgfdsAzxcvbNM");

    cout << str2+" " << zipString(str2) << endl;

    string str3("aabcccccaaaaaaaaaaaaaaaaaaaa");

    cout << str3+" " << zipString(str3) << endl;

    return 0;
}

#endif


#ifdef A1_6

// 1.6 ���ط�ת
/*
��һ����NxN�����ʾ��ͼ������ÿ��������һ��int��ʾ�����дһ���㷨��
�ڲ�ռ�ö����ڴ�ռ�������(����ʹ�û������)����ͼ��˳ʱ����ת90�ȡ�
*/

// my code
vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = mat[i][j];
            mat[i][j] = mat[n-1-i][j];
            mat[n-1-i][j] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                int tmp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = tmp;
            }
        }
    }

    return mat;
}

int main()
{
    int size = 4;
    int array[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    
    vector<vector<int> > mat;
    for (int i = 0; i < size; i++) {
        vector<int> vec(array[i], array[i]+sizeof(array[i])/sizeof(int));
        mat.push_back(vec);
    }
    vector<vector<int> > out;

    cout << "mat = " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << mat[i][j] << '\t';
        }
        cout << endl;
    }

    out = transformImage(mat, size);

    cout << "out = " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << out[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}

#endif


#ifdef A1_7

// 1.7 �������
/*
���дһ���㷨����N�׷�����ĳ��Ԫ��Ϊ0���������ڵ����������㡣
����һ��N�׷���int[][](C++��Ϊvector<vector><int>>)mat�;���Ľ���n��
�뷵����ɲ������int[][]����(C++��Ϊvector<vector><int>>)����֤nС�ڵ���300��
�����е�Ԫ��Ϊint��Χ�ڡ�
����������
[[1,2,3],[0,1,2],[0,0,1]]
���أ�[[0,0,3],[0,0,0],[0,0,0]]
*/

// my code
vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
    vector<int> row(n,0);
    vector<int> col(n,0);  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                mat[i][j] = 0;
            }
        }
    }

    return mat;
}

int main()
{
    int size = 4;
    int array[][4] = {{0,2,3,4},{5,0,7,0},{9,10,11,12},{13,14,15,16}};
    
    vector<vector<int> > mat;
    for (int i = 0; i < size; i++) {
        vector<int> vec(array[i], array[i]+sizeof(array[i])/sizeof(int));
        mat.push_back(vec);
    }
    vector<vector<int> > out;

    cout << "mat = " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << mat[i][j] << '\t';
        }
        cout << endl;
    }

    out = clearZero(mat, size);

    cout << "out = " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << out[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}

#endif


#ifdef A1_8

// 1.8 ��ת�Ӵ�
/*
�ٶ����Ƕ�֪���ǳ���Ч���㷨�����һ�������Ƿ�Ϊ�����ַ������Ӵ���
�뽫����㷨��д��һ�����������������ַ���s1��s2��
���д������s2�Ƿ�Ϊs1��ת���ɣ�Ҫ��ֻ�ܵ���һ�μ���Ӵ��ĺ�����
����������
"Hello world","worldhello "
���أ�false
"waterbottle","erbottlewat"
���أ�true
*/

// my code
bool checkReverseEqual(string s1, string s2) {
    int i;
    int j;

    for (i = 0; i < s2.size(); i++) {
        if (s1[0] == s2[i]) {
            for (j = i; j < s2.size(); j++) {
                if (s1[j-i] != s2[j]) {
                    break;
                }
            }
            if (j < s2.size()) {
                continue;
            }
            for (j = 0; j < s2.size()-i; j++) {
                if (s1[s2.size()-i+j] != s2[j]) {
                    break;
                }
            }
            if (j < s2.size()-i) {
                continue;
            }
            return true;
        }
    }

    return false;
}

// ref code
bool checkReverseEqual1(string s1, string s2) {
    // write code here
    if(s1.size()==0 || s2.size()==0) //ע�ⲻҪ©���ţ�
        return false;
    string str=s1+s1;
    if(str.find(s2)==-1)
        return false;
    return true;
}

int main()
{
    string str1("waterbottle");
    string str2("erbottlewat");

    string str3("Hello world");
    string str4("worldhello ");

    cout << checkReverseEqual(str1, str2) << endl;

    cout << checkReverseEqual(str3, str4) << endl;

    cout << checkReverseEqual1(str1, str2) << endl;

    cout << checkReverseEqual1(str3, str4) << endl;

    return 0;
}


#endif

#ifdef A2_2

// 2.2 �����е�����k����� 
#endif

#ifdef A2_3

// 2.3 ���ʵ�������ɾ�� 
#endif

#ifdef A2_4

// 2.4 ����ָ� 
/*
��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣
ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣
*/

bool create_linklist_rand(ListNode *head, int length)
{
    ListNode *node = NULL;
    ListNode *node1 = NULL;

    head->val = -1;

    node = new ListNode;
    if (node == NULL) {
        return false;
    }
    node->val = 0;
    node->next = NULL;
    head->next = node;

    for (int i = 1; i < length; i++) {
        node1 = new ListNode;
        if (node1 == NULL) {
            return false;
        }

        node1->val = (i * 3) % 10;
        node1->next = NULL;
        node->next = node1;
        node = node1;
    }

    for (node = head->next; node != NULL; node = node->next) {
        cout << node->val << " ";
    }
    cout << endl;

    return true;
}

ListNode* partition(ListNode* pHead, int x)
{
    if(pHead == NULL)
        return NULL;

    ListNode *pNode = pHead;
    ListNode *small = new ListNode(0);
    ListNode *big = new ListNode(0);
    ListNode *ptr1 = small;
    ListNode *ptr2 = big;

    while(pNode)
    {
        if(pNode->val < x)
        {
            ptr1->next = pNode;
            pNode = pNode->next;
            ptr1 = ptr1->next;
            ptr1->next = NULL;
        }
        else
        {
            ptr2->next = pNode;
            pNode = pNode->next;
            ptr2 = ptr2->next;
            ptr2->next = NULL;
        }
    }
    ptr1->next = big->next;
    return small->next;
}

int main(){
    int length = 10;
    ListNode *head = new ListNode;
    ListNode *node;

    create_linklist_rand(head, length);
    node = head->next;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    node = partition(head->next, 5);
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}

#endif

#ifdef A2_5

// 57. ��ʽA+B

/*
�������������ʾ��������ÿ��������һ����λ����Щ��λ�Ƿ����ŵģ�
Ҳ���Ǹ�λ����������ײ�����д������������������ͣ�����������ʽ���ؽ����
������������ListNode* A��ListNode* B���뷵��A+B�Ľ��(ListNode*)��
����������
{1,2,3},{3,2,1}
���أ�{4,4,4}
*/

// my code
ListNode* plusAB(ListNode* a, ListNode* b)
{
    ListNode* node = NULL;
    int pre = 0;
    int sum = 0;

    if (a == NULL || a == NULL) {
        return NULL;
    }

    node = a;
    while (a->next != NULL && b->next != NULL) {
        sum = (a->val + b->val + pre) % 10;
        pre = (a->val + b->val + pre) / 10;
        a->val = sum;
        a = a->next;
        b = b->next;
    }

    if (a->next == NULL && b->next == NULL) {
        sum = (a->val + b->val + pre) % 10;
        pre = (a->val + b->val + pre) / 10;
        a->val = sum;
        if (pre == 1) {
            ListNode* tmpNode = new ListNode(1);
            a->next = tmpNode;
        }
    } else if (a->next == NULL) {
        sum = (a->val + b->val + pre) % 10;
        pre = (a->val + b->val + pre) / 10;
        a->val = sum;
        a->next = b->next;
        b = b->next;
        while (b->next != NULL) {
            sum = (b->val + pre) % 10;
            pre = (b->val + pre) / 10;
            b->val = sum;
            b = b->next;
        }
        sum = (b->val + pre) % 10;
        pre = (b->val + pre) / 10;
        b->val = sum;
        if (pre == 1) {
            ListNode* tmpNode = new ListNode(1);
            b->next = tmpNode;
        }
    } else {
        sum = (a->val + b->val + pre) % 10;
        pre = (a->val + b->val + pre) / 10;
        a->val = sum;
        a = a->next;
        while (a->next != NULL) {
            sum = (a->val + pre) % 10;
            pre = (a->val + pre) / 10;
            a->val = sum;
            a = a->next;
        }
        sum = (a->val + pre) % 10;
        pre = (a->val + pre) / 10;
        a->val = sum;
        if (pre == 1) {
            ListNode* tmpNode = new ListNode(1);
            a->next = tmpNode;
        }
    }

    return node;
}

// ref code 1
ListNode* plusAB1(ListNode* a, ListNode* b) {
    // write code here
    if(a == NULL && b == NULL){
        return NULL;
    }
    if(a == NULL)return b;
    if(b == NULL)return a;

    ListNode* res = new ListNode(0);
    ListNode* ap = a;
    ListNode* bp = b;
    ListNode* result = res;

    int flag = 0;
    int value;  
    int val1;
    int val2;

    while(ap!=NULL || bp!=NULL || flag!=0){
        val1 = (ap == NULL ? 0 : ap->val);
        val2 = (bp == NULL ? 0 : bp->val);
        value = val1 + val2 + flag;

        flag = value/10;

        ListNode* node = new ListNode(value%10);
        res->next = node;
        res = res->next;
        ap = (ap == NULL ? NULL:ap->next);
        bp = (bp == NULL ? NULL:bp->next);
    }
    return result->next;
}

// ref code 2
ListNode* plusAB2(ListNode* a, ListNode* b) {
    // write code here
    ListNode* c = new ListNode(0);
    ListNode* pc = c;
    ListNode* pa =a;
    ListNode* pb =b;
    int add=0;//��λ�ƵĶ���
    while (a != NULL || b != NULL) {
        if (a != NULL && b != NULL) {
            pc->next = new ListNode((a->val + b->val+add)%10);
            pc = pc->next;
            add=(a->val+b->val+add)/10;//��������
            a = a->next;
            b = b->next;
        } else if (a != NULL) {
            pc->next = new ListNode((a->val+add)%10);
            pc = pc->next;
            add=(add+a->val)/10;
            a = a->next;
        } else if (b != NULL) {
            pc->next = new ListNode((b->val+add)%10);
            pc = pc->next;
            add=(add+b->val)/10;
            b = b->next;
        }
    }
    if(add>0){
        pc->next=new ListNode(add);
        pc=pc->next;
    }
    return c->next;
}

int main(){
    int length = 6;
    ListNode *head = new ListNode(-1);
    ListNode *node;

    create_linklist(head, length);
    node = head->next;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    ListNode *head1 = new ListNode(-1);
    ListNode *node1;

    create_linklist(head1, length);
    node = head1->next;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    node = plusAB(head->next, head1->next);
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    node = plusAB1(head->next, head1->next);
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    node = plusAB2(head->next, head1->next);
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}

#endif

#ifdef A2_7

// 2.7 �������� 
/*
���дһ����������������Ƿ�Ϊ���ġ�
����������
{1,2,3,2,1}
���أ�true
{1,2,3,2,3}
���أ�false
*/

// my code
bool isPalindrome(ListNode* pHead)
{
    vector<int> vec;

    if (pHead == NULL) {
        return NULL;
    }

    while (pHead != NULL) {
        vec.push_back(pHead->val);
        pHead = pHead->next;
    }

    for (int i = 0; i < vec.size()/2; i++) {
        if (vec[i] != vec[vec.size()-1-i]) {
            return false;
        }
    }

    return true;
}

int main(){
    int length = 10;
    ListNode *head = new ListNode(-1);
    ListNode *node;

    create_huiwenlist(head, length);
    node = head->next;
    while(node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    cout << isPalindrome(head->next) << endl;

    return 0;
}


#endif


#ifdef A3_3

// 3.3 ����ջ 
/*
��ʵ��һ�����ݽṹSetOfStacks���ɶ��ջ��ɣ�����ÿ��ջ�Ĵ�СΪsize��
��ǰһ��ջ����ʱ���½�һ��ջ�������ݽṹӦ֧������ͨջ��ͬ��push��pop������
����һ����������int[][2] ope(C++Ϊvector&ltvector&ltint>>)��ÿ�������ĵ�һ��
������������ͣ���Ϊ1����Ϊpush��������һ����ΪӦpush�����֣���Ϊ2����Ϊpop������
��һ���������塣�뷵��һ��int[][](C++Ϊvector&ltvector&ltint>>)��Ϊ������в���
���SetOfStacks��˳��ӦΪ���µ��ϣ�Ĭ�ϳ�ʼ��SetOfStacksΪ�ա���֤���ݺϷ���
*/

// my code
vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size)
{

}

int main(){
    vector<vector<int> > vec_list;

    return 0;
}


#endif


#ifdef A3_6

// 3.6 ˫ջ���� 
/*
���дһ�����򣬰������ջ�������򣨼����Ԫ��λ��ջ������Ҫ�����ֻ��ʹ��һ��
�����ջ�����ʱ���ݣ������ý�Ԫ�ظ��Ƶ�������ݽṹ�С�
����һ��int[] numbers(C++��Ϊvector&ltint>)�����е�һ��Ԫ��Ϊջ�����뷵��������ջ��
��ע������һ��ջ����ζ�������������ֻ�ܷ��ʵ���һ��Ԫ�ء�
����������
[1,2,3,4,5]
���أ�[5,4,3,2,1]
*/

// my code
vector<int> twoStacksSort(vector<int> numbers)
{
    vector<int> vec;
    int tmp;

    if (numbers.empty()) {
        return vec;
    }

    vec.push_back(numbers.back());
    numbers.pop_back();
    while (!numbers.empty()) {
        if (numbers.back() <= vec.back()) {
            vec.push_back(numbers.back());
            numbers.pop_back();
        } else {
            tmp = numbers.back();
            numbers.pop_back();
            while (!vec.empty()) {
                if (tmp > vec.back()) {
                    numbers.push_back(vec.back());
                    vec.pop_back();
                } else {
                    vec.push_back(tmp);
                    break;
                }
            }
            if (vec.empty()) {
                vec.push_back(tmp);
            }
        }
    }

    return vec;
}

vector<int> t_twoStacksSort(vector<int> numbers)
{
    vector<int> vec;
    int tmp;

    if (numbers.empty()) {
        return vec;
    }

    tmp = numbers.back();
    vec.push_back(tmp);
    numbers.pop_back();
    while (!numbers.empty()) {
        tmp = numbers.back();
        if (tmp < vec.back()) {
            vec.push_back(tmp);
            numbers.pop_back();
        } else {
            numbers.pop_back();
            while (!vec.empty() && vec.back() < tmp) {
                numbers.push_back(vec.back());
                vec.pop_back();
            }
            vec.push_back(tmp);
        }
    }

    return vec;
}

int main()
{
    int array[]={1,6,4,7,3,5,2,8};
    int length = sizeof(array)/sizeof(int);
    vector<int> numbers(array, array+length);
    vector<int> out;

    cout << "numbers:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << "\t";
    }
    cout << endl;

    out = twoStacksSort(numbers);

    cout << "out:" << endl;
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << "\t";
    }
    cout << endl;

    out = t_twoStacksSort(numbers);

    cout << "out t:" << endl;
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << "\t";
    }
    cout << endl;

    return 0;
}


#endif


#ifdef A3_7

// 3.7 è�������� 
/*
�мҶ���������ֻ����è�͹��������������������������������������ʽ��
��һ��Ϊֱ���������ж�������������������ģ��ڶ���Ϊѡ�������Ķ������ͣ�è�򹷣���
���������ֶ�������������������ġ�

����һ����������int[][2] ope(C++��Ϊvector<vector<int>>)���������¼���
����һ��Ԫ��Ϊ1��������ж���������������ڶ���Ԫ��Ϊ����ı�ţ�����������
��������è������һ��Ԫ��Ϊ2�������������������ڶ���Ԫ����Ϊ0�����ȡ��һ��
������ʽ����Ϊ1����ָ������������Ϊ-1��ָ������è���밴˳�򷵻����������С�
�����ֲ��Ϸ��Ĳ�������û�п��Է�������Ҫ��Ķ������������������ԡ�
����������

[[1,1],[1,-1],[2,0],[2,-1]]

���أ�[1,-1]

*/
#endif

#ifdef A4_2

// 4.2 ����·����� 
/*
����һ������ͼ����ʵ��һ���㷨���ҳ�����֮���Ƿ����һ��·����

����ͼ�е���������ָ��UndirectedGraphNode* a,UndirectedGraphNode* b
(�벻Ҫ�����������ͣ�ͼ������ͼ),�뷵��һ��bool����������֮���Ƿ����һ��·��(a��b��b��a)��

*/
#endif


#ifdef A4_3

// 4.3 �߶���С��BST  
/*
����һ��Ԫ�ظ�����ͬ�Ұ��������е��������У����дһ���㷨������һ�ø߶���С�Ķ����������
����һ����������int[] vals,�뷵�ش����Ķ���������ĸ߶ȡ�
*/


// my code 1: ֱ�Ӽ��� log2(sizeof(vals))+1
int buildMinimalBST(vector<int> vals)
{
    if (vals.empty()) {
        return 0;
    }

    int mid = vals.size()/2;
    int height = 1;

    while (mid != 0) {
        height++;
        mid /= 2;
    }

    return height;
}

// my code 2: ����BST
void build(vector<int> vals, int begin, int end, int* height)
{
    if (vals.empty()) {
        return;
    }

    if (begin == end) {
        *height = 1;
        return;
    }
    int height1 = 0;
    int height2 = 0;

    build(vals, begin, (begin+end)/2, &height1);
    build(vals, (begin+end)/2+1, end, &height2);
    if (height1 == height2) {
        *height = height1 + 1;
    } else {
        *height = height2 + 1;
    }
}

int buildMinimalBST1(vector<int> vals)
{
    if (vals.empty()) {
        return 0;
    }
    int height;

    build(vals, 0, vals.size(), &height);

    return height;
}


int main()
{
    int array[]={1,2,3,4,5,6,7,8};
    int length = sizeof(array)/sizeof(int);
    vector<int> numbers(array, array+length);
    int depth = 0;

    cout << "numbers:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << "\t";
    }
    cout << endl;

    depth = buildMinimalBST(numbers);
    cout << "depth: " << depth << endl;

    depth = buildMinimalBST1(numbers);
    cout << "depth: " << depth << endl;

    return 0;
}


#endif


#ifdef A4_4

// 4.4 ���������
/*
����һ�ö������������һ���㷨����������ĳһ��������н�������

�����������ĸ����ָ��TreeNode* root���Լ������Ͻ�����ȣ��뷵��һ������ListNode��
�������������н���ֵ���밴���ϴ������ҵ�˳�����ӣ���֤��Ȳ��������ĸ߶ȣ�
���Ͻ���ֵΪ�Ǹ������Ҳ�����100000��
*/

// ��ͬ�ڴ�ӡͬ�㣬��queueʵ��

#endif


#ifdef A4_5
// 4.5 ����Ƿ�ΪBST


// �Ա����
bool checkBST(TreeNode* root)
{
    return true;
}

int main()
{
    struct TreeNode* node;

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

    printTreeFromTopToBottom(pNode1);

    cout << checkBST(pNode1) << endl;

    return 0;
}

#endif

#ifdef A5_1

// 5.1 �����Ʋ���
/*
������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ,
���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز����������
��֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i-j+1��
����������
1024��19��2��6
���أ�1100
*/

// MY CODE
int binInsert(int n, int m, int j, int i)
{
    if (j > i) {
        return n;
    }

    int index = 0;
    int ij = 1;
    while (index < (i-j)) {
        ij = (ij << 1)+1;
        index++;
    }

    return (n | ((m << j) & (ij << j)));
}

int main()
{
    cout << binInsert(1024, 19, 2, 6) << endl;
 
    return 0;
}

#endif

#ifdef A5_2
// 5.2 ������С��
/*
��һ������0��1֮���ʵ��������Ϊdouble���������Ķ����Ʊ�ʾ��
����������޷���ȷ����32λ���ڵĶ����Ʊ�ʾ�����ء�Error����

����һ��double num����ʾ0��1��ʵ�����뷵��һ��string����������Ķ����Ʊ�ʾ���ߡ�Error����
����������
0.625
���أ�0.101
*/

// MY CODE
string printBin(double num)
{
    string str = "0.";
    double tmp = num;
    int count = 0;
    if (num > 1) {
        return "Error";
    }

    while (1) {
        tmp *= 2.0;
        if (-0.00000001 < (tmp - 1.0) && (tmp - 1.0) < 0.00000001) {
            str += "1";
            break;
        } else if (tmp > 1.0) {
            tmp = tmp - 1.0;
            str += "1";
        } else {
            str += "0";
        }
        count++;
        if (count > 32) {
            return "Error";
        }
    }

    return str;
}

int main()
{
    cout << 0.625 << " " << printBin(0.625) << endl;
    cout << 0.46502 << " " << printBin(0.46502) << endl;
    return 0;
}

#endif


#ifdef A5_3

// 5.3 ��ӽ�����
/*
��һ�������������ҳ�������Ʊ�ʾ��1�ĸ�����ͬ���Ҵ�С��ӽ�������������(һ���Դ�һ����С)
����������int x���뷵��һ��vector�������������������С����ǰ������֤�𰸴��ڡ�
����������
2
���أ�[1,4]
*/

// MY CODE
vector<int> getCloseNumber(int x)
{
    vector<int> vec;

    return vec;
}

int main()
{
    vector<int> vec;
    vec = getCloseNumber(2);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\t";
    }
    cout << endl;
 
    return 0;
}

#endif


#ifdef A5_5

// 5.5 ����ת��
/*
��дһ��������ȷ����Ҫ�ı伸��λ�����ܽ�����Aת�������B��
������������int A��int B���뷵����Ҫ�ı����λ������
����������
10,5
���أ�4
*/

// MY CODE
int calcCost(int A, int B)
{
    int tmp = A^B;
    int count = 0;

    while (tmp) {
        if (tmp & 1) {
            count++;
        }
        tmp >>= 1;
    }

    return count;
}

int main()
{
    cout << 10 << "\t" << 5 << "\t" << calcCost(10, 5) << endl;

    return 0;
}

#endif


#ifdef A5_6

// 5.6 ��żλ����
/*
���д���򽻻�һ�����Ķ����Ƶ�����λ��ż��λ��
*/

// MY CODE
int exchangeOddEven(int x)
{
    return (((x & 0xaaaaaaaa) >> 1) + ((x & 0x55555555) << 1));
}

int main()
{
    cout << 10 << "\t" << exchangeOddEven(10) << endl;

    return 0;
}

#endif


#ifdef A17_2

// 17.2 ������
/*
����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�
Ϊ0��ʾû�����ӣ�Ϊ-1�����ǶԷ���ҵ����ӡ�
����������
[[1,0,1],[1,-1,-1],[1,-1,0]]
���أ�true
*/

// MY CODE
bool checkWon(vector<vector<int> > board)
{
    int row = board.size();
    int column = board.front().size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (((i-1 >= 0) && (i+1 < row) && (board[i][j] == 1) && (board[i-1][j] == 1) && (board[i+1][j] == 1)) ||
                ((j-1 >= 0) && (j+1 < column) && (board[i][j] == 1) && (board[i][j-1] == 1) && (board[i][j+1] == 1)) ||
                ((i-1 >= 0) && (i+1 < row) && (j-1 >= 0) && (j+1 < column) && (board[i][j] == 1) && (board[i-1][j-1] == 1) && (board[i+1][j+1] == 1)) ||
                ((i-1 >= 0) && (i+1 < row) && (j-1 >= 0) && (j+1 < column) && (board[i][j] == 1) && (board[i-1][j+1] == 1) && (board[i+1][j-1] == 1))) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int size = 3;
    int array[][3] = {{1,0,1},{1,-1,-1},{1,-1,0}};

    vector<vector<int> > board;
    for (int i = 0; i < size; i++) {
        vector<int> vec(array[i], array[i]+sizeof(array[i])/sizeof(int));
        board.push_back(vec);
    }

    cout << checkWon(board) << endl;

    return 0;
}

#endif


#ifdef A17_3

// 17.3 �׳�β�� 
/*
�����һ���㷨������n�Ľ׳��ж��ٸ�β���㡣
����һ��int n���뷵��n�Ľ׳˵�β���������֤nΪ��������
*/

// REF CODE
int getFactorSuffixZero(int n)
{
    int count = 0;
    int j;

    for (int i = 5; i <= n; i += 5){
        j = i;
        while (j % 5 == 0) {
            count ++;
            j /= 5;
        }
    }

    return count ;
}

int getFactorSuffixZero1(int n)
{
    int count= 0;

    while (n > 0) {
        count += n / 5;
        n = n / 5;
    }

    return count;
}

int main()
{
    cout << getFactorSuffixZero(169438) << endl;
    cout << getFactorSuffixZero1(169438) << endl;

    return 0;
}


#endif


#ifdef A17_4

// 17.4 ���ж�max
/*
�ҳ����������������Ǹ��������ǲ���ʹ��if-else�ȱȽϺ��ж��������
*/

// MY CODE
int getMax(int a, int b)
{
    return (((a + b) + abs(a - b)) / 2);
}

int main()
{
    cout << getMax(1, 2) << endl;

    return 0;
}

#endif

#ifdef A17_6

// 17.6 ��С��������
/*
��һ���������飬���дһ���������ҳ�����m��n��ֻҪ��m��n֮���Ԫ���ź���
���������������ġ�ע�⣺n-mӦ��ԽСԽ�ã�Ҳ����˵���ҳ�����������������С�

����һ��int����A������Ĵ�Сn���뷵��һ����Ԫ�飬�����������е������յ㡣
(ԭ����λ�ô�0��ʼ���,��ԭ�������򣬷���[0,0])����֤A��Ԫ�ؾ�Ϊ��������
*/

// MY CODE
vector<int> findSegment(vector<int> A, int n)
{
    int min = 0;
    int max = n-1;
    int i, j;
    vector<int> out;

    for (i = 0; i < n-1; i++) {
        if (A[i] >= A[min]) {
            for (j = i+1; j < n; j++) {
                if (A[j] < A[i]) {
                    min = i;
                    break;
                }
            }
            if (j < n) {
                break;
            }
            min = i;
        } else {
            min = i;
            break;
        }
        cout << min << endl;
    }
    cout << endl;

    for (i = n-1; i > 0; i--) {
        if (A[i] <= A[max]) {
            for (j = i-1; j >= 0; j--) {
                if (A[j] > A[i]) {
                    max = i;
                    break;
                }
            }
            if (j >= 0) {
                break;
            }
            max = i;
        } else {
            max = i;
            break;
        }
        cout << max << endl;
    }

    if (min == n-2) {
        out.push_back(0);
        out.push_back(0);
    } else {
        out.push_back(min);
        out.push_back(max);
    }

    return out;
}

int main()
{
    //int array[]={1,2,6,7,3,5,4,8};
    int array[]={1,2,3,3,8,9};

    int length = sizeof(array)/sizeof(int);
    vector<int> vec(array, array+length);
    vector<int> out;

    cout << "vec:" << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\t";
    }
    cout << endl;

    out = findSegment(vec, length);

    cout << "out:" << endl;
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << "\t";
    }
    cout << endl;

    return 0;
}

#endif


#ifdef A17_7

// 17.7 ���ַ��� 
/*
��һ���Ǹ����������дһ���㷨����ӡ��������Ӣ��������
����һ��int x���뷵��һ��string��Ϊ��������Ӣ��������
����������
1234
���أ�"One Thousand,Two Hundred Thirty Four"
*/

// MY CODE
string toString(int x)
{
    string base[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                        "Eighteen", "Nineteen"};//0~19
    string tyNum[10] = {"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty","Ninety"};
    string bigNum[4] = {"", "Thousand", "Million", "Billion"};
    string result;
    int k=0;
    //��xÿ��λ�ֳ�һ����б���
    if(x==0)
        return "Zero";
    while(x>0)
    {
        int val=x%1000;
        //����λ�����б���
        string temp;
        if(base[val/100]!="")//��λ��
        {
            temp+=base[val/100];
            temp+=" Hundred";
        }
        if(val%100<20)
        {
            if(!temp.empty())
                temp+=" ";
            temp+=base[val%100];
        }
        else
        {
                if(!temp.empty())
                temp+=" ";
                temp+=tyNum[val%100/10];
                if(base[val%10]!="")
                {
                    if(!temp.empty())
                        temp+=" ";
                    temp+=base[val%10];
                }
        }
        if(!temp.empty()&&bigNum[k]!="")
        {
            temp+=" ";
            temp+=bigNum[k];
            if(!result.empty())
                temp+=",";
        }
        result=temp+result;
        k++;
        x/=1000;
    }
    return result;
}

int main()
{
    cout << toString(1234) << endl;

    return 0;
}

#endif


#ifdef A17_8

// 17.8 ����������к� 
/*
��һ���Ǹ����������дһ���㷨����ӡ��������Ӣ��������
����һ��int x���뷵��һ��string��Ϊ��������Ӣ��������
����������
1234
���أ�"One Thousand,Two Hundred Thirty Four"
*/

// MY CODE
string toString(int x)
{
    string base[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                        "Eighteen", "Nineteen"};//0~19
    string tyNum[10] = {"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty","Ninety"};
    string bigNum[4] = {"", "Thousand", "Million", "Billion"};
    string result;
    int k=0;
    //��xÿ��λ�ֳ�һ����б���
    if(x==0)
        return "Zero";
    while(x>0)
    {
        int val=x%1000;
        //����λ�����б���
        string temp;
        if(base[val/100]!="")//��λ��
        {
            temp+=base[val/100];
            temp+=" Hundred";
        }
        if(val%100<20)
        {
            if(!temp.empty())
                temp+=" ";
            temp+=base[val%100];
        }
        else
        {
                if(!temp.empty())
                temp+=" ";
                temp+=tyNum[val%100/10];
                if(base[val%10]!="")
                {
                    if(!temp.empty())
                        temp+=" ";
                    temp+=base[val%10];
                }
        }
        if(!temp.empty()&&bigNum[k]!="")
        {
            temp+=" ";
            temp+=bigNum[k];
            if(!result.empty())
                temp+=",";
        }
        result=temp+result;
        k++;
        x/=1000;
    }
    return result;
}

int main()
{
    cout << toString(1234) << endl;

    return 0;
}

#endif

#ifdef A17_9

// 17.9 ��Ƶͳ�� 
/*
�����һ����Ч�ķ������ҳ�����ָ��������һƪ�����еĳ���Ƶ����
����һ��string����article�������Сn��һ����ͳ�Ƶ���word��
�뷵�ظõ����������еĳ���Ƶ������֤���µĴ���С�ڵ���1000��
*/

// MY CODE
int getFrequency(vector<string> article, int n, string word)
{
    int count = 0;

    for (int i = 0; i < article.size(); i++) {
        if (article[i] == word) {
            count++;
        }
    }

    return count;
}

int getFrequency1(vector<string> article, int n, string word)
{
    int count = 0;
    vector<string> array[256];
    int index = word[0];

    for (int i = 0; i < article.size(); i++) {
        array[article[i].at(0)].push_back(article[i]);
    }

    for (int i = 0; i < array[index].size(); i++) {
        if (array[index][i] == word) {
            count++;
        }
    }

    return count;
}

int main()
{
    string array[] = {"student", "teacher", "student", "school", "father",
                      "student", "a"};
    int number = sizeof(array)/sizeof(string);
    vector<string> article(array, array+number);

    unsigned long time1, time2, time3;

    time1 = GetTickCount();
    cout << getFrequency(article, number, "student") << endl;

    for (int i = 0; i < 1000000; i++) {
        getFrequency(article, number, "student");
    }
    time2 = GetTickCount();
    cout << "time1 = " << time2-time1 << endl;

    cout << getFrequency1(article, number, "student") << endl;
    for (int i = 0; i < 1000000; i++) {
        getFrequency1(article, number, "student");
    }
    time3 = GetTickCount();
    cout << "time2 = " << time3-time2 << endl;

    return 0;
}

#endif

