#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/**
 * 847，对于一个图，求最短路径，每天边的权重是1，所以
 * 可以使用宽度优先搜索来找到最短路径
 * 这里宽度优先搜索的办法就是利用一个队列；
 * 然后存放队头元素，
 * 然后判断队列不是空，然后取出队头元素出来，
 * 扩展队头元素的所有邻接点，然后判断这个点有没有遍历过，如果没有，
 * 这个点入队，同时更新x的距离即可
 * 进行即可；
*/

const int N = 100010;
int h[N], e[N], ne[N], idx;
int d[N], q[N], n, m;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int bfs()
{
    int head = 0, rear = 0;
    q[0] = 1;
    memset(d, -1, sizeof d);
    d[1] = 0;
    while (head <= rear)
    {
        int t = q[head++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++rear] = j;
            }
        }
    }
    return d[n];
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
    }
    cout << bfs() << endl;
}