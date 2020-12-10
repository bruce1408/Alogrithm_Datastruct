#include <iostream>
#include <queue>
using namespace std;
/**
 * 给定一个数组，n*m大小，然后数组的数组要么是1，要么是0
 * i，j 位置与上下左右四个位置相邻，如果这个数组的若干个1是相邻的(不必两两相邻)，那么这些1构成一个块
 * 求数组中的块的大小
*/
const int N = 110;
int n, m, ans, path[N][N];
bool visited[N][N];
typedef pair<int, int> PII; // 表示点的坐标，可以用结构体，也可以用pair来表示

void bfs(int x, int y)
{
    queue<PII> q;             // 设置一个新的队列
    q.push({x, y});           // 当前元素入队
    visited[x][y] = true;     // 表示已经访问过当前节点
    int dx[] = {-1, 0, 1, 0}; // 上下左右四个点
    int dy[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto t = q.front(); // 取出队首元素
        q.pop();            // 队首元素出队
        for (int i = 0; i < 4; i++)
        {
            int newx = t.first + dx[i], newy = t.second + dy[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && path[newx][newy] == 1 && visited[newx][newy] == false)
            {
                q.push({newx, newy});
                visited[newx][newy] = true;
            }
        }
    }
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (path[i][j] == 1 && visited[i][j] == false) // 之前没有访问且当前数字是1
            {
                ans++;
                bfs(i, j);
            }
        }
    }
    cout << ans << endl;
}