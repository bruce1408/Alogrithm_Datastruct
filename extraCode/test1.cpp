#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int temp=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i+1]-nums[i]==0)
        {
            temp = nums[i];
        }
    }
    return temp;
}

int main()
{
    
    vector<int>res = {1,3,4,2,2};
    // cout<<findDuplicate(res)<<endl;
    string a = "a*";
    cout<<a.substr(2)<<endl; // 如果长度是字符串的长度，那么返回的是空字符串
}
