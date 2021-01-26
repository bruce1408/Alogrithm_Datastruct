#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1000010;
/**
 * 单调队列问题
 * 最小值和最大值分开来做，两个for循环完全类似，都做以下四步：
 * 
 * 解决队首已经出窗口的问题;
 * 解决队尾与当前元素a[i]不满足单调性的问题;
 * 将当前元素下标加入队尾;
 * 如果满足条件则输出结果;
 * 
 * 需要注意的细节：
 * 上面四个步骤中一定要先3后4，因为有可能输出的正是新加入的那个元素;
 * 队列中存的是原数组的下标，取值时要再套一层，a[q[]];
 * 算最大值前注意将hh和tt重置;
 * 此题用cout会超时，只能用printf;
 * hh从0开始，数组下标也要从0开始。
*/

int q[8];
int main()
{
    int n = 8, m = 3;
    int head = -1, rear = -1;
    int a[8] = {1, 3, -1, -3, 5, 3, 6, 7};
    for (int i = 0; i < n; i++)
    {
        // 队列头部是否滑出了窗口，然后看起点大于的话，那么就head++
        if (head != rear && i - m + 1 > q[head + 1])
            head++;
        // 新插入的数字如果小于队尾的话，那么就
        while (head != rear && a[q[rear]] >= a[i])
            rear--;
        q[++rear] = i;
        cout << "head: " << head << endl;
        if (i >= m - 1) // 前m个数字就输出，不足m个数字就不用输出
            printf("%d ", a[q[head + 1]]);
    }
    cout << endl;
    head = -1, rear = -1;
    for (int i = 0; i < n; i++)
    {
        if (head != rear && i - m + 1 > q[head + 1])
            head++;
        while (head != rear && a[q[rear]] <= a[i])
            rear--;
        q[++rear] = i;
        if (i >= m - 1) // 前m个数字就输出，不足m个数字就不用输出
            printf("%d ", a[q[head + 1]]);
    }
    cout << endl;
}