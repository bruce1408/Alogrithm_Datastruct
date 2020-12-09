#include <iostream>
#include <vector>
using namespace std;

int n, maxValue, x, k;
const int N = 100010;
int visited[N];
int nums[] = {2, 3, 3, 4};
vector<int>temp, ans;
/**
 * 给定N个整数，从中选择k个数使得这k个数字的和为恰好为给定的整数x，
 * 这k个数的平方和最大，假定方案是唯一的
 * 例如{2, 3, 3, 4}, k = 2, x = 6;
 * 满足的有{2, 4} 、{3, 3}，那么{2, 4}平方和最大输出即可
*/

void dfs(int index, int newK, int sum, int sum2)
{
    if (newK == k && sum == x)
    {
        if(sum2 > maxValue)
        {
            maxValue = sum2;
            ans = temp;
        }
        return ;
    }
    // 如果是超过了k个数，或者处理完了n个数，或者是和超过了x，返回
    if(index == n || nowK > k || sum>x) return ;
    dfs(index + 1, newK, sum, sum2);
    if (sum < x)
    {
        for (int i = index; i < n - 1; i++)
        {
            if (sum + nums[i] <= x)
            {
                ans = max(ans, sum2 + nums[i] * nums[i]);
                return;
                // dfs(i, newK + 1, sum + nums[i], sum2 + nums[i] * nums[i]);
            }
            else
            {
                dfs(i + 1, newK + 1, sum + nums[i], sum2 + nums[i] * nums[i]);
            }
        }
    }
}

int main()
{
    // cin>>n>>k>>x;
    // for(int i=0;i<n;i++)
    //     cin>>nums[i];
    n = 4;
    dfs(0, 0, 0, 0);
    cout << ans << endl;
}