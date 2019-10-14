#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
/**
 * Given an array A of strings made only from lowercase 
 * letters, return a list of all characters that show up 
 * in all strings within the list (including duplicates).
 * For example, if a character occurs 3 times in all strings
 * but not 4 times, you need to include that character 
 * three times in the final answer.
 * You may return the answer in any order.
 * 
 * Example 1:
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 * 
 * 从字符串数组中找到相似的字符
*/

/**
 * 方法 1，需要一个新的数组cnt长度26，初始化为最大的数，然后遍历数组，
 * 累加每个字符串的出现的次数存放到临时数组temp中，然后临时数组temp和
 * 新数组cnt比较，最小值的赋值给新数组cnt，这样cnt存放的是字符串数组
 * 中字符出现的次数，然后把这个返回。
 * 
*/
vector<string> commonChars(vector<string>& A) {
    vector<int>cnt(26, INT_MAX);
    vector<string>res;
    for(auto s:A)
    {
        vector<int>temp(26, 0);
        for(auto i:s)
        {
            temp[i-'a']++;
        }
        for(int i=0; i<26; i++)
        {
            cnt[i] = min(cnt[i], temp[i]);
        }
    }

    for(int i=0; i<26;i++)
    {
        for(int j=0; j<cnt[i]; j++)
        {
            res.push_back(string(1, i +'a'));
        }
    }
    return res;
}

