#include <iostream>
#include <vector>
using namespace std;

/**
 * Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
 * That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
 * Return the answer in an array.
 * 
 * 遍历每一个数组的数字，然后统计这个数组被一个数字小的个数即可，
 * 比如：
 * Input: nums = [8,1,2,2,3]
 * Output: [4,0,1,1,3]
 * 比8小的有4个， 比1小的是0，比2小的是1个，一次类推
*/

/**
 * 方法 1，使用暴力求解，思路最自然，也可以使用额外的数组来降低复杂度。
*/
vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] > nums[j] && i != j)
            {
                count += 1;
            }
        }
        res.push_back(count);
    }
    return res;
}

/**
 * 方法 2，使用的是计数排序的思路，统计每个数字出现的次数放到一个数组里，
*/
vector<int> smallerNumbersThanCurrent2(vector<int> &nums)
{
    vector<int> res(101);
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        res[nums[i]]++;
    }
    // 统计数组中小于等于i的个数
    for (int i = 1; i < 101; i++)
    {
        res[i] += res[i - 1];
    }
    // 遍历这个数组，在原来的统计个数里面找到小于这个数的数字即可，如果遍历到的这个数字是0的话需要特殊处理，直接赋值为0，否则是统计数组的个数即可
    for (int i = 0; i < nums.size(); i++)
    {
        temp.push_back(nums[i] == 0 ? 0 : res[nums[i] - 1]);
    }
    return temp;
}

/**
 * 方法 3，使用二分法来做,先对原来的数组拷贝一份然后排序，
 * 然后遍历原来的数组，使用lower_bound查找第一个大于或者等于原来数组的数字即可。
 * 逻辑上没问题，但是不推荐这种写法
*/
vector<int> smallerNumbersThanCurrent3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp(nums);
    vector<int> res;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        vector<int>::iterator iter = lower_bound(temp.begin(), temp.end(), nums[i]);
        int loc = iter - temp.begin();
        res.push_back(loc);
    }
    return res;
}

int main()
{
    vector<int> nums = {8, 1, 2, 2, 3};
    for (auto i : smallerNumbersThanCurrent3(nums))
    {
        cout << i << ' ';
    }
    cout << endl;
}