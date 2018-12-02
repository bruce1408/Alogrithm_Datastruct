#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


string longestPalindrome(string s) 
{
    int n = s.size();
    for(int i=0;i<n/2;i++)
    {
        int j = i;
        for(int k=0;k<j;k++)
        {
            if(s[k]!=s[j-k-1]) 
        }
    }
}

int main()
{
    string s = "babad";
    cout<<longestPalindrome(s);
}