#include <iostream>
#include <vector>
using namespace std;
/**
 * 最长不下降子序列
 * 在一个数字序列中，找到最长的子序列保证它是不下降的
 * 例如 
 * 1 2 3 -1 -2 7 9
 * 不下降子序列是
 * 1 2 3 7 9
 * 长度是5
 * 
 * 设置一个数组d[i]表示以A[i]结尾的最长不下降子序列
*/
const int N = 20;
int d[N];
int main()
{
    vector<int> res = {1, 2, 3, -1, -2, 7, 9, 10, -2, -9}; // 最长子序列是1,2,3,7,9,10
    int n = res.size();
    int maxnum = 0;
    for (int i = 0; i < n; i++)
    {
        d[i] = 1; // 边界初始条件
        for (int j = 0; j < i; j++)
        {
            if (res[i] > res[j] && (d[j] + 1 > d[i]))
            {
                d[i] = d[j] + 1;
            }
        }
        maxnum = max(maxnum, d[i]);
    }
    cout << maxnum << endl;
}