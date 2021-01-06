#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * 336 给出一个单词的list，然后两两组合，只要组合后的新单词是回文对
 * 那么就记录构成这个回文对的单词下标即可
*/

/**
 * 方法 1，使用暴力搜索来做，超时了，时间复杂度是n^2*L
 * 长度为L的回文串的时间复杂度是O(L)
*/
bool palind(string s)
{
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        else
            i++, j--;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string> &words)
{
    vector<vector<int>> res;
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                string t = words[i] + words[j];
                if (palind(t))
                    res.push_back({i, j});
            }
        }
    }
    return res;
}

/**
 * 方法 2，上面时间复杂度太高了。
 * 分析参考https://www.acwing.com/solution/content/363/
*/
bool check(string s)
{
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        else
            i++, j--;
    }
    return true;
}

vector<vector<int>> palindromePairs2(vector<string> &words)
{
    unordered_map<string, int> hash;
    for (int i = 0; i < words.size(); i++)
    {
        auto w = words[i];
        reverse(w.begin(), w.end());
        hash[w] = i;
    }
    vector<vector<int>> res;
    for (int i = 0; i < words.size(); i++)
    {
        auto w = words[i];
        for (int j = 0; j <= w.size(); j++)
        {
            auto left = w.substr(0, j), right = w.substr(j);
            if (check(right) && hash.count(left) && hash[left] != i)
                res.push_back({i, hash[left]});
            if (check(left) && hash.count(right) && hash[right] != i && w.size() != words[hash[right]].size())
                res.push_back({hash[right], i});
        }
    }
    return res;
}

int main()
{
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    for (auto i : palindromePairs2(words))
    {
        for (auto x : i)
            cout << x << " ";
        cout << endl;
    }
}