#include <iostream>
#include <vector>
using namespace std;

/**
 * 55 跳跃游戏
 * Example 1:
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 初始从0开始，然后能够到达最后一个位置返回true，否则返回的是false
*/

/**
 * 方法 1,设置两个变量，一个是i从头开始遍历
 * 还有一个是j，表示可以最大跳多远，然后如果j<i表示跳的距离不到i，那么就直接返回false
 * 否则每次找j和i这个位置可以跳最远的最大值，赋值给j
 * 
*/
bool canJump(vector<int> &nums)
{
    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        if (j < i)
            return false;
        j = max(j, i + nums[i]);
    }
    return true;
}

int main()
{
    vector<int> res = {3, 2, 1, 0, 4};
    cout << canJump(res) << endl;
}