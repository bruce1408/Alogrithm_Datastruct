#include <iostream>
#include <vector>
using namespace std;

/**
 * 233 求一个数字中1出现的次数
*/

/**
 * 方法 1，从n-1之间逐位进行遍历求解即可，超时了
*/
int countDigitOne(int n)
{
    int ans = 0;
    for (int i = n; i > 0; i--)
    {
        ans += getone(i);
    }
    return ans;
}

int getone(int x)
{
    int res = 0;
    while (x)
    {
        if (x % 10 == 1)
            res++;
        x /= 10;
    }
    return res;
}

/**
 * 方法 2,详细参考
 * https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/
*/
vector<int> bit(int x)
{
    vector<int> res;
    while (x)
    {
        res.push_back(x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int countDigitOne(int n)
{
    if (n <= 0)
        return 0;
    // 得到这个数字的每一位
    vector<int> nums = bit(n);
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int d = nums[i];
        // 当前数字的左边和右边分别计算
        int left = 0, right = 0, carry = 1;
        // 求解左边高位部分
        for (int j = 0; j < i; j++)
            left = left * 10 + nums[j];
        // 求解右边地位部分和位数
        for (int j = i + 1; j < nums.size(); j++)
        {
            right = right * 10 + nums[j];
            carry = carry * 10;
        }
        // 分三种情况，d=0时候 左边高位数 * 位数
        if (d == 0)
            ans += left * carry;
        // d=1时候，左边高位 * 位数 + 右边数 + 1
        else if (d == 1)
            ans += left * carry + right + 1;
        // d>1 的情况是(左边 + 1) * 位数
        else
            ans += (left + 1) * carry;
    }
    return ans;
}

int main()
{
}