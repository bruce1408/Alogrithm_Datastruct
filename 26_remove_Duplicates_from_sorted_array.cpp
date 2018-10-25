#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    int j=0,n = nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i]!=nums[j])
        {
            nums[++j] = nums[i];
        }
    }
    return j+1;
}

int main()
{
    vector<int> num = {1,1,2,2,3,4,5,5,6};
    int i = findDuplicate(num);
    for(int j = 0;j<i;j++)
    {
        cout<<num[j]<<" ";
    }
}