#include <iostream>
#include <string>
using namespace std;

/**
 * 最长公共子序列 LCS(longest common subsequence)
 * 给定两个字符串；A和B，求一个字符串，使得字符串是A和B的最长公共部分；
*/

/**
 * 方法 1，暴力做法，两个字符串的每个字符，分别都有选或者不选两种情况，所以时间复杂度
 * 是O(2^(m+n)*max(n,m))
*/
string getcom(string a, string b)
{
    int n1 = a.size(), n2 = b.size();
    string temp, res;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            temp = "";
            if (a[i] == b[j])
            {
                temp += a[i];
                int h = i + 1;
                while (h < n1)
                {
                    int k = j + 1;
                    for (k = j + 1; k < n2; k++)
                    {
                        if (a[h] == b[k])
                        {
                            temp += a[h];
                            break;
                        }
                    }
                    h++;
                }
                if (temp.size() > res.size())
                {
                    res = temp;
                }
            }
        }
    }
    return res;
}

/**
 * 方法 2，暴力做法复杂度太高，所以选择动态规划做法
 * 使用数组d[i][j]表示：字符串a的第i位结尾的字符 和 字符串b第j位结尾的字符的公共子序列长度
 * 分两种情况：
 * 如果a[i] = b[j]: d[i][j] = d[i-1][j-1] + 1;
 * 如果a[i] != b[j]: d[i][j] = max(d[i-1][j], d[i][j-1])
*/
const int N = 200;
int d[N][N];
int getcom1(string a, string b)
{
    int n1 = a.size(), n2 = b.size();
    // 确定边界
    for (int i = 0; i < n1; i++)
        d[i][0] = 0;
    for (int i = 0; i < n2; i++)
        d[0][i] = 0;

    // 状态转移方程
    for (int i = 1; i < n1; i++)
    {
        for (int j = 1; j < n2; j++)
        {
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    return d[n1 - 1][n2 - 1];
}

int main()
{
    string a = "sadstory", b = "adsminsorry";
    cout << getcom(a, b) << endl;
    cout << getcom1(a, b) + 1 << endl;
}