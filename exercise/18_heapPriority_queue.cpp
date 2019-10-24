// #include<iostream>
// #include<vector>
// using namespace std;

// /**
//  * ---------- 优先队列利用二插堆来实现 -------------
//  * 优先级队列是基于二叉堆实现的，主要操作是插入和删除。
//  * 插入方法 是先插到最后，然后上浮到正确位置；
//  * 删除方法 是只能删除堆顶的元素，先调换位置后再删除，然后下沉到正确位置。核心代码也就十行。
//  * 这里注意，最大堆构成的是最大优先队列，最小堆构成的是最小优先队列
//  */


// /**
//  * 上浮 方法，主要用于插入，当在堆底新插入一个节点的时候，需要进行上浮操作；
//  * swim方法；如果当前的节点比父节点还要大，那么就用此方法
//  * 由下至上，对元素进行上浮，因为堆的某个元素比它的父节点还要大，
//  * 我们需要交换它和它的父节点来修复堆，
//  * 交换之后，这个节点可能比父节点还要大，为了满足条件，要遍历；
// */
// void swim(vector<int>& res, int k)
// {
//     while(k>1 && res[k/2]<res[k])
//     {
//         swap(res[k/2], res[k]);
//         k = k/2;
//     }
// }

// /**
//  * sink方法，主要用于删除堆顶元素，因为交换堆顶元素之后，根节点不能保证满足条件，
//  * 所以需要下沉方法；由上至下遍历这个二插堆，
//  * 因为某个节点比它的子节点还要小，通过和子节点中较大的那个来交换，然后恢复堆；
//  * 这一步做完之后，我们还要继续比较子节点交换之后是不是不满足条件；
// */
// void sink(vector<int>&res, int k, int length)
// {
//     while(2*k < length)
//     {
//         int j = 2*k;
//         if(j+1<length && res[j]<res[j+1]) j++;
//         if(res[k]>res[j]) break;
//         swap(res[j], res[k]);
//         k = j;
//     }
// }


#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
template <class T>
void print(vector<T>&res)
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
    // vector<int>res = {0,50,10,90,30,70,40,80,60,20};

    // // 手动实现的优先队列算法
    // HeapSort heap;
    // heap.make_heap(res);
    // print(res);
    // cout<<"max num is: "<<heap.pop_heap(res)<<endl;
    // print(res);
    // heap.push_heap(res, 109);
    // print(res);
    // heap.sort_heap(res);
    // print(res);


    // vector<int> res ={50,10,90,30,70,40,80,60,20};
    // make_heap(res.begin(), res.end(), less<int>());  // 最大堆，默认的是最大堆
    // // make_heap(res.begin(), res.end(), greater<int>());  // 最小堆
    // print(res);
    // // 插入元素，先在数组中插入，然后在利用push_heap在堆中插入即可，表示插入的新的元素重新构成堆
    // res.push_back(100);
    // push_heap(res.begin(), res.end());
    // print(res);
    // // 删除最大元素，先从堆中删除，然后从容器中删除
    // pop_heap(res.begin(), res.end()); // 函数只是把第一个元素移到最后，然后在进行堆的调整，此时容器最后一个元素是最大值，删除后依然保持堆结构

    vector<int>num = {21,22,12,3,24,54,56};
    priority_queue<int, vector<int>, less<int>>values(num.begin(), num.end());　// 大顶堆的优先队列
    // priority_queue<int, vector<int>, greater<int>>numbers(num.begin(), num.end());
    // cout<<numbers.top()<<endl;
    cout<<values.top()<<endl;
}

