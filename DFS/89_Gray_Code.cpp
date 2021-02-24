#include <iostream>
#include <vector>
using namespace std;

/**
 * 89 给定一个整数n，然后生成格雷码
*/

/**
 * 方法 1，归纳，
 * 如果n=0，那么格雷码就是0
 * 如果n=1，那么格雷码就是0， 1两个数字
 * 如果n=2，那么就把上个格雷码的结果拿来然后镜像复制一次，
 * 前半部分最后加0，后半部分最后加1即可
*/
vector<int> grayCode(int n)
{
    vector<int> res(1, 0);
    while (n--)
    {
        for (int i = res.size() - 1; i >= 0; i--)
        {
            res[i] *= 2;
            res.push_back(res[i] + 1);
        }
    }
    return res;
}
