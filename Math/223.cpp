#include <iostream>
#include <vector>
using namespace std;

/**
 * 223 找出矩形重叠面积之和
 * 对于一维的两个线段，分别是(a, b), (c, d) 求他们的交集的时候
 * min(b, d) - max(a, c) 就是交集的长度
 * 那么对于二维，只要分别把长和宽投影到一维即可
*/
class Solution
{
public:
    typedef long long LL;
    int computeArea(LL A, LL B, LL C, LL D, LL E, LL F, LL G, LL H)
    {
        LL y = max(0LL, min(D, H) - max(F, B));
        LL x = max(0LL, min(C, G) - max(A, E));
        return (D - B) * (C - A) + (H - F) * (G - E) - (x * y);
    }
};
