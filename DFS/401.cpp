#include <iostream>
#include <vector>
using namespace std;

/**
 * 401 二进制手表，然后给定一个数n
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/

/**
 * 方法 1，使用sprintf来做
*/
vector<string> readBinaryWatch(int num)
{
    vector<string> res;
    char str[10];
    for (int i = 0; i < 1 << 10; i++)
    {
        int s = 0;
        for (int j = 0; j < 10; j++)
        {
            if (i >> j & 1)
                s++;
        }
        if (s == num)
        {
            int a = i >> 6, b = i & 63;
            if (a < 12 && b < 60)
            {
                sprintf(str, "%d:%02d", a, b);
                res.push_back(str);
            }
        }
    }
    return res;
}

int main()
{
    int n = 6;
    for (auto x : readBinaryWatch(n))
    {
        cout << x << endl;
    }
}