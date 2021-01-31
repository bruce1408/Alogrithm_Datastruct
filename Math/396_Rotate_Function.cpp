#include <iostream>
#include <vector>
using namespace std;

/**
 * 396 旋转函数，数组旋转之后乘以0开头的数字，求最大的数字
*/

/**
 * 方法 1，按照下标旋转的方式来做，暴力来做超时
*/
int maxRotateFunction(vector<int> &A)
{
    if (A.empty())
        return 0;
    int n = A.size();
    long long res = INT_MIN;
    for (int i = n; i >= 1; i--)
    {
        long long temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp += j * A[(i + j) % n];
        }
        res = max(res, temp);
    }
    return res;
}

/**
 * 方法 2，找规律
 * 好了，来解题吧，我们为了找规律，先把具体的数字抽象为A,B,C,D，那么我们可以得到：
 *
 * F(0) = 0A + 1B + 2C +3D
 * F(1) = 0D + 1A + 2B +3C
 * F(2) = 0C + 1D + 2A +3B
 * F(3) = 0B + 1C + 2D +3A
 * 
 * 那么，我们通过仔细观察，我们可以得出下面的规律：
 * sum = 1A + 1B + 1C + 1D
 * 
 * F(1) = F(0) + sum - 4D
 * F(2) = F(1) + sum - 4C
 * F(3) = F(2) + sum - 4B
 * 那么规律是
 * F(i) = F(i-1) + sum - n*A[n-i]，可以写出代码如下
*/
typedef long long LL;
int maxRotateFunction2(vector<int> &A)
{
    LL sum = 0, cur = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        cur += i * A[i];
        sum += A[i];
    }
    LL res = cur;
    for (int i = n - 1; i >= 0; i--)
    {
        cur += sum - (LL)n * A[i];
        res = max(cur, res);
    }
    return res;
}

int main()
{
    vector<int> res = {4, 3, 2, 6};
    cout << maxRotateFunction2(res) << endl;
}