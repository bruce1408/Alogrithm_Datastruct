#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;
int visited[N], path[N];
int n;

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] != 1)
        {
            visited[i] = 1;
            path[u] = i;
            dfs(u + 1);
            visited[i] = 0;
            path[u] = 0;
        }
    }
}

// const int maxn = 30;
int n1, V, ans, maxValue = 0; // 物品件数n，背包容量V，最大价值
// int w[maxn], c[maxn];
int w[] = {3, 5, 1, 2, 2};
int c[] = {4, 5, 2, 1, 3};
// 总重量sumW 总价值
void dfs1(int index, int sumW, int sumC)
{
    if (index == n1) // 完成了对物品件数的选择
    {
        if (sumW <= V && sumC > maxValue)
        {
            maxValue = sumC;
        }
        return;
    }
    // 如果index不满足物品件数这个条件的话
    dfs1(index + 1, sumW, sumC);
    dfs1(index + 1, sumW + w[index], sumC + c[index]);
}

void dfs2(int index, int sumW, int sumC)
{
    if (index == n1)
    {
        return;
    }
    dfs1(index + 1, sumW, sumC);
    if (sumW + w[index] <= V)
    {
        if (sumC + c[index] > ans)
        {
            ans = sumC + c[index];
        }
        dfs1(index + 1, sumW + w[index], sumC + c[index]);
    }
}
int main()
{
    // cin >> n;
    // n = 3;
    // dfs(0);
    // 输入物品件数以及背包容量
    // cin >> n1 >> V;
    n1 = 5, V = 8;
    

    dfs2(0, 0, 0);
    printf("%d\n", maxValue);
}