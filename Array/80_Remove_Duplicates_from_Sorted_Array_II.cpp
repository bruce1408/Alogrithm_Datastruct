#include <iostream>
#include <vector>
using namespace std;

/**
 * 80 删除数组的重复，使得重复数字最多出现两次
*/

/**
 * 方法 1，使用双指针来做，k从起始位置开始，然后遍历每一个数，k要小于2跳过前两个数
 * 或者当前数x不等于前两个数字，那么就覆盖
 * 
*/
int removeDuplicates(vector<int> &nums)
{
    int k = 0;
    for (auto x : nums)
    {
        if (k < 2 || nums[k - 1] != x || nums[k - 2] != x)
        {
            nums[k++] = x;
        }
    }
    return k;
}

/**
 * 方法 1的扩展,重复数字控制两个以内，如果当前数字x大于上上个数组nums[k-2]，那么重复数字就控制在2个以内
 * 不会有第三个重复数字，参考26题做法
*/
int removeDuplicates_(vector<int> &nums)
{
    int k = 0;
    for (auto x : nums)
    {
        if (k < 2 || x > nums[k - 2])
            nums[k++] = x;
    }
    return k;
}

int main()
{
    vector<int> res = {1, 1, 2, 3, 4, 4, 4, 5, 6};
    int j = removeDuplicates(res);
    for (int i = 0; i < j; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}