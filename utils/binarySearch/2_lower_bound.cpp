#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/**
 * 返回的是lower_bound 是大于等于x的最小下标
*/
void minnum(vector<int> &num)
{
    multiset<int> res;
    for (int i = 0; i < num.size(); i++)
    {
        res.insert(num[i]);
    }
    cout << "大于等于当前数7的第一个数是: " << *res.lower_bound(7) << endl;
    for (multiset<int>::iterator iter = res.begin(); iter != res.end(); iter++)
        cout << *iter << endl;
}
int main()
{
    vector<int> res = {3, 2, 1, 5, 9};
    minnum(res);
}