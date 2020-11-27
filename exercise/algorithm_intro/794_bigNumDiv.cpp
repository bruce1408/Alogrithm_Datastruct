#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * 大数除法
 * 
*/
vector<int> div(vector<int> &res1, int res2)
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