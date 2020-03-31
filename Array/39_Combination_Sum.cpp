#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    // set<vector<int>>tempRes;
    for (int i = 0; i < candidates.size(); i++)
    {
        vector<int> temp;
        int tempNum = candidates[i];
        int count = 2;
        if (target % candidates[i] == 0)
        {
            for (int x = 0; x < target / candidates[i]; x++)
            {
                temp.push_back(candidates[i]);
            }
        }
        else
        {
            int tempCount = target / candidates[i];
            while (tempNum <= target)
            {
                int remainNum = target % tempNum;
                auto iter = find(candidates.begin(), candidates.end(), remainNum);
                if (iter != candidates.end())
                {
                    for (int j = 0; j < tempCount; j++)
                    {
                        temp.push_back(candidates[i]);
                    }
                    temp.push_back(remainNum);
                }
                else
                {
                    tempCount = count;
                }
                tempNum = pow(candidates[i], count);
                count += 1;
            }
        }
        if (temp.size() != 0)
        {
            res.push_back(temp);
        }
    }
    set<vector<int>> tempRes(res.begin(), res.end());
    return vector<vector<int>>(tempRes.begin(), tempRes.end());
}

int main()
{
    vector<int> res = {1, 2};
    int a = 4;
    for (auto i : combinationSum(res, a))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}