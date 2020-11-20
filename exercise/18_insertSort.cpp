#include<iostream>
#include<vector>
#include"../utils/cout_vec.h"
using namespace std;
/**
 * 插入排序的思路: 算法时间复杂度是O(n^2)
 * 是分为已经排好序的和未排好序两组，首个数字
 * 认为是排好序了，然后开始遍历第2个数字，也就是i=1 ~ N-1开始，
 * 有一个中间变量来保存这个i的值，另一个遍历是j取i的前一个数字
 * i-1即可，然后开始判断是不是后面的数字小于前面的数字，如果是
 * 那么就开始把前面的数字复制到数组的后一位，知道条件不满足，最后
 * 我们把保存的临时遍历i的值给j+1的下标的数字即可。
*/
vector<int>insertSort(vector<int>& res)
{
    int len = res.size();
    for(int i=1;i<len;i++)
    {
        int temp = res[i];
        int j = i-1;
        while(j>=0 && res[j]>temp)
        {
            res[j+1] = res[j];
            j--;
        }
        res[j+1] = temp;
    }
    return res;
}

vector<int> insertSort1(vector<int>&res)
{
    int len = res.size();
    for(int i=1; i<len; i++)
    {
        int temp = res[i];
        int j = i-1;
        while(j>=0 && res[j]>temp)
        {
            res[j+1] = res[j];
            j--;
        }
        res[j+1] = temp;
    }
    return res;
}

int main()
{
    vector<int> res = {7,3,4,5,2,1};
    insertSort1(res);
    print(res);
}