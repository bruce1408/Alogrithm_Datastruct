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
 * 给定一个数组，然后对齐进行返回一个数组，该数组是排序之后的数组
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
struct Data{
    int val, idx;
};

int main()
{
    vector<int> res = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    for (auto i : arrayRankTransform(res))
    {
        cout << i << endl;
    }
    vector<Data>v;
}