#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

/**
 * 295 数据流中的中位数
 * 求解中位数的话首先是要针对的是有序的序列
*/

/**
 * 方法 1，最好画图分析，使用两个优先队列，分别是大根堆和小根堆，大根堆保存的是数组左部分较小的值
 * 小根堆保存的是数组右边部分的较大的数字；然后大根堆的数量最多比小根堆要大1才可以，小根堆的数量要严格的小于或者等于大根堆，因为这是要
 * 这样当数据个数是奇数的时候中位数就是大根堆堆顶，是偶数的时候就是大根堆与小根堆堆顶的平均值。
 * 
*/
class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // 如果大根堆是空或者当前数字小于大根堆的堆顶元素，入队
        if (maxheap.empty() || num <= maxheap.top())
            maxheap.push(num);
        else
            minheap.push(num);

        // 如果大根堆的大小比小根堆的大小还要大1，那么就把元素保存到小根堆中；
        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size()) // 如果小根堆的大小大于大根堆的大小，小根堆的元素转移到大根堆，因为小根堆只能小于或者等于大根堆的大小
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if (minheap.size() == maxheap.size())
            return (minheap.top() + maxheap.top()) / 2.0;
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */