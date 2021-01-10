#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * 414 第三个最大的数字，如果没有就返回第二个最大的数，如果有相同的重复的数字
 * 那么就返回的是不重复的第三个最大的数
 * Given a non-empty array of integers, 
 * return the third maximum number in this array. 
 * If it does not exist, return the maximum number. 
 * The time complexity must be in O(n).
 * 
 * Example 1:
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * Explanation: The third maximum is 1.
 * 
 * 求数组中最大的第三个数字，先求出数组中最大的第二个数字,
 * 
 */

/**
 * 方法 1，先求出数组中的第一大的数字，然后依次求解数组中最大的第三个数字,
 * 主要是怎么求解最大的第二个数字，如果第二个数字求解出来了，
 * 那么第三个最大的数也可以求解，
 * 这里有个坑，我自己也没有注意，然后一直通过不了，后来看解答说
 * 初始化的时候要是长整型long的最小值，我自己设置的是INT_MIN，但是
 * 数组中有INT_MIN的时候，返回的就不知道是INT_MIN还是最大值,
 * 扩展一下第4个，第5个最大的数？
*/
int thirdMax1(vector<int> &nums)
{
    int len = nums.size();
    if (len < 3)
        return len == 1 ? nums[0] : max(nums[0], nums[1]);
    long first = LONG_MIN, second = LONG_MIN, thirdNum = LONG_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > first)
        {
            thirdNum = second;
            second = first;
            first = nums[i];
        }
        else if (nums[i] > second && nums[i] < first)
        {
            thirdNum = second;
            second = nums[i];
        }
        else if (nums[i] > thirdNum && nums[i] < second)
        {
            thirdNum = nums[i];
        }
    }
    // 如果第三个数是最小的long_min 或者第二大和第三大数字相同的话，那就返回最大值，否则返回最小值；
    return (thirdNum == LONG_MIN || thirdNum == second) ? first : thirdNum;
}

/**
 * 方法 2，上面的方法的不同写法
*/
int thirdMax2(vector<int> &res)
{
    int s = 0, n = res.size();
    long long inf = 1e18, first = -inf, second = -inf, third = -inf;
    for (int i = 0; i < n; i++)
    {
        if (res[i] > first)
        {
            third = second;
            second = first;
            first = res[i];
            s++;
        }
        else if (res[i] > second && res[i] < first)
        {
            third = second;
            second = res[i];
            s++;
        }
        else if (res[i] > third && res[i] < second)
            third = res[i], s++;
    }
    if (s < 3)
        return first;
    else
        return third;
}

/**
 * 方法 2，这个题目其实用set的话也可以认为是O(N)的时间复杂度；放一句大佬的话在这里：
 * Since we only have 3 elements, insert/delete is constant time operations. 
 * Don't stick to O(nlog n) concept. We only care about big O when the things we are dealing with is big.
 * 
 * 因为只有3个元素，所有插入删除都是常数时间的操作，不要死守O(nlgn)的概念，只有数组非常大的时候才考虑O，感觉很多道理；
 * 利用set的特性，它是自动排序的，而且不会有重复元素,如果set的元素大于3的话，那么就把第一个元素
 * erase删除掉，最后返回的时候，判断长度是不是等于3，如果等于3那么就返回第一个元素，否则返回最后一个元素
 * */
int thirdMax2(vector<int> &nums)
{
    set<int> s;
    for (int num : nums)
    {
        s.insert(num); // 自动的从小到大的排序
        if (s.size() > 3)
        {
            s.erase(s.begin()); // 永远是3的长度
        }
    }
    return s.size() == 3 ? *s.begin() : *s.end();
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << thirdMax2(nums);
    return 0;
}