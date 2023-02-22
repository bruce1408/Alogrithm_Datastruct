#include <iostream>
#include <vector>
using namespace std;

/**
 * 大数加法，两个很大的数字A+B，可能会越界，那么使用数组来存储，然后按照
 * 平常加法一样计算法即可，注意进位和最后一位是否有进位；
 * 这里为了计算方便，数字的首位一般是最高位，因为考虑进位，我们把首位当成最低位即可；
*/

vector<int> sum(vector<int> &a, vector<int> &b)
{
    int t = 0;
    vector<int> res;
    for (int i = 0; i < a.size() || i < b.size(); i++)
    {
        if (i < a.size())
            t += a[i];
        if (i < b.size())
            t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if (t)
        res.push_back(1);
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> res1;
    vector<int> res2;
    for (int i = a.size() - 1; i >= 0; i--)
        res1.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        res2.push_back(b[i] - '0');
    auto res = sum(res1, res2);
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << "";
    }
    cout << endl;
}