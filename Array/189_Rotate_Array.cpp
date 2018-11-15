#include<iostream>
#include<vector>
using namespace std;

// method1:利用辅助数组来做，
void rotate(vector<int>& nums, int k)
{
    vector<int> temp = nums;
    for(int i=0;i<nums.size();i++)
    {
        nums[(k+i)%nums.size()] = temp[i];
    }
}


// 不能利用辅助数组，
int main()
{
    vector<int> res = {1,2,3,4,5,6,7};
    rotate(res,3);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}