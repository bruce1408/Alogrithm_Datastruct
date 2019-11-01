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
    return res;
}

int main()
{
    vector<int> res = {1, 2, 0, 0};
    for(auto i:addToArrayForm(res, 34))
    {
        cout<<i<<" ";
    }
}