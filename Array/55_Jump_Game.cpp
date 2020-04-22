#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法 1，贪婪算法 Greedy Algorithm，
 * 因为这里并不是很关心每一个位置上的剩余步数，而只希望知道能否到达末尾，
 * 也就是说我们只对最远能到达的位置感兴趣，所以维护一个变量 reach，
 * 表示最远能到达的位置，初始化为0。遍历数组中每一个数字，
 * 如果当前坐标大于 reach 或者 reach 已经抵达最后一个位置则跳出循环，
 * 否则就更新 reach 的值为其和 i + nums[i] 中的较大值，
 * 其中 i + nums[i] 表示当前位置能到达的最大位置
*/
bool canJump(vector<int> &nums)
{
    int n = nums.size(), reach = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i > reach || reach >= n - 1)
            break;
        // 当前位置所能到达的最大位置！
        reach = max(reach, i + nums[i]);
    }
    return reach >= n - 1;
}

int main()
{
    vector<int> res = {2, 0};
    cout << canJump(res) << endl;
}