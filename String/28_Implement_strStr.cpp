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
    /*
        for(int i=0;i<n;i++) // 原来的话是遍历整个n长度的字符串，但是现在我不是遍历那么长的
        我只要遍历 n-m + 1长度的即可，遍历到剩下的长度和子字符串相等的位置即可,因为可以提高运算效率.
    */
    for(int i=0;i<n-m+1;i++) // 这个是唯一我改的地方 就是i的取值范围
    {
        int j=i;
        int k = 0;
        while(haystack[j]==needle[k] && k<m)
        {
            j++;
            k++;
        }
        if(k==needle.size()) return i;
    }
    return -1;
}

// 优化算法，时间4ms
// int strStr(string haystack, string needle) 
// {
//     if (needle.empty()) return 0;
//     int m = haystack.size(), n = needle.size();
//     if (m < n) return -1;
//     for (int i = 0; i <= m - n; ++i) 
//     {
//         int j = 0;
//         for (j = 0; j < n; ++j) 
//         {
//             if (haystack[i + j] != needle[j]) break;
//         }
//         if (j == n) return i;
//     }
//     return -1;
// }

int main()
{
    cout<<strStr("hello", "ll")<<endl;
    return 0;
}