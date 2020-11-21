#include<iostream>
#include<vector>
#include"../utils/cout_vec.h"
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
void swim(vector<int>& res, int k)
{
    while(k>1 && res[k/2]<res[k])
    {
        swap(res[k/2], res[k]);
        k = k/2;
    }
}

/**
 * sink 下沉的方法，最大堆的构建方式；
 * 由下至上构建这个二叉堆，
 * 因为某个节点比它的子节点还要小，通过和子节点中较大的那个来交换，然后恢复堆；
 * 这一步做完之后，我们还要继续比较子节点交换之后是不是不满足条件；
*/
void sink(vector<int>&res, int k, int length)
{
    while(2*k < length)
    {
        int j = 2*k;
        if(j+1<length && res[j]<res[j+1]) j++;
        if(res[k]>res[j]) break;
        swap(res[j], res[k]);
        k = j;
    }
}

/**
 * 方法 2，构建一个最小堆的数组
*/
void swimMin(vector<int>& res, int k)
{
    while(k>1 && res[k/2]>res[k])
    {
        swap(res[k/2], res[k]);
        k = k/2;
    }
}

void sinkMin(vector<int>&res, int k)
{
    int N = res.size();
    while(2*k < N)
    {
        int j = 2*k;
        if(j+1<N && res[j]>res[j+1]) j++;
        if(res[k]<=res[j]) break;
        swap(res[j], res[k]);
        k = j;
    }
}

void heapSort(vector<int>&res)
 {
    int length = res.size();
    for(int i=(length)>>1;i>=1;i--)
    {
        sink(res, i, length-1);
    }
    while(length>1)
    {
        swap(res[1], res[length-1]);
        length--;
        sink(res, 1, length);
    }
 }

int main()
{
    vector<int>res = {0,50,10,90,30,70,40,80,60,20};
    heapSort(res);
    print(res);
}

