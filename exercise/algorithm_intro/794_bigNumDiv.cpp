#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/**
 * 大数除法，高精度整数除以低精度数
 * 
*/
vector<int> div(vector<int> &res1, int res2, int &r)
{
    vector<int> res;
    r = 0;
    for (int i = res1.size(); i >= 0; i--)
    {
        r = r * 10 + res1[i]; // 余数
        res.push_back(r / res2);
        r %= res2;
    }
    reverse(res.begin(), res.end());
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
    int c;
    auto res = div(res1, b, c);
    for (int i = res.size() - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    cout << endl
         << c << endl;
}