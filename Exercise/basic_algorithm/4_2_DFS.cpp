#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> graph, vector<vector<int>> used, int x, int y)
{
    int goal_x = 4, goal_y = 4, flag = 0, m = 5, n = 5; //是否能达到终点的标志
    vector<int> px = {-1, 0, 1, 0};                     //通过px 和 py数组来实现左下右上的移动顺序
    vector<int> py = {0, -1, 0, 1};
    // 如果与目标坐标相同，则成功
    if (graph[x][y] == graph[goal_x][goal_y])
    {
        cout << "successful" << endl;
        flag = 1;
        return;
    }
    // 遍历四个方向
    for (int i = 0; i != 4; ++i)
    {
        //如果没有走过这个格子
        int new_x = x + px[i], new_y = y + py[i];
        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&
            used[new_x][new_y] == 0 && !flag)
        {
            used[new_x][new_y] = 1;         //将该格子设为走过
            DFS(graph, used, new_x, new_y); //递归下去
            used[new_x][new_y] = 0;         //状态回溯，退回来，将格子设置为未走过
        }
    }
}

int main()
{
    int n = 5, m = 5; //地图的宽高，设置为5 * 5的表格
    vector<vector<int>> graph = {
        {1, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0}}; //地图

    vector<vector<int>> used(n, vector<int>(m, 0)); //用来标记地图上那些点是走过的
    DFS(graph, used, 2, 3);
}
