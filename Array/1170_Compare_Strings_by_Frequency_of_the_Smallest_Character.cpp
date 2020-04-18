#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Let's define a function f(s) over a non-empty string s, 
 * which calculates the frequency of the smallest character in s. 
 * For example, if s = "dcce" then f(s) = 2 because the smallest character is "c" and its frequency is 2.
 * 
 * Now, given string arrays queries and words, return an integer array answer, 
 * where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words.
 * 
 * Example 1:
 * Input: queries = ["cbd"], words = ["zaaaz"]
 * Output: [1]
 * 
 * Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
 * 
 * 给定两个字符数组，从第一个数组中遍历，然后找到小于第二个数组中重复的长度；
*/
vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
{
    int len1 = queries.size(), len2 = words.size();
    vector<int> res;
    for (auto word : words)
    {
        int repeatNum = 1;
        char before = word[0];
        for (int i = 1; i < word.size(); i++)
        {
            if (before == word[i])
            {
                repeatNum += 1;
            }

            before = word[i];
        }
        res.push_back(repeatNum);
    }
    for (auto i : res)
    {
        cout << i << " ";
    }

    return {};
}

int main()
{
    vector<string> queries = {"bbb", "cc"};
    vector<string> words = {"a", "aa", "aaa", "aaaa"};
    numSmallerByFrequency(queries, words);
}