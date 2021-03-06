#include <iostream>
#include <vector>
using namespace std;

/**
 * 401 二进制手表，然后给定一个数n
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/

/**
 * 方法 1，使用sprintf来保存时间格式
 * 首先一共是10位，然后枚举10个1的所有情况，然后再看当前的情况有多少个1，
 * 如果当前的1的个数和num相同，那么让i右移6位，就是小时，i&63就表示的是
 * 分钟，如果小时和分钟满足要求，就保存到该数组中去
*/
vector<string> readBinaryWatch(int num)
{
    vector<string> res;
    char str[10];
    // 一共有10个1, i < 2^10 = 1024;
    for (int i = 0; i < 1 << 10; i++)
    {
        int u = 1 << 10;
        int s = 0;
        for (int j = 0; j < 10; j++)
        {
            if (i >> j & 1)
                s++;
        }
        if (s == num)
        {
            // 小时右移6位腾出高4位，分钟是低6位直接和63与即可
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
    int n = 0;
    for (auto x : readBinaryWatch(n))
    {
        cout << x << endl;
    } 
}
