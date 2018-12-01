#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

// 在一个旋转的数组中找出最小的数
int findMin(vector<int>& nums) 
{
    int n = nums.size();
    if(nums[0]<nums[n-1]) return nums[0]; // 如果是首元素就小，说明没有旋转，那么就直接输出
    else // 利用二叉搜索。
    {
        int left = 0, right = n-1;
        while(left!=(right-1)) // 这个就是要保证是相邻的，不能相等
        {
            int mid = (left+right)/2;  // 中间数大于左边的数，那么向右移动，否则 向左移动
            if(nums[mid]>nums[left]) left = mid;
            else right = mid;
        }
        return min(nums[left], nums[right]);
    }
}

int main()
{
    vector<int> res = {4, 5, 6, 7, 0, 1, 2};
    int k = findMin(res);
    cout<<k<<endl;
}