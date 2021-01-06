#include <iostream>
#include <vector>
using namespace std;

/**
 * 336 给出一个单词的list，然后两两组合，只要组合后的新单词是回文对
 * 那么就记录构成这个回文对的单词下标即可
*/

/**
 * 方法 1，使用暴力搜索来做，超时了，时间复杂度是n2L
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
        for (int j = 0; < n; j++)
        {
            if (i != j)
            {
                string t = words[i] + words[j];
                if (t)
                    res.push_back({i, j});
            }
        }
    }
    return res;
}

int main()
{
}