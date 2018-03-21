#define A4_5

#include "../common/common.h"

#ifdef A1_1

// 1.1 确定字符互异
/*
请实现一个算法，确定一个字符串的所有字符是否全都不同。
这里我们要求不允许使用额外的存储结构。
*/

#include <iostream>
#include <cstring>

using namespace std;

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

// 1.2 原串翻转
/*
请实现一个算法，在不使用额外数据结构和储存空间的情况下，
翻转一个给定的字符串(可以使用单个过程变量)。
*/

#include <iostream>
#include <cstring>

using namespace std;

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

// 1.3 确定两串乱序同构
/*
给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，
能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

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

// 1.4 空格替换

#endif


#ifdef A1_5

// 1.5 基本字符串压缩
/*
利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串
“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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

// 1.6 像素翻转
/*
有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，
在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
*/

#include <iostream>
#include <vector>

using namespace std;

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

// 1.7 清除行列
/* 
请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
给定一个N阶方阵int[][](C++中为vector<vector><int>>)mat和矩阵的阶数n，
请返回完成操作后的int[][]方阵(C++中为vector<vector><int>>)，保证n小于等于300，
矩阵中的元素为int范围内。
测试样例：
[[1,2,3],[0,1,2],[0,0,1]]
返回：[[0,0,3],[0,0,0],[0,0,0]]
*/

#include <iostream>
#include <vector>

using namespace std;

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

// 1.8 翻转子串
/*
假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。
请将这个算法编写成一个函数，给定两个字符串s1和s2，
请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
测试样例：
"Hello world","worldhello "
返回：false
"waterbottle","erbottlewat"
返回：true
*/

#include <iostream>
#include <cstring>

using namespace std;

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
    if(s1.size()==0 || s2.size()==0) //注意不要漏括号；
        return false;
    string str=s1+s1;
    if(str.find(s2)==-1)
        return false;
    return true;
}

int main()
{
/*
    string str1("waterbottle");
    string str2("erbottlewat");

    cout << checkReverseEqual(str1, str2) << endl;

    string str3("Hello world");
    string str4("worldhello ");

    cout << checkReverseEqual(str3, str4) << endl;
*/
    string str1("waterbottle");
    string str2("erbottlewat");

    cout << checkReverseEqual1(str1, str2) << endl;

    string str3("Hello world");
    string str4("worldhello ");

    cout << checkReverseEqual1(str3, str4) << endl;

    return 0;
}


#endif

#ifdef A2_2

// 2.2 链表中倒数第k个结点 
#endif

#ifdef A2_3

// 2.3 访问单个结点的删除 
#endif

#ifdef A2_4

// 2.4 链表分割 
/*
编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。
注意：分割以后保持原来的数据顺序不变。
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool create_linklist(ListNode *head, int length)
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

        node1->val = (i%2) ? i+1 : i;
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
    ListNode* node;

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
    ListNode *head = new ListNode;
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

#ifdef A2_5

// 57. 链式A+B

/*
有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，
也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
测试样例：
{1,2,3},{3,2,1}
返回：{4,4,4}
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    int add=0;//进位制的东西
    while (a != NULL || b != NULL) {
        if (a != NULL && b != NULL) {
            pc->next = new ListNode((a->val + b->val+add)%10);
            pc = pc->next;
            add=(a->val+b->val+add)/10;//进几个数
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

// 2.7 回文链表 
/*
请编写一个函数，检查链表是否为回文。
测试样例：
{1,2,3,2,1}
返回：true
{1,2,3,2,3}
返回：false
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool create_linklist(ListNode *head, int length)
{
    ListNode *node = NULL;
    ListNode *node1 = NULL;

    node = new ListNode(0);
    if (node == NULL) {
        return false;
    }
    head->next = node;
/*
    for (int i = 1; i < length; i++) {
        node1 = new ListNode(i);
        if (node1 == NULL) {
            return false;
        }
        node->next = node1;
        node = node1;
    }
*/

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

    create_linklist(head, length);
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

// 3.3 集合栈 
/*
请实现一种数据结构SetOfStacks，由多个栈组成，其中每个栈的大小为size，
当前一个栈填满时，新建一个栈。该数据结构应支持与普通栈相同的push和pop操作。
给定一个操作序列int[][2] ope(C++为vector&ltvector&ltint>>)，每个操作的第一个
数代表操作类型，若为1，则为push操作，后一个数为应push的数字；若为2，则为pop操作，
后一个数无意义。请返回一个int[][](C++为vector&ltvector&ltint>>)，为完成所有操作
后的SetOfStacks，顺序应为从下到上，默认初始的SetOfStacks为空。保证数据合法。
*/

#include <iostream>


using namespace std;

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

// 3.6 双栈排序 
/*
请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个
额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
给定一个int[] numbers(C++中为vector&ltint>)，其中第一个元素为栈顶，请返回排序后的栈。
请注意这是一个栈，意味着排序过程中你只能访问到第一个元素。
测试样例：
[1,2,3,4,5]
返回：[5,4,3,2,1]
*/

#include <iostream>
#include <vector>

using namespace std;

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
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << "\t";
    }
    cout << endl;

    return 0;
}


#endif


#ifdef A3_7

// 3.7 猫狗收容所 
/*
有家动物收容所只收留猫和狗，但有特殊的收养规则，收养人有两种收养方式，
第一种为直接收养所有动物中最早进入收容所的，第二种为选择收养的动物类型（猫或狗），
并收养该种动物中最早进入收容所的。

给定一个操作序列int[][2] ope(C++中为vector<vector<int>>)代表所有事件。
若第一个元素为1，则代表有动物进入收容所，第二个元素为动物的编号，正数代表狗，
负数代表猫；若第一个元素为2，则代表有人收养动物，第二个元素若为0，则采取第一种
收养方式，若为1，则指定收养狗，若为-1则指定收养猫。请按顺序返回收养的序列。
若出现不合法的操作，即没有可以符合领养要求的动物，则将这次领养操作忽略。
测试样例：

[[1,1],[1,-1],[2,0],[2,-1]]

返回：[1,-1]

*/
#endif

#ifdef A4_2

// 4.2 有向路径检查 
/*
对于一个有向图，请实现一个算法，找出两点之间是否存在一条路径。

给定图中的两个结点的指针UndirectedGraphNode* a,UndirectedGraphNode* b
(请不要在意数据类型，图是有向图),请返回一个bool，代表两点之间是否存在一条路径(a到b或b到a)。

*/
#endif


#ifdef A4_3

// 4.3 高度最小的BST  
/*
对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。
给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。
*/

#include <iostream>
#include <vector>

using namespace std;

// my code 1: 直接计算 log2(sizeof(vals))+1
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

// my code 2: 创建BST
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
    int array[]={1,6,4,7,3,5,2,8};
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

// 4.4 输出单层结点
/*
对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。

给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，请返回一个链表ListNode，
代表该深度上所有结点的值，请按树上从左往右的顺序链接，保证深度不超过树的高度，
树上结点的值为非负整数且不超过100000。
*/

// 等同于打印同层，用queue实现

#endif


#ifdef A4_5
// 4.5 检查是否为BST

/*
// 自编代码
bool checkBST(TreeNode* root)
{
    return true;
}
*/

int main()
{
    struct TreeNode* node;
/*node
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
*/
    return 0;
}

#endif

#ifdef A5_1

// 5.1 二进制插入
/* 
有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,
其中二进制的位数从低位数到高位且以0开始。
给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，
保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。
测试样例：
1024，19，2，6
返回：1100
*/

#include <iostream>

using namespace std;

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
// 5.2 二进制小数
/* 
有一个介于0和1之间的实数，类型为double，返回它的二进制表示。
如果该数字无法精确地用32位以内的二进制表示，返回“Error”。

给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
测试样例：
0.625
返回：0.101
*/

#include <iostream>
#include <cstring>

using namespace std;

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

// 5.3 最接近的数
/* 
有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
测试样例：
2
返回：[1,4]
*/

#include <iostream>
#include <vector>

using namespace std;

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


