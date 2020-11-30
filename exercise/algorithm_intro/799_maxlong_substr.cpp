#include <iostream>
#include <string>
#include <vector>
#include "../../utils/cout_vec.h"
using namespace std;

/**
 * 给定一个长度为n的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。
 * 输入格式
 * 第一行包含整数n。
 * 第二行包含n个整数（均在0~100000范围内），表示整数序列。
 * 
 * 输出格式,共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。
 * 
 * 数据范围
 * 1≤n≤100000
 * 输入样例：
 * 5
 * 1 2 2 3 5
 * 输出样例：
 * 3
*/

/**
 * 方法 1，使用一个记录次数的数组，然后每次记录重复出现的次数
 * 如果之前没有出现这个数字，那么统计长度的数字count自加一次，该数字对应的次数也加1，
 * 否则退出当前循环，从下一位开始遍历，最后返回最长的那个长度即可，这里的时间复杂度是O(n^2)
*/
int maxSubstr1(vector<int> &res)
{
    int maxnum = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int count = 0;
        vector<int> nums(100010);

        for (int j = i; j < res.size(); j++)
        {
            if (nums[res[j]] == 0)
            {
                count++;
                nums[res[j]] += 1;
            }
            else
                break;
               
            maxnum = max(count, maxnum);
        }
    }
    return maxnum;
}

/**
 * 方法 2，方法 1时间太长了，需要对这个双指针算法进行改进，降低时间复杂度；
 * i从0到n开始遍历，然后j对应的次数是先减次数后右移，如果次数大于1，那么减去当前的次数，然后右移
*/
int maxSubstr2(vector<int>&res)
{
    int n = res.size(), count = 0;
    vector<int>temp(100010);
    for(int i = 0, j = 0;i<n;i++)
    {
        temp[res[i]]++;
        while(j<=i && temp[res[i]]>1)  // 当前这个数组中的数字次数超过1
        {
            temp[res[j]]--;  // 那么就对大于1的数字减1，然后j向后走
            j++;
        }
        count = max(i-j+1, count); // 得到最大的值
    }
    return count;
}
int main()
{
    // int n = 5;
    // cin>>n;
    vector<int> res = {1,0,2,3,5, 2};
    // for (int i = 0; i < n; i++)
    //     cin >> res[i];
    cout << maxSubstr2(res) << endl;
}