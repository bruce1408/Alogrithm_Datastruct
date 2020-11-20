#include<iostream>
#include<vector>
#include<cmath>
#include"../utils/cout_vec.h"
using namespace std;

/**
 * 希尔排序方法就是就是特殊的插入排序，这里的移动不再是
 * 限制为1位，而是移动增量数字g位，原来的插入排序算法算法只是
 * 两两比较，现在我们是进行一个增量数字的比较，每次循环后数组
 * 基本是有序数组(前面小数，后面大数)
 * 
*/

/**
 * 方法 1生成一个增量的数组，这个增量数组中最后一位必须是数字1，
 * 然后遍历增量数组，每次调用插入排序的函数
 * 原本数组是[7,6,4,3,4,1],然后通过增量计算，得到两个数一个是1，一个是4，把数组按照增量
 * 进行预处理，得到的是[4,3,4,1,7,6] 大致有序的一个结果，然后再次遍历增量，得到
 * 最后的完整排序结果[1,3,4,4,6,7]
 * 所以增量的选择是很关键的，有可能增量的选择到最后是没有任何时间复杂度上的降低，所以这个通常采用
 * 2^k-1 这种增量计算方式来计算即可；
 * 
*/
void insertSort(vector<int>&res, int len, int g)
{
    for(int i=g;i<len;i++)
    {
        int temp = res[i];
        int j=i-g;
        while(j>=0 && res[j]>temp)
        {
            res[j+g] = res[j];
            j-=g;
        }
        res[j+g] = temp;
    }
}

vector<int>shellSort(vector<int>&res)
{
    int len = res.size();
    vector<int>incr;

    // 两种计算增量的方式，第一个是按照 h*3+1 来计算，还有一个是按照 参考资料的 2^k-1 来计算增量的
    for(int h=1;;)// 生成一个增量数组
    {
        if(h > len) break;
        incr.push_back(h);
        h = h*3+1;
    }
    for(int i=1;i<len;i++)
    {
        i = pow(2, i)-1;
        incr.push_back(i);
    }
    for(int i=incr.size()-1;i>=0;i--) // 调用插入排序，
    {
        insertSort(res, len, incr[i]);
    }
    return res;
}

/**
 * 方法 2，利用一个do-while 循环即可解决增量数组的问题，
 * 不用再构造一个增量数组，最后一次incr=1会提前执行；
 * */ 
vector<int>shellSort1(vector<int>&res)
{
    int len = res.size(), incr = len;
    do
    {
        incr = incr/3+1;
        insertSort(res, len, incr);
    }
    while(incr>1);
    return res;
}


void shellSort2(vector<int>&A)
{
    int n = A.size();

    for(int gap = n / 2; gap > 0 ; gap = gap / 2)
    {
        for(int i = gap ; i < n ; i ++)
        {
            for(int j = i - gap ; j >= 0 && A[j] > A[j + gap] ; j -= gap)
                swap(A[j],A[j + gap]);
        }
    }
}

int main()
{
    vector<int> res = {7,6,4,3,4,1};
    // shellSort1(res);
    // shellSort2(res);
    shellSort(res);
    print(res);
}