#include <iostream>
#include <string>
using namespace std;

/**
 * 383 赎条信
 * 就是给定两个字符串，a和b，然后看a是否可以由b的字符构成，
 * 比如
 * a = aa
 * b = aab
 * b可以构成a，因为b含有两个字符a
 * 
 * a = aab
 * b = abb
 * b不可以构成a，因为b中的a只有1个，而构成a所要两个a字符才行
*/

/**
 * 方法 1，使用哈希表来存储每个字符的次数，然后遍历，如果没有找到就返回false
 * 否则个数必须要大于等于0
*/
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> m;
        for (char c : magazine)
            ++m[c];
        for (char c : ransomNote)
        {
            if (--m[c] < 0)
                return false;
        }
        return true;
    }
};
