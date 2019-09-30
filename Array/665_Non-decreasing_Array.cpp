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
 * 
 * 给定一个数组，然后最多修改1位来判断是否该数组是非单调递减的
*/

/**
 * 4，2，3
 * -1，4，2，3
 * 2，3，3，2，4
 * 主要是上面的三种情况需要讨论，第一种就是当前数小于前面的数字，而且再前面的数字不存在，难么只要修改
 * 前面的数字为2即可，第二种就是再前面的数字存在，例如是-1，且是小于2的，那么就把前面的数字4修改为2即可，
 * 第三种情况就是再前面的数字大于当前的数字，例如3大于2，所以这个时候把2改成3
 * 
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

/**
 * 方法 3，和方法1类似，需要改变原来数组的值
*/
bool checkPossibility3(vector<int> &nums)
{
    int cnt = 1;
    for(int i=1;i<nums.size();i++)
    {
        if(cnt==0) return false;
        if(i==1 || nums[i]>nums[i-2]) nums[i-1] = nums[i];
        else nums[i] = nums[i-1];
        cnt--;
    }
    return true;
}

/**
 * 方法 4，不需要修改原来的数组。
*/
bool checkPossibility4(vector<int>&nums)
{
    int modify = 0;
    for(int i=1, pre = nums[0];i<nums.size();i++)
    {
        if(pre>nums[i] && modify++) return false;
        if(pre>nums[i] && i-2>=0 && nums[i-2]>nums[i]) continue;
        pre = nums[i];
    }
    return true;
}
int main()
{
    vector<int> res = {3, 4, 2, 3};
    cout << checkPossibility4(res) << endl;
    // for(auto i:res)
    // {
    //     cout<<i<<endl;
    // }
    return 0;
}