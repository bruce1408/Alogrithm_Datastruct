#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
题目描述，删除指定的元素，然后返回当前新的数组的长度
*/
// 利用vector的erase的方法
int removeElement(vector<int>&nums, int val)
{
    int len = nums.size();
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==val)
        {
            nums.erase(nums.begin()+i);
            i--;
            len--;
        }
    }
    return len;
}

// 第二种方法，不用erase，两个指针！
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[res++] = nums[i];
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {3,2,2,3};
    // vector<int> nums = {3,3};
    cout<<removeElement(nums,3)<<endl;
    for(auto i:nums)
    {
        cout<<i<<endl;
    }
    return 0;
}