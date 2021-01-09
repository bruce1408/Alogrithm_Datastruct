#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void minnum(vector<int> &num)
{
    multiset<int> res;
    for (int i = 0; i < num.size(); i++)
    {
        res.insert(num[i]);
    }
    for (multiset<int>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        cout << *res.lower_bound(7) << endl;
    }
}
int main()
{
    vector<int> res = {3, 2, 1, 5, 9};
    minnum(res);
}