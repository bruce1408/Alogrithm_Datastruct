#include<iostream>
#include<vector>
using namespace std;

// 该方法超时了
class Solution1 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 1, maxnum = 0;
        if (nums.size() == 1) return 1;
        if (nums.size()>1)
        {  
            for(int i=0;i<nums.size();i++)
            {
                int flag = i+1;
                if(nums[i]==nums[flag] && flag<nums.size()) count+=1;
                else{
                    if(count >= maxnum) maxnum=count;
                    count=1;
                }
            }
        }
        return maxnum;
    }
};

//方法 2
// class Solution2 {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0]==1? 1 : 0;
//         int count = 0, maxnum = 0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==1) count+=1;
//             else count=0;
//             maxnum = max(maxnum, count);
//         }
//         return maxnum;
//     }
// };


// 方法3
class Solution3 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]==1? 1 : 0;
        int count = 0, maxnum = 0;
        for(int i=0;i<nums.size();i++)
        {
            count = (nums[i]+count)*nums[i];
            maxnum = max(maxnum, count);
        }
        return maxnum;
    }
};
int main()
{  
    vector<int> num = {1,1};
    Solution s;
    int a = s.findMaxConsecutiveOnes(num);
    cout<<"the result is:"<<a<<endl;

}
