#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 深度优先搜索DFS
 * 
*/
// const int N = 100010;
// int visited[N], path[N];
// int n;

// void dfs(int u)
// {
//     if (u == n)
//     {
//         for (int i = 0; i < n; i++)
//             cout << path[i] << " ";
//         cout << endl;
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (visited[i] != 1)
//         {
//             visited[i] = 1;
//             path[u] = i;
//             dfs(u + 1);
//             visited[i] = 0;
//             path[u] = 0;
//         }
//     }
// }

// const int maxn = 30;
int n1, totalW, ans, maxValue = 0; // 物品件数n，背包容量V，最大价值
// int w[maxn], c[maxn];
int w[] = {3, 5, 1, 2, 2};
int c[] = {4, 5, 2, 1, 3};
/**
 * dfs1，每件物品都有选择或者不被选择两种，如果index==n，说明完成了n件物品的选择，
 * 且重量不超过总的最大重量，而且价格大于之前的价格就赋值最大价格，且返回；
 * 时间复杂度是2^n
 * */
void dfs1(int index, int sumW, int sumC)
{
    if (index == n1) // 完成了对物品件数的选择
    {
        if (sumW <= totalW && sumC > maxValue)
        {
            maxValue = sumC;
        }
        return;
    }

    // 如果index不满足物品件数这个条件的话
    dfs1(index + 1, sumW, sumC);

    // 如果index满足物品这个条件
    dfs1(index + 1, sumW + w[index], sumC + c[index]);
}

/**
 * dfs2，上述算法是背包是把n都确定了再去更新最大价值，但是忽略了背包容量不能超过总重量的条件，
 * 可以进行优化，把判断最大重量加入到条件中，只有重量不大于总重量就进行更新即可
*/
void dfs2(int index, int sumW, int sumC)
{
    if (index == n1)
        return;
    dfs2(index + 1, sumW, sumC);   // 不对index物品进行选择
    if (sumW + w[index] <= totalW) // 选择index物品的重量不能超过总重量
    {
        if (sumC + c[index] > maxValue) // 更新最大价值ans
            maxValue = sumC + c[index];
        dfs2(index + 1, sumW + w[index], sumC + c[index]);
    }
}

/**
 * dfs3, 从数组中选择k个数字，然后保证他们的和恰好是给定的数x，
 * 如果有多种方案，那么选择平方和最大的那一对
*/
vector<int> res, temp;
const int n = 4;
int a[n] = {1, 2, 6, 7}, k = 2, maxsum, target = 8;
void dfs3(int index, int nc, int sum, int sum2)
{
    if (nc == k && sum == target)
    {
        if (sum2 > maxsum)
        {
            maxsum = sum2;
            res = temp; // 选择这个最优方案
        }
        return;
    }

    if (index == n || nc > k || sum > target)
        return;
    dfs3(index + 1, nc, sum, sum2);
    temp.push_back(a[index]);
    dfs3(index + 1, nc + 1, sum + a[index], sum2 + a[index] * a[index]);
    temp.pop_back();

    // dfs3(index + 1, nc, sum, sum2); // 当前的值不选
}

int main()
{
    n1 = 5, totalW = 8;
    dfs2(0, 0, 0);
    dfs3(0, 0, 0, 0);
    printf("%d\n", maxValue);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
}