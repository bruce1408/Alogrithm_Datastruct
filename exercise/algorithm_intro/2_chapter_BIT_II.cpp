#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utils/cout_vec.h"
using namespace std;

#define lowbit(i) ((i) & (-i))
const int N = 100010;
struct node
{
    int val; // 序列元素的值
    int pos; //原始序号
} temp[N];

int a[N], c[N];

void update(int x, int v)
{
    for (int i = x; i < N; i += lowbit(i))
        c[i] += v;
}

int getSum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

bool cmp(node a, node b)
{
    return a.val < b.val;
}

int main()
{
    // 数据初始化
    temp[0].val = 999999, temp[0].pos = 0;
    temp[1].val = 18, temp[1].pos = 1;
    temp[2].val = 666, temp[2].pos = 2;
    temp[3].val = 8888, temp[3].pos = 3;
    temp[4].val = 23, temp[4].pos = 4;
    int n = 5;
    // 离散化部分，必须是按照从小到大排序
    sort(temp, temp + 5, cmp); // 按照val升序排序
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || temp[i].val != temp[i - 1].val)
            a[temp[i].pos] = i + 1;
        else
            a[temp[i].pos] = a[temp[i - 1].pos];
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // 正式开始求和
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        update(a[i], 1);
        res.push_back(getSum(a[i] - 1));
    }
    cout << "左边小于该元素的个数" << endl;
    print(res);
}
