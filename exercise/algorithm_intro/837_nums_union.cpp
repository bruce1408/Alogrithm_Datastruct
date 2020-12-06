#include <iostream>
using namespace std;

const int N = 1000010;
int p[N], se[N]; //size表示集合的大小

int find(int x)
{
    // 这里就是包含了路径压缩的算法
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    while (m--)
    {
        int op;
        cin >> op;
        int x1, x2;
        if (op == 1)
        {
            cin >> x1 >> x2;
            // x1 = find(x1), x2 = find(x2);
            if (find(x1) != find(x2))
            {
                se[find(x2)] += se[find(x1)]; // 这里注意先加后合并
                p[find(x1)] = find(x2);       // x1的父节点指向x2
            }
        }
        else if (op == "Q1")
        {
            cin >> x1 >> x2;
            if (find(x1) == find(x2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> x1;
            cout << se[find(x1)] << endl;
        }
    }
}