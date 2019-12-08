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
    // for (auto i : temp)
    // {
    //     cout << i << endl;
    // }
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
 * 方法 3，不用新的数组，直接在原来的A数组进行操作,
*/
vector<int> addToArrayForm3(vector<int> &A, int K)
{
    vector<int> temp;
    int digit = 0, n = A.size(), bitK = 0;
    while (K)
    {
        temp.push_back(K % 10);
        K = K / 10;
    }
    int m = temp.size();
    int i = n - 1, num = 0;
    for (; i >= 0; i--) // 以A为基准，这种情况是A的元素多于temp的数组
    {
        if (n - i - 1 < m) // temp 没有越界
        {
            num = A[i] + temp[n - i - 1] + digit;
            if (num >= 10)
            {
                A[i] = num % 10;
                digit = num / 10;
            }
            else
            {
                A[i] = num;
                digit = 0;
            }
        }
        else // temp 越界后的情况
        {
            num = A[i] + digit;
            if (num >= 10)
            {
                A[i] = num % 10;
                digit = num / 10;
            }
            else
            {
                A[i] = num;
                digit = 0;
            }
        }
        bitK++;
    }
    while (bitK < m) //这种情况是A的元素少于temp的数组
    {
        num = temp[bitK] + digit;
        if (num >= 10)
        {
            A.insert(A.begin(), num % 10);
            digit = num / 10;
        }
        else
        {
            A.insert(A.begin(), num);
            digit = 0;
        }
        bitK++;
    }
    if (digit == 1)
    {
        A.insert(A.begin(), digit);
    }
    return A;
}

/**
 * 方法 4
 * 需要新开辟的数组answer，
*/
vector<int> addToArrayForm4(vector<int> &a, int k)
{
    vector<int> answer;
    int carry = 0;
    while (!a.empty() || k != 0)
    {
        int lastDigit_1 = a.empty() ? 0 : a.back();
        int lastDigit_2 = k % 10;
        int sum = lastDigit_1 + lastDigit_2 + carry;
        answer.push_back(sum % 10);
        carry = sum / 10;
        if (!a.empty())
            a.pop_back();
        k = k / 10;
    }
    if (carry != 0)
        answer.push_back(carry);
    reverse(answer.begin(), answer.end());
    return answer;
}

/**
 * 方法 5，很好的方法；
 * 不需要对K进行逐位处理，而是把K和A的每一位都加起来，加起来之后K = A[i]/10;
 * 然后当前的A[i]是把A[i]%10；
 * for循环结束之后，K如果还大于0的话，说明需要在A[i]的头部插入K%10;
 * K/=10; 
*/
vector<int>addToArrayForm5(vector<int>& A, int K){
    for(int i=A.size()-1; i>=0 && K>0; i--)
    {
        A[i] = A[i]+K;
        K = A[i]/10;
        A[i]%=10;
    }
    while(K>0)
    {
        A.insert(A.begin(), K%10);
        K = K/10;
    }
    return A;
}
int main()
{
    vector<int> res = {6};
    for (auto i : addToArrayForm4(res, 806))
    {
        cout << i << " ";
    }
}