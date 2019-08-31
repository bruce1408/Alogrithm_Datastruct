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
*/

/**
 * 方法 1：
 * 偶数全部放前面，奇数全部放后面 [3,2,1,4]==> [2,4,1,3]
 * 不过复杂度来讲的话有点高；
*/
vector<int> sortArrayByParity1(vector<int> &A)
{
    int j = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 != 0) // 先判断是不是奇数，如果是
        {
            j = i;
            while (j < A.size())
            {
                if (A[j] % 2 == 0)
                    break;
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
 * 方法 1，和上面的思路差不多一样，但是比上面的很自然，就是用两个指针来做，
 * 一个指向当前，还有一个指向下一个数，指当前数先判断是否是奇数，如果是奇数，那么下一下
 * 指针则判断是否是偶数，如果是偶数，交换两个数的位置，然后break退出，
 * 否则，那个快指针继续指向下一个数，知道数组末尾位置。
 * 时间复杂度：由于是两个指针，应该是nlgn的时间复杂度；
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

// 方法 2 这个就是利用C++排序的比较算法，很取巧的算法。
vector<int> sortArrayByParity2(vector<int> &A)
{
    std::sort(A.begin(), A.end(), [](int &a, int &b) -> bool { return a % 2 < b % 2; });
    return A;
}

/**
 * 方法 3 可以叫做偶数前移方法, 这种方法的思路两个指针，慢指针和快指针，快、慢初始设置为0，
 * 快指针遍历数组，先判断是不是偶数，如果是偶数就交换，和慢指针指向的数字交换，然后满指针交换
 * 之后就要自加1次，比如2，3，1，4，第一次2和2交换之后，慢指针加1指向3，然后快指针遍历到4的时候，
 * 是偶数，需要和慢指针交换，那么就是 4 和 3 交换。
 * */
vector<int> sortArrayByParity3(vector<int> &A)
{
    int slow = 0;
    for (int fast = 0; fast < A.size(); fast++)
    {
        if (!(A[fast] & 1)) // 如果快指针遍历的是偶数的话，快慢指针互换，同时慢指针加1；
        {
            int temp = A[slow];
            A[slow] = A[fast];
            A[fast] = temp;
            slow++;
        }
    }
    return A;
}

/**
 * 方法 4 设置两个数组，一个存奇数一个存偶数然后合并。
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
 * 还是两个指针，分别指向数组的头和尾，如果是偶数，头指针后移一位，如果是奇数且尾指针指向的是
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
        if (A[i] % 2 == 0) i++;
        else
        {
            if (A[j] % 2 != 0) j--; // 如果尾指针也是奇数，那么减1
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
    for (auto i : sortArrayByParity5(re))
    {
        cout << i << endl;
    }
    return 0;
}