#include <iostream>
#include <vector>
// #include "../utils/cout_vec.h"
using namespace std;

/**
 * 归并排序,按照长度/2分成两部分，然后递归，直到每个数组数组元素是2，然后排序
 * 之后再合并即可
*/

void MergeArray(vector<int> &array, int start, int mid, int end, vector<int> temp)
{
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end)
	{
		if (array[i] < array[j]) temp[k++] = array[i++];
		else temp[k++] = array[j++];
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
		MergeArray(array, start, mid, end, temp);
	}
}
/**
 * 方法 1，二路归并算法实现
*/
void merge1(vector<int> &res, vector<int> &temp, int left, int mid, int right)
{
    for (int i = left; i <= right; i++)
        temp[i] = res[i];
    int i = left, j = mid + 1, t = left;
    while (i <= mid && j <= right)
    {
        if (temp[i] <= temp[j])
            res[t++] = temp[i++];
        else
            res[t++] = temp[j++];
    }
    while (i <= mid)
        res[t++] = temp[i++];
    while (j <= right)
        res[t++] = temp[j++];
}

void mergeSort1(vector<int> &res, vector<int> &temp, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort1(res, temp, left, mid);
    mergeSort1(res, temp, mid + 1, right);
    merge1(res, temp, left, mid, right);
}

/**
 * 方法 2， 归并排序更加简单 推荐做法
 * 1、首先是确定分界点mid=l+r>>1
 * 2、然后进行递归排序左右区间
 * 3、接着把2个有序的序列进行合并，使用双指针，注意边界问题，都是闭区间，同时需要设置一个临时数组temp
 * 4、最后把结果复制到原数组中去即可
*/
void mergeSort2(vector<int> &res, vector<int> &temp, int l, int r)
{
    // 递归终止条件
    if (l >= r)
        return;

    // 确定分界点
    int mid = (l + r) >> 1;
    // 划分成子问题
    mergeSort2(res, temp, l, mid);
    mergeSort2(res, temp, mid + 1, r);

    // 合并子问题区间
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (res[i] < res[j])
            temp[k++] = res[i++];
        else
            temp[k++] = res[j++];
    }
    while (i <= mid)
        temp[k++] = res[i++];
    while (j <= r)
        temp[k++] = res[j++];

    // 合并子区间
    for (int i = l, j = 0; i <= r; i++, j++)
        res[i] = temp[j];
}

void mergeSort_cdd(vector<int>&nums, vector<int>&temp, int l, int r){
    if(l >=r) return ;
    int mid = (l+r)>>1, i=l, j=mid+1;

    mergeSort_cdd(nums, temp, l, mid);
    mergeSort_cdd(nums, temp, mid+1, r);

    int k = 0;
    while(i<=mid && j<=r){
        if(nums[i] < nums[j] ) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }
    while(i<=mid) temp[k++] = nums[i++];
    while(j<=r) temp[k++] = nums[j++];

    for(int i = l, j = 0;i<=r;i++, j++){
        nums[i] = temp[j];
    }
}

int main()
{
    vector<int> res = {7, 6, 4, 3, 4, 1};
    vector<int> temp(res.size());
    // mergeSort2(res, temp, 0, res.size() - 1);
    MergeSort1(res, 0, res.size()-1, temp);
    for (auto x : res)
        cout << x << " ";
}