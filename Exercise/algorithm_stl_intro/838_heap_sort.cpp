
#include <iostream>
using namespace std;

const int N = 100010;
int h[N], se;

/**
 * 堆排序，构建堆，使用down 或者是 up 操作来插入元素然后
 * 保证调整新插入之后的元素依然是大顶堆或者是小顶堆
 * 本题使用的是最小堆，然后每个根节点的值小于等于左右孩子节点即可
*/
void down(int index)
{
    // 临时变量t保存最开始的index
    int t = index;
    // index 是否终于左孩子节点且左孩子节点值最小
    if (2 * index <= se && h[2 * index] < h[t])
        t = 2 * index; // 左孩子节点赋值给t
    // index 节点是否有右孩子节点且右孩子节点值最小
    if (2 * index + 1 <= se && h[2 * index + 1] < h[t])
        t = 2 * index + 1; // 右孩子节点赋值给t
    if (index != t)        // 如果index和当前的t不相等，说明需要交换
    {
        swap(h[t], h[index]);
        down(t); // 交换之后再从t继续判断；
    }
}

void up(int u)
{
    while(u/2 && h[u] < h[u/2])
    {
        swap(h[u], h[u/2]);
        u/=2;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    se = n;
    for (int i = n / 2; i >= 0; i--)
    {
        down(i);
    }

    while (m--)
    {
        cout << h[1] << " ";
        h[1] = h[se];
        se--;
        down(1);
    }
}
