#include <iostream>
#include <vector>
using namespace std;

/**
 * 485 最大的连续的1，数组只有0和1，返回数组中连续1出现最多的次数
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 * Example 1:
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * 
 * Explanation: The first two digits or the last three digits are consecutive 1s.
 * The maximum number of consecutive 1s is 3.
 * 找到数字中连续出现1最多的次数
*/

/**
 * 方法 1, 找两个变量,一个是全局变量记录最大的和局部最大值的变量，初始值设置为0,开始遍历这个数组,然后当前的值是1的话,
 * 那么就让局部的变量加1,否则,把全局变量和局部变量的最大值给全局变量,并把最后的最大值返回即可.时间复杂度是O(n),空间复杂度是O(1)
*/
int findMaxConsecutiveOnes1(vector<int> &nums)
{
    int res = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            res++;
            ans = max(res, ans);
        }
        else
            res = 0;
        // ans = max(res, ans); // 放这里都一样
    }
    return ans;
}

/**
 * 方法 2,这个写法其实并不是说找出连续的1来，而是找出连续的数，所以，主要是有连续出现的数字就会记录。
 * */
int findMaxConsecutiveOnes2(vector<int> &nums)
{
    int count = 0, maxnum = 0;
    if (nums.size() == 1)
        return 1;
    if (nums.size() > 1)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            int flag = i - 1;
            if (nums[i] == nums[flag])
                count += 1;
            else
            {
                if (count >= maxnum)
                    maxnum = count;
                count = 1;
            }
        }
    }
    return max(maxnum, count);
}

/**
 * 方法 3,这个思路都是一样的,但是写法更加巧妙,一般不会想到这么写,不过还是很fancy
 * */
int findMaxConsecutiveOnes4(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0] == 1 ? 1 : 0;
    int count = 0, maxnum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        count = (nums[i] + count) * nums[i];
        maxnum = max(maxnum, count);
    }
    return maxnum;
}

int main()
{
    vector<int> num = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1};
    // 方法 1
    int a = findMaxConsecutiveOnes1(num);
    cout << a << endl;
}
