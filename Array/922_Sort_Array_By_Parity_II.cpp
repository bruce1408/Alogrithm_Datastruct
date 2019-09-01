#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Given an array A of non-negative integers, 
 * half of the integers in A are odd, 
 * and half of the integers are even.
 * Sort the array so that whenever A[i] is odd, 
 * i is odd; and whenever A[i] is even, i is even.
 * You may return any answer array that satisfies 
 * this condition.
 * 一个数组一般是偶数，一般是奇数，通过算法让对应偶数下标的也是偶数
 * 对应奇数下标的也是奇数。例如
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] 
 * would also have been accepted.
*/

/**
 * 方法 1，时间复杂度太高了，改变了原来的数组。思路就是
 * 使用两个指针，同时指向数组中的每一个数字，如果该数字和下标
 * 对2取余数字相同，那么跳过该数字，否则，快指针进入遍历数组，
 * 如果下一个数字不是偶奇对，那么就互换这两个数字，break当前循环，
 * 如果下一个数字也满足条件，继续遍历数组到结束为止。
 * 
 * 时间复杂度nlogn
 * 
*/
vector<int> sortArrayByParityII(vector<int> &A)
{
    int i = 0, len = A.size();
    while (i < len - 1)
    {
        int j = i;
        if (A[i] % 2 == i % 2)
            i += 1;
        else
        {
            while (j + 1 < len)
            {
                j += 1;
                if (A[j] % 2 != j % 2)
                {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    break;
                }
                else
                    j += 1;
            }
        }
    }
    return A;
}

/**
 * 方法 2 使用的是两个指针，比上面的方法快一些，如果偶数下标的数字
 * 不满足条件，则判断奇数下标，奇数下标不满足条件，则交换两个数字
 * 
*/

vector<int> sortArrayByParityII2(vector<int> &A)
{
    int odd = 1, len = A.size();
    for (int even = 0; even < len; even += 2)
    {
        if (A[even] % 2) // 偶数下标不满足条件
        {
            while (A[odd] % 2)
            {
                odd += 2;
            }
            swap(A[even], A[odd]);
        }
    }
    return A;
}

/**
 * 方法 3 还是利用2个指针，但是时间复杂度很小。和方法 2 异曲同工
 * 都是利用2个指针，思路更加自然一些。
*/
vector<int> sortArrayByParityII3(vector<int>& A) 
{
    for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) 
    {
        while (i < A.size() && A[i] % 2 == 0) 
        {
            i += 2;
        }
        while (j < A.size() && A[j] % 2 == 1) 
        {
            j += 2;
        }
        if (i < A.size() && j < A.size())
        {
            swap(A[i], A[j]);
        } 
    }
    return A;
}


int main()
{
    vector<int> res = {4, 2, 5, 7};
    for (auto i : sortArrayByParityII3(res))
    {
        cout << i << endl;
    }
}