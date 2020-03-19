#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * Given an array of integers arr, replace each element with its rank.
 * The rank represents how large the element is. 
 * The rank has the following rules:
 * Rank is an integer starting from 1.
 * The larger the element, the larger the rank. 
 * If two elements are equal, their rank must be the same.
 * Rank should be as small as possible.
 * 
 * 给定一个数组，然后对齐进行返回一个数组，该数组是排序之后的数组的原来的位置
 * 例如 
 * arr = [40,10,20,30]
 * Output: [4,1,2,3]
*/

/**
 * 方法 1，利用的是哈希map来做一个位置和元素的对应,先排序，然后遍历原来的数组，看
 * 原来的数组在排序之后的数组的什么位置，输出即可
 * 时间复杂度是O(n)
 * 空间复杂度是O(n)
*/
vector<int> arrayRankTransform(vector<int> &arr)
{
    vector<int> res(arr);
    vector<int> result;
    int loc = 1;
    unordered_map<int, int> temp;
    sort(res.begin(), res.end());
    for (auto i : res)
    {
        if (temp.find(i) == temp.end())
        {
            temp[i] = loc++;
        }
    }
    for (auto i : arr)
    {
        result.push_back(temp[i]);
    }
    return result;
}
/**
 * 方法 2，自己定义一个结构体数字和索引,然后对这个结构体这个结构体排序
 * 排序之后再从1开始，设置一个计数rank=1，遍历结构体，如果当前的数字和前面的val的值相同
 * 那么就把result数组的[结构体当前位置] = rank，rank+=1
 * 否则 把当前的rank直接给result，rank不会自增1
*/
struct Data
{
    int val, idx;
};

vector<int> arrayRankTransform1(vector<int> &arr)
{
    vector<Data> temp;
    vector<int> result(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        temp.push_back({arr[i], i});
    }
    sort(temp.begin(), temp.end(), [](Data &a, Data &b) {
        return a.val < b.val;
    });
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout << temp[i].val << " ";
    //     cout << temp[i].idx << endl;
    // }
    if (!temp.empty())
        result[temp[0].idx] = 1;
    for (int i = 1, rank = 1; i < arr.size(); i++)
    {
        if (temp[i].val != temp[i - 1].val)
            rank++;
        result[temp[i].idx] = rank;
    }
    return result;
}
/**
 * 方法 3
*/
vector<int> arrayRankTransform2(vector<int> &arr)
{
    vector<int> sets(arr.begin(), arr.end());
    sort(sets.begin(), sets.end()); // 排序 然后 去重

    sets.erase(unique(sets.begin(), sets.end()), sets.end());
    for (auto i : sets)
    {
        cout << i << endl;
    }
    vector<int> res;
    res.reserve(arr.size());
    for (int a : arr)
    {
        res.push_back(lower_bound(sets.begin(), sets.end(), a) - sets.begin() + 1);
    }
    return res;
}

int main()
{
    vector<int> res = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    for (auto i : arrayRankTransform2(res))
    {
        cout << i << " ";
    }
    vector<Data> v;
}