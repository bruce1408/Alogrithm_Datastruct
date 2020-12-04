#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;

/**
 * 双向链表的操作指南,e表示值是多少，l表示左边的点，r表示右边的点
 * idx表示指向的当前工作的点
 * */
int l[N], r[N], e[N], idx;

void init()
{
    // 0表示左端点，1表示右端点,0的右边是1，1的左边是0，idx从2开始
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

// 双向链在节点k的右边插入一个数
void insert(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    r[l[k]] = idx;
    r[k] = idx++;
}

// 链表删除操作, 删除第k个点
void delete_k(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int m;
    cin >> m;
    init();

    while (m--)
    {
        int x, k;
        string op;
        cin >> op;
        if (op == "L")
        {
            cin >> x;
            insert(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            delete_k(k + 1);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
    cout << endl;
}