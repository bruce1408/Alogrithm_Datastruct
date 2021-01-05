#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 最小循环节求解，如果字符串s长度是len，那么得到next数组之后，
 * 1、如果len 可以被 len-next[len]整除，len%(len - next[len]==0),
 * 那么循环周期就是len/(len - next[len])，循环节就是next[len]个字符构成的子串
 * 2、如果不能整除，那么设置 L = len-next[len]；
 * 需要补的位数是： L - next[len] % L
*/
/**
 * KMP算法：
 * 求解next数组，第一种方式是表示next[i]表示前缀和后缀相同的最长的字符串长度
 * 比如字符串：
 *      a b a b a b
 *   -1 0 0 1 2 3 4
 **/
vector<int> getnext(string s, vector<int> &ne)
{
    int len = s.size();
    int i = 0, j = -1;
    ne[0] = -1;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            ne[i] = j;
        }
        else
            j = ne[j];
    }
    return ne;
}

/**
 * 第二种求解KMP的next数组的方法
 * 就是next[i]表示前缀和后缀相同的最长字符串的的前缀的最后一个下标
*/
vector<int> getnext1(string s, vector<int> &ne)
{
    int j = -1;
    for (int i = 1; i < s.size(); i++)
    {
        while (j != -1 && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
    }
    return ne;
}

int main()
{
    string s = "ababab";
    cout << "字符串是：" << s << endl;
    int len = s.size();
    vector<int> ne(len + 1, -1);
    for (auto i : getnext(s, ne))
        printf("%d ", i);
    printf("\n");
    // for (auto i : getnext1(s, ne))
    //     cout << i << " ";
    // cout << endl;
    return 0;
}
