#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 区间合并：
 * 主要思路就是维护一个l表示左端点，r表示右端点的区间
 * 对所有的区间端点进行排序，这里使用结构体来进行模型区间数据结构，
 * 然后按照左端点进行升序排序，然后开始去维护一个区间端点；
 * 默认这个端点是第一个区间，然后遍历后面的区间端点，和这个端点进行比较
 * 如果当前的端点的左侧l在维护区间的范围内，那么可以合并，然后维护的区间
 * 变成左侧不变，右端点变成max(维护区间的右端点, 当前区间右端点)求最大，
 * 否则，那么更新维护区间端点为当前区间端点；计数加1即可；
*/
struct cord
{
    // 结构体在做vector数据类型的时候初始化列表报错
    int l, r;
    // cord(int x, int y) : l(x), r(y) {}
};

bool cmp(cord a, cord b)
{
    return a.l < b.l;
}

int main()
{
    int n = 5;
    // cin >> n;
    vector<cord> res(n);
    // for (int i = 0; i < n; i++)
    // {
    //     int l, r;
    //     cin >> l >> r;
    //     res[i].l = l, res[i].r = r;
    // }
    res[0].l = 1, res[0].r = 2;
    res[1].l = 2, res[1].r = 4;
    res[2].l = 5, res[2].r = 6;
    res[3].l = 7, res[3].r = 8;
    res[4].l = 7, res[4].r = 9;

    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << res[i].l << " " << res[i].r << endl;
    }

    int count = 1, l = res[0].l, r = res[0].r;
    for (int i = 1; i < n; i++)
    {
        if (l <= res[i].l && res[i].l <= r)
        {
            r = max(res[i].r, r);
        }
        else
        {
            l = res[i].l, r = res[i].r;
            count += 1;
        }
    }
    cout << count << endl;
}