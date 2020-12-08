#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 图的遍历
 * 使用深度优先遍历 和 宽度优先遍历
*/
int n;
const int N = 100010, M = N * 2;
int h[N], value[N], ne[N], idx;
bool st[N]; // 是否已经遍历过了

// 在a的结点插入一条新的边b
void add(int a, int b)
{
    value[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void dfs(int u)
{
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
            dfs(j); // 如果这个点之前没有遇到，那么继续遍历这个点
    }
}
int main()
{
    memset(h, -1, sizeof h);
    dfs(1);
}