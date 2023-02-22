#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/**
 * 拓扑序列：有向图才有拓扑序列
 * 
 * 有向图，所有的边都是从前指向后的，
 * 只要是有一个环的话，那么一定不存在拓扑序列，
 * 可以证明 有向无环图 被称为 拓扑图
 * 有向图的度数：入度、出度
 * 
 * 入度表示多少条边指向自己，
 * 出度表示多少条边出去；
 * 
 * 所以所有入度为0的点可以作为起点，那么就是找到所有入度为0的点入队
 * 然后接着进行宽搜的类型； 
 * 
*/

const int N = 100010;
int n, m;
int h[N], e[N], ne[N];
int q[N], indegree[N], idx;

void add(int a, int b) // 在节点a插入新的节点b
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool topsort()
{
    int head = -1, rear = -1; // head 是-1或者是0都可以
    // 判断所有节点，如果入度为0的话那么入队
    for (int i = 1; i <= n; i++)
    {
        if (!indegree[i])
        {
            q[++rear] = i; // q的下表是0开始，而节点是从1开始
        }
    }
    // dfs 遍历过程
    while (head <= rear)
    {
        int t = q[head++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            indegree[j]--; // 这个节点的入度-1；
            if (indegree[j] == 0)
            {
                q[++rear] = j;
            }
        }
    }
    // 最后入队的个数等于节点个数那么就是对的，这里rear从-1算起，所以是n-1
    return rear == n - 1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        indegree[b]++; // 在a插入新的节点b，所以a->b,因此b的入度+1
    }

    if (topsort())
    {
        for (int i = 0; i < n; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
}