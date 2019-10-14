#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * In a string S of lowercase letters,
 * these letters form consecutive groups of the same character.
 * For example, a string like S = "abbxxxxzyy" has the groups "a", 
 * "bb", "xxxx", "z" and "yy".Call a group large if it has 3 or more characters. 
 * We would like the starting and ending positions of every large group.
 * The final answer should be in lexicographic order.
 * 
 * Example 1:
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * 
 * Explanation: "xxxx" is the single large group with starting 3 and 
 * ending positions 6.
 * 给定一个字符串，然后找出连续重复出现次数大于等于3次的字符的起始位置和结束位置；
 */

/***
 * 方法 1，利用一个新的数组str，存放的是每个字符出现的次数，然后开始遍历这个字符串
 * 设置两个指针，一个是left一个是right，left从头开始遍历字符串，
 * 查看对应的str数组，如果这个字符出现的次数大于等于3才开始继续下面的操作，否则left++；
 * 当该字符次数大于等于3的时候，那么从当前位置的下一个位置开始遍历，travesalIndex
 * 是不是小于字符串长度 且 下一个字符和当前的相等，如果相等就计数变量countNum++；
 * 最后看这个数字计数变量是不是大于等于3，那么就把当前的两个下标装进结果数组res中去；
 */
vector<vector<int>> largeGroupPositions(string S)
{
    int left = 0, right = S.size();
    unordered_map<char, int> str;
    vector<vector<int>> result;
    for (auto x : S)
    {
        str[x]++;
    }
    while (left < right)
    {
        if (str[S[left]] >= 3)
        {
            int travesalIndex = left + 1, countNum = 1;
            while (travesalIndex < right && S[travesalIndex] == S[left])
            {
                countNum += 1;
                travesalIndex++;
            }
            if (countNum >= 3)
            {
                result.push_back({left, travesalIndex - 1});
            }
            left = travesalIndex;
        }
        else
        {
            left += 1;
        }
    }
    return result;
}

/**
 * 方法 2，和上面的思路一样，但是写发更加简洁明了,设置两个指针，left和 right，left
 * 遍历整个数组，right是看当前值往后遍历，看是不是重复出现多次，最后指针距离大于等于3
 * 就返回下标即可；
*/
vector<vector<int>> largeGroupPositions1(string S)
{
    vector<vector<int>> res;
    int left = 0, right = 0, n = S.size();
    while (left < n)
    {
        while (right < n && S[left] == S[right])
            right++;
        if (right - left >= 3)
        {
            res.push_back({left, right - 1});
        }
        left = right;
    }
    return res;
}

/**
 * 方法 3，只利用一层循环来做；用for来代替while循环
*/
vector<vector<int>> largeGroupPositions2(string S)
{
    vector<vector<int>> res;
    int start = 0, n = S.size();
    for (int i = 0; i < n; i++)
    {
        if (S[i] == S[start])
            continue;
        if (i - start >= 3)
            res.push_back({start, i - 1});
        start = i;
    }
    return res;
}

int main()
{
    string str = "abcdddeeeeaabbbcd";
    vector<vector<int>> res = largeGroupPositions2(str);
    for (auto num : res)
    {
        for (auto i : num)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}