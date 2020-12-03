#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
int s[N], point;
/**
 * 830
 * 单调栈算法，求一个数组左边第一个比它还小的数，如果存在输出这个数字
 * 否则输出-1即可；
*/
int main()
{
    int n = 5;
    // cin >> n;
    vector<int> temp = {3, 4, 2, 7, 5};
    for (int i = 0; i < n; i++)
    {
        // int x;
        // cin >> x;
        int x = temp[i];
        while (point && s[point] >= x)
            point--;
        if (point)
            cout << s[point] << " ";
        else
            cout << -1 << " ";
        s[++point] = x;
    }
}