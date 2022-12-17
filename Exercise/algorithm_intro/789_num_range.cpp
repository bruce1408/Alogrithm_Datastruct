#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 方法 1,暴力搜索，超时了
*/
vector<vector<int>> range_num1(vector<int> &res, vector<int> &temp)
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
 * 方法 2，使用STL二分搜索，边界条件较多。
*/
vector<vector<int>> range_num2(vector<int> &res, vector<int> temp)
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

/**
 * 方法 3，使用二分搜索，其实就是手写的low_bound 和 upper_bound的实现，参考yxc
*/
void range_num3(vector<int> &res, vector<int> temp)
{
    int n = res.size(), m = temp.size();
    for (int i = 0; i < m; i++)
    {
        int x = temp[i];
        int l = 0, r = n - 1;
        // lower_bound
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (res[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (res[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << ' ';
            int l = 0, r = n - 1;
            // upper_bound
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (res[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
}

/**
 * 方法 4，使用自己写的模板来实现二分搜索
*/
void range_num4(vector<int> &res, vector<int> temp)
{
    int n = res.size(), m = temp.size();
    for (int i = 0; i < m; i++)
    {
        int x = temp[i];
        int l = 0, r = n - 1;
        // low_bound 部分
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (res[mid] >= x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (res[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            // upper_bound 部分
            cout << l << ' ';
            int l = 0, r = n;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (res[mid] <= x)
                    l = mid + 1;
                else
                    r = mid;
            }
            cout << l << endl;
        }
    }
}

int main()
{
    vector<int> res = {1, 3, 3, 4, 6, 6};
    vector<int> temp = {3, 8, 4};

    // for (auto &i : range_num1(res, temp))
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // range_num3(res, temp);
    range_num4(res, temp);

    // cout << lower_bound(res.begin(), res.end(), 6) - res.begin() << endl;
    // cout << upper_bound(res.begin(), res.end(), 6) - res.begin() << endl;
}