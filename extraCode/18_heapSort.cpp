#include<iostream>
#include<vector>
using namespace std;

/**
 * 方法 1，构建最大堆，利用数组来存放堆,
 * 堆的最主要的问题就是
 * --插入元素 --删除最大元素
 */
// vector<int>buildHeap(vector<int>res)
// {

// }

/**
 * swim方法，最大堆的构建方式；
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
 * sink方法，最大堆的构建方式；
 * 由下至上构建这个二插堆，
 * 因为某个节点比它的子节点还要小，通过和子节点中较大的那个来交换，然后恢复堆；
 * 这一步做完之后，我们还要继续比较子节点交换之后是不是不满足条件；
*/
void sink(vector<int>&res, int k)
{
    int N = res.size();
    while(2*k < N)
    {
        int j = 2*k;
        if(j<N && res[j]<res[j+1]) j++;
        if(res[k]>=res[j]) break;
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
        if(j<N && res[j]>res[j+1]) j++;
        if(res[k]<=res[j]) break;
        swap(res[j], res[k]);
        k = j;
    }
}

void exah(vector<int>&res, int a, int b)
{
    int temp = res[a];
    res[a] = res[b];
    res[b] = temp;
}

int main()
{
    vector<int>res = {0,50,10,90,30,70,40,80,60,20};
    for(int i=1;i<res.size();i++)
    {
        sinkMin(res, i);
    }
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    int N = res.size();
    while(N>1)
    {
        
        // exah(res, 1, N-1);
        swap(res[1], res[N-1]);
        for(auto i:res)
        {cout<<i<<" ";}
        cout<<endl;
        cout<<"the min num is:"<<res[N-1]<<" "<<endl;
        res.pop_back();
        N--;
        sinkMin(res, 1);
    }

}