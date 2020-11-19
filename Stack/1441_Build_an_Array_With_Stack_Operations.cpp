#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/**
 * Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.
 * 
 * Input: target = [1,3], n = 3
 * Output: ["Push","Push","Pop","Push"]
 * 
 * Explanation: 
 * Read number 1 and automatically push in the array -> [1]
 * Read number 2 and automatically push in the array then Pop it -> [1]
 * Read number 3 and automatically push in the array -> [1,3]
 * 
 * 按照栈的思维来存放一个字符，给定目标数组，还有一个n，n的范围从1-n开始，然后
 * 从1-n开始按照栈的操作压栈和出栈，最后使得和目标数组一样的结果，记录操作的记录。
 */

/**
 * 方法 1，使用一个for循环，两个指针来记录位置即可
*/
vector<string> buildArray(vector<int> &target, int n)
{
    int t = target.size(), k = 0, i = 1;
    vector<string> res;
    while (k < t)
    {
        if (i == target[k])
        {
            k++;
            res.push_back("Push");
        }
        else
        {
            res.push_back("Push");
            res.push_back("Pop");
        }
        i++;
    }
    return res;
}

/**
 * 方法 2，参考的lc上面的排名靠前的方法，感觉没有方法 1简单，其实可以双指针来做的。不必使用
 * 两层循环。
*/
vector<string> buildArray2(vector<int> &target, int n)
{
    int i = 1;
    vector<string> ans;
    for (int j = 0; j < target.size(); j++)
    {
        while (i <= n && i != target[j])
        {
            ans.push_back("Push");
            ans.push_back("Pop");
            i++;
        }
        ans.push_back("Push");
        i++;
    }
    return ans;
}
int main()
{
    vector<int> res = {2, 3, 4};
    int n = 4;
    for (auto i : buildArray(res, n))
    {
        cout << i << " ";
    }
}