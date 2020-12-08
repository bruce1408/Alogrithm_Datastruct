#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * 走迷宫问题，n*m的迷宫，然后每次可以上下左右移动1位，
 * 最开始从左上角出发，然后直到走到右下角为止，找出一条最短的路径
 * 使用BFS算法来做，最短路径只有在权重为1的情况下可以使用BFS
 * 
*/

typedef pair<int, int> PII;
const int N = 110;
int n, m;
int path[N][N]; // 保存的是整个地图
int d[N][N];    // 保存的是距离
PII q[N * N];

int bfs(vector<vector<int>> &d)
{
    // 上右下左四个点的坐标
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int head = -1, rear = -1;
    q[0] = {0, 0};
    d[0][0] = 0;
    while (head != rear)
    {
        auto t = q[head++]; // 取出队头
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && path[x][y] != 1 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q[++rear] = {x, y}; // 入队
            }
        }
    }
    return d[n - 1][m - 1];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> path[i][j];
        }
    }
    /**
     * 用来判断这个点是否已经走过了，初始化用-1表示没有走过,
     * 如果走过了，就这个点的坐标+1，最后输出的是最后右下角点的值，即路径长度
     * */
    vector<vector<int>> dis(N, vector<int>(N, -1));
    cout << bfs(dis) << endl;
}