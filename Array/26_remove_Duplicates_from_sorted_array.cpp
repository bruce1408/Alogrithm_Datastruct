#include <iostream>
#include <vector>
using namespace std;

/**
 *  26, 去掉数组中重复的数字，返回的是非重复数组的长度；
 */

/**
 * 方法 1，回家等通知算法；
*/
int removeDuplicates1(vector<int> &nums)
{
    int m = unique(nums.begin(), nums.end()) - nums.begin();
    nums.resize(m);
    return m;
}

/**
 * 方法 2，数组是排好序的，使用原地算法，如果这个数和前面不一样，就保存这个数
 * 使用双指针
*/
int removeDuplicates2(vector<int> &res)
{
    if (res.empty())
        return 0;
    int n = res.size(), i = 0;
    for (int j = 0; j < n; j++)
    {
        if (res[i] != res[j])
            res[++i] = res[j];
    }
    return i + 1;
}

/**
 * 方法 3，写法略有不同，但是思路一样
*/
int removeDuplicates3(vector<int> &res)
{
    int n = res.size(), k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || res[i] != res[i - 1])
            res[k++] = res[i];
    }
    return k;
}

int main()
{
    vector<int> num = {1, 1, 2, 2, 3, 4, 5, 5, 6};
    int i = removeDuplicates3(num);
    for (int j = 0; j < i; j++)
    {
        cout << num[j] << " ";
    }
}