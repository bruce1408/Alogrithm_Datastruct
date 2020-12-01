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
    int n;
    cin >> n;
    vector<cord> res(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        res[i].l = l, res[i].r = r;
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << res[i].l << " " << res[i].r << endl;
    }

    int count = 1, l = res[0].l, r = res[0].r;
    for(int i=1; i<n; i++)
    {
        if(l<= res[i].l <= r)
        {
            r = max(res[i].r, r);
        }

    }
}