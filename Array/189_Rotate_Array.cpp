#include<iostream>
#include<vector>
using namespace std;

// method1:利用辅助数组来做，
// void rotate(vector<int>& nums, int k)
// {
//     vector<int> temp = nums;
//     for(int i=0;i<nums.size();i++)
//     {
//         nums[(k+i)%nums.size()] = temp[i];
//     }
// }


// 不能利用辅助数组,还可以利用上面的思路，。
void insert(vector<int> &nums)
{
    int temp = nums[nums.size()-1];
    for(int i=nums.size()-1;i>=0;i--)
    {
        nums[i] = nums[i-1];
    }
    nums[0] = temp;
}

void rotate(vector<int> &nums,int k)
{
    int n = nums.size();
    while(k)
    {
        insert(nums);
        k--;
    }
}


void rotate(vector<int>& nums, int k) 
/*
    先反转前n-k个数组，然后再反转k个数组，最后反转整个数组；
*/
{
    if (nums.empty() || (k %= nums.size()) == 0) return;
    int n = nums.size();
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}

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