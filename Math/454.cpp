#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * 454 使用hash表来存储前两个数组的数字之和的出现次数，然后再遍历其他两个数组的数字之和，
 * 在hash表中查找是否存在当前数字之和的负数，然后累计次数即可
*/
int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
{
    unordered_map<int, int> hash;

    for (auto c : C)
    {
        for (auto d : D)
        {
            hash[(c + d)]++;
        }
    }

    int res = 0;
    for (auto a : A)
    {
        for (auto b : B)
        {
            res += hash[-(a + b)];
        }
    }
    return res;
}
