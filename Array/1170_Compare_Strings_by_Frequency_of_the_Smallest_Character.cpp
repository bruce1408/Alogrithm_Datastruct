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

/**
 * 方法 1，每个字符返回的是这个最小字母的重复数字，比如zaaaz，返回的是3，不是a重复次数最多，而是a比z小，所以返回的是a的字符重复长度，
 * 然后在第二个字符数组中找到比他大的个数，放入结果数组
*/
vector<int> numRepeat(vector<string> &words)
{
    vector<int> wordNum;
    for (auto word : words)
    {
        int repeatNum = 0, maxNum = 1;
        char before = 'z';
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] < before)
            {
                before = word[i];
                repeatNum = 1;
            }
            else if (before == word[i])
            {
                repeatNum += 1;
            }
        }
        wordNum.push_back(repeatNum);
    }
    return wordNum;
}

vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
{
    int len1 = queries.size(), len2 = words.size();
    vector<int> lenNum;
    vector<int> quNum = numRepeat(queries);
    vector<int> wordNum = numRepeat(words);
    for (int i = 0; i < len1; i++)
    {
        int repNum = 0;
        for (int j = 0; j < len2; j++)
        {
            if (quNum[i] < wordNum[j])
            {
                repNum += 1;
            }
        }
        lenNum.push_back(repNum);
    }
    return lenNum;
}

/**
 * 方法 2，
 * 
*/
int frequency(string s)
{
    int count = 0;
    char small = 'z';
    for (auto i : s)
    {
        if (i < small)
        {
            small = i;
            count = 1;
        }
        else if (i == small)
            count++;
    }
    return count;
}

vector<int> numSmallerByFrequency1(vector<string> &queries, vector<string> &words)
{
    vector<int> freq(10, 0);
    vector<int> res;
    for (auto w : words)
    {
        int num = frequency(w);
        freq[num - 1]++;
    }

    for (auto q : queries)
    {
        int num = frequency(q);
        int sum = 0;
        for (int i = num; i < 10; i++)
            sum += freq[i];
        res.push_back(sum);
    }
    return res;
}

int main()
{
    vector<string> queries = {"bba", "abaaaaaa", "aaaaaa", "bbabbabaab", "aba", "aa", "baab", "bbbbbb", "aab", "bbabbaabb"};
    vector<string> words = {"aaabbb", "aab", "babbab", "babbbb", "b", "bbbbbbbbab", "a", "bbbbbbbbbb", "baaabbaab", "aa"};
    for (auto i : numSmallerByFrequency(queries, words))
    {
        cout << i << " ";
    }
    cout << endl;
}