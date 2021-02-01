#include <iostream>
using namespace std;

/**
 * 丑数II
 * 1是比较特殊的丑数，其他丑数都是2，3，5的倍数
 * 所以每次找到这三个数的倍数的最小值保存进临时数组，然后如果当前最小值等于某个数的倍数的时候
 * 那么就当前指针+1即可
*/
int nthUglyNumber(int n)
{
    vector<int> res(1, 1);
    for (int i = 0, j = 0, k = 0; res.size() < n;)
    {
        int t = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
        res.push_back(t);
        if (res[i] * 2 == t)
            i++;
        if (res[j] * 3 == t)
            j++;
        if (res[k] * 5 == t)
            k++;
    }
    return res.back();
}
