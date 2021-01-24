#include <iostream>
#include <vector>
using namespace std;
/**
 * 31 下一个排列，给定一个数组，然后输出它的另一个不同的排列
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
*/

/**
 * 方法 1，逻辑解法，使用[1，2，7，4，3，1]来作为例子，如果说这个数组是逆序的，那么直接返回初始状态，
 * 如果这个数组不是逆序的，那么从最后一位遍历，如果说后一位大于前一位，那么这个时候就要有如下的操作
 * 记录当前的这个前一位的位置，然后在开始从后往前遍历，找到第一个大于这个位置的数，比如2的数字，发现是3，
 * 那么就交换2和3的位置，就是 [1,3,7,4,2,1],然后开始从3后面所有的位置都翻转一遍即可
 * 最后的数组是[1,3,1,2,4,7]
*/
void nextPermutation1(vector<int> &nums)
{
    int i, j, n = nums.size();
    for (i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            for (j = n - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                    break;
            }
            swap(nums[j], nums[i]);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
    }
    reverse(nums.begin(), nums.end());
}

/**
 * 方法 2，使用比上面更加简洁的写法
*/
void nextPermutation2(vector<int> &nums)
{
    int n = nums.size(), i = n - 2, j = n - 1;
    while (i >= 0 && nums[i] >= nums[i + 1])
        --i;
    if (i >= 0)
    {
        while (nums[j] <= nums[i])
            --j;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

/**
 * 方法 3，找到第一个非降序的位置，
*/
void nextPermutation3(vector<int> &nums)
{
    // 第一步找到第一个逆序的数字
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i + 1 < nums.size() && nums[i] > nums[i + 1])
        {
            j = i;
            break;
        }
    }
    if(j==0) 
        sort(nums.begin(), nums.end());
    else
    {
        
    }
    
}
int main()
{
    vector<int> res = {2, 3, 5, 4, 1};
    nextPermutation3(res);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}