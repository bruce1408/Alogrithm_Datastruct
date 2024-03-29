#include <iostream>
#include <queue>
using namespace std;
/**
 * 宽度优先搜索一般步骤是由队列实现，然后总是按层次的顺序进行遍历，基本写法如下：
 * void BFS(int s)
 * {
 *   queue<int>q;
 *   q.push(s);
 *   while(!q.empty())
 *   {
 *      取出队首元素
 *      访问队首元素
 *      将队首元素出队
 *      将top下一层的节点中未曾入队的节点全部入队，然后设置为已入队
 *   }
 * }
 * 
 * 给定一个数组，n * m大小，然后数组的数组要么是1，要么是0
 * i，j 位置与上下左右四个位置相邻，如果这个数组的若干个1是相邻的(不必两两相邻)，那么这些1构成一个块
 * 求数组中的块的大小
*/
const int N = 110;
int n, m, ans, res, path[N][N];
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
            if (newx >= 0 && newx < n 
            && newy >= 0 && newy < m 
            && path[newx][newy] == 1 
            && visited[newx][newy] == false)
            {
                q.push({newx, newy});
                visited[newx][newy] = true;
                res++;
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
    // cout << res << endl;
    cout << ans << endl;
}