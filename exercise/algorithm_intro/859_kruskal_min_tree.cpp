#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 克鲁斯卡尔算法来求最短路径,
 *      该算法的基本思想就是：
 *      对所有边权按照从小到大的顺序进行排序
 *      按照边权从小到大测试所有边，如果当前测试的所连接两个顶点都不在一个连通块，则把这条边测试加入最小生成树，否则就舍弃
 *      然后继续执行上一步，直到最小生成树边数等于总顶点数-1或者是测试完所有边是结束，而当结束时候如果最小生成树边数小于总
 *      顶点数-1，说明该图不连通
 * 这里确定两个顶点是否是在一个集合中，我们使用并查集的概念来做，通过查询父节点是不是一个节点来判断当前是否在同一个集合中。
 * kruskal算法主要的时间复杂度来自于对边的排序，时间复杂度是O(mlogm)，如果是稠密图边多的情况，那么适合使用prim算法，
 * 如果是稀疏图边少的情况，适合使用kruskal算法。
*/
int n, m;
const int N = 100010;
const int M = 200010;
const int inf = 1e9;
int p[N]; // g表示从u到v边权，p表示并查集中的父节点所存放的数组

struct edge
{
    int u, v; // 边的两个端点编号
    int cost; // 边权
} e[M];

bool cmp(edge a, edge b)
{
    return a.cost < b.cost; // 对边权按照从小到大排序
}

/**
 * 带路径压缩的找父节点的方法
*/
int findfather(int
        p[a] = findfather(p[a]);
    return p[a];
}

int kruskal()
{
    // ans 表示的是边权之和 num_edge 为当前生成树的边数
    int res = 0, num_edge = 0;
    sort(e, e + m, cmp); // 对所有边权进行从小到大排序
    for (int i = 1; i <= n; i++)
        p[i] = i;               // 初始化并查集父节点保存数组
    for (int i = 0; i < m; i++) // 枚举所有的边
    {
        int fau = findfather(e[i].u);
        int fav = findfather(e[i].v);
        int w = e[i].cost;
        if (fau != fav) // 两个端点不在同一个集合
        {
            p[fau] = fav; // 集合合并
            res += w;     //加上这两个顶点的边权
            num_edge++;   // 最小生成树的边数也自加1
            // if (num_edge == n - 1)
            //     break; //边数等于顶点数-1结束算法
        }
    }
    if (num_edge < n - 1)
        return -1;

    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[i].u = a, e[i].v = b, e[i].cost = c;
    }

    int t = kruskal();
    if (t == -1)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    if(t==-1) cout<<"impossible"<<endl;
    else cout<<t<<endl;
}
