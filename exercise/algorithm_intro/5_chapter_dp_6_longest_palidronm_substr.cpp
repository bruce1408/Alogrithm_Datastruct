#include <iostream>
#include <string>
using namespace std;

/**
 * 最长回文子串
 * 给定一个字符串，然后返回这个最长回文串的长度
 * 输入：
 * patzjujztaccbcc
 * 输出：
 * atzjujzta
*/
bool pard(int i, int j, string a)
{
    while (i < j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a = "zsubusht";
    // cout << a.substr(1, 3) << endl;
    int n = a.size();
    string res;
    for (int i = 0; i < n; i++)
    {
        string temp;
        for (int j = i; j < n; j++)
        {
            if (pard(i, j, a))
            {
                temp = a.substr(i, j);
                // cout << temp << endl;
                if (temp.size() > res.size())
                {
                    res = temp;
                }
            }
        }
    }
    cout << res << endl;
}