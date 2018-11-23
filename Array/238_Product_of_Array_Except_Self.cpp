#include<iostream>
#include<vector>
using namespace std;


//  given [1,2,3,4], return [24,12,8,6]
/*
    由于最终的结果都是要乘到结果res中，所以我们可以不用单独的数组来保存乘积，
    而是直接累积到res中，我们先从前面遍历一遍，将乘积的累积存入res中，然后从后面开始遍历，
    用到一个临时变量right，初始化为1，然后每次不断累积，最终得到正确结果
*/
vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> res(nums.size(),1);
    res[0] = 1;
    for(int i=1;i<nums.size();i++)
    {
        res[i] = res[i-1] * nums[i-1];
    }
    int right = 1;
    for(int i=nums.size()-1;i>=0;i--)
    {
        res[i] = res[i]*right;
        right = right * nums[i]; // 右面的累乘
    }
    return res;
}

int main()
{
    vector<int> res = {1,2,3,4};

    for(auto i:productExceptSelf(res))
    {
        cout<<i<<endl;
    }
}