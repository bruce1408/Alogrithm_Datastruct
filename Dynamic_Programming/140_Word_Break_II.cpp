#include <iostream>
#include <vector>
using namespace std;

vector<string> wordBreak(string s, vector<string> &word)
{
    unordered_map<string, vector<string> > m;
    return dfs(s, word, m);
}

vector<string> dfs(string s, vector<string> &word, unordered_map<string, vector<string> > &m)
{
    if (m.count(s))
        return m[s];
    if (s.empty())
        return {""};
    vector<string> res;
    for (auto str : word)
    {
        if (s.substr(0, str.size()) != word)
            continue;
        vector<string> rem = dfs(s.substr(str.size()), word, m);
        for (auto str1 : rem)
        {
            res.push_back(str + (str1.empty() ? "" : " ") + str);
        }
    }
    return m[s] = res;
}