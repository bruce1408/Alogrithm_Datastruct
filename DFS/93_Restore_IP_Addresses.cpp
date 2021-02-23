#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 93 复原ip地址
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
 * leetcode 17 和这个很像
*/

/**
 * 方法 1，使用dfs来做，用k表示当前需要分的段数
 * 当只有一位时，0可以成某一段，如果有两位或三位时，像 00， 01， 001， 011， 000等都是不合法的，
 * 所以我们还是需要dfs函数来判断某个字符串是否合法
*/
void dfs(int u, int k, string &s, vector<int> &path, vector<string> &ans);
vector<string> restoreIpAddresses1(string s)
{
    vector<string> ans;
    vector<int> path;
    dfs(0, 0, s, path, ans);
    return ans;
}

/**
 * u表示枚举到的字符串下标，k表示当前截断的IP个数，s表示原字符串
 * */
void dfs(int u, int k, string &s, vector<int> &path, vector<string> &ans)
{
    if (u == s.size())
    {
        if (k == 4)
        {
            string ip = to_string(path[0]);
            for (int i = 1; i < 4; i++)
                ip += '.' + to_string(path[i]);
            ans.push_back(ip);
        }
        return;
    }
    if (k > 4)
        return;

    unsigned t = 0;
    for (int i = u; i < s.size(); i++)
    {
        t = t * 10 + s[i] - '0';
        if (t >= 0 && t < 256)
        {
            path.push_back(t);
            dfs(i + 1, k + 1, s, path, ans);
            path.pop_back();
        }
        if (!t)
            break;
    }
}

/**
 * 方法 2，思路相同，写法略不同，推荐写法
*/
void dfs1(string &s, int u, int k, string path, vector<string> &ans)
{
    if (u == s.size())
    {
        if (k == 4)
        {
            path.pop_back();
            ans.push_back(path);
        }
        return;
    }
    if (k == 4)
        return;
    for (int i = u, t = 0; i < s.size(); i++)
    {
        if (i > u && s[u] == '0')
            break; // 有前导0
        t = t * 10 + s[i] - '0';
        if (t <= 255)
            dfs1(s, i + 1, k + 1, path + to_string(t) + '.', ans);
        else
            break;
    }
}

vector<string> restoreIpAddresses2(string s)
{
    vector<string> ans;
    dfs1(s, 0, 0, "", ans);
    return ans;
}

int main()
{
    string s = "25525511135";
    for (auto i : restoreIpAddresses2(s))
        cout << i << endl;
}