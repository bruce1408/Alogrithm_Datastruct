#include <iostream>
#include <vector>
// #include "../Utils/cout_vec.h"
using namespace std;

/**
 * 快速排序1，推荐写法, 可作为模板
 * 1、首先确定递归终止条件
 * 2、确定pivot中枢值是多少，一般取左边界，有边界，或者是中间的某个数，异或是根据其他规则来确定都可以
 * 3、希望把数组分成两份，利用双指针，i从左边界开始到中间，j从右边界开始到中间，按照pivot左边的都小于这个值，右边的都大于这个值，
 * 4、如果i和j要是相遇或者i>j的话，那么退出，否则交换i和j的值，然后i继续自加，j继续自减一位即可；
 * 5、最后继续递归遍历，左边的从l到j，右边的从j+1到r，这里因为不选择i的原因是，可能i最后大于j，选择i可能指向最后一位死循环
*/
void quickSort1(vector<int> &q, int l, int r)
{
    if (l >= r)
        return;
    int x = q[(l + r) >> 1], i = l, j = r;
    while (1)
    {
        while (q[i] < x)
            i++;
        while (q[j] > x)
            j--;
        if (i >= j)
            break;
        swap(q[i], q[j]);
        i++, j--;
    }
    cout << i << " " << j << endl;
    quickSort1(q, l, j); // 这个地方不能把j换成i，否则可能死循环
    quickSort1(q, j + 1, r);
}

int main()
{
    vector<int> res = {49, 59, 88, 37, 98, 97, 68, 54, 31, 3};
    int n = res.size();
    quickSort1(res, 0, n - 1);
    for (auto x : res)
        cout << x << " ";
}