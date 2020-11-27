#include<iostream>
#include<vector>
using namespace std;

vector<int> multi(vector<int>&res1, int res2)
{
    vector<int>res;
    for(int i=0;i<res1.size();i++)
    {
        
    }
}

int main()
{
    string a;
    cin>>a;
    int b;
    cin>>b;
    vector<int>res1;
    for(int i=a.size()-1; i>=0;i++)
    {
        res1.push_back(a[i]);
    }
    auto res = multi(res1, b);
    for(int i=res.size()-1;i>=0;i--)
    {
        printf("%d", res[i]);
    }
}