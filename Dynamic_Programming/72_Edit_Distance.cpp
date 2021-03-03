#include <iostream>
#include <vector>
using namespace std;

/**
 * 72编辑距离 
 * 给出两个字符串a和b，然后有三种操作
 * 分别是删除，修改，添加
 * 对其中字符串进行3种操作之后变成另一个字符串，那么最少的操作是多少
*/

/**
 * 方法 1，使用动态规划算法来做
 * 状态fij表示a中1到i变成b中1到j的按照顺序的操作的方案集合
 * 求最小的那个方案即可
 * 对于每个字符村都有3中方案，两个字符串就是6中方案，分别是a字符串添加，删除，修改
 * 和b字符串中添加，删除，修改
 * a删除的话，表示a中的1到i-1和b中的1到j是相同的，所以f[i][j] = fi-1j + 1即可
 * a添加的话，表示a中的1到i后面补上一个bj，和b的1-j相同，所以，fij = fij-1 + 1
 * a修改的话，表示最后一个不同，前面的i-1和j-1相同，fij = fi-1j-1 + 1,如果ai等于bj
 * 那么就不用加一，否则加一，同理b数组也是三种情况
 * fij = fij-1 + 1;
 * fij = fi-1j +1;
 * fij = fi-1j-1 + 1/0;
 * 所以上面的6中状态合并起来为三种，先遍历前面两种，最后一种修改方案需要判断是不是
 * 最后ai等于bj，如果是的话，那么就不用加1，否则要加1即可
*/
int minDistance(string w1, string w2)
{
    int n = w1.size(), m = w2.size();
    string a = ' ' + w1, b = ' ' + w2;
    vector<vector<int> > f(n + 1, vector<int>(m + 1));
    // 状态初始化，如果b字符串是空，那么要么a进行删除或者b添加
    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int i = 1; i <= m; i++)
        f[0][i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            int t = a[i] != b[j];
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + t);
        }
    }
    return f[n][m];
}