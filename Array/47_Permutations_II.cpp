#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
using namespace std;


/*
    方案一：
*/
bool next_permut(vector<int>& nums) //  下一个排列的函数组合
{
    for (int i=0;i<nums.size();i++)
        cout << nums[i] <<" ";
    cout <<'\n';
    int last_increasing = nums.size()-1;
    for(;last_increasing>=1 && nums[last_increasing-1]>=nums[last_increasing]; last_incdreasing--);
    last_increasing--;
    if (last_increasing<0)
        return false;
    cout << last_increasing<<'\n';
    int next_larger=last_increasing+1;
    for(;next_larger<nums.size() && nums[next_larger]>nums[last_increasing];next_larger++);
    next_larger--;
    swap(nums[next_larger], nums[last_increasing]);
    reverse(nums.begin()+last_increasing+1, nums.end());
    return true;
}
    
vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> answer;
    answer.push_back(nums);
    while(next_permut(nums))  // 下一个排列的函数
        answer.push_back(nums);
    return answer;
}

// 方法二 ： 在46的基础上加上set
void helper(vector<int> nums,int begin, set<vector<int>>& result)
{
    if(begin>=nums.size())
    {
        result.insert(nums);
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
    set<vector<int>> result;
    helper(nums, 0, result);
    return vector<vector<int>>(result.begin(),result.end()); 
}


// 方案三 
void perm(vector<int > nums,int i ,int n,vector<vector<int>> &ans)
{
    if((n-1)==i)
    {
        ans.push_back(nums);
        return ;
    }
    for(int j = i;j<n;j++)
    {
        if(j!=i&&nums[j]==nums[i])
            continue;
        swap(nums[i],nums[j]);
        perm(nums,i+1,n,ans);
    }
}
    
vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    vector<vector<int> > ans;
    sort(nums.begin(),nums.end());
    perm(nums,0,nums.size(),ans);
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 2};
    permuteUnique(nums);
    // for(auto i:permuteUnique(nums))
    // {
    //     for(auto j: i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
}