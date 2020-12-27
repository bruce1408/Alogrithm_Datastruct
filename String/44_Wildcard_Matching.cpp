#include<iostream>
#include<vector>
using namespace std;
/**
 * 
*/
bool isMatch(string s, string p) {
    // 和 10题那个正则表达式子不同的是，这里的*可以前面不用有字符
    int n = s.size(), m = p.size();
    vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    for(int i=1; i<=m; i++)
    {   
        // 如果s个数0，那么p只要是*，都满足条件
        if(p[i-1]=='*') dp[0][i] = dp[0][i-1];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else
            {  
                dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='?') && dp[i-1][j-1];
            }
        }
    }
    return dp[n][m];

}