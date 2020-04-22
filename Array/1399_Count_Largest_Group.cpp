#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an integer n. Each number from 1 to n is grouped according to the sum of its digits. 
 * Return how many groups have the largest size.
 * 
 * Example 1:
 * Input: n = 13
 * Output: 4
 * Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
 * [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
 * 
 * 从1-n位数和相加，比如
 * 输入n=13，输出=4，Input: n = 13，有这么几组数字
 * [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
 * 1 和 10的位数和相等，2 和 11 的位数和相等，4 和 13 的位数和相等。
*/

/**
 * 方法 1，使用哈希表的方法，遍历数组中的每一个数字，然后求他的位数和的次数，把这个位数和放到一个新的数组中去，
 * 统计这个数组中的最大的位数和出现的次数
 * 然后看新的统计次数的数组中，判断是否和最大出现次数相同，如果相同的话，那么就自加1
*/
int countLargestGroup(int n)
{
    int sum = 0, maxCount = 0;
    vector<int> temp(37);
    for (int i = 1; i < n + 1; i++)
    {
        int num = 0;
        int tempNum = i;
        while (tempNum)
        {
            num += tempNum % 10;
            tempNum = tempNum / 10;
        }
        temp[num]++;
        maxCount = max(maxCount, temp[num]);
    }

    for (int i = 0; i < 37; i++)
    {
        if (temp[i] == maxCount)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    cout << countLargestGroup(13) << endl;
}