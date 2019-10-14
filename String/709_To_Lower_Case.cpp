#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * Implement function ToLowerCase() that has a string parameter str, 
 * and returns the same string in lowercase.
 * 
 * Example 1:
 * Input: "Hello"
 * Output: "hello" 
 * 
 * 把字符串的大写转换成小写字母即可；
 */

/**
 * 方法 1，就是利用ascii码，小写字母的范围是在97-122之间，
 * 大写字母的范围是在65-90之间，对于每一个字符，如果它和小a相减小于0，说明是大写字母
 * 然后加上大写字母和小写字母的差值32即可
*/
string toLowerCase(string str)
{
    string s = "";
    for (auto x : str)
    {
        if (x - 'a' < 0)
        {
            x = x + 32;
            s += x;
        }
        else
        {
            s += x;
        }
    }
    return s;
}

/**
 * 方法 1的写法还可以提炼一下，思路都是一样的
*/
string toLowerCase2(string str)
{
    for (auto &x : str)
    {
        if (x >= 'A' && x <= 'Z')
            x += 32;
    }
    return str;
}
int main()
{
    cout << toLowerCase2("Aello");
    return 0;
}