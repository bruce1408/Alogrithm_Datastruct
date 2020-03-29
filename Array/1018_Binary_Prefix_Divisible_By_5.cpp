#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/**
 * Given an array A of 0s and 1s, 
 * consider N_i: the i-th subarray 
 * from A[0] to A[i] interpreted as a binary number 
 * (from most-significant-bit to least-significant-bit.)
 * 
 * Return a list of booleans answer, where answer[i] is true 
 * if and only if N_i is divisible by 5.
 * 
 * Example 1:
 * Input: [0,1,1]
 * Output: [true,false,false]
 * Explanation: 
 * The input numbers in binary are 0, 01, 011; 
 * which are 0, 1, and 3 in base-10. 
 * Only the first number is divisible by 5, so answer[0] is true.
 * 返回可以被5整除的布尔数组
*/

/**
 * 方法 1， 遍历数组，然后设置一个十进制的数求和sum=0
 * 每次sum的值*2，然后加上下载这个数，最后sum对5求余数，
 * 如果整除，那么为true
*/
vector<bool> prefixesDivBy5(vector<int> &A)
{
    vector<bool> res(A.size(), false);
    long sumNum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sumNum = sumNum * 2 + A[i];
        // 如果不加下面这一句的话会越界！
        sumNum = sumNum % 5;
        if (sumNum % 5 == 0)
        {
            res[i] = true;
        }
    }
    return res;
}

int main()
{
    vector<int> res = {1, 0, 1, 0, 0, 0, 1};
    for (auto i : prefixesDivBy5(res))
    {
        cout << i << " ";
    }
}