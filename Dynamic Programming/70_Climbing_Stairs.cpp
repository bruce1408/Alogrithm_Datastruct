#include <iostream>
#include <vector>
using namespace std;

/**
 * 方法 1，使用动态规划来做，但是超时了
*/
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

/**
 * 方法 2，时间复杂度为O(n)
*/
int climbStairs2(int n)
{
    vector<int> res(n);
    if (n >= 1)
        res[0] = 1;
    if (n >= 2)
        res[1] = 2;
    for (int i = 2; i < n; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res[n - 1];
}

int main()
{
    cout << climbStairs2(3) << endl;
}