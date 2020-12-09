#include <iostream>
using namespace std;

/**
 * n-皇后问题是指将 n 个皇后放在 n∗n 的国际象棋棋盘上，
 * 使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、
 * 同一列或同一斜线上。在给定整数n，请你输出所有的满足条件的棋子摆法。
 * 输入格式
 * 共一行，包含整数n。
 * 输出格式
 * 每个解决方案占n行，每行输出一个长度为n的字符串，用来表示完整的棋盘状态。
 * 其中”.”表示某一个位置的方格状态为空，”Q”表示某一个位置的方格上摆着皇后。
 * 每个方案输出完成后，输出一个空行。
 * 
 * bool数组用来判断搜索的下一个位置是否可行，col列，dg对角线，
 * udg反对角线，g[N][N]用来存路径
 * 定义纵坐标为y轴，横坐标为x轴，u是每一层的状态，i是枚举每一列的状态，
 * 那么y:u, x:i;
 * 正对角线y = x+b -> b  = y-x+n; 
 * 反对角线是 y = -x+b -> b = x+y;
 * 那么应该是dg[n+u-i]，udg[u+i].
 * O(n*n!)
 * */
int n;
const int N = 20;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u)
{
    // u == n 表示已经搜了n行，故输出这条路径
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            puts(g[i]); // 等价于cout << g[i] << endl;
        puts("");       // 换行
        return;
    }
    //对n个位置按行搜索
    for (int i = 0; i < n; i++)
        // 剪枝(对于不满足要求的点，不再继续往下搜索)              udg[n - u + i]，+n是为了保证大于0
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            // 恢复现场 这步很关键
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
}

/**
 * 定义纵坐标为y轴，横坐标为x轴，u是每一层的状态，
 * i是枚举每一列的状态，那么y:u, x:i;
 * 正对角线y = x+b -> b  = y-x+n; 
 * 反对角线是 y = -x+b -> b = x+y; 那么应该是dg[n+u-i]，udg[u+i].
 * O(2^n)
*/
bool row[N], col[N], dg[N * 2], udg[N * 2];

void dfs2(int x, int y, int s)
{
    if (s > n)
        return;
    if (y == n) // 每一行的最后一列搜索完毕，开始下一行
    {
        x++;
        y = 0;
    }
    if (x == n) // 最后一行搜索完毕
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << g[i][j];
                cout << endl;
            }
            cout << endl;
        }
        return;
    }
    // 不放皇后，继续下一层遍历
    g[x][y] = '.';
    dfs2(x, y + 1, s);

    // 满足条件的话这位置是可以放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs2(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0);
    return 0;
}
