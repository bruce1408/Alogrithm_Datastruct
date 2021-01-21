#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 244 谜一样的牛
 * 有n头奶牛，已知它们的身高为 1~n 且各不相同，但不知道每头奶牛的具体身高。
 * 现在这n头奶牛站成一列，已知第i头牛前面有Ai头牛比它低，求每头奶牛的身高。
 *
 * 输出包含n行，每行输出一个整数表示牛的身高。
 * 第i行输出第i头牛的身高。
 * 输入 1, 2, 1, 0
 * 输出 2，4，5，2，1
 * 输入a1, a2, a3, .....an
 * 实际上就是求当前数组中剩余第 ai + 1 小的数
 *
 * 涉及的主要操作：
 * 1 从剩余数组中找出第k个小的数，序列中第k大的就是在求解最小的i，是的hash[1] + hash[2] + ... hash[i] >=k 成立。用树状数组来解决hash求和的问题 (hash 用来记录元素出现的个数  )
 * 2 删除某个数
 *
 * 思路：
 * 使用树状数组 + 二分
 * 设定每一个身高为1，表示可以用1次，树状数组来维护其前缀和
*/

/**
 * 方法 1，这个题目就是求解在剩下的数中第i+1小的牛的标号
 * 维护一个vector即可，不用树状数组
*/
vector<int> v; // 表示存放的数据下标
vector<int> ans1;
void findknum()
{
    int n = 5;                               // 假设是有5个数字
    vector<int> res = {0, 0, 1, 2, 1, 0, 0}; // 输入数字是1，2，1，0，下标是从2开始
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    for (int i = n; i >= 1; i--)
    {
        int y = res[i];
        vector<int>::iterator it = v.begin() + y;
        cout << "*it = : " << *it << endl;
        ans1.push_back(*it);
        v.erase(it);
    }
    reverse(ans1.begin(), ans1.end());
    for (auto X : ans1)
        cout << X << endl;
}

/**
 * 方法 2，使用树状数组
*/
const int N = 100010;
int n, a[N], ans[N], c[N];
#define lowbit(i) ((i) & (-i))

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        c[i] += v;
}

int getSum(int x)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += c[i];
    return sum;
}

int main()
{
    cin >> n;
    // i从2开始，默认1就是0
    for (int i = 2; i <= n; i++)
        scanf("%d", &a[i]);

    // 1-n的身高这里是只能使用一次
    for (int i = 1; i <= n; i++)
        update(i, 1);

    for (int i = n; i > 0; i--)
    {
        int k = a[i] + 1; // 找到第a[i] + 1 个大的数就是当前牛的身高
        // 使用二分来找第一个大于等于k的数
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (getSum(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        ans[i] = l;
        update(l, -1); // 当前的数字已经用过了，直接加上-1即可
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    // 方法 2入口
    findknum();
}
