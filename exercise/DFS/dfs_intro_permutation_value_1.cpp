#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 给定一个数字n，然后求这个数字的全排列，使用深度优先搜索来做
 * 
 * 此题中dfs表示的含义是：求出从第u行到最后一行的所有path。
 * dfs的求法：根据通项公式的含义，假设已知第u+1行到最后一行的所有path，
 * 综合1和2得出：path[u] 与 path[u+1] 合并后，即为dfs的解。
 * 回溯的特征是：递归的最外层是一个循环。因为一次dfs得到的是所有的path。
 * 每一次都是从当前现场中去取得剩下未访问的元素。
 * 这一块自己画个图就很容易理解。
 * 反证：如果不进行现场的恢复，则在第一次完成深搜后，
 * 所有元素都已经被访问过了。这样在回溯到上一层时，
 * 上层的现场中的状态都被下层更改了，数据就会乱套
*/
const int N = 100010;
int visited[N], path[N];
int n;

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] != 1)
        {
            visited[i] = 1;
            path[u] = i;
            dfs(u + 1);
            visited[i] = 0;
            path[u] = 0;
        }
    }
}

/**
 * 物品价格的最大值：
 * 输入长度为n的数组表示有n个物品，然后每个物品分别对应它的价格和重量
 * 这里设置两个数组，一个表示物品的重量，还有一个表示物品的价格
 * 最后找出不超过给定重量的最大价格；
 * 例如：
 * 给定物品数是5，最大重量不能超过8；
 * 物品的重量分别是：3，5，1，2，2
 * 物品的价格分别是：4，5，2，1，3
 * 那么在给定的重量下面，最大的价值是10，
 * 因为选择物品重量是：3，1，2，2，价格就是4+2+1+3=10
 * 
 * 详细思路为:
 * 从n件物品中选择若干件放入背包，然后计算他们的价格最大；
 * 每件物品都有两个选择，这就是所谓的岔路头，那么死胡同就是物品的质量
 * 总和不能超过V；
 * DFS函数的参数记录的是当前处理物品编号index，
 * void DFS(int index, int sumW, int sumC)
 * 如果选择不放入index号物品，那么sumW和sumC不变，接下来处理index+1
 * 即前往DFS(int index+1, sumW, int sumC)这条分支，
 * 而如果选择index物品，
 * 那么sumW将增加当前物品的重量w[index],
 * sumC增加当前物品的价格c[index],
 * 接着处理index+1号物品，那么前往DFS(index+1, sumW+w[index], sumC+c[index])
 * 
 * 最后如果index增加到n，那么就是n物品已经处理完毕，此时记录的sumC和sumW表示记录的
 * 总重量和总价格。
 * 如果sumW不超过V且sumC大于最大的值，那么就记录一个全局的最大值，更新这个
 * 价格的最大值即可；
 * 
*/
// const int maxn = 30;
int n1, V, ans, maxValue = 0; // 物品件数n，背包容量V，最大价值
// int w[maxn], c[maxn];
int w[] = {3, 5, 1, 2, 2};
int c[] = {4, 5, 2, 1, 3};
/**
 * dfs1写法 1
 * */
void dfs1(int index, int sumW, int sumC)
{
    if (index == n1) // 完成了对物品件数的选择
    {
        if (sumW <= V && sumC > maxValue)
            maxValue = sumC;
        return;
    }
    // 如果index不满足物品件数这个条件的话
    dfs1(index + 1, sumW, sumC);
    dfs1(index + 1, sumW + w[index], sumC + c[index]);
}

/**
 * dfs2 写法 2的写法更像是n皇后问题的一种类型
*/
void dfs2(int index, int sumW, int sumC)
{
    if (index == n1)
    {
        return; // 已经完成了对n件物品的选择
    }
    dfs1(index + 1, sumW, sumC); // 不选第index物品
    // 只有加入index物品之后没有查过限定重量，才可以继续
    if (sumW + w[index] <= V && sumC + c[index] > ans)
    {
        ans = sumC + c[index]; // 更新最大的价值
        // 选择第index+1件商品
        dfs1(index + 1, sumW + w[index], sumC + c[index]);
    }
}
// int main()
// {
//     // cin >> n;
//     // n = 3;
//     // dfs(0);
//     // 输入物品件数以及背包容量
//     // cin >> n1 >> V;
//     n1 = 5, V = 8;
//     dfs2(0, 0, 0);
//     printf("%d\n", maxValue);
// }

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0)
        return 1;
    double x = sqrt(b * b - a * c * 4);
    if (x <= 0)
        return 1;
    double x1 = (-b + x) / (2 * a);
    double x2 = (-b - x) / (2 * a);
    printf("r1=%7.2f\nr2=%7.2f", x1, x2);
}