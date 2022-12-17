#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 字符串处理部分，分别是处理间隔为1，长度是k的字符串；
 * 第二个处理函数是滑动窗口处理，每次滑窗步长为1，窗口长度大小为k
*/
void interval_K(string s, int k)
{
    cout << "间隔为1，长度为k个字符打印出来：" << endl;
    int n = s.size();
    for (int i = 0; i <= n - k; i += k)
    {
        cout << s.substr(i, k) << endl;
    }
}

void continus_K(string s, int k)
{
    cout << "类似于字符串的滑动窗口" << endl;
    int n = s.size();
    for (int i = 0; i <= n - k; i++)
    {
        cout << s.substr(i, k) << endl;
    }
}

int main()
{
    string s = "abcdefg";
    int k = 2;
    interval_K(s, k);
    continus_K(s, k);
}
