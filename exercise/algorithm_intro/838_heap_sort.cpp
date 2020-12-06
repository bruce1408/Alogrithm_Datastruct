
#include <iostream>
using namespace std;

const int N = 100010;
int h[N], se;

/**
 * 堆排序，构建堆，使用down 或者是 up 操作来插入元素然后
 * 保证调整新插入之后的元素依然是大顶堆或者是小顶堆
*/
void down(int index)
{
    int t = index;

    if (2 * index <= se && h[2 * index] < h[t])
        t = 2 * index;
    if (2 * index + 1 <= se && h[2 * index + 1] < h[t])
        t = 2 * index + 1;
    if (index != t)
    {
        swap(h[t], h[index]);
        down(t);
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
