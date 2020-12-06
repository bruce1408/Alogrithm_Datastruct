#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 100010;
int h[N], cnt, ph[N], hp[N];
/**
 * 这里构造堆的情况加入了一个复杂的操作，就是第k个数插入和删除
 * 这里就需要记录，类似链表一样，记录第k个数
*/
void heap_swap(int i, int j)
{
    swap(ph[hp[i]], ph[hp[j]]);
    swap(hp[i], hp[j]);
    swap(h[i], h[j]);
}
void down(int index)
{
    int t = index;

    if (2 * index <= cnt && h[2 * index] < h[t])
        t = 2 * index;
    if (2 * index + 1 <= cnt && h[2 * index + 1] < h[t])
        t = 2 * index + 1;
    if (index != t)
    {
        heap_swap(t, index);
        down(t);
    }
}

void up(int index)
{
    while (index / 2 && h[index] > h[index / 2])
    {
        heap_swap(index, index / 2);
        index /= 2;
    }
}

int main()
{
    int n, m = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int k, x;
        if (s == "I")
        {
            cin >> x;
            cnt++; // 堆里面多一个元素
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if (op == "PM")
        {
            cout << h[1] << endl;
        }
        else if (op == "DM")
        {
            heap_swap(1, cnt);
            size--;
            down(1);
        }
        else if (op == "D")
        {
            cin >> k;
            k = ph[k]; // 找到它在堆里面的位置
            heap_swap(k, 1);
            size--;
            down(k), up(k);
        }
        else
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
}
