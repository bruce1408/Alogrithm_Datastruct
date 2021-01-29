#include <iostream>
#include <vector>
using namespace std;

/**
 * 66 数组加1
 * 给定一个数组，然后加1，得到最后的数组的结果。
 * 比如[1，2，3]，加1 之后，是[1，2，4]
*/

/**
 * 最高位如果是9，且有进位的话，那么后后面肯定是999，然后最后一位是0；第一位是1，那么push_back(0),然后第一位赋值为1；
 * 标准答案
*/
vector<int> plusOne(vector<int> &digits)
{
    int t = 1;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        digits[i] += t;
        t = digits[i] / 10;
        digits[i] %= 10;
    }
    if (t)
    {
        digits.push_back(0);
        for (int i = digits.size() - 2; i >= 0; i--)
            digits[i + 1] = digits[i];
        digits[0] = 1;
    }
    return digits;
}

int main()
{
    vector<int> nums = {9, 9, 9};
    plusOne(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    return 0;
}