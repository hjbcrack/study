

#include "common.h"

////////////////////////////////////////////////////////////////////////////////

int Array[] = {2, 5, 3, 9, 8, 6, 10, 2, 7};
//int Array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//int Array[] = {2,3,4,5,1};

int nArray = sizeof(Array)/sizeof(int);


void output(int array[], int number)
{
    for (int i = 0; i < number; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

////////////////////////////////////////////////////////////////////////////////

// 冒泡，从index i=0开始，每次循环比较前面number-1-i个未排序的元素，每次都在未排序元素的末尾放上当前最大值

void maopao(int array[], int number)
{
    for (int i = 0; i < number-1; i++) {
        for (int j = 0; j < number-1-i; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }

        output(array, nArray);
    }
}

////////////////////////////////////////////////////////////////////////////////
// 鸡尾酒排序冒泡，也叫定向冒泡排序，是冒泡排序的一种改进。此算法与冒泡排序的不同处在于从低到高然后从高到低

void cocktail(int array[], int number)
{
    int left =0;
    int right = number;
    int move = 0;

    while(left < right) {
        for (int i = left; i < right-1; i++) {
            if (array[i] > array[i+1]) {
                swap(&array[i], &array[i+1]);
                move = 1;
            }
        }

        if (move == 0)
            break;
        right--;
        move = 0;

        output(array, nArray);

        for (int i = right; i > left; i--) {
            if (array[i] < array[i-1]) {
                swap(&array[i], &array[i-1]);
                move = 1;
            }
        }

        if (move == 0)
            break;
        left++;
        move = 0;

        output(array, nArray);
    }
}

////////////////////////////////////////////////////////////////////////////////

// 选择，从index i=0开始，每次从后面的元素里循环查找最小值放在index i的位置。

void xuanze(int array[], int number)
{
    for (int i = 0; i < number-1; i++) {
        int min = i;
        for (int j = i+1; j < number; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(&array[i], &array[min]);

        output(array, nArray);
    }
}

////////////////////////////////////////////////////////////////////////////////

// 插入，从index i=1开始，每次循环比较移动前面i-1个已经排序的元素，最终将其放在<=array[i]的元素之后

void charu(int array[], int number)
{
    for (int i = 1; i < number; i++) {
        if(array[i] < array[i-1]) {
            int j = i;
            int tmp = array[i];
            while(j >= 1 && tmp < array[j-1]) {
                array[j] = array[j-1];
                j--;
            }

            array[j] = tmp;
        }

        output(array, nArray);
    }
}

////////////////////////////////////////////////////////////////////////////////

// 二分插入，从index i=1开始，每次循环比较移动前面i-1个已经排序的元素，最终将其放在<=array[i]的元素之后

void erfencharu(int array[], int number)
{
    for (int i = 1; i < number; i++) {
        if(array[i] < array[i-1]) {
            int tmp = array[i];
            int left = 0;
            int right = i-1;
            int mid;

            while(left <= right) {
                mid = (left+right) / 2;
                if (tmp > array[mid]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            int j = i;
            while(j > left) {
                array[j] = array[j-1];
                j--;
            }
            array[j] = tmp;
        }

        output(array, nArray);
    }
}

////////////////////////////////////////////////////////////////////////////////

/* 希尔，改进的插入排序，从index i=1开始，每次循环比较移动前面i-1个已经排序的元素，
         最终将其放在<=array[i]的元素之后，不同之处是，每次移动的步长逐步缩小递减
*/
void shell(int array[], int number)
{
    int h = 0;

    while (h <= number)                          // 生成初始增量
    {
        h = 3 * h + 1;
    }

    while (h >= 1)
    {
        for (int i = h; i < number; i++)
        {
            if(array[i] < array[i-h]) {
                int j = i;
                int tmp = array[i];
                while(j >= h && tmp < array[j-h]) {
                    array[j] = array[j-h];
                    j -= h;
                }

                array[j] = tmp;
            }
        }

        h = (h - 1) / 3;                    // 递减增量

        output(array, nArray);
    }
}

////////////////////////////////////////////////////////////////////////////////

/* 快速，从index i=0开始，每次从后面的元素里循环查找最小值放在index i的位置。
    快速排序的时间主要耗费在划分操作上，对长度为k的区间进行划分，共需k-1次关键字的比较。

    最坏情况是每次划分选取的基准都是当前无序区中关键字最小(或最大)的记录，划分的结果是
    基准左边的子区间为空(或右边的子区间为空)，而划分所得的另一个非空的子区间中记录数目，
    仅仅比划分前的无序区中记录个数减少一个。时间复杂度为O(n*n)

    在最好情况下，每次划分所取的基准都是当前无序区的"中值"记录，划分的结果是基准的左、
    右两个无序子区间的长度大致相等。总的关键字比较次数：O(nlgn)

    尽管快速排序的最坏时间为O(n2)，但就平均性能而言，它是基于关键字比较的内部排序算法中
    速度最快者，快速排序亦因此而得名。它的平均时间复杂度为O(nlgn)。

*/
int Partition(int array[], int left, int right)  // 划分函数
{
    int pivot = array[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                    // tail为小于基准的子数组最后一个元素的索引

    for (int i = left; i < right; i++)      // 遍历基准以外的其他元素
    {
        if (array[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
        {
            swap(&array[++tail], &array[i]);
        }
    }

    swap(&array[tail + 1], &array[right]);  // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
                                            // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    output(array, nArray);
    return tail + 1;                        // 返回基准的索引
}

void QuickSort(int array[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(array, left, right); // 基准的索引
    QuickSort(array, left, pivot_index - 1);
    QuickSort(array, pivot_index + 1, right);
}

////////////////////////////////////////////////////////////////////////////////

/*
    堆排序
    堆排序是指利用堆这种数据结构所设计的一种选择排序算法。堆是一种近似完全二叉树的结构（通常堆是通过一维数组来实现的），
    并满足性质：以最大堆（也叫大根堆、大顶堆）为例，其中父结点的值总是大于它的孩子节点。

    1. 由输入的无序数组构造一个最大堆，作为初始的无序区
    2. 把堆顶元素（最大值）和堆尾元素互换
    3. 把堆（无序区）的尺寸缩小1，并调用heapify(A, 0)从新的堆顶元素开始进行堆调整
    4. 重复步骤2，直到堆的尺寸为1
*/

#include <stdio.h>

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定


void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
    int left_child = 2 * i + 1;         // 左孩子索引
    int right_child = 2 * i + 2;        // 右孩子索引
    int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
    if (left_child < size && A[left_child] > A[max])
        max = left_child;
    if (right_child < size && A[right_child] > A[max])
        max = right_child;
    if (max != i)
    {
        swap(&A[i], &A[max]);           // 把当前结点和它的最大(直接)子节点进行交换
        Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整

        output(A, nArray);
    }
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
        Heapify(A, i, heap_size);
    return heap_size;
}

void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);    // 建立一个最大堆
    while (heap_size > 1)               // 堆（无序区）元素个数大于1，未完成排序
    {
        // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
        // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
        swap(&A[0], &A[--heap_size]);
        Heapify(A, 0, heap_size);       // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
    }
}

////////////////////////////////////////////////////////////////////////////////

/*
归并排序是创建在归并操作上的一种有效的排序算法，效率为O(nlogn)，1945年由冯·诺伊曼首次提出。

　　归并排序的实现分为递归实现与非递归(迭代)实现。递归实现的归并排序是算法设计中分治策略的典型应用，我们将一个大问题分割成小问题分别解决，然后用所有小问题的答案来解决整个大问题。非递归(迭代)实现的归并排序首先进行是两两归并，然后四四归并，然后是八八归并，一直下去直到归并了整个数组。

　　归并排序算法主要依赖归并(Merge)操作。归并操作指的是将两个已经排序的序列合并成一个序列的操作，归并操作步骤如下：

    申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
    设定两个指针，最初位置分别为两个已经排序序列的起始位置
    比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
    重复步骤3直到某一指针到达序列尾
    将另一序列剩下的所有元素直接复制到合并序列尾
*/

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定


void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素

    while (index < len)
    {
        if (i <= mid && j <= right) {
            temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
        } else if (i <= mid) {
            temp[index++] = A[i++];
        } if (j <= right) {
            temp[index++] = A[j++];
        }
    }

    for (index = 0; index < len; index++)
    {
        A[left++] = temp[index];
    }

    output(temp, len);
}

void MergeSortRecursion(int A[], int left, int right)    // 递归实现的归并排序(自顶向下)
{
    if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)    // 非递归(迭代)实现的归并排序(自底向上)
{
    int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
    {
        left = 0;
        while (left + i < len)              // 后一个子数组存在(需要归并)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
            Merge(A, left, mid, right);
            left = right + 1;               // 前一个子数组索引向后移动

            output(A, len);
        }
    }
}

int t_maopao(int A[], int number)
{
    for (int i = 0; i < number-1; i++) {
        for (int j = 0; j < number-1-i; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
            }
        }
        output(A, number);
    }
}

int t_cocktail(int A[], int number)
{
    int left = 0;
    int right = number;
    int move = 0;

    while (left < right) {
        for (int i = left; i < right-1; i++) {
            if (A[i] > A[i+1]) {
                swap(A[i], A[i+1]);
                move = 1;
            }
        }
        output(A, number);

        if (move == 0)
            break;
        right--;
        move = 0;

        for (int i = right-1; i > left; i--) {
            if (A[i] < A[i-1]) {
                swap(A[i], A[i-1]);
                move = 1;
            }
        }

        output(A, number);

        if (move == 0)
            break;
        left++;
        move = 0;
    }
}

int t_xuanze(int A[], int number)
{
    int index;

    for (int i = 0; i < number-1; i++) {
        index = i;
        for (int j = i+1; j < number; j++) {
            if (A[index] > A[j]) {
                index = j;
            }
        }
        swap(A[i], A[index]);
        output(A, number);
    }
}

int t_charu(int A[], int number)
{
    for (int i = 1; i < number; i++) {
        if(A[i] < A[i-1]) {
            int j = i;
            int tmp = A[i];
            while(j >= 1 && tmp < A[j-1]) {
                A[j] = A[j-1];
                j--;
            }

            A[j] = tmp;
        }

        output(A, nArray);
    }
}


int main()
{
    printf("input: \n");
    output(Array, nArray);
    printf("------------------------------\n");

    //maopao(Array, nArray);
    //cocktail(Array, nArray);
    //xuanze(Array, nArray);
    //charu(Array, nArray);
    //erfencharu(Array, nArray);
    //shell(Array, nArray);
    //QuickSort(Array, 0, nArray-1);
    //HeapSort(Array, nArray);
/*
    printf("------------------------------\n");
    printf("output: \n");

    output(Array, nArray);

    int A1[] = { 6, 5, 3, 1, 8, 7, 2, 4 };      // 从小到大归并排序
    int A2[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int n1 = sizeof(A1) / sizeof(int);
    int n2 = sizeof(A2) / sizeof(int);

    output(A1, n1);
    MergeSortRecursion(A1, 0, n1 - 1);          // 递归实现
    printf("递归实现的归并排序结果：");
    output(A1, n1);

    MergeSortIteration(A2, n2);                 // 非递归实现
    printf("非递归实现的归并排序结果：");
    output(A2, n2);
*/

    //t_maopao(Array, nArray);

    //t_cocktail(Array, nArray);

    //t_xuanze(Array, nArray);

    //t_charu(Array, nArray);

    output(Array, nArray);


    return 0;
}

