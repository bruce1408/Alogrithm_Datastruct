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