#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 输入: citations = [0,1,3,5,6]
 * 输出: 3 
 * 解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
 * 由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3;
*/

/**
 * 方法 1，已经排序，然后指数因子为s[i]的至少是n-i
*/
int hIndex(vector<int> &s)
{
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= (n - i))
            return n - i;
    }
    return 0;
}

/**
 * 方法 2，使用二分优化，
*/
int hIndex2(vector<int> &s)
{
    int n = s.size();
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (s[n - mid] >= mid)
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}

int main()
{
    vector<int> res = {0, 1, 3, 5, 6};
    cout << hIndex2(res) << endl;
}