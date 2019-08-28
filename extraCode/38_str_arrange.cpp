#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int moreHalfNum(vector<int>res)
{
  int n = res.size();
  vector<int>tmp(n,0);
  for(int i=0;i<n;i++)
  {
    if(tmp[i]>=5)
    {
      cout<<tmp[i]<<endl;
      return tmp[i];
    }
    else
      tmp[res[i]]++;
  }
  return 0;
}

int main()
{
  vector<int> res = {1,2,3,2,2,2,5,4,2};
  cout<<moreHalfNum(res);
}
