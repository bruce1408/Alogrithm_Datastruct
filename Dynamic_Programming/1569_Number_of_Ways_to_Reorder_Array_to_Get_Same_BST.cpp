#include<iostream>
#include<vector>
using namespace std;

// Input: nums = [2,1,3]
// Output: 1


class Solution {
    public:
    int numOfWays(vector<int>& nums) {

        const int n = nums.size();
        const int kMod = 1e9 + 7;
        vector<vector<int>> cnk(n + 1, vector<int>(n + 1, 1));    
        for (int i = 1; i <= n; ++i)      
        for (int j = 1; j < i; ++j)
            cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % kMod; 
           
        function<int(vector<int>)> trees = [&](const vector<int>& nums) {
            const int n = nums.size();
            if (n <= 2) return 1;
            vector<int> left;
            vector<int> right;
            for (int i = 1; i < nums.size(); ++i)
                if (nums[i] < nums[0]) left.push_back(nums[i]);
                else right.push_back(nums[i]);
            long ans = cnk[n - 1][left.size()];
            ans = (ans * trees(left)) % kMod;      
            ans = (ans * trees(right)) % kMod;      
            return static_cast<int>(ans);
        };
        return trees(nums) - 1;
    } 
};

int help(vector<int>&nums)
{
    if(nums.size()==0) return 1;
    vector<int>f(nums.size());
    
    int l1 = 0, l2 = 0;
    if (nums.size() == 0) return 0;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[0] > nums[i]) l1 = i;
        else l2 = i;
    }
    // if(l1 == 0 || l2==0) return 0;
    int l = l1 < l2? l1:l2;
    int r = l1 > l2? l1:l2;
    cout<<l<<" "<<r<<endl;
    vector<int>left(nums.begin() + 1 , nums.begin() + 1 + l);
    vector<int>right(nums.begin()+l+1, nums.end());
    return help(left) * help(right);
}

int numOfWays(vector<int>& nums) {
    return help(nums);
    // cout<<"the left is "<<endl;
    // for(auto x: left) cout<<x<<endl;
    // cout<<"the right is "<<endl;
    // for(auto x:right) cout<<x<<endl;

    // int n = left.size();
    // int m = right.size();
    // return (n-1) * m + 1 + (m-1)*(n);
}



int main()
{
    vector<int>res = {3,1,2,5,4,6};
    cout<<numOfWays(res)<<endl;
}