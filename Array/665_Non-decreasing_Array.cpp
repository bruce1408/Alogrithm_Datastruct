#include<iostream>
#include<vector>
using namespace std;

// 分两种情况，第一种情况就是如果要修改的数是第一个数，那么后面的数字复制给第一个数
// 否则，判断当前数的后一个数和前一个数的大小，后一个数小于前一个数，那么修改后一个数为当前数，否则，修改当前数为后一个数
// 比如 3，4，2，5.当前数字4不满足，后一个数字2小于前一个数3，修改的是2，而不是4。如果修改4，那么有问题。
bool checkPossibility(vector<int>& nums) {
    int cnt=1;
    for(int i=0;i<nums.size()-1;i++)
    {
        cout<<"before: "<<nums[i]<<endl;
        if(nums[i]>nums[i+1])
        {
            if(i==0) nums[i] = nums[i+1];
            else
            {
                if(nums[i+1]<nums[i-1]) nums[i+1] = nums[i];
                else nums[i] = nums[i+1];
            }
            --cnt;
        }
    }
    return cnt==0?true:false;
}


// 方法二：从第一个数字开始而已 
bool checkPossibility1(vector<int>& nums) {
    int cnt = 1, n = nums.size();
    for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[i - 1]) {
            if (cnt == 0) return false;
            if (i == 1 || nums[i] >= nums[i - 2]) nums[i - 1] = nums[i];
            else nums[i] = nums[i - 1];
            --cnt;
        } 
    }
    return true;
}

int main()
{
    vector<int> res = {4,2,3};
    cout<<checkPossibility(res)<<endl;
    // for(auto i:res)
    // {
    //     cout<<i<<endl;
    // }
    return 0;
}