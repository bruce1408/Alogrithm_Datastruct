#include <iostream>
using namespace std;

/**
 * 并查集：是一种维护集合的数据结构
 * 他的名字中并、查、集分别是合并、查找、集合这3个单词,并查集的实现使用一个数组即可 int fath[N], father[i]表示元素i的父节点
 * father[1] = 1：1的父节点是1
 * father[2] = 3：2的父节点是3
 * father[3] = 1；3的父节点是1
 * 说明1和3的父节点是相同的，在一个集合中。
 * 初始化：
 * for(int i=0;i<n;i++)
 * {
 *      father[i] = i; 每个元素的父节点是自己
 * }
 * 并查集支持集合的两个操作：
 * 1 合并两个集合
 *      合并集合是把两个集合合并到一个集合中，先判断是否两个元素属于同一集合，当属于不同集合才可以合并，合并过程就是
 *      把一个结合的根节点的父节点指向另一个集合的根节点。
 *      例如两个元素的根节点分别是faA和faB，只需要把其中的一个父节点指向另一个节点，
 *      father[faA] = faB 或者 father[faB] = faA
 * void union(int a, int b)
 * {
 *      int faA = findfather(a);
 *      int faB = findfather(b);
 *      if(faA != faB) father[faA] = faB;
 * }
 * 
 * 2 判断两个元素是否在一个集合当中
 *      规定同一集合只能存在一个根节点，所以查找操作就是对给定的节点寻找根节点，实现方式用递推或者是递归，就是反复寻找父节点
 * int findfather(int x)
 * {
 *      while(x!=father[x])
 *      {
 *          x = father[x];
 *      }    
 *      return x;
 * }
 * 
 * int findfather(int x)
 * {
 *      if(father[x]==x) return x;
 *      else return findfather(father[x]);
 * }
 * 
 * 这种写法更加省时
 * int findfather(int a)
 * {
 *     if(a != father[a]) father[a] = findfather(father[a]);
 *     return father[a];
 * }
*/
const int N = 1000010;
int p[N];

int find(int x)
{
    // 这里没有用到路径压缩，所以可能超时
    // while(x!=p[x])
    // {
    //     x = p[x];
    // }
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        string op;
        cin >> op;
        int x1, x2;
        cin >> x1 >> x2;
        if (op == "M")
        {
            p[find(x1)] = find(x2);
        }
        else
        {
            if (find(x1) == find(x2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}