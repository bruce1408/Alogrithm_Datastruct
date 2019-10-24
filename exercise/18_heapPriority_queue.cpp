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

// /**
//  * 方法 2，构建一个最小堆的数组
// */
// void swimMin(vector<int>& res, int k)
// {
//     while(k>1 && res[k/2]>res[k])
//     {
//         swap(res[k/2], res[k]);
//         k = k/2;
//     }
// }

// void sinkMin(vector<int>&res, int k)
// {
//     int N = res.size();
//     while(2*k < N)
//     {
//         int j = 2*k;
//         if(j+1<N && res[j]>res[j+1]) j++;
//         if(res[k]<=res[j]) break;
//         swap(res[j], res[k]);
//         k = j;
//     }
// }

//  void heapSort(vector<int>&res)
//  {

//     int length = res.size();
//     for(int i=(length)>>1;i>=1;i--)
//     {
//         sink(res, i, length-1);
//     }
//     while(length>1)
//     {
//         swap(res[1], res[length-1]);
//         // cout<<"=======the min num is=======:"<<res[length-1]<<endl;
//         length--;
//         sink(res, 1, length);
//     }
//  }

// int main()
// {
//     vector<int>res = {0,50,10,90,30,70,40,80,60,20};
//     heapSort(res);
//     //打印出来这个数组
//     for(auto i:res)
//     {
//         cout<<i<<" ";
//     }
// }


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> res ={50,10,90,30,70,40,80,60,20};
    // make_heap(res.begin(), res.end(), less<int>());  // 最大堆
    make_heap(res.begin(), res.end(), greater<int>());  // 最小堆
    for(auto x:res) 
    {cout<<x<<" ";}
}

