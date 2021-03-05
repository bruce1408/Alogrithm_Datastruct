#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 10_正则表达式：
 * "*" 表示前面0个或n个重复的字母
 * "." 表示可以代替任何字母
 * 给定字符串a 和 b，判读是否b可以表达a串
*/

/**
 * 方法 1
 * 若p为空，若s也为空，返回 true，反之返回 false。
 * 若p的长度为1，若s长度也为1，且相同或是p为 '.' 则返回 true，反之返回 false。
 * 若p的第二个字符不为*，若此时s为空返回 false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。
 * 若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括 p[0] 为点），
 * 调用递归函数匹配s和去掉前两个字符的p（这样做的原因是假设此时的星号的作用是让前面的字符出现0次，验证是否匹配,
 * 若匹配返回 true，否则s去掉首字母（因为此时首字母匹配了，我们可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，
 * 所以不需要去掉），继续进行循环。
 * 返回调用递归函数匹配s和去掉前两个字符的p的结果（这么做的原因是处理星号无法匹配的内容，比如 s="ab", p="a*b"，
 * 直接进入 while 循环后，我们发现 "ab" 和 "b" 不匹配，所以s变成 "b"，那么此时跳出循环后，
 * 就到最后的 return 来比较 "b" 和 "b" 了，返回 true。再举个例子，比如 s="", p="a*"，
 * 由于s为空，不会进入任何的 if 和 while，只能到最后的 return 来比较了，返回 true，正确）。
*/
bool isMatch(string s, string p)
{
    // p和s都是空字符串，返回true，否则false
    if (p.empty())
        return s.empty();

    // 如果p长度是1且p是.那么s长度也是1返回true
    if (p.size() == 1)
        return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));

    // 如果p第二个字符不是*，递归从第二个字符开始判断
    if (p[1] != '*')
    {
        if (s.empty())
            return false;
        return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
    // s = ab, p = a*b, 考虑*的情况
    while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
    {
        if (isMatch(s, p.substr(2)))
            return true;
        s = s.substr(1);
    }
    return isMatch(s, p.substr(2));
}

/**
 * 方法 2，使用动态规划，使用上面边界条件不容易想到所有的情况
 * 状态d[i][j]就是表示所有第一个字符串[1-i]中和第二个字符串[1-j]匹配的方案
 * 状态计算部分
 * 如果是p[j] !='*',直接匹配就可以了，s[i] 和 p[j]匹配的两种情况，
 * 第一种情况是s[i]==p[j]的情况，
 * 第二种情况是p[j]=='.'的情况
 * 然后考虑*使用了0次，那么dij  = d[i,j-2]
 * 如果使用超过1次d[ij] = d[i-1][j],因为上次j没有使用到*符号，而本次才使用了*，所以当前的d[ij]=上次i-1和j
 * 并且当前s[i-1]==p[j-2] || p[j-2]=='.',使用ab 和a*b举例即可
*/
bool isMatch2(string s, string p)
{
    int n = s.size(), m = p.size();
    vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= n; i++) //i从0开始
    {
        for (int j = 1; j <= m; j++) //j从1开始，j从0没有意义
        {
            // 这里p[j-1]是*的情况
            if (p[j - 1] == '*' && j > 1)
            {
                // *表示的是一个字符的情况  || *匹配1个字符的情况
                dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
            else
                dp[i][j] = (i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
        }
    }
    return dp[n][m];
}

int main()
{
    string a = "aac", b = "a*c";
    cout << isMatch2(a, b) << endl;
}