#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 克鲁斯卡尔算法来求最短路径
 * 
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
int findfather(int a)
{
    if (a != p[a]) p[a] = findfather(p[a]);
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
            p[fau] = fav;        // 集合合并
            res += w; //加上这两个顶点的边权
            num_edge++;          // 最小生成树的边数也自加1
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
    if(t==-1) cout<<"impossible"<<endl;
    else cout<<t<<endl;
}
