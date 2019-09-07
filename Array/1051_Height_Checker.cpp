#include <iostream>
#include <vector>
using namespace std;

/**
 * Students are asked to stand in non-decreasing order
 *  of heights for an annual photo.
 * Return the minimum number of students 
 * not standing in the right positions.  
 * (This is the number of students that must move 
 * in order for all students to be standing in 
 * non-decreasing order of height.)
 * 
 * Example 1:
 * Input: [1,1,4,2,1,3]
 * Output: 3
 * Explanation: 
 * Students with heights 4, 3 and the last 1 are 
 * not standing in the right positions.
 * 
 * 这道题有点争议，我做的时候给出的例子[1,2,1,2,1,1,1,1,2,1]
 * 答案是5，就是错误的位置都计算到。但是结果是却是4，很多人都在
 * 讨论这个题目没有描述清楚，下面的方法 1是我自己做的，我觉得思路
 * 还是很自然的，但是答案是5，方法 2的答案是正确的，粗暴简单
 *  
*/

/**
 * 方法 1的思路自然，就是当前的数字如果小于前面的数字，那么就是位置
 * 不对，然后判断这个数是不是最大的数，count+1，如果这个数不是最大的数
 * 那么还要考虑这个数是不是比最大的数字还要小，如果是，那么还是出现的
 * 位置不对，count+1，负责，这个数就是当前的最大数字。
*/
int heightChecker(vector<int> &heights)
{
    int count = 0, maxNum = heights[0];
    for (int i = 1; i < heights.size(); i++)
    {
        if (heights[i] < heights[i - 1]) // 当前数小于前一个数
        {
            maxNum = max(heights[i], maxNum);
            count += 1;
        }
        else
        {
            if (heights[i] < maxNum)
                count += 1;
            else
                maxNum = heights[i];
        }
    }
    return count;
}

/**
 * 方法 2 简单暴力，设置一个新的数组然后排序，依次比对这两个数组相同
 * 位置的数字是否相同，不相同的话count+1
 * 
*/

int heightChecker1(vector<int> &heights)
{
    int count = 0;
    vector<int> res = heights;
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] != heights[i])
            count += 1;
    }
    return count;
}

int main()
{
    vector<int> res = {1, 2, 1, 2, 1, 1, 1, 2, 1};

    cout << heightChecker1(res) << endl;
}
