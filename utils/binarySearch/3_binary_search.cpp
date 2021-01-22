#include <iostream>
#include <vector>
using namespace std;

/**
 * 二分搜索模板的情况
 * firstK 表示的是 第一个大于等于的情况
 * lastK 表示的是 最后一个小于等于的情况
*/

/**
 * 返回第一个大于等于该数的位置
*/
int firstK(vector<int> &res, int k)
{
    int l = 0, r = res.size();
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (res[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

/**
 * 返回最后一个小于等于该数的位置
*/
int lastK(vector<int> &res, int k)
{
    int l = 0, r = res.size();
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (res[mid] <= k)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{

    vector<int> res = {1, 2, 3, 3, 5, 7, 8, 9};
    int n, k;
    cout << "input a nums n" << endl;
    cin >> n;
    while (n--)
    {
        cin >> k;
        cout << "target x first location is: " << firstK(res, k) << endl;
        cout << "target x last location is: " << lastK(res, k) << endl;
    }
}
