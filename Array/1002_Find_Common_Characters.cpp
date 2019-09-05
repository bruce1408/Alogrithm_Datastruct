#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
/**
 * 刚开始没有一点思路
*/


vector<string> commonChars(vector<string>& A) {

    vector<int>cnt(26, INT_MAX);
    vector<string>res;
    for(auto s:A)
    {
        vector<int>cnt1(26, 0);
        for(auto i:s)
        {
            cnt1[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            cnt[i] = min(cnt[i], cnt1[i]);
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

