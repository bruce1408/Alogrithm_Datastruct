#include <iostream>
#include <vector>
using namespace std;

/**
 * 303 给定一个数组，然后求解这个数组的前缀和
*/

class NumArray
{
public:
    vector<int> s;
    NumArray(vector<int> &nums)
    {
        s.resize(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++)
        {
            s[i] = s[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j)
    {
        i++, j++;
        return s[j] - s[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */