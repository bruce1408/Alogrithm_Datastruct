#include<iostream>
#include<vector>
int n, maxValue, x, k;
const int N = 100010;
int nums[N], visited[N];
/**
 * 给定N个整数，从中选择k个数使得这k个数字的和为恰好为给定的整数x，
 * 这k个数的平方和最大，假定方案是唯一的
 * 例如{2, 3, 3, 4}, k = 2, x = 6;
 * 满足的有{2, 4} 、{3, 3}，那么{2, 4}平方和最大输出即可
*/

void dfs()
{

}

int main()
{
    cin>>n>>k>>x;
    for(int i=0;i<n;i++)
        cin>>nums[i];
    dfs(0, );
}