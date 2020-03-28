// #include <iostream>
// #include <vector>
// using namespace std;

// /**
//  * vector 不是常规的基本数据类型，而是pair类型的数据类型
//  * 新的数据类型的vector如何排序，下面例子可以说明
// */
// bool cmp(const pair<int, int> &a, const pair<int, int> &b)
// {
//     if (a.first == b.first)
//     {
//         return a.second < b.second;
//     }
//     return a.first < b.first;
// }

// int main()
// {
//     vector<int> oneNum = {2, 1, 2, 3, 4, 5, 1, 9};
//     vector<pair<int, int>> res;
//     for (int i = 0; i < oneNum.size(); i++)
//     {
//         res.push_back(pair<int, int>(oneNum[i], i));
//     }
//     sort(res.begin(), res.end(), cmp);
//     for (auto i : res)
//     {
//         cout << i.first << ' ' << i.second << endl;
//     }
// }

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * 翻转reverse vector中的前n个元素
*/
int main()
{
    vector<int> res = {1, 2, 3, 4, 5, 2, 4};
    auto iter = max_element(res.begin(), res.end());
    cout << iter - res.begin() << endl;
    reverse(res.begin(), res.begin() + 4);
    for (auto i : res)
    {
        cout << i << " ";
    }
}
