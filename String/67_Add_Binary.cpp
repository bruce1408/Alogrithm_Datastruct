#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 67_Add binary
 * 二进制加法计算
 * 给定两个二进制数字的字符串，然后求出他们的二进制加法结果
 * Input: a = "11", b = "1"
 * Output: "100"
*/

/**
 * 方法 1，使用二进制加法，设置一个进位符t，然后从低位到高位分别相加，最后结果放到一个临时数组
 * 最后把结果保存到字符串s中
*/
string addBinary1(string a, string b)
{
    int i = a.size() - 1, j = b.size() - 1, t = 0;
    string s;
    vector<int> res;
    while (j >= 0 || i >= 0)
    {
        if (i >= 0)
            t += a[i--] & 1;
        if (j >= 0)
            t += b[j--] & 1;
        res.push_back(t % 2);
        t /= 2;
    }
    if (t)
        res.push_back(t);
    for (int i = res.size() - 1; i >= 0; i--)
        s += to_string(res[i]);
    return s;
}

/**
 * 方法 2，不用临时数组，直接把结果加到string中
*/
string addBinary2(string a, string b)
{
    string res = "";
    int m = a.size() - 1, n = b.size() - 1, carry = 0;
    while (m >= 0 || n >= 0)
    {
        int p = m >= 0 ? a[m--] - '0' : 0;
        int q = n >= 0 ? b[n--] - '0' : 0;
        int sum = p + q + carry;
        res = to_string(sum % 2) + res;
        carry = sum / 2;
    }
    return carry == 1 ? "1" + res : res;
}

int main()
{
    string a = "1010", b = "1011";
    cout << addBinary2(a, b) << endl;
}