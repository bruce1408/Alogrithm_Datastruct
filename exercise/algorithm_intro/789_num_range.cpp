#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 方法 3，使用归并排序，思路同方法 2；
*/
vector<vector<int>> range_num(vector<int> &res, vector<int> &temp)
{
    vector<vector<int>> output;
    int n = res.size(), m = temp.size();
    for (int i = 0; i < m; i++)
    {
        bool flag = true;
        vector<int> result = {-1, -1};
        for (int j = 0; j < n; j++)
        {
            if (temp[i] == res[j] && flag && j != n - 1)
            {

                result[0] = j;
                flag = false;
            }
            else if (temp[i] == res[j] && flag && j == n - 1)
            {
                result[0] = j;
                result[1] = j;
            }
            else if (temp[i] == res[j] && flag == false)
            {
                result[1] = j;
            }
        }
        output.push_back(result);
    }
    return output;
}

/**
 * 方法 2，使用
*/
vector<vector<int>> range_num1(vector<int> &res, vector<int> temp)
{
    int n = res.size();
    vector<vector<int>> results;
    for (int i = 0; i < temp.size(); i++)
    {
        int index1 = lower_bound(res.begin(), res.end(), temp[i]) - res.begin();
        int index2 = upper_bound(res.begin(), res.end(), temp[i]) - res.begin();
        if (index1 >= n)
        {
            results.push_back({-1, -1});
        }
        else if (index1 < n && index2 == n && index2 - index1 <= 1)
        {
            results.push_back({index1, index1});
        }
        else if (index1 == index2)
        {
            results.push_back({-1, -1});
        }
        else
        {
            results.push_back({index1, index2 - 1});
        }
    }
    return results;
}

int main()
{
    int n, m;
    vector<int> res = {1, 3, 3, 4, 6, 6};
    vector<int> temp = {2, 8, 3};

    for (auto &i : range_num1(res, temp))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << lower_bound(res.begin(), res.end(), 6) - res.begin() << endl;
    cout << upper_bound(res.begin(), res.end(), 6) - res.begin() << endl;
}