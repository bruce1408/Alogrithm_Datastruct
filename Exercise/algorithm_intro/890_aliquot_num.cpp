#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 20;
int p[N];
/**
 * 890 能被整除的数
 * 使用容斥原理，两个集合的容斥原理 A U B = A + B - AB，这是两个集合，一共是3项
 * 假设是n个集合的话，那么总共有2^n-1项
 * 思路就是首先设置一个数组，来存放m个质数
 * 然后遍历每一项，从1——2^m-1,然后这里可以使用位移运算，
 * 每一项都设置一个数t，表示当前数t是乘质数之后的结果，s表示乘以质数的数量，这两个变量分别初始化为1 和 0；
 * 然后开始遍历每一个质数，如果当前项右移j位是1，那么t如果不大于t*当前这个质数，就更新为他们的乘积，然后s自加一次；
 * 否则t=-1直接退出当前循环。
 * 最后判断s是否是奇数，如果是奇数，表示乘以奇数次质数，前面的符号为正， 否则是负号。
 * 最后res累加n/t返回res即可
*/

int main()
{
    int n, m;
    cin >> n >> m;
    int res = 0;

    for (int i = 0; i < m; i++)
        cin >> p[i];

    for (int i = 1; i < 1 << m; i++) // i一共有从1到n-1项
    {
        // cout << i << endl;
        int t = 1, s = 0;
        for (int j = 0; j < m; j++) // 遍历每一项的m个质数
        {
            if (i >> j & 1) // i 右移 j，表示第j为是不是包含质数，如果包含那么就乘
            {
                if ((LL)t * p[j] > n) // 当前t乘以质数要小于等于n才可以
                {
                    t = -1;
                    break;
                }
                t *= p[j]; // t 乘上质数且s++
                s++;
            }
        }
        if (t != -1)
        {
            if (s % 2)
                res += n / t;
            else
                res -= n / t;
        }
    }
    cout << res << endl;
}
