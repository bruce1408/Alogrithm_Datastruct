#include <iostream>
#include <vector>
#include << algorithm>
using namespace std;

/**
 * 912 数组排序，给一个无序的数组， 然后排序即可
 * 这里直接使用快排的模板即可
*/

/**
 * 方法 1，使用快排
*/
void quick_sort(vector<int> &res, int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1;
    int x = res[(l + r) / 2];
    while (i < j)
    {

        while (res[++i] < x)
            ;
        while (res[--j] > x)
            ;
        if (i < j)
            swap(res[i], res[j]);
    }
    quick_sort(res, l, j);
    quick_sort(res, j + 1, r);
}

vector<int> sortArray(vector<int> &res)
{
    quick_sort(res, 0, res.size() - 1);
    return res;
}

int main()
{
    vector<int> res = {5, 2, 3, 1};
    sortArray(res);
}