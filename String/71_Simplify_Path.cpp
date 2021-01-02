#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 71 simplify path
 * 给定一个路径，用字符串表示，然后输出这个路径的最简路径
 * 输入：
 * path = "/a/./b/../../c/"
 * 输出：
 * path = "/c"
*/

/**
 * 方法 1，判断这个字符串是在每个/之间看中间单词是什么，有可能是字母路径，有可能是.表示当前路径
 * 有可能是..表示上一个路径，所以，需要用/作为分隔符，方便起见，给定的字符最后一位如果没有/,那么就加上/
 * 然后遍历每个单词，如果当前字符不是/,那么把字符累加到name中去即可，
 * 如果当前的字符是/斜线，那么分几种情况需要讨论
 *      1.如果name是..说明要回到上一级目录，那么就把res最后的路径出栈即可，知道res为/
 *      2.如果name是.或者空字符串，那么说明当前字符，不用任何操作，直接把/ 和 name路径加上即可
 *      最后把name清空即可
 * 最后判断一下res是不是为空，如果为空的话，那么返回/斜线即可
*/
string simplifyPath(string p)
{
    string res, name;
    if (p.back() != '/')
        p.push_back('/');
    for (auto c : p)
    {
        if (c != '/')
            name += c;
        else // 当前字符可能不是c
        {
            if (name == "..") // 表示上级目录，最后的路径删除
            {
                while (res.size() && res.back() != '/') // 如果res不是空或者最后不是斜线，那么就一直出栈
                    res.pop_back();
                if (res.size())
                    res.pop_back();
            }
            else if (name != "." && name != "")
                res += '/' + name;
            name.clear();
        }
    }
    if (res.empty())
        res = "/";
    return res;
}

int main()
{
    string s = "/a/./b/../../c/";
    cout << simplifyPath(s) << endl;
}