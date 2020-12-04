#include <iostream>
#include <cstdio>
using namespace std;

/**
 * kmp 算法
 *  给定一个模式串S，以及一个模板串P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
 * 模板串P在模式串S中多次作为子串出现。
 * 求出模板串P在模式串S中所有出现的位置的起始下标。
*/

/**
 * 方法 1，使用双指针来做，可能会超时
*/
void kmpBF()
{
    int m = 3, n = 5;
    string s = "ababa";
    string p = "aba";
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (s[i + j] != p[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << i << " ";
    }
    cout << endl;
}

/**
 * 方法 2，优化双指针算法，使用next数组，用kmp算法来做
*/
const int N = 1000010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    // cin >> n >> p + 1 >> m >> s + 1;
    n = 3, m = 5;
    p+1 = "aba";
    s+1 = "ababa";
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
        cout<<endl;
    }
    return 0;
}
