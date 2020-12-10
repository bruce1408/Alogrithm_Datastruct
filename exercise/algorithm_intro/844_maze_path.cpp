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
int d[N][N];    // 保存的是距离长度
PII q[N * N];
PII rute[N][N];

int bfs1(vector<vector<int>> &d, vector<vector<int>> &rute1)
{
    // 上右下左四个点的坐标
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int head = -1, rear = -1;
    q[0] = {0, 0};
    d[0][0] = 0;
    while (head <= rear)
    {
        auto t = q[head++]; // 取出队头
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && path[x][y] != 1 && d[x][y] == -1)
            {
                // cout<<x<<" "<<y<<endl;
                d[x][y] = d[t.first][t.second] + 1;
                q[++rear] = {x, y}; // 入队
                rute1.push_back({t.first, t.second});
                rute[x][y] = t;
            }
        }
    }
    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << " " << y << endl;
        auto t = rute[x][y];
        x = t.first, y = t.second;
    }

    return d[n - 1][m - 1];
}

/**
 * 自己手写第二遍
*/
int n, m;
const int N = 110;
int path[N][N], visited[N][N], dis[N];
pair<int, int> q[N * N];

int bfs2(vector<vector<int>> &visited)
{
    // 上右下左
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int head = 0, rear = 0;
    q[0] = {0, 0};
    visited[0][0] = 0;

    while (head <= rear)
    {
        auto t = q[head++];
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x < n && x >= 0 && y >= 0 && y < m && path[x][y] != 1 && visited[x][y] == -1)
            {
                q[++rear] = {x, y};
                visited[x][y] = visited[t.first][t.second] + 1;
            }
        }
    }
    return visited[n - 1][m - 1];
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
    vector<vector<int>> visited(N, vector<int>(N, -1));
    cout << bfs2(visited) << endl;
}