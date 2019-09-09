#include <iostream>
#include <vector>
using namespace std;


/**
 * Given an array with n integers, your task is to check if it could become
 *  non-decreasing by modifying at most 1 element.
 * We define an array is non-decreasing if array[i] <= array[i + 1] 
 * holds for every i (1 <= i < n).
 * 
 * Example 1:
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
 * 
 * Example 2:
 * Input: [4,2,1]
 * Output: False
*/

/**
 * 方法 1，分两种情况，第一种情况就是如果要修改的数是第一个数，那么后面的数字复制给第一个数
 * 否则，判断当前数的后一个数和前一个数的大小，后一个数小于前一个数，那么修改后一个数为当前数，
 * 否则，修改当前数为后一个数,比如 3，4，2，5.当前数字4不满足，后一个数字2小于前一个数3，
 * 修改的是2，而不是4。如果修改4，那么有问题。
 * */ 
bool checkPossibility(vector<int> &nums)
{
    int cnt = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        cout << "before: " << nums[i] << endl;
        if (nums[i] > nums[i + 1])
        {
            if (i == 0)
                nums[i] = nums[i + 1];
            else
            {
                if (nums[i + 1] < nums[i - 1])
                    nums[i + 1] = nums[i];
                else
                    nums[i] = nums[i + 1];
            }
            --cnt;
        }
    }
    return cnt == 0 ? true : false;
}

// 方法二：从第一个数字开始而已
bool checkPossibility1(vector<int> &nums)
{
    int cnt = 1, n = nums.size();
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] < nums[i - 1])
        {
            if (cnt == 0)
                return false;
            if (i == 1 || nums[i] >= nums[i - 2])
                nums[i - 1] = nums[i];
            else
                nums[i] = nums[i - 1];
            --cnt;
        }
    }
    return true;
}

bool checkPossibility2(vector<int> &nums)
{
    int count = 0, maxNum = INT_MIN;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count += 1;
            if (nums[i + 1] < maxNum && i != 0)
                return false;
        }
        else
            maxNum = max(nums[i], maxNum);
    }
    cout << count << endl;
    if (count > 1)
        return false;
    else
        return true;
}

int main()
{
    vector<int> res = {2, 3, 3, 2, 4};
    cout << checkPossibility2(res) << endl;
    // for(auto i:res)
    // {
    //     cout<<i<<endl;
    // }
    return 0;
}