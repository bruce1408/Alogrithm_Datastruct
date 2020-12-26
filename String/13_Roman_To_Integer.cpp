#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 罗马数字转化为数字，排出4和9相关的数字，然后其他数字都是组合而来的，如果前面一位小于后面一位
 * 那么就减去，否则加上即可
*/
int romanToInt(string s)
{
    unordered_map<char, int> hash;
    hash['I'] = 1, hash['V'] = 5;
    hash['X'] = 10, hash['L'] = 50;
    hash['C'] = 100, hash['D'] = 500;
    hash['M'] = 1000;

    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && hash[s[i]] < hash[s[i + 1]])
        {
            res = res - hash[s[i]];
        }
        else
            res += hash[s[i]];
    }
    return res;
}

int main()
{
    string s = "III";
    cout << romanToInt(s) << endl;
}
