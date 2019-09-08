#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an array, rotate the array to the right by k steps, 
 * where k is non-negative.
 * 对于一个数组来说，把后k个数组提到前面
 * 
 * Example 1:
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * 
*/

/***
 * 方法 1超时了，思路很自然，就是循环k次，每一次循环就把数组最后一个数字提出来，然后数组集体向后
 * 移动一位，原来最后的数字放到第一个位置即可。但是超时了，所以还需要寻找其他方法。
*/
void rotate1(vector<int> &nums, int k)
{
    int len = nums.size();
    for (int i = 0; i < k; i++)
    {
        int temp = nums[len - 1];
        for (int j = len - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = temp;
    }
}

/**
 * 方法 2新建一个数组，利用下标之间的映射关系来做i=(i+k)%数组的长度;空间复杂度O(n)
*/
void rotate2(vector<int> &nums, int k)
{
    int len = nums.size();
    vector<int> res = nums;
    for (int i = 0; i < len; i++)
    {
        nums[(i + k) % len] = res[i];
    }
}

/**
 * 方法 3和上面的思路大致一样，但是不用创建一个新的数组，利用下标关系i->(i+k)%n来做
 * 需要变量来保存中间临时结果。
*/
void rotate3(vector<int> &nums, int k)
{
    int start = 0, idx = 0, cur = nums[0], pre = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        pre = cur;
        idx = (idx + k) % n;
        cur = nums[idx];
        nums[idx] = pre;
        /**
         * 用来判断是否重复处理某一个idx下标的数，如果是，那么idx和start自增1，处理
         * 下一个数。例如[1,2,3,4],k=2
         * i=0,pre = cur = a[0]=1, idx = 2,cur = a[2] = 3,a[2]=pre = 1;
         * [1,2,1,4]
         * i=1,pre = cur = 3, idx = 0, cur= a[0]=1,a[0]=pre = 3;
         * [3,2,1,4]
         * i=2,pre = cur = 1,idx = 2,cur=a[2]=1,a[2] = pre =1;
         * [3,2,1,4]
         * i=3,pre = cur = 1,，idx = 0,cur = a[0] = 3, a[0]=pre =1;
         * [1,2,1,4]
         * */ 
        if (idx == start) // 
        {
            idx = ++start;
            cur = nums[idx];
        }
    }
}

/**
 * 方法 4先翻转前部分数组，然后翻转后部分数组，最后翻转整个数组;空间复杂度是O(1)：
*/
void rotate4(vector<int> &nums, int k)
{
    int len = nums.size();
    if (nums.empty() || (k %= len) == 0)
        return;
    vector<int> res = nums;
    reverse(nums.begin(), nums.begin() + len - k);
    reverse(nums.begin() + len - k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> res = {1, 2, 3, 4};
    rotate3(res, 2);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}