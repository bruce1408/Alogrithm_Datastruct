#include <iostream>
#include <vector>
using namespace std;

/**
 * 66 数组加1
 * 给定一个数组，然后加1，得到最后的数组的结果。
 * 比如[1，2，3]，加1 之后，是[1，2，4]
*/

/**
 * 方法 1，digits 是数组。考虑几种情况：第一种是999，第二种是9，第三种是109；
   999 的时候要最高位进位，所以，最后一位补0，最高位重置为1
   第三种是109
*/
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    int carry = 0;
    if (digits[n - 1] != 9)
        digits[n - 1] += 1;
    else
    {
        carry = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] == 9 && i != 0 && carry == 1)
            {
                digits[i] = 0;
                carry = 1;
            }
            else if (digits[i] != 9 && carry == 1)
            {
                digits[i] = carry + digits[i];
                carry--;
            }
            else if (digits[i] != 9 && carry == 0)
            {
                digits[i] = digits[i];
            }
            else if (digits[i] == 9 && i == 0 && carry == 1)
            {
                digits.push_back(0);
                digits[0] = carry;
            }
        }
    }
    return digits;
}

/**
 * 最高位如果是9，且有进位的话，那么后后面肯定是999，然后最后一位是0；第一位是1，那么push_back(0),然后第一位赋值为1；
 * 标准答案
*/
vector<int> plusOne1(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
            digits[i] = 0;
        else
        {
            digits[i] += 1;
            return digits; // 立马就返回了
        }
    }
    if (digits.front() == 0) // 也可以这么写：if(digits.front==0) digits.insert(digits.begin(),1);
    {
        digits.push_back(0);
        digits[0] = 1;
    }
    return digits;
}

/**
 * 方法 3，使用递归来做这道题目，注意递归条件是什么
*/
void plusFunc(vector<int> &res, int digit, int index)
{
    if (digit == 1 && index >= 0)
    {
        int temp = res[index] + 1;
        digit = temp / 10;
        res[index] = temp % 10;
        plusFunc(res, digit, --index);
    }
    else if (digit == 1)
    {
        res.insert(res.begin(), 1);
    }
    else
    {
        return;
    }
}
vector<int> plusOne2(vector<int> &res)
{
    int index = res.size() - 1;
    plusFunc(res, 1, index);
    return res;
}
int main()
{
    vector<int> nums = {2, 9, 9};
    plusOne2(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    return 0;
}