#include <iostream>
#include <vector>
using namespace std;

// 合并数组，排好序，然后在拷贝到原来的数组array
void MergeArray(vector<int> &array, int start, int end, int mid, vector<int> temp)
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = array[i++];
    }
    while (j <= end)
    {
        temp[k++] = array[j++];
    }
    for (int i = 0; i < k; i++)
    {
        array[start + i] = temp[i];
    }
}
// 归并排序，将数组前半部分后半部分分成最小单元，然后在合并
void MergeSort1(vector<int> &array, int start, int end, vector<int> temp)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort1(array, start, mid, temp);
        MergeSort1(array, mid + 1, end, temp);
        MergeArray(array, start, end, mid, temp);
    }
}
// // 在这里创建临时数组，节省内存开销，因为以后的temp都是在递归李使用的。
// void MergeSort(vector<int> &array, int len)
// {
//     int start = 0;
//     int end = len - 1;
//     vector<int> temp(len);
//     MergeSort1(array, start, end, temp);
// }

void PrintArray(vector<int> array, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> array = {2, 4, 3, 6, 7, 3, 7, 8, 1};
    int n = array.size();
    vector<int> temp(n);
    MergeSort1(array, 0, n - 1, temp);
    PrintArray(array, 9);
    return 0;
}
