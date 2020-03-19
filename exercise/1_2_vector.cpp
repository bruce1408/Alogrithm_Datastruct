#include <iostream>
#include <vector>
using namespace std;

/**
 * vector 不是常规的基本数据类型，而是pair类型的数据类型
 * 新的数据类型的vector如何排序，下面例子可以说明
*/
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    vector<int> oneNum = {2, 1, 2, 3, 4, 5, 1, 9};
    vector<pair<int, int>> res;
    for (int i = 0; i < oneNum.size(); i++)
    {
        res.push_back(pair<int, int>(oneNum[i], i));
    }
    sort(res.begin(), res.end(), cmp);
    for (auto i : res)
    {
        cout << i.first << ' ' << i.second << endl;
    }
}