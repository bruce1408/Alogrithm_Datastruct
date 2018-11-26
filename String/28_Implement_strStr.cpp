#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// 804ms 暴力搜索，时间很长
int strStr(string haystack, string needle)
{
    if(needle.empty()) return 0;
    int n = haystack.size(), m = needle.size();
    if(m>n) return -1;
    for(int i=0;i<n;i++) // n = 5, m=2
    {
        int count = m;
        int j=i;
        int k = 0;
        while(haystack[j]==needle[k] && k<m)
        {
            j++;
            k++;
            count--;
        }
        if(count==0) return j-m;
    }
    return -1;
}

// 优化算法，时间4ms
int strStr(string haystack, string needle) 
{
    if (needle.empty()) return 0;
    int m = haystack.size(), n = needle.size();
    if (m < n) return -1;
    for (int i = 0; i <= m - n; ++i) 
    {
        int j = 0;
        for (j = 0; j < n; ++j) 
        {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == n) return i;
    }
    return -1;
}

int main()
{
    cout<<strStr("hello", "ll")<<endl;
    return 0;
}