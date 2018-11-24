#include<iostream>
#include<vector>
using namespace std;


int dp(vector<int> &res, vector<int> &m, int n)
{
    if(n<=1) return 0;
    if(m[n]>0) return m[n];
    return m[n]= min(dp(res, m, n-1) + res[n-1], dp(res, m, n-2)+res[n-2]);
}
int minCost(vector<int> &res)
{
    vector<int> m(res.size()+1);
    return dp(res,m,res.size());
}


int main()
{
    vector<int> res = {10,15,10};
    cout<<minCost(res);
}
