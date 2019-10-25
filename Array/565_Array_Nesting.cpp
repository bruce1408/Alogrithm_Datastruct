#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

/**
 * A zero-indexed array A of length N contains all integers from 0 to N-1.
 * Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }
 * subjected to the rule below.
 * 
 * Suppose the first element in S starts with the selection of element A[i] of index = i,
 * the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy,
 * we stop adding right before a duplicate element occurs in S.
 * 
 * Example 1:
 * Input: A = [5,4,0,3,1,6,2]
 * Output: 4
 * Explanation: 
 * 
 * A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
 * One of the longest S[K]:
 * S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 * 
*/


/**
 * 方法 1，暴力解法，因为S[0] = A[0], A[A[0]], A[A[A[0]]]...
 * 所以暴力做法就是每次遍历元素，然后把这个数字给recurise，让recurise函数处理
 * recurise函数用法是A[0]这个元素进行 0到n-1次的遍历；A[0], A[A[0]],A[A[A[0]]]...
 * 把这个新的元素集合装到哈希set中，这里不用set是只用了查找功能，可以加快时间，如果哈希set
 * 有重复的数值，那么直接返回当前的哈希表的长度，否则，直接返回哈希表的长度；
 * 然后对每个返回值进行比较，取最后较大的数字即可；
*/
int recurise(vector<int>&num, int k)
{
    vector<int>result;
    unordered_set<int>res;
    for(int i=0;i<num.size();i++)
    {
        int index = i;
        int tempK = k;
        while(index>=0)
        {
            tempK = num[tempK];
            index--;   
        }
        if(res.count(tempK)==0)
        {
            res.insert(tempK);
        }
        else
        {
            return res.size();
        }
    }
    return res.size();
}

int arrayNesting1(vector<int>&nums)
{
    set<int>res;
    int result = INT32_MIN;
    for(int i=0;i<nums.size();i++)
    {
        int comp = recurise(nums, i);
        if(result<comp)
        {
            result = comp;
        }
    }
    return result;
}

/**
 * method 2
 */


int helper(vector<int>& nums, int start, vector<bool>& visited) {
    int i = start, cnt = 0; // 记录数组中存放了多少个元素；
    while (cnt == 0 || i != start) // 是否次数是0，表示刚开始计数，或者是
    {
        visited[i] = true;
        i = nums[i];  
        ++cnt;
    }
    return cnt;
}

int arrayNesting2(vector<int>& nums) 
{
    int n = nums.size(), res = INT32_MIN;
    vector<bool> visited(n, false);
    for (int i = 0; i < nums.size(); ++i) 
    {
        if (visited[nums[i]]) continue;
        res = max(res, helper(nums, i, visited));
    }
    return res;
}

/**
 * 方法 3，
*/
int arrayNesting3(vector<int>& nums) 
{
    int n = nums.size(), res = INT32_MIN;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (visited[nums[i]]) continue;
        int cnt = 0, j = i;
        while(cnt == 0 || j != i) {
            visited[j] = true;
            j = nums[j];
            ++cnt;
        }
        res = max(res, cnt);
    }
    return res;
}


int main()
{
    vector<int>res = {1,2,0};
    cout<<arrayNesting3(res)<<endl;
}
