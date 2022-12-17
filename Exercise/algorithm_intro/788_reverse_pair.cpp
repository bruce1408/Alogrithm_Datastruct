#include <iostream>
#include <vector>
using namespace std;

/**
 * 这道题输入一个数组， 然后求逆序数对的个数。
 * 方法 1，超时了，使用的是双指针，两层循环；
*/
int reverse_pair(vector<int> &res)
{
    int n = res.size(), i = 0, count = 0;
    while (i < n)
    {
        int j = i - 1;
        while (j >= 0)
        {
            if (res[j--] > res[i])
                count++;
        }
        i++;
    }
    return count;
}

/**
 * 方法 2，使用归并排序的思想
*/
typedef long long LL;
const int N = 1e5 + 10;
int n;
int q[N], tmp[N];
LL merge_sort2(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) >> 1;
    LL res = merge_sort2(l, mid) + merge_sort2(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
        {
            res += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];

    return res;
}

/**
 * 方法 3，使用归并排序，思路同方法 2；
*/
long long result = 0;
void mergeSort3(vector<int> &res, vector<int> &temp, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    mergeSort3(res, temp, l, mid);
    mergeSort3(res, temp, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (res[i] <= res[j])
            temp[k++] = res[i++];
        else
        {
            temp[k++] = res[j++];
            result += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = res[i++];
    while (j <= r)
        temp[k++] = res[j++];
    for (int i = 0, j = l; j <= r; i++, j++)
    {
        res[j] = temp[i];
    }
}

int main()
{

    vector<int> res = {2, 3, 4, 5, 6, 1};
    int n = res.size();
    vector<int> temp(res);
    mergeSort3(res, temp, 0, n - 1);
    cout << "共有：" << result << endl;
    // cout << "共有： " << reverse_pair(res) << endl;
}