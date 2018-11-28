#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    vector<int>m1(128),m2(128);
    for(int i=0;i<n1;i++) // 统计 前n1个数目的字符。s1,s2字符出现的次数
    {
        ++m1[s1[i]];++m2[s2[i]];
    }
    if(m1==m2) return true;

    // 相当于一个窗口的作用。
    for(int i=n1;i<n2;i++)
    {
        ++m2[s2[i]];
        --m2[s2[i-n1]];
        if(m1==m2) return true;
    }
    return false;
}

// 只用一个哈希表加两个指针来工作
bool checkInclusion2(string s1, string s2) 
{
    int n1 = s1.size(), n2 = s2.size(), left = 0;
    vector<int> m(128);
    for (char c : s1) ++m[c];
    for (int right = 0; right < n2; ++right) 
    {
        if (--m[s2[right]] < 0) 
        {
            while (++m[s2[left++]] != 0) {}
        } 
        else if (right - left + 1 == n1) return true;
    }
    return n1 == 0;
}

int main()
{
    string s1 = "ab",s2="eidbaooo";
    checkInclusion(s1, s2);
    return 0;
}