


////////////////////////////////////////////////////////////////////////////////

/* 兔子问题：
   有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月
   又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少对？
   兔子规律对: 1, 1, 2, 3, 
*/

#if 0

// 标准


#include <stdlib.h>
#include <stdio.h>

int fun(int m)
{
    if (m == 1 || m == 2)
        return 1;
    else
        return (fun(m-1) + fun(m-2));
}

int main()
{
    int month = 12;
    int i;

    for (i = 1; i <= month; ++i) {
        printf("month %d: %d \n", i, fun(i));
    }

    return 0;
}

#endif

#if 0
#include <stdlib.h>
#include <stdio.h>

// 标准

main()
{
    long f1,f2;
    int i;
    f1=f2=1;
    for(i=1;i<=20;i++) {
        printf("%12ld %12ld",f1,f2);
        if(i%2==0)
            printf("\n");/*控制输出，每行四个*/
        f1=f1+f2;/*前两个月加起来赋值给第三个月*/
        f2=f1+f2;/*前两个月加起来赋值给第三个月*/
    }
}

#endif

////////////////////////////////////////////////////////////////////////////////

#if 0
/*
    判断101-200之间有多少个素数，并输出所有素数。
    1, 2, 3, 5, 7, 11, 13, 17, 19,
*/

#include <stdlib.h>
#include <stdio.h>
#include "math.h"

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

/*
    打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和
    等于该数本身。例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3的三次方。

    程序分析：利用for循环控制100-999个数，每个数分解出个位，十位，百位。
*/

#if 0

#include <stdlib.h>
#include <stdio.h>
#include "math.h"

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

/*
将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。

程序分析：对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：
(1)如果这个质数恰等于n，则说明分解质因数的过程已经结束，打印出即可。
(2)如果n<>k，但n能被k整除，则应打印出k的值，并用n除以k的商,作为新的正
   整数你n,重复执行第一步。
(3)如果n不能被k整除，则用k+1作为k的值,重复执行第一步。
*/

#if 0

// 标准

#include <stdlib.h>
#include <stdio.h>
#include "math.h"


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

/*
    输入两个正整数m和n，求其最大公约数和最小公倍数。 **************************

    参考算法: 辗除法，即辗转相除法，又名欧几里德算法，乃求两个正整数之最大公因子的算法。
*/

#if 0

#include <stdlib.h>
#include <stdio.h>

/*
int main()
{
    int num1, num2, i, num;
    int big, small;

    printf("\nplease input a number:\n");
    scanf("%d %d", &num1, &num2);
    printf("%d, %d \n", num1, num2);

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
*/

// 标准

main()
{
    int a,b,num1,num2,temp;

    printf("please input two numbers:\n");
    scanf("%d %d",&num1,&num2);

    if(num1) {
        temp=num1;
        num1=num2;
        num2=temp;
    }

    a=num1;b=num2;
    while(b!=0)/*利用辗除法，直到b为0为止*/
    {
        temp=a%b;
        a=b;
        b=temp;

        printf("a = %d, b = %d, t = %d \n", a, b, temp);
    }

    printf("gongyueshu:%d\n",a);
    printf("gongbeishu:%d\n",num1*num2/a);
}


#endif


////////////////////////////////////////////////////////////////////////////////

/*
    题目：求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如
    2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
*/
#if 0

#include <stdlib.h>
#include <stdio.h>


int main()
{
    int a, n, sum=0;
    int i;

    printf("please input a and n:\n");
    scanf("%d %d", &a, &n);

    for (int i = 1; i <= n; ++i) {
        sum *= 10;
        sum += i * a;
    }

    printf("sum: %d\n", sum);
}


#endif

// 参考

#if 0
#include <stdio.h>

main()
{
    int a,n,count=1;
    long int sn=0,tn=0;
    printf("please input a and n\n");
    scanf("%d,%d",&a,&n);
    printf("a=%d,n=%d\n",a,n);
    while(count<=n)
    {
        tn=tn+a;
        sn=sn+tn;
        a=a*10;
        ++count;
    }
    printf("a+aa+...=%ld\n",sn);
}

#endif


////////////////////////////////////////////////////////////////////////////////

/* 同步/互斥: 哲学家就餐问题 */

#if 0

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pthread.h>
#include <errno.h>
#include <math.h>
#include <unistd.h>


//筷子作为mutex
pthread_mutex_t chopstick[6];
void *eat_think(void *arg)
{
    char phi = *(char *)arg;
    int left,right; //左右筷子的编号
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
        sleep(1); //思考
        pthread_mutex_lock(&chopstick[left]); //拿起左手的筷子
        printf("Philosopher %c fetches left chopstick %d, right %d\n", phi, left, right);
        if (pthread_mutex_trylock(&chopstick[right]) == EBUSY){ //拿起右手的筷子
            pthread_mutex_unlock(&chopstick[left]); //如果右边筷子被拿走放下左手的筷子
            printf("Philosopher %c fetches release left chopstick %d for right %d busy\n", phi, left, right);
            continue;
        }

        //pthread_mutex_lock(&chopstick[right]); //拿起右手的筷子，如果想观察死锁，把上一句if注释掉，再把这一句的注释去掉
        printf("Philosopher %c fetches right chopstick %d\n", phi, right);
        printf("Philosopher %c is eating.\n",phi);
        sleep(1); //吃饭

        pthread_mutex_unlock(&chopstick[left]); //放下左手的筷子
        printf("Philosopher %c release left chopstick %d\n", phi, left);
        pthread_mutex_unlock(&chopstick[right]); //放下左手的筷子
        printf("Philosopher %c release right chopstick %d\n", phi, right);
    }
}

int main(){
    pthread_t A,B,C,D,E; //5个哲学家

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
// gcc suanfa.c -lm -o suanfa

/* 等额本息 */

#if 0
#include <stdio.h>
#include <math.h>

main()
{
    double sum = 10000;
    double rate = 0.0042;
    double mom_rate = rate / 12;
    double mon_benxi = 0;
    double mons = 12;
    double sum_lixi;
    double mon_lixi;

    /* sum：贷款本金
       rate: 贷款月利率
       month：贷款月数
    */
    //monPay = sum * [rate*(1+rate)^n]/[(1+rate)^n-1]
    sum_lixi = sum * mons * mom_rate * pow((1+mom_rate), mons) / (pow((1+mom_rate), mons) - 1) - sum;
    mon_benxi = (sum * rate * pow((1+rate), mons)) / (pow((1+rate), mons) - 1);

    printf("monPay = %f", monPay);
    /*
    　　每月利息 = 剩余本金x贷款月利率
    　　还款总利息=贷款额*贷款月数*月利率*（1+月利率）贷款月数/【（1+月利率）还款月数 - 1】-贷款额
        还款总额=还款月数*贷款额*月利率*（1+月利率）贷款月数/【（1+月利率）还款月数 - 1】

    */
    printf("\n");
}
#endif


#if 0

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//AC    等额本金 Average Capital
//ACPI  等额本息 Average Capital Plus Interest
float fLoanSum;//总需要贷款金额
float fMonthIRate;//月利率（年利率求得）
float fACPI_MonthPay;//ACPI月付
float fACPI_PaidI = 0;//ACPI已经付清的金额
float fAC_PaidP = 0;//AC已经付清的金额
float fACPI_Sum = 0;//ACPI贷款还款的本息和
float fAC_Sum = 0;//AC贷款还款的本息和
int iMonth, i;

int main()
{
    float fMonthI, fMonthP;//月息和本金

    puts("请输入：\n贷款总额(元)\t贷款年限\t贷款利率%：");
    scanf("%f %d %f", &fLoanSum, &iMonth, &fMonthIRate);
    fMonthIRate /= 12;//求得月利率
    fMonthIRate /= 100;//去掉%，直接算得月利率：x%的值
    iMonth *= 12;

    //等额本息
    fACPI_MonthPay = fLoanSum*fMonthIRate*pow(1 + fMonthIRate, iMonth) / (pow(1 + fMonthIRate, iMonth) - 1); //每月本息和

    printf("等额本息:\n");
    printf("  月份\t 月还款\t 月本金\t 月利息\n");
    for (i = 1; i <= iMonth; i++)
    {
        fMonthI = (fLoanSum - fACPI_PaidI)*fMonthIRate; //每月利息
        fACPI_Sum += fMonthI;                           //纳入还款总额

        fMonthP = fACPI_MonthPay - fMonthI;             //每月本金
        fACPI_PaidI += fMonthP;                         //已付本金

        //printf("   Month[%d]:Sum:%.2f  MonthInterest:%.2f  MonthPrincipal:%.2f\n", i, fMonthI + fMonthP, fMonthI, fMonthP);
        printf("  %d月:\t %.2f\t %.2f\t %.2f\n", i, fMonthI + fMonthP, fMonthP, fMonthI);
    }
    printf("总利息:\t %.2f 本息总和:%.2f\n\n", fACPI_Sum, fACPI_Sum + fLoanSum);

    //等额本金
    fMonthP = fLoanSum / iMonth;                        //每月本金

    printf("等额本金: \n");
    printf("  月份\t 月还款\t 月本金\t 月利息\n");
    for (i = 1; i <= iMonth; i++)
    {
        fMonthI = (fLoanSum - fAC_PaidP)*fMonthIRate;   //月利息
        fAC_Sum += fMonthI;                             //计入还款额

        fAC_PaidP += fMonthP;                           //已付本金
        //printf("   Month[%d]:Sum:%.2f  MonthInterest:%.2f  MonthPrincipal:%.2f\n", i, fMonthI + fMonthP, fMonthI, fMonthP);
        printf("  %d月:\t %.2f\t %.2f\t %.2f\n", i, fMonthI + fMonthP, fMonthP, fMonthI);
    }

    printf("总利息:\t %.2f 本息总和:%.2f\n", fAC_Sum, fAC_Sum + fLoanSum);

    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////

// KMP算法

#if 0

#include<stdio.h>
#include<stdlib.h>

void cal_next(char *str, int *next, int len)
{
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1;//k初始化为-1
    for (int q = 1; q <= len-1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
        {
            k = next[k];//往前回溯
        }
        if (str[k + 1] == str[q])//如果相同，k++
        {
            k = k + 1;
        }
        next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}

int KMP(char *str, int slen, char *ptr, int plen)
{
    int *next = new int[plen];
    cal_next(ptr, next, plen);//计算next数组

    printf("next plen = %d \n", plen);
    for (int i = 0; i < plen; i++) {
        printf("next[%d] = %d \n", i, next[i]);
    }

    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k >-1&& ptr[k + 1] != str[i])//ptr和str不匹配，且k>-1（表示ptr和str有部分匹配）
            k = next[k];//往前回溯
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)//说明k移动到ptr的最末端
        {
            //cout << "在位置" << i-plen+1<< endl;
            //k = -1;//重新初始化，寻找下一个
            //i = i - plen + 1;//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠），感谢评论中同学指出错误。
            return i-plen+1;//返回相应的位置
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
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

#if 0
//链表的基本操作(无表头)

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}LNode, *LinkList;

static int g_data = 1;

//尾插法创建链表
LinkList CreateLinkList(int nNodeCount)
{
    LinkList head = NULL, p = NULL, r = NULL;
    int i;
    for (i = 0; i < nNodeCount; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        if (NULL == p)
        {
            printf("分配内存失败\n");
            free(p);
            exit(0);
        }
        printf("为p->data赋值：");
        //scanf("%d", &p->data);
        p->data = g_data++;
        p->next = NULL;              //动态创建一个节点时，在初始状态下，令next域为空
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

//输出链表
void PrintLinkList(LinkList L)
{
    LinkList p = NULL;
    if (NULL == L)
    {
        printf("链表为空\n");
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

//插入  （关键点：0， 1， 2）
void InsertLinkList(LinkList &L, int nInsertPoint, ElemType nInsertValue)
{
    LinkList p = NULL, r = NULL;
    int i = 1;
    if (NULL == L)   //链表校验
    {
        printf("链表为空\n");
        exit(0);
    }
    r = (LinkList)malloc(sizeof(LNode)); //创建节点校验
    if (NULL == r)
    {
        printf("内存分配失败\n");
        free(r);
        exit(0);
    }
    r->data = nInsertValue;
    r->next = NULL;
    p = L;
    while ((NULL != p) && (i < nInsertPoint - 1))  //合法插入点，指针移动
    {
        p = p->next;
        i++;
    }
    if (1 == nInsertPoint)  //插入点为1
    {
        r->next = p;
        L = r;
    }
    else
    {
        while ((NULL == p) || (i > nInsertPoint - 1))   //判断非法插入点。前者判断是否越界，后者判断是否 <=0;
        {
            printf("非法插入点，请检查参数\n");
            exit(0);
        }
        //合法插入点
        r->next = p->next;
        p->next = r;
    }
}

//删除
void DeleteLinkList(LinkList &L, int nDeletePoint)
{
    LinkList p = NULL, r = NULL;
    int i = 1;
    if (NULL == L)
    {
        printf("链表为空，无法删除\n");
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
            printf("非法删除点， 请检查参数\n");
            exit(0);
        }
        //合法删除点
        r = p->next;
        p->next = r->next;
    }
    free(r);  //释放删除节点
}

//销毁
void DestroyLinkList(LinkList &L)
{
    LinkList p = NULL, r = NULL;
    if (NULL  == L)
    {
        printf("链表为空\n");
        exit(0);
    }
    p = L;
    while (NULL != p)
    {
        r = p;
        p = p->next;
        free(r);
    }
    printf("成功销毁\n");
}

//查找元素
ElemType FindLinkList(LinkList L, int nFindPoint)
{
    LinkList p = NULL;
    int i = 1;
    if (NULL == L)
    {
        printf("链表为空\n");
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
            printf("非法查找点\n");
            exit(0);
        }
        return p->next->data;
    }
}

//修改元素
void ModifyLinkList(LinkList &L, int nModifyPoint, ElemType nModifyValue)
{
    LinkList p = NULL;
    int i = 1;
    if (NULL == L)
    {
        printf("链表为空\n");
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
            printf("非法修改点\n");
            exit(0);
        }
        p->next->data = nModifyValue;
    }
}

int main()
{
    LinkList La = NULL;
    La = CreateLinkList(4);
    //测试插入
    printf("插入前链表:\n");
    PrintLinkList(La);
    InsertLinkList(La, -1, 4);
    printf("插入后链表:\n");
    PrintLinkList(La);

    //测试删除
    printf("删除前链表:\n");
    PrintLinkList(La);
    DeleteLinkList(La, 2);
    printf("删除后链表:\n");
    PrintLinkList(La);

    //测试查找
    PrintLinkList(La);
    int x = FindLinkList(La, 2);
    printf("%d\n", x);

    //测试修改
    PrintLinkList(La);
    ModifyLinkList(La, -1, 4);
    PrintLinkList(La);

    DestroyLinkList(La);   //销毁链表
    return 0;
}

#endif


////////////////////////////////////////////////////////////////////////////////


#if 0

// 请用普通的互斥锁编程实现一个读写锁

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

#if 0

#include <stdio.h>
#include <stdlib.h>


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

// 双向链表的相邻的奇偶Node调换顺序

#if 0

// 自己编写

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    Node *pre;
    Node *next;
} NODE;

bool create_linklist(NODE *head, int length)
{
    NODE *node = NULL;
    NODE *node1 = NULL;

    head->data = -1;
    head->pre = NULL;

    node = new NODE;
    if (node == NULL) {
        return false;
    }
    node->data = 0;
    node->pre = head;
    head->next = node;

    for (int i = 1; i < length; i++) {
        node1 = new NODE;
        if (node1 == NULL) {
            return false;
        }

        node1->data = i;
        node1->pre = node;
        node1->next = NULL;
        node->next = node1;
        node = node1;
    }

    for (node = head->next; node != NULL; node = node->next) {
        printf("%d ", node->data);
    }
    printf("\n");

    return true;
}

bool swap_list(NODE *head)
{
    NODE *node = NULL;
    NODE *node1 = NULL;

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

        //printf("b %d %d", node->data, node->pre->data);
        //printf("\n");
    }

    printf("swap: ");
    for (node = head->next; node != NULL; node = node->next) {
        printf("%d ", node->data);
    }
    printf("\n");
}

int main(){
    int length = 10;
    NODE *head = new NODE;

    create_linklist(head, length);

    swap_list(head);

    return 0;
}



#endif


#if 0

#include <stdlib.h>  
#include <stdio.h>  

#include <iostream>  
#include <string.h>  
#include <vector>  
#include <iterator>  
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
            //将最后节点衔接到P  
            p->next=temp->next;  
            if(temp->next!=NULL)  
            temp->next->pre=p;  
  
            //将前节点先接到temp  
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


// 单链表的相邻的奇偶Node调换顺序

#if 0

// 自己编写

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    Node *next;
} NODE;

bool create_linklist(NODE *head, int length)
{
    NODE *node = NULL;
    NODE *node1 = NULL;

    head->data = -1;

    node = new NODE;
    if (node == NULL) {
        return false;
    }
    node->data = 0;
    node->next = NULL;
    head->next = node;

    for (int i = 1; i < length; i++) {
        node1 = new NODE;
        if (node1 == NULL) {
            return false;
        }

        node1->data = i;
        node1->next = NULL;
        node->next = node1;
        node = node1;
    }

    for (node = head->next; node != NULL; node = node->next) {
        printf("%d ", node->data);
    }
    printf("\n");

    return true;
}

bool swap_list(NODE *head)
{
    NODE *node = NULL;
    NODE *node1 = NULL;  // 记录下一个结点
    NODE *nodepre = NULL;  // 记录前一个结点

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

    printf("swap: ");
    for (node = head->next; node != NULL; node = node->next) {
        printf("%d ", node->data);
    }
    printf("\n");
}

int main(){
    int length = 10;
    NODE *head = new NODE;

    create_linklist(head, length);
    swap_list(head);

    return 0;
}



#endif



////////////////////////////////////////////////////////////////////////////////

#if 0

#include<iostream>
using namespace std;
static int gEightQueen[8] = { 0 }, gCount = 0;
void print()//输出每一种情况下棋盘中皇后的摆放情况
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
int check_pos_valid(int loop, int value)//检查是否存在有多个皇后在同一行/列/对角线的情况
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

#if 0

// 自己编写
/* 如果在同一条斜线判断:
    方法1: 只有两种可能，一是横纵坐标之和相等，一是横纵坐标之差相等;
    \ 这样的斜线，同一对角线，那么x1-y1=x2-y2;
    / 这样的斜线，同一对角线，那么x1+y1=x2+y2;

    方法2: 用math函数abs，则abs(x2-x1) == abs(y2-y1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
/*
int check_pos_valid(int loop, int value)
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
*/
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

#if 1

// 自己编写

#include <stdio.h>
#include <stdlib.h>

#define MINK 5

int g_min[MINK] = {0};

void sort(int array[], int number)
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

void insert_compare(int value)
{
    int i = 0;

    if (value < g_min[4])
        g_min[4] = value;

    for (i = 0; i < MINK; i++) {
        sort(g_min, MINK);
    }
}

void get_minK(int array[], int number)
{
    int i = 0;

    for (i = 0; i < MINK; i++) {
        g_min[i] = array[i];
    }

    sort(g_min, MINK);

    for (i = MINK; i < number; i++) {
        insert_compare(array[i]);
    }
}

#include <math.h>

int main(int argc, char*argv[])
{
    int array[] = {0,13,5,38,4,10,13,22,55,42,36,1,5,-3,78,11,32,18};
    int number = sizeof(array)/sizeof(int);

    get_minK(array, number);

    for (int i = 0; i < MINK; i++) {
        printf("%d ", g_min[i]);
    }
    printf("\n");

    
    for (int i = 1; i < 200; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i < 200; i++) {
        printf("%f ", log2((double)i));
    }
    printf("\n");

    printf("N = %d, logN = %f, N = %d, logN = %f, N = %d, logN = %f, N = %d, logN = %f, N = %d, logN = %f\n", 10, log2(10), 100, log2(100), 1000, log2(1000), 10000, log2(10000), 100000, log2(100000));

    return 0;
}

#endif



////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

