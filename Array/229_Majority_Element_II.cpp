#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    找出出现次数大于 n/3 数字，O(1)的空间复杂度,自己的想法是先排序，然后改造投票法，但是超时了
*/
vector<int> majorityElement(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int>res;
    int majorNum = nums[0], count = 1, timesNum = n/3;
    for(int i=1; i<n; i++)
    {
        if(nums[i]==majorNum)
        {
            count++;
            if(count>timesNum) res.push_back(majorNum);
        } 
        else
        {
            count = 1;
            majorNum = nums[i];
        }
    }
    if(res.empty())
    {
        return {};
    }
    else return res;
}

// 方法二,投票法，不使用排序算法~,题目要求不能排序
vector<int> majorityElement2(vector<int>& nums)
{
    vector<int>res;
    int timesNum = nums.size()/3;
    int candidate1 = 0,candidate2=0,count1=0,count2=0;
    // 第一个for循环选出对多的两个数字
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==candidate1) count1++;
        else if(nums[i]==candidate2) count2++;
        else if(count1==0)
        {
            candidate1 = nums[i];
            count1 = 1;
        }
        else if(count2==0)
        {
            candidate2 = nums[i];
            count2 = 1;
        }
        else --count1,--count2;
    }
    count1=count2=0; // 重新开始计数
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==candidate1) count1++;
        else if(nums[i]==candidate2) count2++;
    }
    if(count1>timesNum) res.push_back(candidate1);
    if(count2>timesNum) res.push_back(candidate2);
    return res;
}
int main()
{
    vector<int> res = {3,2,2,2,1,1,2,3,3,3};
    for(auto i : majorityElement2(res)) 
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}