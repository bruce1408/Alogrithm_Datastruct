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
 * 
 * 一个数组一般是偶数，一般是奇数，通过算法让对应偶数下标的也是偶数
 * 对应奇数下标的也是奇数。例如
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] 
 * would also have been accepted.
*/

/**
 * 方法 1，思路就是使用两个指针，同时指向数组中的每一个数字，如果该数字和下标
 * 对2取余数字相同，那么跳过该数字，否则，j指针进入遍历数组，
 * 如果下一个数字不是偶奇对，那么就互换这两个数字，break当前循环，
 * 如果下一个数字也满足条件，继续遍历数组到结束为止。
 * 这个和方法 4思路都一样
 * 时间复杂度nlgn
 * 
*/
vector<int> sortArrayByParityII(vector<int> &A)
{
    int i = 0, j = 1, len = A.size();
    while (i < len )
    {
        if (A[i] % 2 == 0) 
            i += 2;
        else // 不满足偶数条件
        {
            while (j < len)
            {
                if (A[j] % 2 != 1) // 如果不满足奇数条件
                {
                    swap(A[i], A[j]);
                    break;
                }
                else
                    j += 2;
            }
        }
    }
    return A;
}

/**
 * 方法 2 使用的是两个指针，比上面的方法快一些，如果偶数下标的数字
 * 不满足条件，则判断奇数下标，奇数下标不满足条件，则交换两个数字
*/
vector<int> sortArrayByParityII2(vector<int> &A)
{
    int odd = 1, len = A.size();
    for (int even = 0; even < len; even += 2)
    {
        if (A[even] % 2) // 偶数下标不满足条件则进入循环
        {
            while (A[odd] % 2) // 奇数下标满足条件，循环终止就不满足，互换i和j的元素
            {
                odd += 2;
            }
            swap(A[even], A[odd]);
        }
    }
    return A;
}

/**
 * 方法 3 还是利用2个指针，但是时间复杂度很小。和方法 2异曲同工，代码最简练；
 * 都是利用2个指针，思路更加自然一些。
*/
vector<int> sortArrayByParityII3(vector<int> &A)
{
    for (int i = 0, j = 1; i < A.size(); i += 2, j += 2)
    {
        while (i < A.size() && A[i] % 2 == 0) // 偶数下标满足
        {
            i += 2;
        }
        while (j < A.size() && A[j] % 2 == 1) // 奇数下标满足
        {
            j += 2;
        }
        if (i < A.size() && j < A.size()) // 不满足的话互换即可
        {
            swap(A[i], A[j]);
        }
    }
    return A;
}

/**
 * 方法 4，利用两个指针，如果分别指向偶数下标和奇数下标，如果偶数和奇数同时满足条件，那么就同时加2，
 * 跳到下一个判断的位置，否则，如果偶数下标不满足，则遍历奇数下标，交换不满足的奇数下标元素，如果奇数下标
 * 不满足，那么遍历偶数下标的元素，最后交换偶数下标的元素即可。和方法 1思路一样，但是代码写的有些冗余
*/
vector<int> sortArrayByParityII4(vector<int> &A)
{
    int len = A.size();
    int i = 0, j = 1;
    while (i < len && j < len)
    {
        if (A[i] % 2 == 0 && A[j] % 2 == 1)
        {
            i += 2, j += 2;
        }
        else
        {
            if (A[i] % 2 != 0)
            {
                while (A[j] % 2 == 1 && j < len)
                    j += 2;
                swap(A[i], A[j]);
            }
            if (A[j] % 2 == 0)
            {
                while (A[i] % 2 == 0 && i < len)
                    i += 2;
                swap(A[i], A[j]);
            }
        }
    }
    return A;
}

int main()
{
    vector<int> res = {3, 1, 4, 2};
    for (auto i : sortArrayByParityII(res))
    {
        cout << i << endl;
    }
}