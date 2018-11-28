#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

/*
    列举一个数组的全排列的所有情况
*/
// vector<int> iterfun(vector<int> res, int len)
// {
//     if(len==2) 
//     {
//         int temp = res[0];
//         res[0] = res[1];
//         res[1] = res[0];
//         return res;
//     }
//     else
//     {
//         for (int i=0;i<res.size();i++)
//         {
//             int temp = res[i];
//             res.erase(res.begin() + i);
//             vector<int> midResult = iterfun(res, res.size());
//             midResult.insert(midResult.begin(),temp);
//             return midResult;
//         }
//     }
// }
// vector<vector<int>> permute(vector<int>& nums)
// {
//     vector<vector<int>> res;
//     int num = nums[0];
//     nums.erase(nums.begin());
//     vector<int> afterAns = iterfun(nums, nums.size());
//     for(int i=0;i<nums.size();i++)
//     {
//         vector<int> temp = iterfun(nums,nums.size());
//         temp.insert(begin()+i,num);
//         res.push_back(temp);
//     }
//     res.push_back(iterfun(nums, nums.size()));
//     return res;
// }



vector<vector<int>> permute1(vector<int>& nums) 
{
    vector<vector<int>> ans;
    if(nums.size() <= 1)	
    {
        ans.push_back(nums);
    }

    else
    {
        int num = nums[0];
        nums.erase(nums.begin()); // 移除第一个元素开始排列
        vector<vector<int>> afterAns = permute1(nums);
        for(int i = 0; i < afterAns.size(); i++) 
        {
            for(int j = 0; j <= afterAns[i].size(); j++)    
            {
                vector<int> tmp = afterAns[i];
                tmp.insert(tmp.begin() + j, num);  // 每个都插一个数字
                ans.push_back(tmp);
            }
        }
    }
    return ans;
}


// 100% 的写法,思路比较自然
void helper(vector<int> nums,int begin, vector<vector<int>>& result)
{
    if(begin>=nums.size())
    {
        result.push_back(nums);
        return ;
    }
    for(int i=begin;i<nums.size();i++)
    {
        swap(nums[begin],nums[i]);
        helper(nums, begin+1,result);
        swap(nums[begin],nums[i]);
    }
}
vector<vector<int>>permute(vector<int>nums)
{
    vector<vector<int>> result;
    helper(nums, 0, result);
    return result; 
}


int main()
{
    vector<int> nums = {1, 1, 2};
    for(auto i:permute(nums))
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}