#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * There are some chips, and the i-th chip is at position chips[i].
 * You can perform any of the two following types of moves any number
 * of times (possibly zero) on any chip:
 * Move the i-th chip by 2 units to the left or to the right with 
 * a cost of 0.
 * Move the i-th chip by 1 unit to the left or to the right with a 
 * cost of 1.There can be two or more chips at the same position initially.
 * Return the minimum cost needed to move all the chips to 
 * the same position (any position).
 * 
 * Example 1:
 * Input: chips = [1,2,3]
 * Output: 1
 * Explanation: Second chip will be moved to positon 3 with cost 1. 
 * First chip will be moved to position 3 with cost 0. Total cost is 1
 * 
 * 本题目的大致意思就是说一个数组，然后每个数字可以+-2，也可以+-1，
 * 通过上面的加减操作使得这个数组的数字全部一样，但是+-2的代价是0
 * +-1的代价是1；最后得到最小的代价是多少
 * 1，2，3 
 * 3-2变成1，代价0， 2-1变成1，代价是1，
 * 总代价1；
 * 
 * 1，3，5
 * 1+2，代价0， 3不变，5-2，代价0；
 * 总代价0；
*/

/**
 * 方法 1，如果一个数字全是偶数或者全是奇数，那么代价为0，
 * 如果有偶数也有奇数，我们只要统计偶数的个数和奇数的个数，最后
 * 返回这两个数的最小数即可
*/
int minCostToMoveChips(vector<int> &chips)
{
    int n = chips.size(), odd = 0, even = 0;

    for (int i = 0; i < n; i++)
    {
        if (chips[i] % 2 == 1)
        {
            odd += 1;
        }
        else
        {
            even += 1;
        }
    }
    return min(odd, even);
}

int main()
{
    vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    cout << minCostToMoveChips(res) << endl;
}