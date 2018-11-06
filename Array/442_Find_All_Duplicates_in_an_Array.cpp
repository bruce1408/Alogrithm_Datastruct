#include<iostream>
#include<vector>
using namespace std;


vector<int> findDuplicates(vector<int>& nums)
{
    vector<int>res;
    for(int i=0; i<nums.size(); i++)
    {
        nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        if(nums[abs(nums[i])-1]>0) res.push_back(abs(nums[i]));
    }
    return res;
}


int main()
{
    vector<int>res = {1, 2, 3, 1, 3, 6, 6};
    vector<int> out = findDuplicates(res);
    for(auto i:out)
    {
        cout<<i<<endl;
    }
    return 0;
}