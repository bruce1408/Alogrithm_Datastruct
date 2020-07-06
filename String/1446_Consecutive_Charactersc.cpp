#include <iostream>
#include <vector>
using namespace std;
/**
 * 计算一个字符串连续相同的字符个数
 * 
 * Input: s = "leetcode"
 * Output: 2
 * Explanation: The substring "ee" is of length 2 with the character 'e' only.
*/

/**
 * 方法 1，使用双指针来做即可。时间复杂度n!
*/
int maxPower(string s)
{
    int cnt = 0, res = 0;
    int i = 0, n = s.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n && s[j] == s[i])
        {
            cnt += 1;
            j++;
            i++;
        }
        res = max(res, cnt);
        cnt = 0;
        i++;
    }
    return res + 1;
}

/**
 * 方法 2，时间复杂度是O(n)
*/
int maxPower2(string s)
{
    int power = 1, mx = 0;
    char c0 = 0;
    for (auto c1 : s)
    {
        (c0 == c1) ? ++power : power = 1;
        mx = max(mx, power);
        c0 = c1;
    }
    return mx;
}

int main()
{
    string s = "hooraaaaaaaaaaay";
    cout << maxPower2(s) << endl;
}