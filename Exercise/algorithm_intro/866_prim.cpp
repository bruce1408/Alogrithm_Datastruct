#include <iostream>
#include <vector>
using namespace std;

/**
 * 使用试除法来判定素数
 * 求质数：质数也叫素数，就是可以被1和自己整除，同时必须大于1的整数
 * 方法 1，使用暴力解法，就是只要在2到n-1之间存在可以被n整除的数，那么就不是素数
 * 否则就是素数，这个算法的时间复杂度是O(n)
 * 可以优化：
*/
void prim(int x)
{
    if (x < 2)
        cout << "No" << endl;
    else
    {
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}
/**
 * 方法 2，优化素数的判定，因为假如在2到n-1之间存在可以被整除的数k
 * 那么n/k也可以被整除，因为约数都是成对出现的，而且k和n/k肯定有一个
 * 满足大于根号n，一个小于根号n，这就启发我们，只要判定n能否被2,3根号n
 * 一个整除即可，即可判定是否是素数。这里不写根号的原因是计算消耗时间，
 * 所以改成n/k即可；
*/
void prim(int x)
{
    if (x < 2)
        cout << "No" << endl;
    else
    {
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int n;
int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        prim(x);
    }
}