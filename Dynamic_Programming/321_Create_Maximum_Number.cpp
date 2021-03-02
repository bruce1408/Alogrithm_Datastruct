#include <iostream>
#include <vector>
using namespace std;

/**
 * 321 给定两个数组，然后一个整数k，从两个数组中按照原来的顺序选择数
 * 总共选择k个数构成一个序列，这个序列要求值是最大的即可
*/
vector<int> maxArray(vector<int> &nums, int k)
{
    vector<int> res(k);
    int j = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        while (j && res[j - 1] < x && j + n - i > k)
            j--;
        if (j < k)
            res[j++] = x;
    }
    return res;
}

vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    while (a.size() && b.size())
    {
        if (a > b)
            res.push_back(a[0]), a.erase(a.begin());
        else
            res.push_back(b[0]), b.erase(b.begin());
    }
    while (a.size())
        res.push_back(a[0]), a.erase(a.begin());
    while (b.size())
        res.push_back(b[0]), b.erase(b.begin());
    return res;
}

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size(), m = nums2.size();
    vector<int> res(k, INT_MIN); // 初始化为最小的k个数字
    for (int i = max(0, k - m); i <= min(n, k); i++)
    {
        auto a = maxArray(nums1, i);
        auto b = maxArray(nums2, k - i);
        auto c = merge(a, b);
        res = max(res, c);
    }
    return res;
}

int main()
{
    vector<int> res = {9, 0, 1, 5, 3, 4, 6};
    int k = 3;
    for (auto i : maxArray(res, k))
    {
        cout << i << " ";
    }
}
