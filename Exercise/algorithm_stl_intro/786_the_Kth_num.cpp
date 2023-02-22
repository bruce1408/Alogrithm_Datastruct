#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 786 第k个数
 * 使用快速选择排序来求解第k个数字是多少
 * 思路就是先选择一个数字x，左边的数字都小于这个x且个数大于等于k的话，那么说明第k个数字在
 * 左边的区间，否则在右边区间
 * 
 * 这里主要注意递归的终止条件是l==r
 * 第二个是区间j作为参考边界，最后循环结束的时候一定是i>=j
 * 所以j是最小的边界，然后考虑j - l + 1 和k的大小，如果k小于这个数，那么说明在这个区间内，
 * 否则在另外一半的区间，k此时变成k-s1;
*/
const int N = 100010;
int a[N], n, k;

int quick_sort(int l, int r, int k)
{
    if (l == r)
        return a[l];
    int i = l - 1, j = r + 1;
    int x = a[l]; // 随机选择一个中枢值
    while (i < j)
    {
        while (a[++i] < x)
            ;
        while (a[--j] > x)
            ;
        if (i < j)
            swap(a[i], a[j]); // 交换两个数字
    }
    int sl = j - l + 1;
    if (sl >= k)
        return quick_sort(l, j, k);
    else
        return quick_sort(j + 1, r, k - sl);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cout << quick_sort(0, n - 1, k) << endl;

    return 0;
}