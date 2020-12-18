#include <iostream>
#include <vector>
using namespace std;

/**
 * 求质数：质数也叫素数，就是可以被1和自己整除，同时必须大于1的整数
 * 方法 1，使用暴力解法，时间复杂度是O(n)
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
 * 方法 2，
*/
void prim(int x)
{
    if (x < 2)
        cout << "No" << endl;
    else
    {
        for (int i = 2; i <= x/i; i++)
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