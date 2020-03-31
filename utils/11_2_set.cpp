#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// set 和multiset 可以自动对数组中的数进行排序，但是multiset是可以允许重复数字出现！

int main()
{
    vector<vector<int>> res = {{1}, {2, 3}, {1}};
    set<vector<int>> temp;
    for (int i = 0; i < res.size(); i++)
    {
        temp.insert(res[i]);
    }
    for (auto i : temp)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    set<vector<int>> mos(res.begin(), res.end());
    cout << "mos begin is:" << endl;
    for (auto i : mos)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}