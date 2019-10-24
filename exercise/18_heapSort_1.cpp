#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * maxHeap,构建最大堆
*/
template<class type>
void heapAdjust(vector<type>& vec, int index, int length)
{
    int i = index;
    int j = 2*i;
    for(; j<=length; j*=2)
    {
        if(j+1<=length && vec[j]<vec[j+1]) j++;
        if(vec[i]>vec[j]) break;
        swap(vec[i], vec[j]);
        i = j;
    }
}

/**
 * 最大堆的排序
*/
template<class type>
void heapSort(vector<type>&vec)
{
    int length = vec.size();
    for(int i=(length-1)>>1;i>=1;i--)
    {
        heapAdjust(vec, i, length-1);
    }
    
    for(int i=length-1;i>1;i--)
    {
        type temp = vec[1];
        vec[1] = vec[i];
        vec[i] = temp;
        heapAdjust(vec, 1, i-1);
    }
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class HeapSort
{
    public:
    //构建堆
    void make_heap(vector<int>&res);
    // 删除最大元素
    int pop_heap(vector<int>&res);
    // 插入新的元素
    void push_heap(vector<int>&res, int num);
    // 堆排序
    void sort_heap(vector<int>&res);
    // 下沉的堆调整
    void heap_adujest(vector<int>&res, int i, int length);
    // 堆的上浮
    void swim_adjuest(vector<int>&res, int i);
};

void HeapSort::heap_adujest(vector<int>&res, int i, int length)
{
    while(2*i<length)
    {
        int index = 2*i;
        if(index+1<length && res[index]<res[index+1])
        {
            index++;
        }
        if(res[i]>res[index]) break;
        swap(res[i], res[index]);
        i = index;
    }
}


void HeapSort::swim_adjuest(vector<int>&res, int k)
{
    while(k>1 && res[k/2]<res[k])
    {
        swap(res[k/2], res[k]);
        k = k/2;
    }
}

void HeapSort::make_heap(vector<int>&res)
{
    int length = res.size();
    for(int i = (length-1)>>1;i>=1;i--)
    {
        heap_adujest(res, i, length);
    }
}

int HeapSort::pop_heap(vector<int>&res)
{
    int length = res.size();
    swap(res[1], res[length-1]);
    int maxNum = res[length-1];
    res.pop_back();
    heap_adujest(res, 1, res.size()-1);
    return maxNum;
}

void HeapSort::push_heap(vector<int>&res, int num)
{
    res.push_back(num);
    int newlength = res.size();
    swim_adjuest(res, newlength-1);
}

void print(vector<int>&res)
{
    for(auto x:res)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

void HeapSort::sort_heap(vector<int>&res)
{
    int length = res.size();
    for(int i=length-1;i>=1;i--)
    {
        swap(res[1], res[i]);
        heap_adujest(res, 1, i);
    }
}

int main()
{
    vector<int>res = {0,50,10,90,30,70,40,80,60,20};

    HeapSort heap;
    heap.make_heap(res);
    print(res);
    cout<<"max num is: "<<heap.pop_heap(res)<<endl;
    print(res);
    heap.push_heap(res, 109);
    print(res);
    // heap.sort_heap(res);
    // print(res);

}


