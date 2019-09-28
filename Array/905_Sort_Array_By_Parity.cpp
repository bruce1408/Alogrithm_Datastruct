#include <iostream>
#include <vector>
using namespace std;
/**
 * Given an array A of non-negative integers, 
 * return an array consisting of all the even elements of A,
 * followed by all the odd elements of A.
 * You may return any answer array that satisfies this condition.
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * 返回一个偶数在前，奇数在后的数组；
 * *再做一次
*/

/**
 * 方法 1：
 * 偶数全部放前面，奇数全部放后面 [3,2,1,4]==> [2,4,1,3]
 * 设置两个指针，一个是i，从0开始遍历数组，还有一个是j，从0开始。i遍历数组，如果这个数字是偶数的话，
 * 那么就是当前的指针i指向的数和j开始交换位置，同时j++，如果不是的话，那么继续i向后遍历。只用时间复杂度是
 * O(n)即可；
*/
vector<int> sortArrayByParity(vector<int> &A)
{
    for (int i = 0, j = 0; i < A.size(); i++)
    {
        if ((A[i] & 1) == 0)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
    return A;
}

/**
 * 方法 2，遍历数组，如果当前的数字是奇数，那么来一个新的指针j，让它指向当前的数字下标，
 * 然后这个指针j的范围不能超过数组长度，如果j从i开始向后遍历，如果是偶数，直接退出当前的
 * 循环，否则j继续遍历；偶数的情况j退出之后，j和i都不超过数组长度的情况，交换i和j的数字即可； 
 * */
vector<int> sortArrayByParity1(vector<int> &A)
{
    int j = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 != 0) // 是奇数就进行交换
        {
            j = i;
            while (j < A.size())
            {
                if (A[j] % 2 == 0)
                    break; // 只要找到了一个偶数就停止寻找
                else
                    ++j;
            }
            if (i < A.size() && j < A.size())
                swap(A[i], A[j]);
        }
    }
    return A;
}

/**
 * 方法 3，和上面的思路差不多一样，但是比上面的很自然，就是用两个指针来做，
 * 一个指向当前，还有一个指向下一个数，指当前数先判断是否是奇数，如果是奇数，那么下一下
 * 指针则判断是否是偶数，如果是偶数，交换两个数的位置，然后break退出，
 * 否则，那个快指针继续指向下一个数，知道数组末尾位置。方法 3和 方法 1的思路一样，但是
 * 写法上多了一重循环，建议以方法1为准即可！
 * 时间复杂度：由于是两个指针，应该是nlogn的时间复杂度；
*/
vector<int> sortArrayByParity_(vector<int> &res)
{
    for (int i = 0; i < res.size(); i++)
    {
        int j = i + 1;
        if (res[i] & 1) // 当前是奇数
        {
            while (j < res.size())
            {
                if (!(res[j] & 1)) // 是偶数，则交换
                {
                    int temp = res[i];
                    res[i] = res[j];
                    res[j] = temp;
                    break;
                }
                else
                    j += 1;
            }
        }
    }
    return res;
}

/**
 * 方法 4 这个就是利用C++排序的比较算法，很取巧的算法。
 * */
vector<int> sortArrayByParity2(vector<int> &A)
{
    std::sort(A.begin(), A.end(), [](int &a, int &b) -> bool { return a % 2 < b % 2; });
    return A;
}

/**
 * 方法 5，设置两个数组，一个存奇数一个存偶数然后合并。
 * 之后把两个数组合并
*/
vector<int> mergeTwoVector(vector<int> &res)
{
    vector<int> even, odd;
    for (auto num : res)
    {
        if (num & 1)
            odd.push_back(num);
        else
            even.push_back(num);
    }
    even.insert(even.end(), odd.begin(), odd.end());
    return even;
}

/**
 * 方法 6，还是两个指针，分别指向数组的头和尾，如果是偶数，头指针后移一位，如果是奇数且尾指针指向的是
 * 偶数，那么就互换一下，同时头指针加1，尾指针减1，而如果是头指针指向的是奇数且尾指针也是奇数，
 * 尾指针自减1，因为本来就是需要把奇数放到最后：
 * 例如 3，1，2，4，头指向3，尾指向4，头是奇数且尾是偶数，那么互换，4，1，2，3
*/
vector<int> sortArrayByParity5(vector<int> &A)
{
    int i = 0;
    int j = A.size() - 1;
    while (i < j)
    {
        if (A[i] % 2 == 0) // 偶数的情况
            i++;
        else
        {
            if (A[j] % 2 != 0)
                j--;           // 如果尾指针也是奇数，那么减1
            if (A[j] % 2 == 0) // 偶数的话互换
            {
                swap(A[i], A[j]);
                i++, j--;
            }
        }
    }
    return A;
}

int main()
{
    vector<int> re = {0, 1, 2};
    for (auto i : sortArrayByParity(re))
    {
        cout << i << endl;
    }
    return 0;
}