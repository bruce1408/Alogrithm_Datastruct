#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 306 累加数字
 * 判断这个序列是不是一个菲波那切数列
 * 如果是的话就返回1，否则返回0
*/

/**
 * 方法 1，使用高精度的方式来保存每个数字，计算相邻两个数的和
 * 是不是和下一段是不是匹配，如果整个都可以匹配完，那么就是可以返回1
*/

string add(string x, string y)
{
    vector<int> a, b, c;
    for (int i = x.size() - 1; i >= 0; i--)
        a.push_back(x[i] - '0');
    for (int i = y.size() - 1; i >= 0; i--)
        b.push_back(y[i] - '0');
    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i++)
    {
        if (i < a.size())
            t += a[i];
        if (i < b.size())
            t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    string z;
    for (int i = c.size() - 1; i >= 0; i--)
    {
        z += to_string(c[i]);
    }
    return z;
}

bool isAdditiveNumber(string num)
{
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = i + 1; j + 1 < num.size(); j++)
        {
            int a = -1, b = i, c = j;
            while (true)
            {
                // 前导0的情况去掉
                if ((b - a > 1 && num[a + 1] == '0' )|| (c - b > 1 && num[b + 1] == '0'))
                    break;
                auto x = num.substr(a + 1, b - a), y = num.substr(b + 1, c - b);
                auto z = add(x, y);
                if (z != num.substr(c + 1, z.size()))
                    break;
                a = b, b = c, c += z.size();
                if (c + 1 == num.size())
                    return true;
            }
        }
    }
    return false;
}
