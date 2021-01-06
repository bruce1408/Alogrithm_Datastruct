#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 443 字符串压缩，
 * Input:
 * ["a","a","b","b","c","c","c]
 * Output:
 * ["a","2","b","2","c","3"]
 * 
*/

/**
 * 方法 1，使用双指针算法来做
 * 两个指针分别指向的是单词重复的那段区间，然后再判断区间长度，大于9的话要逐位
 * 转化成字符即可
*/
int compress(vector<char> &chars)
{
    const int n = chars.size();
    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        int count = 1;
        while (i < n && chars[i] == chars[i - 1])
        {
            ++i;
            ++count;
        }
        chars[p++] = chars[i - 1];
        if (count == 1)
            continue;
        for (char c : to_string(count))
            chars[p++] = c;
    }
    for (auto i : chars)
    {
        cout << i << " ";
    }
    return p;
}

/**
 * 方法 2，使用to_string 算法其实是一个logn空间复杂度
*/
int compress2(vector<char> &s)
{
    int n = s.size();
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j + 1 < n && s[i] == s[j + 1])
            j++;
        int len = j - i + 1;
        s[k++] = s[i];
        if (len > 1)
        {
            int t = k;
            while (len)
            {
                s[t++] = '0' + len % 10;
                len /= 10;
            }
            reverse(s.begin() + k, s.begin() + t);
            k = t;
        }
        i = j;
    }
    return k;
}

int main()
{
    vector<char> res = {'a', 'a', 'a', 'b', 'b'};
    cout << compress2(res) << endl;
}