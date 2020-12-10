#include <iostream>
#include <queue>
using namespace std;

const int N = 110;
int n, m, ans;
vector<vector<string>> path = {
    {".", ".", ".", ".", "."},
    {".", "*", ".", "*", "."},
    {".", "*", "S", "*", "."},
    {".", "*", "*", "*", "."},
    {".", ".", ".", "T", "."}};
bool visited[N][N];
typedef pair<int, int> PII;
struct node
{
    int x, y;
    int step;
} S, T, Node;

// node start, f, res;

int bfs()
{
    queue<node> q;
    q.push(S); // 起点入队
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        node t = q.front(); // 取出队首元素
        q.pop();
        if (t.x == T.x && t.y == T.y)
        {
            return t.step;
        }

        for (int i = 0; i < 4; i++)
        {
            int newx = t.x + dx[i];
            int newy = t.y + dy[i];
            // 注意这里不等于*，判断条件不能改成==".",这样会走不到终点T的
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && path[newx][newy] != "*" && visited[newx][newy] == false)
            {
                visited[newx][newy] = true;
                Node.x = newx, Node.y = newy;
                Node.step = t.step + 1;
                q.push(Node);
            }
        }
    }
    return -1;
}

int main()
{
    // cin >> n >> m;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> path[i][j];
    //     }
    // }
    n = 5, m = 5;
    // int x1 = 2, y1 = 2, x2 = 4, y2 = 3;
    // cin >> x1 >> y1 >> x2 >> y2;
    S.x = 2, S.y = 2, T.x = 4, T.y = 3;
    S.step = 0;
    cout << bfs() << endl;
}