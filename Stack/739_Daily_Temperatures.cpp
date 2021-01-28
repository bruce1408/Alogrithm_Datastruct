#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * 739 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：
 * 要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替
 * 输入：
 * [73, 74, 75, 71, 69, 72, 76, 73]，
 * 输出
 * [1, 1, 4, 2, 1, 1, 0, 0]
 * 
*/

/**
 * 方法 1，其实就是从右往左求解比当前数还要大的最近的数的位置，然后它和当前数的距离即可
 * 这里使用单调栈来做，单调栈之前遇到的都是找到数组左边比它还小的最近的数所在的位置，那么
 * 这里是从右往左，所以从右边开始遍历，然后出栈的条件也不一样，左边比它还小的条件是如果栈顶元素
 * 大于等于当前数字，那么栈顶元素直接出栈，这里是找到大于当前元素，所以栈顶元素如果小于等于当前数的话，
 * 那么栈顶元素出栈，然后如果栈为空，那么如题目所说下标为0，否则当前下标是栈顶元素和当前数字i的差值就是距离
 * 最后当前i下标入栈
*/
vector<int> dailyTemperatures(vector<int> &t)
{
    vector<int> res(t.size());
    stack<int> ans;
    for (int i = t.size() - 1; i >= 0; i--)
    {
        while (!ans.empty() && t[ans.top()] <= t[i])
            ans.pop();
        if (ans.empty())
            res[i] = 0;
        else
            res[i] = ans.top() - i;
        ans.push(i);
    }
    return res;
}

int main()
{
    vector<int> res = {73, 74, 75, 71, 69, 72, 76, 73};
    for (auto x : dailyTemperatures(res))
        cout << x << " ";
    cout << endl;
}