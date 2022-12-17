#include <iostream>
#include <vector>
#include "../../utils/cout_vec.h"
using namespace std;

/**
 * 给定一个长度为 n 的整数序列 a1,a2,…,an 以及一个长度为 m 的整数序列 b1,b2,…,bm。
 * 请你判断 a 序列是否为 b 序列的子序列。
 * 子序列指序列的一部分项按原有次序排列而得的序列，例如序列 {a1,a3,a5} 是序列 {a1,a2,a3,a4,a5} 的一个子序列。
 * 输入格式
 * 第一行包含两个整数 n,m。
 * 第二行包含 n 个整数，表示 a1,a2,…,an。
 * 第三行包含 m 个整数，表示 b1,b2,…,bm。
 * 输出格式
 * 如果 a 序列是 b 序列的子序列，输出一行 Yes。
 * 否则，输出 No。
 * 
 * 数据范围
 * 1≤n≤m≤10^5,
 * −10^9≤ai,bi≤10^9
 * 输入样例：
 * 3 5
 * 1 3 5
 * 1 2 3 4 5
 * 输出样例：
 * yes
*/

/**
 * 方法 1，使用双指针来做
*/
string subSequence1(vector<int> &a, vector<int> &b)
{
    vector<int> temp;
    for (int i = 0, j = 0; j < b.size(); j++)
    {
        if (b[j] == a[i] && i < a.size())
        {
            temp.push_back(j);
            i++;
        }
    }
    print(temp);
    if (temp.size() != a.size())
        return "No";
    for (int i = 0; i < temp.size() - 1; i++)
    {
        if (temp[i] > temp[i + 1])
            return "No";
    }
    return "Yes";
}

/**
 * 方法 2，使用双指针来做，但是写法更加简单
*/
void subSequence2(vector<int> &a, vector<int> &b)
{
    int i = 0;
    for (int j = 0; j < b.size(); j++)
    {
        if (b[j] == a[i] && i < a.size())
            i++;
    }
    if (i != a.size())
        printf("No");
    else
        printf("Yes");
}

int main()
{
    // int n, m;
    // cin>>n>>m;
    // vector<int>a(n);
    // vector<int>b(n);
    // for(int i=0;i<n;i++) cin>>a[i];
    // for(int j= 0;j<m;j++) cin>>b[j];
    vector<int> a = {2, 2, 2};
    vector<int> b = {1, 1, 1, 2, 2, 2};
    subSequence2(a, b);
}