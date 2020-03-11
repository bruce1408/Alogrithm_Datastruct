#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * 
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

int main()
{
    vector<int> res = {37, 12, 28, 9, 100, 56, 80, 5, 12};
    for (auto i : arrayRankTransform(res))
    {
        cout << i << endl;
    }
}