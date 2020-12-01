#include <iostream>
#include <vector>
#include "../../utils/cout_vec.h"
using namespace std;

/**
 * 802区间和
 * 可以用离散化来求解区间和，就是对于一个数字范围很大，但是数据长度
 * 范围不大的数组，把他们映射到有限长度的数组当中即可；
 * 输入样例：
 * 3 3
 * 1 2
 * 3 6
 * 7 5
 * 1 3
 * 4 6
 * 7 8
 * 输出样例：
 * 8
 * 0
 * 5
 * 首先下标的记录是从1开始，这里数组记录为：1，3，7，1，3，4，6，7，8；然后去重，得到需要用到的数组下标；[1，3，4，6，7，8]
 * 然后构造a元素数组，a[i] += 每个元素对的值，这里的i是在数组下标里面查找find(i)的位置+1，前缀和从1开始，需要写一个二分查找算法；
 * 然后进行计算前缀和s[i] = s[i-1] + a[i]
 * 
*/

/**
 * 方法 1，离散化
*/
typedef pair<int, int> cord;
const int N = 300010;
int a[N], s[N];

int find(int x, vector<int> &alls)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l + 1; // 映射到从1开始的前缀和
}

int main()
{
    // int n, m;
    // cin >> n >> m;
    // vector<int> alls; //待离散化的数组
    vector<int> alls = {1, 3, 7, 1, 3, 4, 6, 7, 8};
    vector<cord> add, query;

    // for (int i = 0; i < n; i++)
    // {
    //     int x, c;
    //     cin >> x >> c;
    //     add.push_back({x, c});
    //     alls.push_back(x);
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     int l, r;
    //     cin >> l >> r;
    //     query.push_back({l, r});
    //     alls.push_back(l);
    //     alls.push_back(r);
    // }
    add.push_back({1, 2});
    add.push_back({3, 6});
    add.push_back({7, 5});

    query.push_back({1, 3});
    query.push_back({4, 6});
    query.push_back({7, 8});
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    print(alls);

    // 处理插入，处理元素数组a
    for (auto item : add)
    {
        int x = find(item.first, alls);
        cout << "find x is: " << x << endl;
        a[x] += item.second;
    }

    // 构造前缀和数组s
    for (int i = 1; i <= alls.size(); i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    // 计算区间和部分
    for (auto item : query)
    {
        int l = find(item.first, alls), r = find(item.second, alls);
        cout << s[r] - s[l - 1] << endl;
    }
}