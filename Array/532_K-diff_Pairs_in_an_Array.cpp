#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>

using namespace std;
// int findPairs(vector<int> &nums, int k)
// {
//     /*
//         方法一： 哈希表，存储每一个数组出现的次数；这样的哈希表自带去重对的功能，
//         如果 你的k是0的话，那么我就只统计哈希表出现次数大于1的数字
//     */
//     int count=0;
//     unordered_map<int ,int> m;
//     for(auto i:nums)
//     {
//         ++m[i];
//     }
//     for(auto a:m)
//     {
//         if(k==0 && a.second>1) ++count;
//         if(k>0 && m.count(a.first+k)) ++count; 
//     }
//     return count;
// }

// 
int findPair(vector<int> &nums, int k) {
    /*
        使用双指针，先排序，然后第一个指针指向第一个元素，工作指针查看哪个和它相减是小于k的
    */
    int res = 0, n = nums.size(), j = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) 
    {
        int j = i + 1;
        while (j < n && nums[j] - nums[i] < k) ++j;
        if (j < n && nums[j] - nums[i] == k) ++res;
        while (j < n && nums[j] == nums[i]) ++j;
        i=j;
    }
    return res;
}


int findPairs1(vector<int>& nums, int k) {
    /*
        使用双指针，先排序，然后第一个指针指向第一个元素，工作指针查看哪个和它相减是小于k的
    */
    int n = 0,i = 0;
    sort(nums.begin(), nums.end());
    if(nums.size()<=1) return 0;
    while(i<nums.size()) 
    {
        int j = i + 1;
        while (j < nums.size() && nums[j] - nums[i] < k) ++j; // skip the diff < k
        if (j < nums.size() && nums[j] - nums[i] == k) ++n;
        while (j < nums.size() && nums[j] == nums[i]) ++j;
        i=j;
    }
    return n;
}


int main()
{
    vector<int> res = {3, 1, 1};
    int k = findPair(res, 2);
    cout<<k<<endl;
    return 0;
}