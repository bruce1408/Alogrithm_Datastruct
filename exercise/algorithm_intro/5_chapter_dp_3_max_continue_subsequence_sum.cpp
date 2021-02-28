#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定一个数字序列
 * a1, a2, a3....an求i到j使得ai + ...aj最大，并输出这个最大和
 * -2, 11, -4, 13, -5, -2 最大和是 20
 * 用dp[i]表示i作为最大和最后的节点
 * dp[0] = -2;
 * dp[1] = 11;
 * dp[2] = 11-4 = 7;
 * ... 
*/
const int N = 20;
int dp[N], maxnum = 0;
int main()
{
    vector<int> res = {-2, 11, -4, 13, -5, -2};
    dp[0] = -2;
    for (int i = 1; i < res.size(); i++)
    {
        dp[i] = max(dp[i - 1] + res[i], res[i]);
        maxnum = max(dp[i], maxnum);
    }
    cout << maxnum << endl;
}

bool isMatch(string s, string p)
{
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
            else
            {
                dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
    }
    return dp[m][n];
}

/**
 * 方法 2，时间复杂度是n^2
*/
const int N = 1000;
int f[N];
int a[N];
int main()
{
    cin>>n;
    for(int =1; i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1; i<=n;i++)
    {
        f[i] = 1; // 只有i是一个数
        for(int j = 1;j<i;j++)
        {
            if(a[j]<a[i]) f[i] = max(f[j] + 1, f[i]); 
        }
    }

    int res = 0;
    for(int i =1;i<=n;i++) res = max(res, f[i]);
    cout<<res;
}