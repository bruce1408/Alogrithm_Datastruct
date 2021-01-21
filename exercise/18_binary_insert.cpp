/*
二分插入排序算法（升序）
 */
#include <iostream>
#include <vector>
using namespace std;

void binSort(vector<int> &a, int len)
{
    int mid, left, right, temp;
    for (int i = 1; i < len; i++)
    {
        left = 0;      //初始化已拍好序的左边界为0
        right = i - 1; //右边界为待排序元素的前一个位置
        temp = a[i];   //待排序元素
        while (left <= right)
        {
            mid = (left + right) / 2; //计算中间位置
            if (temp < a[mid])
            {
                right = mid - 1; //如果比中间位置小则缩小右边的范围为mid-1
            }
            else
            {
                left = mid + 1; //如果比中间位置大则扩大右边的范围为mid+1，
            }
        }
        for (int j = i - 1; j >= left; j--)
            a[j + 1] = a[j]; //将大于等于左边界值的元素全部后移
        if (left != i)
            a[left] = temp; //待插入元素插入位置不等于现在所处位置时，则插入空处
    }
}

int main()
{
    vector<int> res = {49, 38, 65, 97, 76, 13, 27, 49}; //待排序数组
    int len = res.size();
    binSort(res, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}