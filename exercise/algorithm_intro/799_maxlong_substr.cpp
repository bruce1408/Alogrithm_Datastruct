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

int maxSubstr(vector<int> &res)
{
    int maxNum = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int count = 1;
        for (int j = i; j < res.size() - 1; j++)
        {
            if (res[j] != res[j + 1])
                count++;
            else
            {
                i = j;
                break;
            }
            maxNum = max(count, maxNum);
        }
    }
    return maxNum;
}

int maxSubstr1(vector<int> &res)
{
    int maxnum = 0;
    for (int i = 0; i < res.size(); i++)
    {
        vector<int> nums(100010);
        int count = 0;
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
int main()
{
    // int n = 5;
    // cin>>n;
    vector<int> res = {9, 3, 6, 9, 5, 10, 1, 2, 3, 9};
    // for (int i = 0; i < n; i++)
    //     cin >> res[i];
    cout << maxSubstr1(res) << endl;
}