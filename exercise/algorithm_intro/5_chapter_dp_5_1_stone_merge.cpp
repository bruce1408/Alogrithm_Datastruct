#include <iostream>
using namespace std;
/**
 * 282 石子合并，区间DP
*/
const int N = 310;
int f[N][N];
int n;
int s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];

    // 先循环区间长度，然后再循环左右端点
    for (int len = 2; len <= n; len++) 
    {
        for (int i = 1; i + len - 1 < n; i++)
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e9;
            for(int k = l; k<r;k++)
            {
                
            }
        }
    }
}