#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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