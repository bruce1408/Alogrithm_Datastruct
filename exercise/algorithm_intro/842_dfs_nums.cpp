#include <iostream>
#include <vector>
using namespace std;

/**
 * 使用DFS来做数字的全排列，DFS:回溯+剪枝
 * DFS：回溯的时候一定要恢复现场
*/

void dfs(int u, vector<int> &path, vector<int> &st, int n)
{
    if (u == n) // 类似于死胡同或者是递归边界
    {
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            path[u] = i;
            dfs(u + 1, path, st, n);
            st[i] = false; // 恢复现场
        }
    }
}

int main()
{
    int n = 3;
    // cin >> n;
    vector<int> path(n);
    vector<int> st(n + 1);
    dfs(0, path, st, n);
}