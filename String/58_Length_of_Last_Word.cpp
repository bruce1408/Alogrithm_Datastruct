#include <iostream>
#include <string>
using namespace std;

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
 * return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a maximal substring consisting of non-space characters only
 * 
 * Input: "Hello World"
 * Output: 5
*/

/**
 * 方法 1，去掉开头和结尾的空格，然后再开始统计，如果遇空格直接为0，否则累加，最后输出res累加结果,推荐算法
*/
int lengthOfLastWord(string s)
{
    int left = 0, right = (int)s.size() - 1, res = 0;
    while (s[left] == ' ')
        ++left;
    while (s[right] == ' ')
        --right;
    for (int i = left; i <= right; ++i)
    {
        if (s[i] == ' ')
            res = 0;
        else
            ++res;
    }
    return res;
}

/**
 * 方法 2，如果遇到非空格的字符，只需要判断其前面一个位置的字符是否为空格，
 * 如果是的话，那么当前肯定是一个新词的开始，将计数器重置为1，如果不是的话，说明正在统计一个词的长度，计数器自增1即可。
 * 但是需要注意的是，当 i=0 的时候，无法访问前一个字符，所以这种情况要特别判断一下，归为计数器自增1那类，
*/
int lengthOfLastWord2(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != ' ')
        {
            if (i != 0 && s[i - 1] == ' ')
                res = 1;
            else
                ++res;
        }
    }
    return res;
}
/**
 * 方法 3，只要从末尾开始，去除末尾的空格符，然后开始计数即可
*/
int lengthOfLastWord3(string s)
{
    int right = s.size() - 1, res = 0;
    while (right >= 0 && s[right] == ' ')
        --right;
    while (right >= 0 && s[right] != ' ')
    {
        right--;
        res += 1;
    }
    return res;
}
int main()
{
    string s = "h we";
    cout << lengthOfLastWord3(s) << endl;
}