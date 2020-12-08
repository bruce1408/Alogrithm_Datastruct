#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
/**
 * 图的遍历
 * 使用深度优先遍历 和 宽度优先遍历
*/
int n;
const int N = 100010, M = N * 2;
int h[N], value[M], ne[M], idx;
bool st[N]; // 是否已经遍历过了
int ans = N;

// 在a的结点插入一条新的边b
void add(int a, int b)
{
    value[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

// 返回以u为根节点的子树的大小
int dfs(int u)
{
    st[u] = true;
    int sum = 1, res = 0; // sum表示当前节点个数， res 表示连通块的大小的最大值
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = value[i];
        if (!st[j])
        {
            int s = dfs(j); // 如果这个点之前没有遇到，那么继续遍历这个点
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}
int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
}