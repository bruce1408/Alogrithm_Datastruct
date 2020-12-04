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
    /**
     * 最开始的时候，链表的头节点要指向-1，
     * 为的就是在后面进行不断操作后仍然可以知道链表是在什么时候结束
     * 个人认为head其实就是一个指针，是一个特殊的指针罢了。
     * 刚开始的时候它负责指向空结点，在链表里有元素的时候，
     * 它变成了一个指向第一个元素的指针
     * 当它在初始化的时候指向-1，来表示链表离没有内容
    */
    head = -1; // 头结点是空的-1，然后idx是从0号开始分配

    /**
     * idx在我看来扮演两个角色，第一个是在一开始的时候，作为链表的下标，
     * 让我们好找,第二在链表进行各种插入，删除等操作的时候，
     * 作为一个临时的辅助性的所要操作的元素的下标来帮助操作。
     * 并且是在每一次插入操作的时候，给插入元素一个下标，
    */
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
            if (k == 0) // 如果删除头结点的话，那么头结点下一个节点
                head = ne[head];
            else
                delete_k(k - 1); // 下标从0开始的，第一个插入的点是0， 第k个插入点是k-1
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