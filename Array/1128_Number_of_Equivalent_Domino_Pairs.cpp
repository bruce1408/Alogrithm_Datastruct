#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 第一种方法超时了，效果不是很好
*/
int numEquivDominoPairs(vector<vector<int>> &dominoes)
{
    int count = dominoes.size();
    int cur = 0, after = 0;
    int res = 0;
    while (cur < count)
    {
        for (after = cur + 1; after < count; after++)
        {
            if (((dominoes[cur][0] == dominoes[after][0]) &&
                 (dominoes[cur][1] == dominoes[after][1])) ||
                ((dominoes[cur][0] == dominoes[after][1]) &&
                 dominoes[cur][1] == dominoes[after][0]))
                res += 1;
        }
        cur += 1;
    }
    return res;
}

/**
 * 方法 2 使用hash_map的思路来解决,不会超时
*/
int numEquivDominoPairs1(vector<vector<int>> &dominoes)
{
    int count = 1;
    unordered_map<vector<int>, int> temp;
    for (auto i : dominoes)
    {
        vector<int> res = {i[1], i[0]};
        unordered_map<vector<int>, int>::iterator it;
        it = temp.find(i)
        if (temp.find(i) == temp.end() && temp.find(res) == temp.end())
        {
            count += 1;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> res = {
        {1, 2},
        {2, 1},
        {3, 4},
        {5, 6}};
    cout << numEquivDominoPairs1(res) << endl;
}
