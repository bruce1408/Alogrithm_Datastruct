#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include "../../utils/cout_vec.h"

using namespace std;
/**
 * 差分求解
 * 输入一个长度为n的整数序列。
 * 接下来输入m个操作，每个操作包含三个整数l, r, c，表示将序列中[l, r]之间的每个数加上c。
 * 请你输出进行完所有操作后的序列。
 * 输入格式
 * 第一行包含两个整数n和m。
 * 第二行包含n个整数，表示整数序列。
 * 接下来m行，每行包含三个整数l，r，c，表示一个操作。
 * 输出格式
 * 共一行，包含n个整数，表示最终序列。
 * 数据范围
 * 1≤n,m≤100000,
 * 1≤l≤r≤n,
 * −1000≤c≤1000,
 * −1000≤整数序列中元素的值≤1000 
 * 
 * 输入样例：
 * 6 3
 * 1 2 2 1 2 1
 * 1 3 1
 * 3 5 1
 * 1 6 1
 * 
 * 输出样例：
 * 3 4 5 3 4 2
*/

/**
 * 数组a是数组b的前缀和
 * 数组b是数组a的差分
 * ai = b1 + b2 + b3 + .... +bi 
 * ...
 * b1 = a1
 * b2 = a2 - a1
 * b3 = a3 - a2
 * ...
 * bn = an - an-1
 * 如果得到b数组，可以前缀和求出a数组；
 * 如果暴力来做的话那么就是O(n),差分的话就是O(1)
 */

/**
 * 方法 1，不用差分直接做
*/
void add(vector<int> &res, int l, int r, int v)
{
    for (int i = l - 1; i < r; i++)
        res[i] += v;
}

/**
 * 方法 2，差分做法
*/
void insert(vector<int> &b, int l, int r, int c)
{
    // 让b[l] 加上c，后面都加上了c，b[r+1]减去c就是对整个区间[l, r]之间进行差分
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    int n = 6, m = 3; // 设置6个数字，3个插入的区间
    // cin >> n >> m;
    vector<int> a = {0, 1, 2, 2, 1, 2, 1};
    vector<int> b(n + 1);
    unordered_map<int, pair<int, int>> nums;

    // 分别是3个区间加入加上数字1
    nums[0] = make_pair(1, 3);
    nums[1] = make_pair(3, 5);
    nums[2] = make_pair(1, 6);

    // 求解差分数组b的初始化，对每个数进行差分求解
    for (int i = 1; i <= n; i++)
        insert(b, i, i, a[i]);
    // b 数组为 1，1，0，-1，1，-1；而b数组的前缀和就是a数组
    int k = 0;
    while (k < m)
    {
        int l = nums[k].first;  // 区间左端点
        int r = nums[k].second; // 区间右端点
        int c = 1;              // 区间加上的数字
        insert(b, l, r, c);
        k++;
    }

    // a[i] 是b[i]的前n项和
    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1]; // 求数组b的前缀和就是数组a
        printf("%d ", b[i]);
    }
    // 非差分做法
    // vector<int> res = {1, 2, 2, 1, 2, 1};
    // add(res, 1, 3, 1);
    // add(res, 3, 5, 1);
    // add(res, 1, 6, 1);
    // print(res);
}