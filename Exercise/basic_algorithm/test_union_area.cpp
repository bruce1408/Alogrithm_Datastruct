// 联通区域里面的字符进行替换

#include<iostream>
#include<vector>
using namespace std;
/**
这道题我们拿到基本就可以确定是图的dfs、bfs遍历的题目了。题目中解释说被包围的区间不会存在于边界上，
所以我们会想到边界上的o要特殊处理，只要把边界上的o特殊处理了，那么剩下的o替换成x就可以了。
问题转化为，如何寻找和边界联通的o，我们需要考虑如下情况。
这时候的o是不做替换的。因为和边界是连通的。
为了记录这种状态，我们把这种情况下的o换成#作为占位符，待搜索结束之后，遇到o替换为x（和边界不连通的o）；
遇到#，替换回o(和边界连通的o)。
如何寻找和边界联通的o? 从边界出发，对图进行dfs和bfs即可。这里简单总结下dfs和dfs。

dfs递归。最常用，如二叉树的先序遍历。


X X X X
X O O X
X X O X
X O X X
*/

void dfs(vector<vector<char>>&board, int i, int j) {
    if (i < 0 || j < 0 || i >= board.size()  || j >= board[0].size() ||
     board[i][j] == 'x' || board[i][j] == '#') {
        // board[i][j] == '#' 说明已经搜索过了. 
        return;
    }
    board[i][j] = '#';
    dfs(board, i - 1, j); // 上
    dfs(board, i + 1, j); // 下
    dfs(board, i, j - 1); // 左
    dfs(board, i, j + 1); // 右
}


void solve(vector<vector<char>>&board) {
    if ( board.size() == 0) return;
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 从边缘o开始搜索
            bool isEdge = (i == 0 || j == 0 || i == m - 1 || j == n - 1);
            if (isEdge && board[i][j] == 'o') {
                dfs(board, i, j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'o') {
                board[i][j] = '4';
            }

            if (board[i][j] == '#') {
                board[i][j] = 'o';
            }
        }
    }
}

int main()
{
    vector<vector<char>>res{
        {'x','x','x','x'},
        {'x','o','o','x'},
        {'x','x','o','x'},
        {'x','o','x','x'}};
    
    solve(res);

    for(int i = 0;i<res.size();i++)
    {
        for(int j = 0;j<res[0].size();j++)
        {
            cout<<res[i][j];
        }
        cout<<endl;
    }
}