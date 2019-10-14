#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

/**
 * Given a n x n matrix where each of the rows and columns 
 * are sorted in ascending order, 
 * find the kth smallest element in the matrix.
 * Note that it is the kth smallest element in the sorted order,
 *  not the kth distinct element.
 * 
 * Example:
 * matrix = [
 * [ 1,  5,  9],
 * [10, 11, 13],
 * [12, 13, 15]],
 * k = 8,
 * return 13.
 * 该矩阵是行和列都按照升序排列的，找到数组中的第k个数字
 */

/**
 * 方法 1，简单粗暴，就是把元素全部装进一个一维数组，然后排序，找到第i个数字
 * 该方法时间复杂度是O(nlogn)， 空间复杂度是O(n^2)
 * 虽然可以做，但是不是最好的方法；
*/
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    vector<int> res(matrix.size() * matrix[0].size());
    int count = 1, index = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            res[index++] = matrix[i][j];
        }
    }
    sort(res.begin(), res.end());
    for (auto x : res)
    {
        if (count == k)
        {
            return x;
        }
        count += 1;
    }
    return -1;
}


/**
 * 方法 2，利用优先队列的特性，对队列中的每个元素进行从大到小的排序，
 * 然后把元素放进优先队列中，查看这个队列当前的长度是不是大于k，那么就把队列顶部的元素
 * 移除，最后返回的就是队列top元素，就是第k个元素即可；
*/
int kthSmallest1(vector<vector<int>> & matrix, int k)
{
    priority_queue<int>mypq;
    int count=1;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            mypq.emplace(matrix[i][j]);
            if(mypq.size()>k)
            {
                mypq.pop();
            }
        }
    }
    return mypq.top();
}

/**
 * 方法 3，利用的是二分查找来找这个数字
 * 这题我们也可以用二分查找法来做，我们由于是有序矩阵，那么左上角的数字一定是最小的，
 * 而右下角的数字一定是最大的，所以这个是我们搜索的范围，然后我们算出中间数字mid，
 * 由于矩阵中不同行之间的元素并不是严格有序的，所以我们要在每一行都查找一下 mid，
 * 我们使用 upper_bound，这个函数是查找第一个大于目标数的元素，如果目标数在比该行的尾元素大，
 * 则 upper_bound 返回该行元素的个数，如果目标数比该行首元素小，则 upper_bound 返回0, 
 * 我们遍历完所有的行可以找出中间数是第几小的数，然后k比较，进行二分查找，left 和 right 最终会相等，
 * 并且会变成数组中第k小的数字。举个例子来说吧，比如数组为:
 * [1 2
 * 12 100]
 * k = 3
 * 那么刚开始 left = 1, right = 100, mid = 50, 遍历完 cnt = 3，此时 right 更新为 50
 * 此时 left = 1, right = 50, mid = 25, 遍历完之后 cnt = 3, 此时 right 更新为 25
 * 此时 left = 1, right = 25, mid = 13, 遍历完之后 cnt = 3, 此时 right 更新为 13
 * 此时 left = 1, right = 13, mid = 7, 遍历完之后 cnt = 2, 此时 left 更新为8
 * 此时 left = 8, right = 13, mid = 10, 遍历完之后 cnt = 2, 此时 left 更新为 11
 * 此时 left = 11, right = 12, mid = 11, 遍历完之后 cnt = 2, 此时 left 更新为 12
 * 循环结束，left 和 right 均为 12，任意返回一个即可
 * 时间复杂度是O(nlgn * lgx)x是最大值和最小值的差值
*/

int kthSmallest2(vector<vector<int>>&nums, int k)
{

    int left = nums[0][0], right = nums.back().back();
    while(left < right)
    {
        int mid = left + (right - left)/2, cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            cnt += upper_bound(nums[i].begin(), nums[i].end(), mid) - nums[i].begin(); // 位置索引
        } 
        if(cnt < k) left = mid+1;
        else right = mid;  

    }
    return left;
}

int main()
{
    vector<vector<int>> nums = {
        {1, 2},
        {12, 100}};
    cout << kthSmallest2(nums, 3) << endl;

    return 0;
}