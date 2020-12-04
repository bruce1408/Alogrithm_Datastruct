#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;

/**
 * 双向链表的操作指南,e表示值是多少，l表示左边的点，r表示右边的点
 * idx表示指向的当前工作的点
 * */
int head, l[N], r[N], e[N], tail;

void init()
{
    
    // 0表示左端点，1表示右端点,0的右边是1，1的左边是0，idx从2开始
    r[0] = 1;
    l[1] = 0;
    idx = 2;


}

// 链表插入，这里指针指向某个节点就是直接复制。
void insert(int x)
{
    e[idx] = x;
    ne[idx] = head; // 这里就相当于ne[idx] = head->next;
    head = idx;     // 然后head指向idx
    idx++;
}

// 在第k个点的后面插入
void insert_k(int x, int k)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 链表删除操作,下标是k的点后面的删掉
void delete_k(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m;
    init();

    while (m--)
    {
        int x, k;
        char op;
        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            insert(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (k == 0)
                head = ne[head];
            else
                delete_k(k - 1);
        }
        else
        {
            cin >> k >> x;
            insert_k(x, k - 1);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
    cout << endl;
}