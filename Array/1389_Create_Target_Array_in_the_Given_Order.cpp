#include <iostream>
#include <vector>
using namespace std;
/**
 * Example 1:
 * Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
 * Output: [0,4,1,3,2]
 * Explanation:
 * nums       index     target
 * 0            0        [0]
 * 1            1        [0,1]
 * 2            2        [0,1,2]
 * 3            2        [0,1,3,2]
 * 4            1        [0,4,1,3,2]
 * 在index 的位置 插入 nums 的元素即可；
*/

/**
 * 方法 1，使用insert函数，在index[i] 的位置 插入的值是 nums[i]；
*/
vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
{
    vector<int> res(index.size(), 0);
    for (int i = 0; i < index.size(); i++)
    {
        res.insert(res.begin() + index[i], nums[i]);
    }
    return vector<int>(res.begin(), res.begin() + index.size());
}

/**
 * 方法 2,前半部分是记录数组中的大小位置索引，如果前面的数字大于等于后面的数字的话，那么就当前位置的值+1即可
 * 如果这个数值
*/
vector<int> createTargetArray1(vector<int> &nums, vector<int> &index)
{
    vector<int> res(nums.size());
    for (int i = 0; i < index.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (index[j] >= index[i])
            {
                index[j]++;
            }
        }
    }

    for (int i = 0; i < index.size(); ++i)
    {
        res[index[i]] = nums[i];
    }
    return res;
}

int main()
{
    vector<int> nums = {0, 1, 2, 3, 4};
    vector<int> index = {0, 1, 2, 2, 1};
    for (auto i : createTargetArray1(nums, index))
    {
        cout << i << " ";
    }
    cout << endl;
}