#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/**
 * 题目是要求数组的度，就是包含重复最多元素的最小子序列，必须是连续的；度就是重复
 * 数字最多的元素，切下标之差最小的
 * 比如 [1，2，2，3，1]；2重复了2次，1也重复了2次，最小子序列长度很明显，是包含2的长度为2；
 * [1,2,2,3,1,4,2]，重复最多的元素是2，包含2的连续子序列的长度是6，返回6；
 * [1,1,2,2,2,1] 1 和 2 都重复了3次，但是2的最短子序列的长度是3，所以返回3；
 * */

/**
 * 方法 1，自己做的时间复杂度较高，在n个元素的数组中，加入同时存在n/2个重复的数字，比如[1,1,2,2,3,3], 
 * 重复数字是1，2，3；那么间复杂度是O(n/2 * n) = O(n^2),空间复杂度是O(n);
 * 思路就是在数组中，利用哈希表来记录每一个元素重复的次数，同时找到重复次数最多的元素，放进一个新的临时数组temp中去，
 * 然后挨个遍历重复次数最多的元素，我们下一步是希望找到这个最多元素的起始出现位置和结束位置，这样两者相减就是序列的长度，
 * 这个序列的长度和其他的重复数字序列长度比较，最终取最短的返回即可；所以这里找到重复元素的位置尤为关键，
 * 在temp中遍历重复元素的时候，每次设置一个临时的长度遍历tempLength，然后appear=0是第一次出现的位置，
 * 往后变加1，这样可以得到该重复元素长度序列，以此类推和temp中的下一个重复元素临时长度比较，最短的赋值给minLength；
 * 返回即可；总的来说时间复杂度比较高，最坏的情况下达到了O(n^2),leetcode提交的结果
 * 是超过了5%。还是可以继续优化
*/
int findShortestSubArray1(vector<int> &nums)
{
    unordered_map<int, int> res;
    vector<int> temp;
    vector<int> location(nums);
    int numCount = 0;
    for (int i = 0; i < nums.size(); i++) // find the maxnum frequency elements
    {
        ++res[nums[i]];
        // if (res[nums[i]] > numCount)
        // {
        //     numCount = max(res[nums[i]], numCount);
        // }
        if (res[nums[i]] > numCount)
        {
            numCount = res[nums[i]];
        }
    }
    cout << "the numCount is: " << numCount << endl;
    for (auto i : res)
    {
        if (i.second == numCount)
        {
            temp.push_back(i.first);
        }
    }
    int minLength = INT_MAX;
    for (int i = 0; i < temp.size(); i++)
    {
        int tempLength = 0, beginIndex = 0, endIndex = 0, appear = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == temp[i] && appear == 0)
            {
                beginIndex = j;
                appear += 1;
            }
            if (nums[j] == temp[i] && appear > 0)
            {
                endIndex = j;
            }
        }
        tempLength = endIndex - beginIndex;
        minLength = min(tempLength, minLength);
    }
    return minLength + 1;
}

/**
 * 方法 2这里忽略了一种情况，就是如果一个数组有多个重复次数相同的元素没有考虑进去，
 * 比如[2,1,1,2,1,3,3,3,1,3,1,3,2];这个数组同时存在两个数1，3，他们重复次数相同，都是5
 * 但是因为程序会先计算最开始出现的那个数字，也就是1，如果1最先达到了5次，那么后面即使3也出现了
 * 5次他也不会考虑，最后按照3来计算最小序列，这显然不科学，要么就是给一个数组来装重复数字，例如方法1
 * temp来保存1和数字3，然后遍历他们，计算最小的序列；
*/
int findShortestSubArray2(vector<int> &nums)
{
    if (nums.size() == 1)
        return 1;
    int count = 0, numMax = 0;
    unordered_map<int, int> res, startIdx;
    for (int i = 0; i < nums.size(); i++)
    {
        ++res[nums[i]];

        if (count < res[nums[i]])
        {
            count = res[nums[i]];
            numMax = nums[i];
        }
    }
    cout << numMax << endl;
    int index1 = 0, index2 = 0, appear = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == numMax && appear == 0) // 重复元素第一次出现的位置
        {
            index1 = i;
            appear += 1;
        }
        if (nums[i] == numMax && appear > 0)
        {
            index2 = i;
        }
    }
    return index2 - index1 + 1;
}

/**
 * 方法 3：为了优化方法 2，方法 3只用一个哈希表，这个方法思路跟上面的解法很相似，
 * 还是要建立数字出现次数的哈希表，还有就是建立每个数字和其第一次出现位置之间的映射，
 * 那么我们当前遍历的位置其实可以看作是尾位置，还是可以计算子数组的长度的。
 * 我们遍历数组，累加当前数字出现的次数，如果某个数字是第一次出现，
 * 建立该数字和当前位置的映射，如果当前数字的出现次数等于degree时，
 * 当前位置为尾位置，首位置在startIdx中取的，二者做差加1来更新结果res；
 * 如果当前数字的出现次数大于degree，说明之前的结果代表的数字不是出现最多的，
 * 直接将结果res更新为当前数字的首尾差加1的长度，然后degree也更新为当前数字出现的次数
 * 
 * 这里的degree其实就是相当于
*/
int findShortestSubArray3(vector<int> &nums)
{
    int num = INT_MAX;
    int degree = 0;
    unordered_map<int, int> res, startIdx;
    for (int i = 0; i < nums.size(); i++)
    {
        ++res[nums[i]];               // 每个元素出现的次数
        if (!startIdx.count(nums[i])) // 第一次出现的话
            startIdx[nums[i]] = i;    // 每个元素的首次出现的位置
        if (res[nums[i]] == degree)   //如果满足degree的话，那么就找到最小长度的作为输出结果
        {
            num = min(num, i - startIdx[nums[i]] + 1);
        }
        else if (res[nums[i]] > degree) // 如果你当前的次数比度还大，那么就更新度
        {
            num = i - startIdx[nums[i]] + 1;
            degree = res[nums[i]];
        }
    }
    return num;
}

/**
 * 方法 4：一个哈希表；记录nums中每个元素出现的所有的下表，其实是一个二维的数组
 * 例如[1,1,2,2,2,1],建立hash_map之后是[1:[0,1,5],2:[2,3,4]]即可；然后遍历每个元素
 * 找到它下标最大长度即可，这个最大的也就是出现最多次数的元素，然后遍历每一个最大长度的元素，
 * 最后一个元素减去第一个元素就是他的距离；方法 4思路最好；
 * 
 * 其实方法 4用python来写的话很容易，写一个字典，每个字典键是元素，值是元素所在的位置，这样
 * 就构成了以键是元素，值是元素位置的list的字典，然后遍历字典，找到对应位置list中最大位置的
 * 元素，接下来就是求这个元素的位置list的距离来比较最短的即可；
 * 
*/
int findShortestSubArray4(vector<int> &nums)
{
    int degree = 0;
    unordered_map<int, vector<int>> res;
    for (int i = 0; i < nums.size(); i++)
    {
        res[nums[i]].push_back(i);
    }
    // find degree
    for (auto ele : res)
    {
        degree = max((int)ele.second.size(), degree);
    }
    // 找到度相同的最小长度
    int length = nums.size();
    for (auto ele : res)
    {
        if (ele.second.size() == degree)
        {
            length = min(length, ele.second.back() - ele.second[0] + 1);
        }
    }
    return length;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 2, 1};
    // vector<int> nums = {2,1,1,2,1,3,3,3,1,3,1,3,2};
    cout << findShortestSubArray3(nums) << endl;
    return 0;
}
