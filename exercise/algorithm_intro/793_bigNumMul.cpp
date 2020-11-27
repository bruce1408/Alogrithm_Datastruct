#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 大数乘法：
 * A*b，A可能是一个很大越界的数字，b是一个小数，每次乘法的时候不是乘b的每一位
 * 而是乘以整个数字b，初始进位设置为0，然后每次考虑到进位 t = A[i] * b + t(上次的进位)
 * 这里开辟一个存放结果的数组res，res保存t%10余数，新的进位是t/10得到的；
 * 最后判断是否有t进位大于0，如果大于0的话，那么存放res，然后去除前导0；返回结果数组
*/
vector<int> mul(vector<int> &res1, int res2)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < res1.size(); i++)
    {
        t = res1[i] * res2 + t;
        res.push_back(t % 10);
        t /= 10;
    }
    if (t > 0)
        res.push_back(t);
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    return res;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> res1;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        res1.push_back(a[i] - '0');
    }
    auto res = mul(res1, b);
    for (int i = res.size() - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    cout << endl;
}