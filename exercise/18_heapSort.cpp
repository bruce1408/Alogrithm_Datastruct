#include <iostream>
#include <vector>
#include "../utils/cout_vec.h"
using namespace std;

/**
 * 堆排序的方法就是构建最大堆或者是最小堆.
 * 最大堆的根节点是最大值，最小堆根节点为最小值，然后即使去掉这个根节点，其余结点通过调整
 * 也可以成为最大堆或者是最小堆，这样每次数组根节点的元素就是一个有序的数组；
 * 
 * 方法 1，构建最大堆，利用数组来存放堆,
 * 堆的最主要的问题就是
 * --插入元素 --删除最大元素(记住是删除最大的元素，不是任意元素)
 * --插入元素 --删除最大元素
 * 下面主要介绍两个方法，swim 和 sink 上浮和下沉，
 * 插入和删除的方法主要建立在上面两个方法基础之上，插入是要把插入的元素
 * 插入到堆底最后，然后再让其上浮，
 * 删除的方法是把堆顶的元素和堆底的元素互换位置，然后再把新的堆顶的位置下沉
 * 到合适的位置；
 * 
 * 优先队列是基于二叉堆实现的，主要是插入和删除，插入是先插到最后，
 * 然后上浮到正确位置；删除是调换位置后再删除，然后下沉到正确位置
 * 
 * swim 上浮的方法，最大堆的构建方式；
 * 由下至上，对元素进行上浮，因为堆的某个元素比它的父节点还要大，
 * 我们需要交换它和它的父节点来修复堆，
 * 交换之后，这个节点可能比父节点还要大，为了满足条件，要遍历；
*/
void swim(vector<int> &res, int k)
{
    while (k > 1 && res[k / 2] < res[k])
    {
        swap(res[k / 2], res[k]);
        k = k / 2;
    }
}

/**
 * sink 下沉的方法，最大堆的构建方式；
 * 由下至上构建这个二叉堆，
 * 因为某个节点比它的子节点还要小，通过和子节点中较大的那个来交换，然后恢复堆；
 * 这一步做完之后，我们还要继续比较子节点交换之后是不是不满足条件；
*/
void sink(vector<int> &res, int k, int length)
{
    while (2 * k < length)
    {
        int j = 2 * k;
        if (j + 1 < length && res[j] < res[j + 1])
            j++;
        if (res[k] > res[j])
            break;
        swap(res[j], res[k]);
        k = j;
    }
}

/**
 * 方法 1，构建一个最小堆的数组
*/
void swimMin(vector<int> &res, int k)
{
    while (k > 1 && res[k / 2] > res[k])
    {
        swap(res[k / 2], res[k]);
        k = k / 2;
    }
}

void sinkMin(vector<int> &res, int k)
{
    int N = res.size();
    while (2 * k < N)
    {
        int j = 2 * k;
        if (j + 1 < N && res[j] > res[j + 1])
            j++;
        if (res[k] <= res[j])
            break;
        swap(res[j], res[k]);
        k = j;
    }
}

void heapSort1(vector<int> &res)
{
    int length = res.size();
    for (int i = (length) >> 1; i >= 1; i--)
    {
        sink(res, i, length - 1);
    }
    while (length > 1)
    {
        swap(res[1], res[length - 1]);
        length--;
        sink(res, 1, length);
    }
}

/**
 * 方法 2，堆排序简单写法,
 * 首先将前 n - 1 个节点为根节点的子树进行调整, 建立一个大顶堆, 将堆顶元素弹出, 并更新大顶堆
*/
void adjust(vector<int> &A, int root, int n)
{
    int temp = A[root], j = 2 * root + 1; // 左边的叶子节点
    while (j < n)
    {
        if (j + 1 < n && A[j] < A[j + 1])
            j++; // 左边的叶子节点 < 右边的叶子节点
        if (temp >= A[j])
            break;
        A[(j - 1) / 2] = A[j];
        j = 2 * j + 1;
    }
    A[(j - 1) / 2] = temp;
}

void heapSort2(vector<int> &res)
{
    int n = res.size();
    for (int i = n / 2; i >= 0; i--)
        adjust(res, i, n);
    cout << "最大堆构造结果：" << endl;
    print(res);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(res[0], res[i]);
        adjust(res, 0, i);
    }
}

/**
 * 重新写堆排序heapSort3，首先就是构造最大堆矩阵；
 * 遍历根节点，然后设置左叶子节点，判断左叶子节点是不是超过数组范围，要是没有超过，那么在左叶子和右叶子中选择一个最大的节点作为
 * 可能要置换的节点，判断当前根节点是不是大于这个最大的叶子节点，如果大于的话，那么不用置换，退出当前循环，否则，根节点的值赋值为
 * 当前的最大的叶子节点的值即可，叶子节点的值继续往下遍历，知道最后一层的叶子节点。
 * 
 * 当最大堆的结构完成之后，需要交换根节点和最后一个节点，然后交换之后根节点不满足最大堆的性质，重新进行排序构建最大堆，这个时候
 * 放弃上次交换的根节点，最后得到一个有序的数组
*/
// void adjust1(vector<int> &res, int i, int len)
// {
//     int temp = res[i], j = 2 * i + 1;
//     while (j < len)
//     {
//         if (j + 1 < len && res[j] < res[j + 1])
//             j++;
//         if (temp >= res[j])
//             break;
//         res[(j - 1) / 2] = res[j];
//         j = 2 * j + 1;
//     }
//     res[(j - 1) / 2] = temp;
// }

// void heapSort3(vector<int> &res)
// {
//     int n = res.size();
//     for (int i = n / 2; i >= 0; i--)
//     {
//         adjust1(res, i, n);
//     }
//     print(res);
//     for (int i = n - 1; i >= 0; i--)
//     {
//         swap(res[0], res[i]);
//         adjust1(res, 0, i);
//     }
// }
void adjuest1(vector<int> &res, int i, int n)
{
    int temp = res[i], j = 2 * i + 1;
    while (j < n)
    {
        if (j + 1 < n && res[j] < res[j + 1])
            j++;
        if (temp >= res[j])
            break;
        res[(j - 1) / 2] = res[j];
        j = 2 * j + 1;
    }
    res[(j - 1) / 2] = temp;
}

void heapSort3(vector<int> &res)
{
    int n = res.size();
    for (int i = n / 2; i >= 0; i--)
    {
        adjuest1(res, i, n);
    }
    print(res);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(res[0], res[i]);
        adjuest1(res, 0, i);
    }
}
int main()
{
    vector<int> res = {100, 50, 10, 90, 30, 70, 40, 80, 60, 20};
    // heapSort1(res);
    // heapSort2(res);
    heapSort3(res);
    print(res);
}
