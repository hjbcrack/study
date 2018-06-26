

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

// ð�ݣ���index i=0��ʼ��ÿ��ѭ���Ƚ�ǰ��number-1-i��δ�����Ԫ�أ�ÿ�ζ���δ����Ԫ�ص�ĩβ���ϵ�ǰ���ֵ

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
// ��β������ð�ݣ�Ҳ�ж���ð��������ð�������һ�ָĽ������㷨��ð������Ĳ�ͬ�����ڴӵ͵���Ȼ��Ӹߵ���

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

// ѡ�񣬴�index i=0��ʼ��ÿ�δӺ����Ԫ����ѭ��������Сֵ����index i��λ�á�

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

// ���룬��index i=1��ʼ��ÿ��ѭ���Ƚ��ƶ�ǰ��i-1���Ѿ������Ԫ�أ����ս������<=array[i]��Ԫ��֮��

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

// ���ֲ��룬��index i=1��ʼ��ÿ��ѭ���Ƚ��ƶ�ǰ��i-1���Ѿ������Ԫ�أ����ս������<=array[i]��Ԫ��֮��

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

/* ϣ�����Ľ��Ĳ������򣬴�index i=1��ʼ��ÿ��ѭ���Ƚ��ƶ�ǰ��i-1���Ѿ������Ԫ�أ�
         ���ս������<=array[i]��Ԫ��֮�󣬲�֮ͬ���ǣ�ÿ���ƶ��Ĳ�������С�ݼ�
*/
void shell(int array[], int number)
{
    int h = 0;

    while (h <= number)                          // ���ɳ�ʼ����
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

        h = (h - 1) / 3;                    // �ݼ�����

        output(array, nArray);
    }
}

////////////////////////////////////////////////////////////////////////////////

/* ���٣���index i=0��ʼ��ÿ�δӺ����Ԫ����ѭ��������Сֵ����index i��λ�á�
    ���������ʱ����Ҫ�ķ��ڻ��ֲ����ϣ��Գ���Ϊk��������л��֣�����k-1�ιؼ��ֵıȽϡ�

    ������ÿ�λ���ѡȡ�Ļ�׼���ǵ�ǰ�������йؼ�����С(�����)�ļ�¼�����ֵĽ����
    ��׼��ߵ�������Ϊ��(���ұߵ�������Ϊ��)�����������õ���һ���ǿյ��������м�¼��Ŀ��
    �����Ȼ���ǰ���������м�¼��������һ����ʱ�临�Ӷ�ΪO(n*n)

    ���������£�ÿ�λ�����ȡ�Ļ�׼���ǵ�ǰ��������"��ֵ"��¼�����ֵĽ���ǻ�׼����
    ����������������ĳ��ȴ�����ȡ��ܵĹؼ��ֱȽϴ�����O(nlgn)

    ���ܿ���������ʱ��ΪO(n2)������ƽ�����ܶ��ԣ����ǻ��ڹؼ��ֱȽϵ��ڲ������㷨��
    �ٶ�����ߣ�������������˶�����������ƽ��ʱ�临�Ӷ�ΪO(nlgn)��

*/
int Partition(int array[], int left, int right)  // ���ֺ���
{
    int pivot = array[right];               // ����ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
    int tail = left - 1;                    // tailΪС�ڻ�׼�����������һ��Ԫ�ص�����

    for (int i = left; i < right; i++)      // ������׼���������Ԫ��
    {
        if (array[i] <= pivot)              // ��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ
        {
            swap(&array[++tail], &array[i]);
        }
    }

    swap(&array[tail + 1], &array[right]);  // ���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ���������Ǵ��ڻ�׼��������
                                            // �ò������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
    output(array, nArray);
    return tail + 1;                        // ���ػ�׼������
}

void QuickSort(int array[], int left, int right)
{
    if (left >= right)
        return;
    int pivot_index = Partition(array, left, right); // ��׼������
    QuickSort(array, left, pivot_index - 1);
    QuickSort(array, pivot_index + 1, right);
}

////////////////////////////////////////////////////////////////////////////////

/*
    ������
    ��������ָ���ö��������ݽṹ����Ƶ�һ��ѡ�������㷨������һ�ֽ�����ȫ�������Ľṹ��ͨ������ͨ��һά������ʵ�ֵģ���
    ���������ʣ������ѣ�Ҳ�д���ѡ��󶥶ѣ�Ϊ�������и�����ֵ���Ǵ������ĺ��ӽڵ㡣

    1. ��������������鹹��һ�����ѣ���Ϊ��ʼ��������
    2. �ѶѶ�Ԫ�أ����ֵ���Ͷ�βԪ�ػ���
    3. �Ѷѣ����������ĳߴ���С1��������heapify(A, 0)���µĶѶ�Ԫ�ؿ�ʼ���жѵ���
    4. �ظ�����2��ֱ���ѵĳߴ�Ϊ1
*/

#include <stdio.h>

// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�


void Heapify(int A[], int i, int size)  // ��A[i]���½��жѵ���
{
    int left_child = 2 * i + 1;         // ��������
    int right_child = 2 * i + 2;        // �Һ�������
    int max = i;                        // ѡ����ǰ����������Һ�������֮�е����ֵ
    if (left_child < size && A[left_child] > A[max])
        max = left_child;
    if (right_child < size && A[right_child] > A[max])
        max = right_child;
    if (max != i)
    {
        swap(&A[i], &A[max]);           // �ѵ�ǰ�����������(ֱ��)�ӽڵ���н���
        Heapify(A, max, size);          // �ݹ���ã������ӵ�ǰ������½��жѵ���

        output(A, nArray);
    }
}

int BuildHeap(int A[], int n)           // ���ѣ�ʱ�临�Ӷ�O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // ��ÿһ����Ҷ��㿪ʼ���½��жѵ���
        Heapify(A, i, heap_size);
    return heap_size;
}

void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);    // ����һ������
    while (heap_size > 1)               // �ѣ���������Ԫ�ظ�������1��δ�������
    {
        // ���Ѷ�Ԫ����ѵ����һ��Ԫ�ػ��������Ӷ���ȥ�����һ��Ԫ��
        // �˴������������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Զ������ǲ��ȶ��������㷨
        swap(&A[0], &A[--heap_size]);
        Heapify(A, 0, heap_size);       // ���µĶѶ�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�O(logn)
    }
}

////////////////////////////////////////////////////////////////////////////////

/*
�鲢�����Ǵ����ڹ鲢�����ϵ�һ����Ч�������㷨��Ч��ΪO(nlogn)��1945���ɷ롤ŵ�����״������

�����鲢�����ʵ�ַ�Ϊ�ݹ�ʵ����ǵݹ�(����)ʵ�֡��ݹ�ʵ�ֵĹ鲢�������㷨����з��β��Եĵ���Ӧ�ã����ǽ�һ��������ָ��С����ֱ�����Ȼ��������С����Ĵ���������������⡣�ǵݹ�(����)ʵ�ֵĹ鲢�������Ƚ����������鲢��Ȼ�����Ĺ鲢��Ȼ���ǰ˰˹鲢��һֱ��ȥֱ���鲢���������顣

�����鲢�����㷨��Ҫ�����鲢(Merge)�������鲢����ָ���ǽ������Ѿ���������кϲ���һ�����еĲ������鲢�����������£�

    ����ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ��������
    �趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ��
    �Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ��
    �ظ�����3ֱ��ĳһָ�뵽������β
    ����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β
*/

// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(n)
// �ȶ��� ------------ �ȶ�


void Merge(int A[], int left, int mid, int right)// �ϲ��������ź��������A[left...mid]��A[mid+1...right]
{
    int len = right - left + 1;
    int *temp = new int[len];       // �����ռ�O(n)
    int index = 0;
    int i = left;                   // ǰһ�������ʼԪ��
    int j = mid + 1;                // ��һ�������ʼԪ��

    while (index < len)
    {
        if (i <= mid && j <= right) {
            temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // ���Ⱥű�֤�鲢������ȶ���
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

void MergeSortRecursion(int A[], int left, int right)    // �ݹ�ʵ�ֵĹ鲢����(�Զ�����)
{
    if (left == right)    // ������������г���Ϊ1ʱ���ݹ鿪ʼ���ݣ�����merge����
        return;
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)    // �ǵݹ�(����)ʵ�ֵĹ鲢����(�Ե�����)
{
    int left, mid, right;// ����������,ǰһ��ΪA[left...mid]����һ��������ΪA[mid+1...right]
    for (int i = 1; i < len; i *= 2)        // ������Ĵ�Сi��ʼΪ1��ÿ�ַ���
    {
        left = 0;
        while (left + i < len)              // ��һ�����������(��Ҫ�鲢)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len - 1;// ��һ���������С���ܲ���
            Merge(A, left, mid, right);
            left = right + 1;               // ǰһ����������������ƶ�

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

    int A1[] = { 6, 5, 3, 1, 8, 7, 2, 4 };      // ��С����鲢����
    int A2[] = { 6, 5, 3, 1, 8, 7, 2, 4 };
    int n1 = sizeof(A1) / sizeof(int);
    int n2 = sizeof(A2) / sizeof(int);

    output(A1, n1);
    MergeSortRecursion(A1, 0, n1 - 1);          // �ݹ�ʵ��
    printf("�ݹ�ʵ�ֵĹ鲢��������");
    output(A1, n1);

    MergeSortIteration(A2, n2);                 // �ǵݹ�ʵ��
    printf("�ǵݹ�ʵ�ֵĹ鲢��������");
    output(A2, n2);
*/

    //t_maopao(Array, nArray);

    //t_cocktail(Array, nArray);

    //t_xuanze(Array, nArray);

    //t_charu(Array, nArray);

    output(Array, nArray);


    return 0;
}

