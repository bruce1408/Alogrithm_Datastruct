#include<iostream>
#include<vector>
using namespace std;

vector<int> findDisappreNum(vector<int> &res)
{
    vector<int>temp;
    for(int i=0;i<res.size();i++)
    {
        int idx = abs(res[i])-1;
        res[idx] = (res[idx]>0) ? -res[idx] : res[idx];
    }

    for(int i=0;i<res.size();i++)
    {
        if(res[i]>0)
        {
            temp.push_back(i+1);
        }
    }
    return temp;
}

int main()
{
    vector<int> res = {4,3,2,7,8,3,1};
    vector<int>out = findDisappreNum(res);
    for(auto i:out)
    {
        cout<<i<<" ";
    }
    return 0;

}