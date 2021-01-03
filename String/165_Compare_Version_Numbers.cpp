#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * 165比较括号
 * 给定两个字符串的版本号，然后分别比较字符串的版本号码的大小；版本号之间用'.'隔开即可
 * 然后版本号要是大于另一个的话，那么就是返回1，如果小于的话就是返回-1，其他返回0
 * 比如：
 * a = 1.0.1 ,b = 1.1.1;
 * 返回-1
*/

/**
 * 方法 1，判断版本号的大小，版本1是version1，版本2是version2，用c_str() 函数和 atoi函数即可
 * */
int compareVersion1(string version1, string version2)
{
    int v1 = version1.size(), v2 = version2.size();
    int i = 0, j = 0, d1 = 0, d2 = 0;
    string s1, s2;
    while (i < v1 || j < v2)
    {
        while (i < v1 && version1[i] != '.')
            s1.push_back(version1[i++]);
        d1 = atoi(s1.c_str());
        while (j < v2 && version2[j] != '.')
            s2.push_back(version2[j++]);
        d2 = atoi(s2.c_str());
        if (d1 > d2)
            return 1;
        else if (d1 < d2)
            return -1;
        s1.clear(); // 之前的保存要清除
        s2.clear();
        ++i;
        ++j;
    }
    return 0;
}

/**
 * 方法 2，不需要构成开辟空间，而是累加每一个数，最后判断数字的大小
 * */
int compareVersion2(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.size() || j < t.size())
    {
        int num1 = 0, num2 = 0;
        while (i < s.size() && s[i] != '.')
            num1 = num1 * 10 + s[i++] - '0';
        while (j < t.size() && t[j] != '.')
            num2 = num2 * 10 + t[j++] - '0';
        if (num1 > num2)
            return 1;
        else if (num1 < num2)
            return -1;
        i++, j++;
    }
    return 0;
}

/**
 * 方法 3，字符流函数
 * */
// int compareVersion3(string version1, string version2)
// {
//     istringstream v1(version1 + "."), v2(version2 + ".");
//     int d1 = 0, d2 = 0;
//     char dot = '.';
//     while (v1.good() || v2.good())
//     {
//         if (v1.good())
//             v1 >> d1 >> dot;
//         if (v2.good())
//             v2 >> d2 >> dot;
//         if (d1 > d2)
//             return 1;
//         else if (d1 < d2)
//             return -1;
//         d1 = d2 = 0;
//     }
//     return 0;
// }

int main()
{
    string s1 = "1.0.1", s2 = "1";
    cout << compareVersion2(s1, s2) << endl;
}