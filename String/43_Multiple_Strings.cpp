#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 43 字符串相乘
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
*/

/**
 * 方法 1，设一个数组来记录每个字符相乘之后的结果，然后再加上当前的结果，因为考虑最高位是地位，所以遍历字符串的时候从高到低
 * 比如：
 *               1    2   3
 *               4    5   6
 *   ----------------------------
 *               6    12    18
 *          5    10   15
 *    4     8    12 
 *  -----------------------------
 *   4+1  13+3  28+2   27+1   8
 * --------------------------------
 *    5     6    0      8     8
 * 
*/
string multiply(string num1, string num2)
{
    string res;
    int n = num1.size(), m = num2.size();
    vector<int> temp(n + m);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = (num2[j] - '0') * (num1[i] - '0');
            temp[n - i - 1 + m - j - 1] = temp[n - i - 1 + m - j - 1] + ans;
        }
    }

    int t = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        t += temp[i];
        temp[i] = t % 10;
        t /= 10;
    }

    int k = temp.size() - 1;
    while (k > 0 && !temp[k])
        k--;
    while (k >= 0)
        res += temp[k--] + '0';
    return res;
}

int main()
{
    string a = "123", b = "456";
    cout << multiply(a, b) << endl;
}