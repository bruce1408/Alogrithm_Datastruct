#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 高精度减法,保证a的长度大于b的长度，否则算b-a
 * 和高精度加法类似，都是需要一个数组来保存，然后还需要记录是否有没有借位；
 * 每一位其实是a[i] - b[i] - t,
*/

/**
 * 判断a是否大于等于b的情况
*/
bool cmp(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    else
    {
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] != b[i])
                return a[i] > b[i];
        }
    }
    return true; // 所有的数都相同也返回true
}

vector<int> sub(vector<int> &a, vector<int> &b)
{
    int t = 0;
    vector<int> res;
    for (int i = 0; i < a.size(); i++)
    {

        t = a[i] - t;
        if (i < b.size())
            t -= b[i];
        res.push_back((t + 10) % 10); // 这里主要是两种情况，要么是t<0,那么就要借位，t+10 % 10，否则 t>=0 就是 t % 10;
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    // 考虑最后结果去除前导0
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
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
    if (cmp(res1, res2))
    {
        auto res = sub(res1, res2);
        for (int i = res.size() - 1; i >= 0; i--)
            printf("%d", res[i]);
    }
    else
    {
        auto res = sub(res2, res1);
        printf("-");
        for (int i = res.size() - 1; i >= 0; i--)
            printf("%d", res[i]);
    }
    cout << endl;
}