#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 520 检查单词的大小写格式是否正确
 * 满足以下几点：
 * 要么全部都是大写
 * 要么全部都是小写
 * 如果单词长度不为1，首字母大写其他小写
 * 大写字母的ASCII码65开头，小写字母是97开头
*/

/**
 * 方法 1，设置一个大写计数位，如果大写的话那么cnt+1，
 * 最后判断是否没有大写？或者是全是大写？或者是首字母大写，其余都是小写字母
*/
bool detectCapitalUse(string word)
{
    int cnt = 0, n = word.size();
    for (int i = 0; i < n; i++)
    {
        if (word[i] <= 'Z')
            cnt++;
    }
    return cnt == 0 || cnt == n || (cnt == 1 && word[0] <= 'Z');
}

int main()
{
    string s = "leetcode";
    cout << detectCapitalUse(s) << endl;
}