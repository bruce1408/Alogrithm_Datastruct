#include <iostream>
#include <vector>
#include "../utils/cout_vec.h"
using namespace std;

/**
 * 快速排序，找出 pivot 那个数字，然后开始递归，这个数字就是分割排序
 * 计算出来的
*/
// int partition(vector<int> &res, int left, int right)
// {
//     int temp = res[right];
//     int i = left - 1;
//     for (int j = left; j < right; j++)
//     {
//         if (res[j] <= temp)
//         {
//             i += 1;
//             swap(res[j], res[i]);
//         }
//     }
//     swap(res[i + 1], res[right]);
//     return i + 1;
// }

// vector<int> quickSort1(vector<int> &res, int left, int right)
// {
//     int pivot = 0;
//     if (left < right)
//     {
//         pivot = partition(res, left, right);
//         quickSort1(res, left, pivot - 1);
//         quickSort1(res, pivot + 1, right);
//     }
//     return res;
// }

/**
 * 快速排序二，推荐写法, 可作为模板
*/
void quickSort2(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;
    int x = q[(l + r) >> 1], i = l, j = r;
    while (1)
    {
        while (q[i] < x)
            i++;
        while (q[j] > x)
            j--;
        if (i >= j)
            break;
        swap(q[i], q[j]);
        i++;
        j--;
    }
    cout << i << " " << j << endl;
    quickSort2(q, l, j); // 这个地方不能把j换成i
    quickSort2(q, j + 1, r);
}

/**
 * 快速排序三，推荐写法
*/
void quickSort3(vector<int> &res, int l, int r)
{
    if (l >= r)
        return;
    int pivot = res[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while (res[i] < pivot);
        do
        {
            j--;
        } while (res[j] > pivot);
        if (i < j)
            swap(res[i], res[j]);
    }
    quickSort3(res, l, j);
    quickSort3(res, j + 1, r);
}

int main()
{
    // vector<int> res = {5, 1, 9, 3, 7, 4, 8, 6, 1, 0, 8, 5};
    vector<int> res = {49, 59, 88, 37, 98, 97, 68, 54, 31, 3};
    int n = res.size() - 1;
    quickSort2(res, 0, n);
    // quickSort3(res, 0, n);

    print(res);
}