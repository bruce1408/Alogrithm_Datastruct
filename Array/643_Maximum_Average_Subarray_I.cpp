#include<iostream>
#include<vector>
using namespace std;

// 方法一：kandane 算法 53题很类似
double findMaxAverage(vector<int>& nums, int k)
{
    double global_max = INT_MIN;
    double current_max = INT_MIN;
    
    for(int i=0;i<nums.size()&& i<=nums.size()-k;i++)
    {
        int count = i;
        double ksum = 0;
        while(count<i+k && count<nums.size())
        {
            ksum+=nums[count++];
        }
        // cout<<i<<" :"<<ksum<<endl;
        current_max = max(ksum, current_max);
        if(current_max>global_max)
        {
            global_max = current_max;
        }
    }
    return global_max/k;
}

// 方法二：利用滑窗来做 ,前k个相加，然后减去第i-k个数。不断向右滑动
double findMaxAverage2(vector<int>& nums, int k)
{
    int current_sum = 0;
    int global_sum = INT_MIN;
    for(int i=0;i<k;i++) {current_sum+=nums[i];}
    global_sum = current_sum;
    for(int i=k;i<nums.size();i++)
    {
        current_sum = current_sum-nums[i-k]+nums[i]; // 删除前i-k号元素，然后加上滑窗现在的范围内新的数字nums[i]
        if(current_sum>global_sum)
        {
            global_sum = current_sum;
        }
    }
    return (double)global_sum/k;
}

int main()
{
    vector<int> nums = {0, 1, 1, 3, 3};
    cout<<findMaxAverage2(nums, 4)<<endl;
    return 0;
}