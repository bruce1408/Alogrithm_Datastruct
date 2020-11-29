#include<iostream>
#include<vector>
#include"../../utils/cout_vec.h"

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
 * 输入样例：
 * 6 3
 * 1 2 2 1 2 1
 * 1 3 1
 * 3 5 1
 * 1 6 1
 * 输出样例：
 * 3 4 5 3 4 2
*/

/**
 * ai = b1 + b2 + b3 + .... +bi
 * ...
 * b1 = a1
 * b2 = a2 - a1
 * b3 = a3 - a2
 * ...
 * bn = an - an-1
 * */ 
void insert(vector<int>&b, int l, int r, int c)
{
    b[l]+=c;
    b[r+1]-=c;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i=1; i<=n; i++)
        cin>>a[i]; 
    // 对每个数进行差分求解
    for(int i=1;i<=n;i++) insert(b, i, i, a[i]);
    while(m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    // a[i] 是b[i]的前n项和
    for(int i=1;i<=n;i++)
    {
        b[i] += b[i-1];
        printf("%d ", b[i]);
    } 
}