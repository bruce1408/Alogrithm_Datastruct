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
 * 方法 2，利用2个指针，遍历这个矩阵，其实是有规律的，
 * 就是右边的永远大于左边，下边大于上边
 * 
*/

// int kthSmallest2(vector<vector<int>>& matrix, int k)
// {
//     int rowIndex = 1, columnIndex = 1, count = 1, startX = 0, startY = 0;
//     int rows = matrix.size(), columns = matrix[0].size();
   
//     while(columnIndex < columns && rowIndex < rows && k!=count)
//     {
//         if(matrix[startX][columnIndex] < matrix[rowIndex][startY])
//         {
//             startY+=1;
//         }
//         else if(matrix[startX][columnIndex] > matrix[rowIndex][startY])
//         {
//             startX+=1;
//         }
//         else
//         {
//             return -1;
//         }
//     }
//     return -1;
// }


/**
 * 方法 3，利用的是二分查找来找这个数字
*/
int main()
{
    vector<vector<int>> nums = {
        {1, 2},
        {1, 3}};
    cout << kthSmallest1(nums, 1) << endl;

    return 0;
}