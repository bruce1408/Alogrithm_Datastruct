#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int romanToInt(string s) 
{
    /*
        罗马字母转化成数字，如果是前一个数字小于等于后一个数字，那么就累加，
        否则累计相减
    */
    unordered_map<char, int> m = {{'I',1},{'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        int val = m[s[i]];
        if(i==s.size()-1 || m[s[i]]>=m[s[i+1]]) res+=val;
        else res-=val;  
    }
    return res; 
}
int main()
{
    string a = "IV";
    cout<<romanToInt(a);
    return 0;
}