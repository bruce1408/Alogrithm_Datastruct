#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;


// 给两个数字进行全排列
void helper(int n, int k, vector<int>out, vector<vector<int>>& res,int begin)
{
    if(out.size()==k) {res.push_back(out);return ;}
    for(int i=begin;i<=n;i++)
    {
        out.push_back(i);
        helper(n,k,out,res,i+1);
        out.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) 
{
    if(k>n || k<0) return {};
    vector<vector<int>>res;
    vector<int> out;
    helper(n, k, out, res, 1);
    return res; 
}


// method2
vector<vector<int>> combine1(int n, int k) 
{
    if(k>n || k<0) return {};
    vector<vector<int>>res = combine1(n-1, k-1);
    for(auto &i:res) i.push_back(n);
    for(auto &i:combine(n-1, k)) res.push_back(i);
    return res;
}