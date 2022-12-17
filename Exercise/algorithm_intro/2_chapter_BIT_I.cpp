#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utils/cout_vec.h"
using namespace std;

/**
 * 给定一个数组，统计在该元素左边比该元素小的元素个数
 * 树状数组，binary indexed tree，用来解决两类问题
 * 第一就是快速求解前缀和
 * 第二就是修改某一个数
 * 上面两个步骤的时间复杂度都是O(logn)
*/
const int N = 100010;
#define lowbit(i) ((i) & (-i)) // lowbit 写成宏定义方便运算
int c[N];                      // c[i]数组表示的是在i号位之前lowbit(i)个整数之和

/**
 * 更新函数，对第x个数加上v
 * 对第x个数字加上v，那么就要寻找树状数组c[x]覆盖的都要加上v，那么如何寻找树状数组中的对应项？
 * 只要找到了，那么就加上这个v即可
 * 比如找到c[x] 对应的c[y],那么是使得c[y]覆盖c[x]即可。
 * 例如a[5] 加上v，那么就是让c[5]开始找，离c[5]最近能覆盖c[5]的矩形是c[6],离c[6]最近的覆盖矩形是
 * c[8]...所以只要把c[5],c[6,c[8]都加上v即可。
 * 如何寻找到当前c[x]最近能覆盖的c[y]，结论是lowbit(y)必须要大于lowbit(x),不然不可能覆盖到lowbit(x),
 * 所以问题转化为找到一个尽可能小的a，是的lowbit(x+a) > lowbit(x),如果lowbit(a) < lowbit(x)，那么
 * lowbit(x + a) < lowbit(x),因为lowbit是返回最后位上的1，所以lowbit(x + a) == lowbit(a);
 * 所以lowbit(a) 不小于lowbit(x),所以lowbit(a)取最小是lowbit(x),因为x和a相同的话，那么在最后1位1会产生
 * 进位，从而所以lowbit(x+a) > lowbit(x)成立，最小的a是lowbit(x)
 * 代码如下所示：
*/
void update(int x, int v)
{
    int s = 0;
    for (int i = x; i <= N; i += lowbit(i))
        c[i] += v, s += lowbit(i); // 让c[i]加上v，然后让c[i+lowbit(i)]加上v
}

/**
 * 返回前x个整数之和，因为
 * a[1] + ... a[x] = 
*  sum(1, x) = 
*  a[1] + a[x - lowbit(x)] + a[x - lowbit(x) + 1] + ...a[x] = 
*  a[1] + a[x - lowbit(x)] + c[x] 因为c[x]覆盖的长度是lowbit(x),所以c[x] 是a[x - lowbit(x) + 1 ~ x]的和
 * 所以，上面式子可以写成
 * sum(1, x) = sum(1, x- lowbit(x)) + c[x];
 * 前x个数之和如下函数所示：
*/
int getSum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i]; // 累积c[i]，然后把问题缩小sum(1, i-lowbit(i));
    return sum;      // 返回sum和
}

int main()
{
    vector<int> res = {2, 3, 1, 5, 6, 1}; // 给定一个数组，统计在该元素左边比该元素小的元素个数
    vector<int> left_less;
    vector<int> left_great;
    vector<int> right_less;
    vector<int> right_great;
    int len = res.size();

    cout << "原数组为:" << endl;
    print(res);

    // 统计左边部分
    for (int i = 0; i < res.size(); i++)
    {
        update(res[i], 1);
        // 统计在元素左边比该元素大的元素个数
        left_great.push_back(getSum(N) - getSum(res[i]));
        // 统计在元素左边比该元素小的元素个数
        left_less.push_back(getSum(res[i] - 1));
    }
    cout << "左边大于该元素的个数：" << endl;
    print(left_great);
    cout << "左边小于该元素的个数：" << endl;
    print(left_less);

    // 统计右边部分
    // for (int i = res.size() - 1; i >= 0; i--)
    // {
    //     update(res[i], 1);
    //     // 统计在元素右边比该元素大的元素个数
    //     right_great.push_back(getSum(N) - getSum(res[i]));
    //     // 统计在元素右边比该元素小的元素个数
    //     right_less.push_back(getSum(res[i] - 1));
    // }
    // reverse(right_great.begin(), right_great.end()); // 右边部分需要翻转一下
    // reverse(right_less.begin(), right_less.end());
    // cout << "右边大于该元素的个数：" << endl;
    // print(right_great);
    // cout << "右边小于该元素的个数：" << endl;
    // print(right_less);
    // cout << endl;
}