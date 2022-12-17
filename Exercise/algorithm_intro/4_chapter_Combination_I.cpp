#include <iostream>
#include <vector>
using namespace std;
const int N = 110;
vector<int> res(N, 0);

/**
 * 求解n！共有多少质因子，比如
 * 6！ = 1*2*3*4*5*6
 * 质因子2的个数是4， 质因子3的个数是2
 * 2里面是1个，4里面是2个，6里面是1个
 * 3里面是1个，6里面是1个，所以分别是4和2
*/

/**
 * 方法 1，求解所有的质因子个数
 * 先遍历1-n所有数字，然后再对其进行质因子分解，即可求得每个数的质因子，然后
 * 累加求得最后的质因子个数
*/
void cal1(int n)
{
    for (int t = 1; t <= n; t++)
    {
        int x = t;
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                while (x % i == 0)
                {
                    res[i]++;
                    x /= i;
                }
            }
        }
        if (x > 1) // 最后若x大于1是剩下的那个质因数
            res[x] += 1;
    }
    for (int i = 2; i <= 6; i++)
    {
        cout << i << " " << res[i] << endl;
    }
}

/**
 * 方法 2，求质因子p的个数
*/
int cal2(int n, int p)
{
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int temp = i;
        while (temp % p == 0)
        {
            ans++;
            temp /= p;
        }
    }
    return ans;
}

/**
 * 方法 3，优化使用公式
 * n！ = n/p + n/p^2 + n/p^3 + .... 个质因子p
 * 向下取整
 * 利用上面这个公式可以很快的算出n！末尾有多少个0，时间复杂度是O(logn)的时间复杂度
*/
int cal3(int n, int p)
{
    int ans = 0;
    while (n)
    {
        ans = ans + n / p;
        n = n / p;
    }
    return ans;
}

/**
 * 方法 4，继续优化
 * n！中质因子的个数，实际上等于1-n中p的倍数的个数n/p 加上 n/p!中质因子p的个数
*/
int cal4(int n, int p)
{
    if (n < p)
        return 0;
    return cal4(n / p, p) + n / p;
}

int main()
{
    int n = 6;
    // cal1(n); // 计算所有的质因数的个数
    cout << cal3(10, 2) << endl;
}