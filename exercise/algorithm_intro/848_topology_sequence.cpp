#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


/**
 * 拓扑序列：
 * 有向图，所有的边都是从前指向后的，
 * 只要是有一个环的话，那么一定不存在拓扑序列，
 * 可以证明有向无环图被称为拓扑图
 * 有向图的度数：入度、出度
 * 入度表示多少条边指向自己，
 * 出度表示多少条边出去；
 * 
 * 所以所有入度为0的点可以作为起点，那么就是找到所有入度为0的点
 * 入队
 * 然后接着进行宽搜的类型； 
*/

const int N  = 100010;
int n, m;
int h[N], e[N], ne[N];
int q[N], d[N], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx; 
    idx++;
}

bool topsort()
{
    int head = 0, rear = -1;
    for(int i=1;i<=n;i++)
    {
        if(!d[i])
        {
            q[++rear] = i;
        }
    }
    while(head<=rear)
    {
        int t = q[head++];
        for(int i= h[t];i!=-1;i=ne[i])
        {
            int j = e[i];
            d[j]--;
            if(d[j]==0)
            {
                q[++rear] = j;
            }
        }
    }
    return rear == n-1;
}

int main()
{
    cin>>n>>m;
    memset(h, -1, sizeof h);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        add(a, b);
        d[b]++; // 入度+1
    }
    if(topsort())
    {
        for(int i=0; i<n; i++)
        {
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
}