#include<iostream>
#include<vector>
using namespace std;

/**
 * 131 分割回文串
 * 给定一个英文字符串，然后找出所有的回文串子串
*/
vector<vector<string>>res;
vector<string>out;
vector<vector<bool>>f;

/**
 * 方法 1，使用dfs，先用一个二维数组记录这个字符串的所有回文串的位置，然后方便后面
 * 查找的使用
 * 判断ij这一段是不是回文串的时候，如果i和j相同，那么ij位置是true
 * 如果si==sj,两种情况，要么是i+1 > j-1,说明是两个字符，要么是f[i+1][j-1]=true
 * 那么f[i][j] = true;说明是回文串的情况
 * 然后开始dfs搜索遍历情况
*/
vector<vector<string>> partition(string s) {
    int n = s.size();
    // 初始化字符串s是不是回文串，保存到二维数组中
    f = vector<vector<bool>>(n, vector<bool>(n));
    for(int j = 0;j < n;j++)
    {
        for(int i = 0; i<=j;i++)
        {
            if(i == j) f[i][j] = true;
            else if(s[i] == s[j])
            {
                if(f[i+1][j-1] || i + 1 > j-1) f[i][j] = true;
            }
        }
    }    
    
    dfs(s, 0);
    return res;
}

void dfs(string &s, int u)
{
    if(u == s.size())
        res.push_back(out);
    else
    {
        for(int i = u; i<s.size(); i++)
        {
            if(f[u][i]) // 是回文串的情况下，把i-u+1长度的s加进去即可
            {
                out.push_back(s.substr(u, i-u+1));
                dfs(s, i+1);
                out.pop_back();

            }
        }
    }

}