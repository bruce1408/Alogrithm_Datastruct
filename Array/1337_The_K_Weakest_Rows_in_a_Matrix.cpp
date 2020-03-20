#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 1337 和 1331 非常类似,但是可以有重复的数字出现
 * Given a m * n matrix mat of ones (representing soldiers) and zeros 
 * (representing civilians), return the indexes of the k weakest rows 
 * in the matrix ordered from the weakest to the strongest.
 * 
 * A row i is weaker than row j, 
 * if the number of soldiers in row i is less than 
 * the number of soldiers in row j, or they have the same number 
 * of soldiers but i is less than j. 
 * Soldiers are always stand in the frontier of a row, that is, 
 * always ones may appear first and then zeros.
*/

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<int> oneNum;
    vector<int> result;
    for (int i = 0; i < mat.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 1)
            {
                count += 1;
            }
        }
        oneNum.push_back(count);
    }

    vector<pair<int, int>> res;
    for (int i = 0; i < oneNum.size(); i++)
    {
        res.push_back(pair<int, int>(oneNum[i], i));
    }
    sort(res.begin(), res.end(), cmp);
    // for (auto i : res)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << endl;

    for (int i = 0; i < k; i++)
    {
        result.push_back(res[i].second);
    }

    return result;
}

int main()
{
    vector<vector<int>> res = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}};
    for (auto i : kWeakestRows(res, 3))
    {
        cout << i << endl;
    }
}
