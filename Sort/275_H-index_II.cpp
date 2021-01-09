#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * 输入: citations = [0,1,3,5,6]
 * 输出: 3 
 * 解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
 * 由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3;
*/

int hIndedx(vector<int> &res)
{
    int n = res.size();
    for(int i=0;i<n;i++)
    {
        
    }
}

int main()
{
    vector<int> res = {0, 1, 3, , 5, 6};
    cout << hIndedx(res) << endl;
}