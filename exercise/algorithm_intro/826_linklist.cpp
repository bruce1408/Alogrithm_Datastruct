#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;

/**
 * head表示的是头结点，e[i]表示节点的值，ne[i]表示next指针,
 * idx表示当前可用插入指针位置
 * */
int head, e[N], ne[N], idx;

void init()
{
    head = -1; // 头结点是空的-1，然后idx是从0号开始分配
    idx = 0;
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