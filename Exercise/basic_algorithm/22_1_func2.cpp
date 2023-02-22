#include<iostream>
using namespace std;
/**
 * 走方格，给定一个nxm的方格阵子；
 * 给定一个 n×mn×m 的方格阵，沿着方格的边线走，从左上角 (0,0)(0,0) 开始，每次只能往右或者往下走一个单位距离，
 * 问走到右下角 (n,m)(n,m) 一共有多少种不同的走法。
 * 输入格式
 * 共一行，包含两个整数 nn 和 mm。
 * 输出格式
 * 
 * 共一行，包含一个整数，表示走法数量。
 * 数据范围
 * 1≤n,m≤101≤n,m≤10
 * 输入样例：
 * 2 3
 * 输出样例：
 * 10 
*/

// int res;
// int n,m;
// int route(int x, int y)
// {
//     if(x==n && y==m)
//     {
//         res+=1;
//     }
//     else{
//         if(x<n) route(x+1, y);
//         if(y<m) route(x, y+1);
//     }
//     return res;
// }

// int main()
// {
//     cin>>n>>m;
//     cout<<route(0, 0)<<endl;
// }

/**
 * 方法二
*/
#include <iostream>

using namespace std;

int fc(int n, int m) // f(n,m)表示到达n,m点的方案数
{
    if(m == 0 || n == 0) return 1;//在左界或上界时 只能由一个方向接受所到来的点 所以方案数为1
    return fc(n - 1, m) + fc(n, m - 1);// (n,m)点可由上边或者左边接收到 固加方案数即为到达上边点与左边点的和
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << fc(n,m) << endl;//f(n,m)即是答案
    return 0;
}


/**
 * 方法三
*/
int n,m;
int f[11][11];

int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) f[i][j] = 1;
            else f[i][j] = f[i-1][j] + f[i][j-1];
        }
    }
    cout<<f[n][m];
}

//方法四
#include <iostream>

using namespace std;

const int N = 10;
int dp[N + 1][N + 1]; 

int uniquePath(int n, int m)
{
    dp[0][0] = 1;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
        {
            if(i) dp[i][j] += dp[i - 1][j];
            if(j) dp[i][j] += dp[i][j - 1];
        }

    return dp[n][m];    

}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << uniquePath(n, m) << endl;
    return 0;
}
