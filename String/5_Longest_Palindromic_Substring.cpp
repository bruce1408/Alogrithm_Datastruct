#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

/**
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
*/

/**
 * 方法 1,查找字符子串的最长回文串长度, 两层for循环来做.babad
*/
string longestPalindrome(string s) 
{
    int len = s.size(), left = 0, right = len-1;
    if(len==1) return s;
    
    

    return s;
}

int main()
{
    string s = "babad";
    cout<<longestPalindrome(s)<<endl;
}