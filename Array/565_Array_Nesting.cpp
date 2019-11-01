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
 * *重做一遍；
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
    int tempK = k;
    for(int i=0;i<num.size();i++)
    {
        int index = i;
        tempK = num[tempK];
       
        if(res.count(tempK)==0)
        {
            res.insert(tempK);
        }
    }
    return res.size();
}

int arrayNesting1(vector<int>&nums)
{
    set<int>res;
    int result = INT32_MIN;
    for(int i=0;i<nums.size();i++)  // 和方法 2相比，这里少了一个判断的数组；所以时间复杂度是O(n^2);
    {
        result = max(result, recurise(nums, i));
    }
    return result;
}

/**
 * 方法 2， 和方法 1相比，主要在helper处进行了代码简化，方法 1是
 * 循环计算每个元素和位置然后给如果哈希表没有出现，就装进去，但是方法 2思路是下次出现重复数字必定是
 * 新的数组中的头部位置，所以只要记录的位置i和开始位置不等即可，然后返回计数的次数cnt即可；
 * 另外在arrayNesting函数中，辅助数组中出现这个数字那么就不判断，否则进行判断，也节省了大量的时间；
 */
int helper(vector<int>& nums, int start, vector<bool>& visited)  
{
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
        if (visited[nums[i]]) continue; // 这个数字没有出现时候是false，进行判断，否则，不用判断了；这里认为之前出现过得不用判断
        // 这个是怎么证明呢？
        res = max(res, helper(nums, i, visited));
    }
    return res;
}

/**
 * 方法 3，对方法 2进行优化，思路都是一样的；
*/
int arrayNesting3(vector<int>& nums) 
{
    int n = nums.size(), res = INT32_MIN;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) 
    {
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

/**
 * 方法 4,利用不需要新建一个辅助数组，核心的思想就是如果某个数出现在正确的下标索引位置上，那么
 * 它一定不能组成嵌套数组；
 * 比如说：{ 5,4,0,3,1,6,2 }；
 * A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2；
 * S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}，那么A[0] = 5;在第5个位置上的元素就是5；出现
 * 了相应位置上的元素相同的情况，类似这种情况就构不成嵌套数组；
 * *方法 4 非常好理解
 * 
*/
int arrayNesting4(vector<int>&nums)
{
    int res = 0;
    for(int i=0;i<nums.size();i++)
    {
        int cnt = 1;
        while(nums[i]!=i) // 遍历每个元素；
        {
            swap(nums[i], nums[nums[i]]);
            cnt+=1;
        }
        res = max(res, cnt);
    }
    return res;
}

int main()
{
    vector<int>res = {5,4,0,3,1,6,2};
    cout<<arrayNesting4(res)<<endl;
}
