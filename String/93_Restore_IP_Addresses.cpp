#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 * Example:
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 给定一个数字字符串，然后输出所有可能的IP地址的组合，每个ip地址0不能大头，单独的0是可以的，且范围都在
 * 0-255之间
 * 
 * 参考链接：https://www.cnblogs.com/grandyang/p/4305572.html
 * 
 * 17 提和这个很像
*/

vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    dfs(s, 0, 0, res, ""); // 从第0未开始搜索，搜第0个数字
    return res;
}

void(string &s, int index, int cnt, vector<string> &res, string t)
{
    if (index == cnt * 3 && cnt < 4)
    {
        res.push_back(t);
        return;
    }
    

}

int main()
{
}