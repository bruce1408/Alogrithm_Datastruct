#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 *
 * Example:
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 给出一个数组，然后找到这个数组构成最大的面积，数组长度是长，高是数组长度范围内构成第二低的数字
 * */

/**
 * 方法 1，利用两个指针来做，头指针left和尾指针right，
 * 每次面积就是尾指针减去头指针的差然后再乘以
 * 这两个指针所指向元素的最小值即可，如果头指针大于尾指针，那么尾指针--，否则头指针++，
 * 直到遍历停止
 * 
*/
int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    while (left < right)
    {
        int tempArea = (right - left) * min(height[left], height[right]);
        maxArea = max(tempArea, maxArea);
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxArea;
}

/**
 * 方法 2，和方法 1的方法相同，但是根据逻辑来优化代码；如果数组中，高是相同的，
 * 那么面积只和长度有关
 * 比如[1,8,2,8,8],第二个1和最后1个8构成的面积最大，然后接下来到倒数的第二个8的时候，
 * 这个时候高都是8，但是长度却减小了，所以肯定面积比原来的要小很多，
 * 这个时候的面积不用考虑
*/

int maxArea1(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1, maxArea = 0;
    while (left < right)
    {
        int h = min(nums[left], nums[right]);
        maxArea = max(maxArea, h * (right - left));
        while (left < right && h == nums[left])
            left++;
        while (left < right && h == nums[right])
            right--;
    }
    return maxArea;
}

int main()
{
    vector<int> res = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea1(res) << endl;
    return 0;
}