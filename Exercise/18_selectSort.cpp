#include<iostream>
#include<vector>
#include"../utils/cout_vec.h"
using namespace std;

/**
 * 选择排序是选择当前最小的数字。
 * 找出未排序数组的最小值的位置minNum，然后把minNum位置和未排序的起始
 * 位置相互交换即可,时间复杂度是O(n^2);
*/
vector<int>selectSort(vector<int>&res)
{
    int len = res.size();
    for(int i=0; i<len; i++)
    {
        int minNum = i;
        for(int j=i; j<len; j++)
        {
            if(res[j]<res[minNum])
            {
                minNum = j; // 把最小的数的位置找到给数组
            }
        }
        swap(res[i], res[minNum]); // 一轮结束后交换最小数字和未排序的数
    }
    return res;
}
/**
 * 选择排序和上面思路完全一样，自己重新写一次；
 * 简单选择排序的思路就是：
 * 给定一个乱序的数组，然后开始遍历这个数组，每次设置最小值的位置为当前遍历的位置，
 * 然后开始从当前位置的下一个位置开始比较这个最小位置的值哪个大？要是小于这个最小位置，那么就
 * 把最小位置的标志位改写为遍历的当前这个位置，最后判断一下最开始的最小位置和当前更改之后的最小位置一致，
 * 如果不一致，就更改他们的位置即可。他是稳定排序
*/
void selectSort1(vector<int>&res)
{
    int len = res.size();
    for(int i=0;i<len;i++)
    {
        int min = i;
        for(int j=i+1;j<len;j++)
        {
            if(res[min] > res[j])
            {
                min = j;
            }
        }
        if(i!=min)
        {
            swap(res[i], res[min]);
        }
    }
}

int main()
{
    vector<int> res = {7,6,4,3,4,1};
    selectSort1(res);
    print(res);
}