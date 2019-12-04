#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/**
 * For a non-negative integer X, 
 * the array-form of X is an array of its digits in left to right order.
 * For example, if X = 1231, then the array form is [1,2,3,1].
 * Given the array-form A of a non-negative integer X, 
 * return the array-form of the integer X+K.
 * 
 * Example 1:
 * Input: A = [1,2,0,0], K = 34
 * Output: [1,2,3,4]
 * Explanation: 1200 + 34 = 1234
*/

/**
 * 方法 1，暴力解决，就是把数组的数字凑成一个整数，然后开始和k相加，再把这个结果拆成数组，
 * 但是这样的话有可能会越界，比如999999999...所以这个理论虽然可以，但是实际上越界；
*/
vector<int> addToArrayForm(vector<int> &A, int K)
{
    int sumNum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sumNum = sumNum * 10 + A[i];
    }
    sumNum = sumNum + K;

    vector<int> res;
    stack<int> temp;
    while (sumNum)
    {
        temp.push(sumNum % 10);
        sumNum = sumNum / 10;
    }
    while (!temp.empty())
    {
        res.push_back(temp.top());
        temp.pop();
    }
    if (res.empty())
    {
        return {0};
    }
    return res;
}

/**
 * 方法 2，利用的是每一位相加，然后有进位
*/
vector<int> addToArrayForm2(vector<int> &A, int K)
{
    vector<int> temp;
    vector<int> res;
    int n = A.size();
    while (K)
    {
        temp.push_back(K % 10);
        K = K / 10;
    }
    for (auto i : temp)
    {
        cout << i << endl;
    }
    int digit = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int num = 0;
        if (n - i - 1 < temp.size())
        {
            num = temp[n - i - 1] + A[i] + digit;
        }
        else
        {
            num = A[i] + digit;
        }

        if (num >= 10 && i == 0)
        {
            A.insert(A.begin(), 1, num / 10);
            num = num % 10;
            A[1] = num;
        }

        else if (num >= 10 && i > 0)
        {
            A[i] = num % 10;
            digit = 1;
        }
        else if (num < 10)
        {
            A[i] = num;
            digit = 0;
        }
    }
    if (temp.size() > A.size())
    {
        for (int i = 0; i < temp.size() - n; i++)
        {
            A.insert(A.begin(), 1, temp[n + i] + digit);
            digit = 0;
        }
    }
    return A;
}
/**
 * 方法 3，不用新的数组，直接在原来的数组上进行操作，最优方法
*/
vector<int> addToArrayForm3(vector<int> &A, int K)
{
    for (int i = A.size() - 1; i >= 0 && K > 0; i--)
    {
        A[i] += K;
        K = A[i] / 10;
        A[i] = A[i] % 10;
    }
    while (K > 0)
    {
        A.insert(A.begin(), K % 10);
        K = K / 10;
    }
    return A;
}

int main()
{
    vector<int> res = {6};
    for (auto i : addToArrayForm3(res, 809))
    {
        cout << i << " ";
    }
}