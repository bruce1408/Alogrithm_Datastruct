#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int p = 1, q = 1; 
        int n = nums.size();
        for(int i=0; i< n-1; i++)
        {
            if(nums[i+1] - nums[i] > 0)
            {
                p = q+1;
            }
            else if(nums[i+1] - nums[i] < 0) q = p+1;
        }
        return min(n, max(p, q));
    }
};

int main()
{
    vector<int> nums = {1,7,4,9,2,5};
    Solution s;
    cout<<s.wiggleMaxLength(nums);
    return 0;
}