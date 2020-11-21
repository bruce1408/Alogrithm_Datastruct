#include<iostream>
#include<vector>
#include<cmath>
#include"../utils/cout_vec.h"
using namespace std;

/**
 * 希尔排序方法就是就是特殊的插入排序，
 * 插入排序是每次两两比较，但是希望这里的移动不再是限制为1位，两两比较，而是移动增量数字g位，
 * 我们是进行一个增量数字的比较，每次循环后数组
 * 基本是有序数组(前面小数，后面大数)
 * 
 * 希尔排序是不稳定排序
 * 
*/

/**
 * 方法 1，首先生成一个增量的数组，这个增量数组中最后一个增量必须是数字1，
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
    // for(int i=1;i<len;i++)
    // {
    //     i = pow(2, i)-1;
    //     incr.push_back(i);
    // }
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

/**
 * 方法 3，这个写法就是每次增量按照除以2的方式来进行计算，但是有可能会到最后没有降低时间复杂度。
 * 比如数组： [2,1,5,3,7,6,9,8], 无论增量是4还是2，都没有改变这个数组的值； 
 * 只有增量是1的时候最后才改变了这个数组， 这里一定要保证最后一轮的增量为1；
 * */ 
void shellSort2(vector<int>&A)
{
    int n = A.size();
    vector<int>incr;
    for(int i=1, temp = 1; i<n && temp < n; i++)
    {
        incr.push_back(temp);
        temp = pow(2, i+1) - 1;
    }
    print(incr);
    for(int gap = n / 2-1; gap > 0; gap = gap / 2)
    {
        for(int i = gap; i < n; i ++)
        {
            for(int j = i - gap ; j >= 0 && A[j] > A[j + gap]; j -= gap)
                swap(A[j], A[j + gap]);
        }
        cout<<"在当前增量为： "<<gap<<"，增量结束一次之后的变化："<<endl;
        print(A);
    }
}


/**
 * 重新回顾，手写希尔排序,调用希尔排序长度为g的函数即可
*/
void innerSort(vector<int>&res, int len, int g)
{
    for(int i=g;i<len;i++)
    {
        int temp = res[i];
        int j = i-g;
        while(j>=0 && res[j] > temp)
        {
            res[j+g] = res[j];
            j-=g;
        }
        res[j+g] = temp;
    }
}

void shellSort3(vector<int>&res)
{
    vector<int>incr;
    int len = res.size();
    for(int i=1, temp=1;i<len && temp<len;i++)
    {
        incr.push_back(temp);
        temp = pow(2, i+1) - 1;
    }
    print(incr);
    for(int i=incr.size()-1;i>=0;i--)
    {
        cout<<incr[i]<<endl;
        innerSort(res, len, incr[i]);
    }
}


/**
 * 希尔排序不用调用增量为g的函数，直接在一个函数里面写即可，这里最后不是赋值，而是交换
 * 两个数，交换完毕之后排序完成
*/
void shellSort4(vector<int>&res)
{
    vector<int>incr;
    int n = res.size();
    // 定义一个增量数组，使用2^k-1形式，最后一个增量一定是1；
    for(int i=1, temp=1;i<n && temp < n;i++)
    {
        incr.push_back(temp);
        temp = pow(2, i+1) - 1;
    }
    print(incr);
    for(int i=incr.size()-1; i>=0;i--)
    {
        int g = incr[i];
        for(int j = g; j<n; j++)
        {
            for(int k = j-g, temp = res[j]; k>=0 && temp < res[k];k-=g)
            {
                swap(res[k+g] , res[k]);
            }
        }
    }
}


int main()
{
    vector<int> res = {2, 1, 5, 3, 7, 6, 9, 8};
    // shellSort(res);
    // shellSort1(res);
    // shellSort2(res);
    // shellSort3(res);
    shellSort4(res);
    
    print(res);
}