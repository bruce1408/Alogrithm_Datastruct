#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/**
 * 大数除法，高精度整数除以低精度数
 * 首先就是初始化余数，让余数为0，然后开始余数*10 + 当前数字，组成被除数，然后除以除数，商就
 * 存放到结果数组当中去，然后余数对除数进行求余，得到的结果就是下一个余数：
 * 比如 1234/11, 余数*10 + a[0] = 0*10 + 1 = 1,不够10进行整除，所以结果数组保存0，然后余数是1，
 * 下一次余数就是 1* 10 + 2 = 12 ，正好够11整除，然后结果是1，保存到结果数组，余数是1，接着遍历，最后
 * 得到的结果是数组的低位保存的是数字的高位，我们希望和加法类似，数组的0位保存个位算起，把结果数组取反，然后
 * 在去除前缀0，然后输出数组结果和最后的余数即可
 * 
*/
vector<int> div(vector<int> &res1, int res2, int &r)
{
    vector<int> res;
    r = 0;
    for (int i = res1.size() - 1; i >= 0; i--)
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
    cout << "请输入两个数，被除数和除数： " << endl;
    cin >> a >> b;
    vector<int> res1;
    for (int i = a.size() - 1; i >= 0; i--)
        res1.push_back(a[i] - '0');

    int c = 0;
    auto res = div(res1, b, c);
    for (int i = res.size() - 1; i >= 0; i--)
        printf("%d", res[i]);
    cout << endl
         << c << endl;
}