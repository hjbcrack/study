
#define SUAN    17

#include "common.h"

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 1)

/* �������⣺
   ��һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�С���ӳ����������º�ÿ����
   ����һ�����ӣ��������Ӷ���������ÿ���µ���������Ϊ���ٶԣ�
   ���ӹ��ɶ�: 1, 1, 2, 3, 
*/

int fun(int m)
{
    if (m == 1 || m == 2)
        return 1;
    else
        return (fun(m-1) + fun(m-2));
}

int fun1(int m)
{
    long f1, f2;
    int i;
    f1 = f2 = 1;
    for(i = 0; i < m; i+=2) {
        printf("%12ld %12ld", f1, f2);
        if(i%2 == 0)
            printf("\n");  /*���������ÿ���ĸ�*/
        f1 = f1 + f2;  /*ǰ�����¼�������ֵ����������*/
        f2 = f1 + f2;  /*ǰ�����¼�������ֵ����������*/
    }
}

int main()
{
    int month = 12;
    int i;

    printf("fun: \n");
    for (i = 1; i <= month; ++i) {
        printf("month %d: %d \n", i, fun(i));
    }

    printf("fun1: \n");
    fun1(month);

    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 2)
/*
    �ж�101-200֮���ж��ٸ����������������������
    1, 2, 3, 5, 7, 11, 13, 17, 19,
*/

int fun(int number)
{
    int i;
    int n = sqrt(number);

    for (i = 2; i <= n; ++i) {
        if (number % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int i;

    for (i = 101; i <= 200; ++i) {
        if (fun(i) != 0)
            printf("%d \n", i);
    }

    return 0;
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 3)
/*
    ��ӡ�����еġ�ˮ�ɻ���������ν��ˮ�ɻ�������ָһ����λ�������λ����������
    ���ڸ����������磺153��һ����ˮ�ɻ���������Ϊ153=1�����η���5�����η���3�����η���

    �������������forѭ������100-999������ÿ�����ֽ����λ��ʮλ����λ��
*/

int fun(int number)
{
    int x, y, z;

    x = number / 100;
    y = (number / 10) % 10;
    z = number % 10;

    if ((x*x*x+y*y*y+z*z*z) == number) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int i;

    for (i = 100; i <= 999; ++i) {
        if (fun(i) != 0)
            printf("%d \n", i);
    }

    return 0;
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 4)
/*
��һ���������ֽ������������磺����90,��ӡ��90=2*3*3*5��

�����������n���зֽ���������Ӧ���ҵ�һ����С������k��Ȼ������������ɣ�
(1)����������ǡ����n����˵���ֽ��������Ĺ����Ѿ���������ӡ�����ɡ�
(2)���n<>k����n�ܱ�k��������Ӧ��ӡ��k��ֵ������n����k����,��Ϊ�µ���
   ������n,�ظ�ִ�е�һ����
(3)���n���ܱ�k����������k+1��Ϊk��ֵ,�ظ�ִ�е�һ����
*/

int main()
{
    int n,i;
    printf("\nplease input a number:\n");
    scanf("%d",&n);
    printf("%d=",n);
    for(i = 2; i <= n; i++){
        while(n != i)
        {
            if(n%i == 0) {
                printf("%d*",i);
                n = n / i;
            } else {
                break;
            }
        }
    }
    printf("%d \n",n);

    return 0;
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 5)
/*
    ��������������m��n���������Լ������С�������� **************************
    �ο��㷨: շ��������շת�����������ŷ������㷨����������������֮������ӵ��㷨��
*/

// MY CODE
int gcd(int num1, int num2)
{
    int i, num;
    int big, small;

    num = (num1 > num2) ? num2 : num1;
    for (i = num; i > 1; --i){
        if ((num1 % i == 0) && (num2 % i == 0)) {
            big = i;
            printf("big is %d \n", i);
            break;
        }
    }

    if (i == 1) {
        big = 1;
        printf("big is 1 \n");
    }

    small = num1 * num2 / big;
    printf("small is %d \n", small);

    return 0;
}

// REF CODE
int gcd1(int num1, int num2)
{
    int a,b,temp;

    if(num1) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    a = num1;
    b = num2;
    while(b!=0)/*����շ������ֱ��bΪ0Ϊֹ*/
    {
        temp=a%b;
        a=b;
        b=temp;
    }

    printf("gongyueshu:%d\n",a);
    printf("gongbeishu:%d\n",num1*num2/a);
}

main()
{
    int num1,num2;

    printf("please input two numbers:\n");
    scanf("%d %d",&num1,&num2);

    printf("gcd: \n");
    gcd(num1, num2);

    printf("gcd1: \n");
    gcd(num1, num2);
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 6)
/*
    ��Ŀ����s=a+aa+aaa+aaaa+aa...a��ֵ������a��һ�����֡�����
    2+22+222+2222+22222(��ʱ����5�������)������������м��̿��ơ�
*/

int fun(int a, int n)
{
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum *= 10;
        sum += i * a;
    }

    return sum;
}

int fun1(int a, int n)
{
    long int sum=0,tn=0;
    long count = 0;

    while(count < n)
    {
        tn = tn + a;
        sum = sum + tn;
        a = a*10;
        ++count;
    }

    return sum;
}

int main()
{
    int a, n;

    printf("please input a and n:\n");
    scanf("%d %d", &a, &n);

    printf("fun: a+aa+...=%ld\n", fun(a, n));
    printf("fun1: a+aa+...=%ld\n", fun1(a, n));

    return 1;
}
#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 7)
/* ͬ��/����: ��ѧ�ҾͲ����� */

// ������Ϊmutex
pthread_mutex_t chopstick[6];
void *eat_think(void *arg)
{
    char phi = *(char *)arg;
    int left,right; //���ҿ��ӵı��
    switch (phi){  
        case 'A':  
            left = 5;
            right = 1;
            break;
        case 'B':  
            left = 1;
            right = 2;
            break;
        case 'C':  
            left = 2;
            right = 3;
            break;
        case 'D':  
            left = 3;
            right = 4;
            break;
        case 'E':  
            left = 4;
            right = 5;
            break;
    }

    int i;
    for(;;){
        sleep(1); //˼��
        pthread_mutex_lock(&chopstick[left]); //�������ֵĿ���
        printf("Philosopher %c fetches left chopstick %d, right %d\n", phi, left, right);
        if (pthread_mutex_trylock(&chopstick[right]) == EBUSY){ //�������ֵĿ���
            pthread_mutex_unlock(&chopstick[left]); //����ұ߿��ӱ����߷������ֵĿ���
            printf("Philosopher %c fetches release left chopstick %d for right %d busy\n", phi, left, right);
            continue;
        }

        //pthread_mutex_lock(&chopstick[right]); //�������ֵĿ��ӣ������۲�����������һ��ifע�͵����ٰ���һ���ע��ȥ��
        printf("Philosopher %c fetches right chopstick %d\n", phi, right);
        printf("Philosopher %c is eating.\n",phi);
        sleep(1); //�Է�

        pthread_mutex_unlock(&chopstick[left]); //�������ֵĿ���
        printf("Philosopher %c release left chopstick %d\n", phi, left);
        pthread_mutex_unlock(&chopstick[right]); //�������ֵĿ���
        printf("Philosopher %c release right chopstick %d\n", phi, right);
    }
}

int main(){
    pthread_t A,B,C,D,E; //5����ѧ��

    int i;
    for (i = 0; i < 5; i++)
        pthread_mutex_init(&chopstick[i],NULL);

    pthread_create(&A,NULL, eat_think, (void*)"A");
    pthread_create(&B,NULL, eat_think, (void*)"B");
    pthread_create(&C,NULL, eat_think, (void*)"C");
    pthread_create(&D,NULL, eat_think, (void*)"D");
    pthread_create(&E,NULL, eat_think, (void*)"E");

    pthread_join(A,NULL);
    pthread_join(B,NULL);
    pthread_join(C,NULL);
    pthread_join(D,NULL);
    pthread_join(E,NULL);
    return 0;
}
#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 8)
// KMP�㷨

void cal_next(char *str, int *next, int len)
{
    next[0] = -1;//next[0]��ʼ��Ϊ-1��-1��ʾ��������ͬ�����ǰ׺������׺
    int k = -1;//k��ʼ��Ϊ-1
    for (int q = 1; q <= len-1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])//�����һ����ͬ����ôk�ͱ��next[k]��ע��next[k]��С��k�ģ�����kȡ�κ�ֵ��
        {
            k = next[k];//��ǰ����
        }
        if (str[k + 1] == str[q])//�����ͬ��k++
        {
            k = k + 1;
        }
        next[q] = k;//����ǰ����k��ֵ��������ͬ�����ǰ׺������׺��������next[q]
    }
}

int KMP(char *str, int slen, char *ptr, int plen)
{
    int *next = new int[plen];
    cal_next(ptr, next, plen);//����next����

    printf("next plen = %d \n", plen);
    for (int i = 0; i < plen; i++) {
        printf("next[%d] = %d \n", i, next[i]);
    }

    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k >-1&& ptr[k + 1] != str[i])//ptr��str��ƥ�䣬��k>-1����ʾptr��str�в���ƥ�䣩
            k = next[k];//��ǰ����
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)//˵��k�ƶ���ptr����ĩ��
        {
            //cout << "��λ��" << i-plen+1<< endl;
            //k = -1;//���³�ʼ����Ѱ����һ��
            //i = i - plen + 1;//i��λ����λ�ã����forѭ��i++���Լ�������һ��������Ĭ�ϴ�������ƥ���ַ������Բ����ص�������л������ͬѧָ������
            return i-plen+1;//������Ӧ��λ��
        }
    }
    return -1;  
}

int main(){
    char *str = (char*)"bacbababadababacambabacaddababacasdsd";
    char *ptr = (char*)"ababaca";

    int a = KMP(str, 36, ptr, 7);

    printf("a = %d \n", a);

    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 9)

class testC{
public:
    char buffer[0];
    //int x;
};

int main(){

    testC A;
    testC B[100];

    printf("testC = %d, A = %d 0x%08x, B = %d 0x%08x, \n", sizeof(testC), sizeof(A), &A, sizeof(B), &B);

    int *buf = new int[10];
    buf[0] = 1;
    buf[1] = 2;
    buf[2] = 3;
    buf[3] = 4;
    buf[4] = 5;

    int *buf1 = NULL;
    printf("buf1 = %x\n", buf1);

    memcpy(buf1, buf, 10*sizeof(int));

    printf("buf[4] = %x, %d, buf1[4] = %x, %d \n", &buf[4], buf[4], &buf1[4], buf1[4]);

    delete []buf;
    int *buf2 = new int[10];
    buf2[0] = 6;
    buf2[1] = 7;
    buf2[2] = 8;
    buf2[3] = 9;
    buf2[4] = 10;

    printf("buf[4] = %x, %d, buf1[4] = %x, %d, buf2[4] = %x, %d \n",
           &buf[4], buf[4], &buf1[4], buf1[4], &buf2[4], buf2[4]);

    return 0;
}
#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 10)
//����Ļ�������(�ޱ�ͷ)

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}LNode, *LinkList;

static int g_data = 1;

//β�巨��������
LinkList CreateLinkList(int nNodeCount)
{
    LinkList head = NULL, p = NULL, r = NULL;
    int i;
    for (i = 0; i < nNodeCount; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        if (NULL == p)
        {
            printf("�����ڴ�ʧ��\n");
            free(p);
            exit(0);
        }
        printf("Ϊp->data��ֵ��");
        //scanf("%d", &p->data);
        p->data = g_data++;
        p->next = NULL;              //��̬����һ���ڵ�ʱ���ڳ�ʼ״̬�£���next��Ϊ��
        if (NULL == head)
        {
            head = p;
        }
        else
        {
            r->next = p;
        }
        r = p;
    }

    return head;
}

//�������
void PrintLinkList(LinkList L)
{
    LinkList p = NULL;
    if (NULL == L)
    {
        printf("����Ϊ��\n");
        exit(0);
    }
    p = L;
    printf("\n");
    while (NULL != p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

//����  ���ؼ��㣺0�� 1�� 2��
void InsertLinkList(LinkList &L, int nInsertPoint, ElemType nInsertValue)
{
    LinkList p = NULL, r = NULL;
    int i = 1;
    if (NULL == L)   //����У��
    {
        printf("����Ϊ��\n");
        exit(0);
    }
    r = (LinkList)malloc(sizeof(LNode)); //�����ڵ�У��
    if (NULL == r)
    {
        printf("�ڴ����ʧ��\n");
        free(r);
        exit(0);
    }
    r->data = nInsertValue;
    r->next = NULL;
    p = L;
    while ((NULL != p) && (i < nInsertPoint - 1))  //�Ϸ�����㣬ָ���ƶ�
    {
        p = p->next;
        i++;
    }
    if (1 == nInsertPoint)  //�����Ϊ1
    {
        r->next = p;
        L = r;
    }
    else
    {
        while ((NULL == p) || (i > nInsertPoint - 1))   //�жϷǷ�����㡣ǰ���ж��Ƿ�Խ�磬�����ж��Ƿ� <=0;
        {
            printf("�Ƿ�����㣬�������\n");
            exit(0);
        }
        //�Ϸ������
        r->next = p->next;
        p->next = r;
    }
}

//ɾ��
void DeleteLinkList(LinkList &L, int nDeletePoint)
{
    LinkList p = NULL, r = NULL;
    int i = 1;
    if (NULL == L)
    {
        printf("����Ϊ�գ��޷�ɾ��\n");
        exit(0);
    }
    p = L;
    while ((NULL != p) && (i < nDeletePoint - 1))
    {
        p = p->next;
        i++;
    }
    if (1 == nDeletePoint)
    {
        L = p->next;
        r = p;
    }
    else
    {
        while ((NULL == p) || (i > nDeletePoint - 1))
        {
            printf("�Ƿ�ɾ���㣬 �������\n");
            exit(0);
        }
        //�Ϸ�ɾ����
        r = p->next;
        p->next = r->next;
    }
    free(r);  //�ͷ�ɾ���ڵ�
}

//����
void DestroyLinkList(LinkList &L)
{
    LinkList p = NULL, r = NULL;
    if (NULL  == L)
    {
        printf("����Ϊ��\n");
        exit(0);
    }
    p = L;
    while (NULL != p)
    {
        r = p;
        p = p->next;
        free(r);
    }
    printf("�ɹ�����\n");
}

//����Ԫ��
ElemType FindLinkList(LinkList L, int nFindPoint)
{
    LinkList p = NULL;
    int i = 1;
    if (NULL == L)
    {
        printf("����Ϊ��\n");
        exit(0);
    }
    p = L;
    while ((NULL != L) && (i < nFindPoint - 1))
    {
        p = p->next;
        i++;
    }
    if (1 == nFindPoint)
    {
        return p->data;
    }
    else
    {
        while ((NULL == p) || (i > nFindPoint - 1))
        {
            printf("�Ƿ����ҵ�\n");
            exit(0);
        }
        return p->next->data;
    }
}

//�޸�Ԫ��
void ModifyLinkList(LinkList &L, int nModifyPoint, ElemType nModifyValue)
{
    LinkList p = NULL;
    int i = 1;
    if (NULL == L)
    {
        printf("����Ϊ��\n");
        exit(0);
    }
    p = L;

    while ((NULL != L) && (i < nModifyPoint - 1))
    {
        p = p->next;
        i++;
    }
    if (1 == nModifyPoint)
    {
        p->data = nModifyValue;
    }
    else
    {
        while ((NULL == p) || (i > nModifyPoint - 1))
        {
            printf("�Ƿ��޸ĵ�\n");
            exit(0);
        }
        p->next->data = nModifyValue;
    }
}

int main()
{
    LinkList La = NULL;
    La = CreateLinkList(4);
    //���Բ���
    printf("����ǰ����:\n");
    PrintLinkList(La);
    InsertLinkList(La, -1, 4);
    printf("���������:\n");
    PrintLinkList(La);

    //����ɾ��
    printf("ɾ��ǰ����:\n");
    PrintLinkList(La);
    DeleteLinkList(La, 2);
    printf("ɾ��������:\n");
    PrintLinkList(La);

    //���Բ���
    PrintLinkList(La);
    int x = FindLinkList(La, 2);
    printf("%d\n", x);

    //�����޸�
    PrintLinkList(La);
    ModifyLinkList(La, -1, 4);
    PrintLinkList(La);

    DestroyLinkList(La);   //��������
    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 11)

// ������ͨ�Ļ��������ʵ��һ����д��

count_mutex = mutex_init();
write_mutex = mutex_init();
read_count = 0;
 
void read_lock()
{
    lock(count_mutex);
    read_count++;
    if (read_count == 1) {
        lock(write_mutex);
    }
    unlock(count_mutex);
}

void read_unlock()
{
    lock(count_mutex);
    read_count--;
    if (read_count == 0) {
        unlock(write_mutex);
    }
    unlock(count_mutex);
}

void write_lock()
{
    lock(write_mutex);
}

void write_unlock()
{
    unlock(write_mutex);
}

int main()
{
    read_lock();
    write_lock();
    
    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 12)

int main(){

    for(int A = 9; A >=0; A--)
        for (int B = 9; B >=0; B--)
            for (int C = 9; C >=0; C--)
                for (int D = 9; D >=0; D--) {
                    if ((A*1000+B*100+C*10+D) == 9*(D*1000+C*100+B*10+A)
                        && (A*1000+B*100+C*10+D) < 10000 && !(A==B || B==C || C==D)) {
                        printf("ABCD = %d, DCBA = %d \n", (A*1000+B*100+C*10+D),
                               (D*1000+C*100+B*10+A));
                    }
                }

    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 13)
// ˫����������ڵ���żNode����˳��

// MY CODE
bool swap_dlist(DListNode *head)
{
    DListNode *node = NULL;
    DListNode *node1 = NULL;

    if (head == NULL) {
        return false;
    }

    for (node = head->next; node != NULL; node = node->next) {
        node1 = node->next;
        if(node1 == NULL)
            break;
  
        node->pre->next = node1;
        if (node1->next != NULL)
            node1->next->pre = node;

        node1->pre = node->pre;
        node->pre = node1;
 
        node->next = node1->next;
        node1->next = node;
    }
}

int main(){
    int length = 10;
    DListNode *head = new DListNode(-1);

    create_dlinklist(head, length);

    swap_dlist(head);

    print_dlinklist(head);

    return 0;
}

#endif


#if 0

using namespace std;  
  
typedef struct Node  
{  
    struct Node* next;  
    struct Node* pre;  
    int data;  
}Node;  
  
typedef struct D_List  
{  
    Node* head;  
    Node* tail;  
    int size;  
}D_List;  
  
bool creat_DList(D_List &l,int val)  
{  
    Node* node=(Node*)malloc(sizeof(Node));  
    node->next=NULL;  
    node->pre=NULL;  
    node->data=val;  
    //Node* head;  
    //Node* tail;  
    l.head=node;  
    l.tail=node;  
    if(node!=NULL)  
        return true;  
    else  
        return false;  
}  
  
bool insert_DList(D_List &l,int val)  
{  
    Node* node=(Node*)malloc(sizeof(Node));  
    node->data=val;  
    node->next=NULL;  
    l.tail->next=node;  
    node->pre=l.tail;  
    l.tail=node;  
    if(node!=NULL)  
        return true;  
    else  
        return false;  
}  
  
void func(D_List& l);  
  
int main()  
{  
    D_List l;  
    creat_DList(l,1);  
    insert_DList(l,2);  
    insert_DList(l,3);  
    insert_DList(l,4);  
    insert_DList(l,5);  
    insert_DList(l,6);  
    insert_DList(l,7);  
    insert_DList(l,8);  
    insert_DList(l,9);  
    insert_DList(l,10);  
    insert_DList(l,11);  
    insert_DList(l,12);  
    insert_DList(l,13);  
    cout<<l.head->data<<l.head->next->data<<endl;  
    cout<<l.tail->data<<l.tail->pre->data<<endl;  
    func(l);  
    Node *p=l.head;  
    while(p)  
    {  
        cout<<p->data<<endl;  
        p=p->next;  
    }
    return 0;  
}  
  
void func(D_List& l)  
{  
    Node* p=l.head;  
    l.head=p->next;  
    while(p&&p->next)  
    {  
        //p=p->next;  
        if(p->next)  
        {  
            Node* temp;  
            temp=p->next;  
            //�����ڵ��νӵ�P  
            p->next=temp->next;  
            if(temp->next!=NULL)  
            temp->next->pre=p;  
  
            //��ǰ�ڵ��Ƚӵ�temp  
            temp->pre=p->pre;  
            if(p->pre!=NULL)  
            p->pre->next=temp;  
  
            temp->next=p;  
            //temp=p->pre;  
  
            p->pre=temp;  
  
            //p=temp;  
            p=p->next;  
        }  
    }

    printf("swap: ");
    for (p =  l.head->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}  

#endif



#if (SUAN == 14)
// ����������ڵ���żNode����˳��

// MY CODE
bool swap_linklist(ListNode *head)
{
    ListNode *node = NULL;
    ListNode *node1 = NULL;  // ��¼��һ�����
    ListNode *nodepre = NULL;  // ��¼ǰһ�����

    if (head == NULL) {
        return false;
    }

    nodepre = head;
    for (node = head->next; node != NULL; node = node->next) {
        node1 = node->next;
        node->next = node1->next;
        node1->next = node;
        nodepre->next = node1;
        nodepre = node;
    }
}

int main()
{
    int length = 10;
    ListNode *head = new ListNode(-1);

    create_linklist(head, length);
    swap_linklist(head);
  
    print_linklist(head);

    return 0;
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 15)
// �˻ʺ�����

static int gEightQueen[8] = { 0 }, gCount = 0;
void print()//���ÿһ������������лʺ�İڷ����
{
    for (int i = 0; i < 8; i++)
    {   
        int inner;
        for (inner = 0; inner < gEightQueen[i]; inner++)
            cout << "*";
            cout <<"#";
        for (inner = gEightQueen[i] + 1; inner < 8; inner++)
            cout << "*";
        cout << endl;
    }
    cout << "==========================\n";
}

int check_pos_valid(int loop, int value)//����Ƿ�����ж���ʺ���ͬһ��/��/�Խ��ߵ����
{
    int index;
    int data;
    for (index = 0; index < loop; index++)
    {
        data = gEightQueen[index];
        if (value == data)
            return 0;
        if ((index + data) == (loop + value))
            return 0;
        if ((index - data) == (loop - value))
            return 0;
    }
    return 1;
}

void eight_queen(int index)
{
    int loop;
    for (loop = 0; loop < 8; loop++)
    {
        if (check_pos_valid(index, loop))
        {
            gEightQueen[index] = loop;
            if (7 == index)
            {
                gCount++, print();
                gEightQueen[index] = 0;
                return;
            }
            eight_queen(index + 1);
            gEightQueen[index] = 0;
        }
    }
}

int main(int argc, char*argv[])
{
    eight_queen(0);
    cout << "total=" << gCount << endl;
    return 0;
}

#endif

#if (SUAN == 16)

// MY CODE
/* �����ͬһ��б���ж�:
    ����1: ֻ�����ֿ��ܣ�һ�Ǻ�������֮����ȣ�һ�Ǻ�������֮�����;
    \ ������б�ߣ�ͬһ�Խ��ߣ���ôx1-y1=x2-y2;
    / ������б�ߣ�ͬһ�Խ��ߣ���ôx1+y1=x2+y2;

    ����2: ��math����abs����abs(x2-x1) == abs(y2-y1)
*/


static int g_eight_queen[8] = { 0 };
int g_count = 0;

void print_eight_queen()
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (g_eight_queen[i] == j) {
                printf("#");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("==========================\n");
}

int check_pos_valid(int loop, int value)
{
    int index;
    int data;
    for (index = 0; index < loop; index++)
    {
        data = g_eight_queen[index];
        if (value == data)
            return 0;
        if ((index + data) == (loop + value))
            return 0;
        if ((index - data) == (loop - value))
            return 0;
    }
    return 1;
}

int check_pos_valid1(int loop, int value)
{
    int index;
    int data;
    for (index = 0; index < loop; index++)
    {
        data = g_eight_queen[index];
        if ((value == data) ||
            abs(loop - index) == abs(value - data))
            return 0;
    }
    return 1;
}

void eight_queen(int index)
{
    int loop;
    for (loop = 0; loop < 8; loop++)
    {
        if (check_pos_valid(index, loop))
        {
            g_eight_queen[index] = loop;
            if (7 == index)
            {
                g_count++;
                print_eight_queen();
                g_eight_queen[index] = 0;
                return;
            }
            eight_queen(index + 1);
            g_eight_queen[index] = 0;
        }
    }
}

int main(int argc, char*argv[])
{
    eight_queen(0);
    printf("total = %d \n", g_count);

    return 0;
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if (SUAN == 17)
// ������������С��k���� 

// MY CODE

void sort(vector<int> &array, int number)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    for (i = number-1; i >= 0; i--) {
        for (j = i; j >= 1; j--) {
            if (array[j] < array[j-1]) {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

vector<int> get_minK(vector<int> input, int k)
{
    int i = 0;
    int number = input.size();
    vector<int> out;

    if (input.empty()) {
        return out;
    }

    for (i = 0; i < k; i++) {
        out.push_back(input[i]);
    }

    sort(out, k);

    for (i = k; i < number; i++) {
        if (input[i] < out[k-1]) {
            out[k-1] = input[i];
            sort(out, k);
        }
    }

    return out;
}

int main(int argc, char*argv[])
{
    int array[] = {0,13,5,38,4,10,13,22,55,42,36,1,5,-3,78,11,32,18};
    int number = sizeof(array)/sizeof(int);
    vector<int> vec(array, array+number);
    int minK = 4;
    vector<int> out;

    out = get_minK(vec, minK);

    for (int i = 0; i < minK; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");

    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////


