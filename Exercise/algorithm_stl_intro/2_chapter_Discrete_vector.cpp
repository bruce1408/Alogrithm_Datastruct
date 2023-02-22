#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utils/cout_vec.h"
using namespace std;
const int N = 100010;
/**
 * 对一个数组进行离散化
 * 如果是               9999, 201920, 23, 2, 450
 * 离散化之后的数组是     4，5，2，1，3
 * 可以使用树状数组来做题
*/
struct node
{
    int val;
    int pos;
} temp[N];

bool cmp(node a, node b)
{
    return a.val < b.val;
}

int main()
{
    vector<int> res = {9999, 201920, 23, 2, 450};
    for (int i = 0; i < res.size(); i++)
    {
        temp[i].val = res[i];
        temp[i].pos = i;
    }
    vector<int> ds(res.size());
    sort(temp, temp + res.size(), cmp);

    for (int i = 0; i < res.size(); i++)
    {
        if (i == 0 || temp[i - 1].val != temp[i].val)
            ds[temp[i].pos] = i + 1;
        else
            ds[temp[i].pos] = ds[temp[i - 1].pos];
    }
    print(ds);
}