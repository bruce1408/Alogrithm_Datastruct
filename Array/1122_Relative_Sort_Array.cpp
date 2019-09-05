#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
/**
 * 刚开始没有一点思路
*/
vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res(1001, 0);
    vector<int> ans(arr1.size());
    int k = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        res[arr1[i]]++; // arr1中每一个数的次数
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        while (res[arr2[i]] > 0)
        {
            ans[k++] = arr2[i];
            res[arr2[i]]--;
        }
    }
    for (int i = 0; i < 1001; i++)
    {
        while (res[i] > 0)
        {
            ans[k++] = i;
            res[i]--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> res = relativeSortArray(arr1, arr2);
    for (auto i : res)
    {
        cout << i << endl;
    }
}
