#include <iostream>
#include <vector>
using namespace std;
/**
 * 
 * 最长上升子序列问题 LIS (longest increase sequence)
 * 在一个数字序列中，找到最长的子序列保证它是不下降的
 * 例如 
 * 1 2 3 -1 -2 7 9
 * 不下降子序列是
 * 1 2 3 7 9
 * 长度是5
 * 
 * 设置一个数组d[i]表示以A[i]结尾的最长不下降子序列
 * a[i]之前的存在元素a[j]<=a[i]
 * 且 f[j] + 1 > f[i] j结尾的元素长度+1要大于以i结尾的元素
 * 满足上面两条
*/
const int N = 20;
int f[N]; // 状态情况
int g[N]; // 求出最长序列打印出来

int main()
{
    vector<int> a = {1, 2, 3, -1, -2, 7, 9, 10, -2, -9}; // 最长子序列是1,2,3,7,9,10
    int n = a.size();
    int maxnum = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1; // 边界初始条件
        g[i] = 0;
        for (int j = 0; j < i; j++)
        {
            // 写法 1
            // if (res[i] > res[j])
            //     d[i] = max(d[i], d[j] + 1);

            if (a[i] > a[j])
            {
                // 记录每个i是从j转移过来的
                if (f[i] < f[j] + 1)
                    g[i] = j, f[i] = f[j] + 1;
            }
        }
        maxnum = max(maxnum, f[i]); // 最长的序列数值
    }
    for (int i = 0; i <= n; i++)
        cout << g[i] << " ";
    cout << endl;
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[k] < f[i])
            k = i;
    }
    cout << f[k] << endl;
    for (int i = 0, len = f[k]; i < len; i++)
    {
        cout << a[k] << " ";
        k = g[k];
    }

    cout << maxnum << endl;
}

/**
 * 方法 2，使用优化来做
*/
 