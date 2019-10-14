#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 给定一个数组，它的数组是升序和降序排列，类似一个山的形状。
 * 
*/
int peakIndexInMountainArray(vector<int> &A)
{
    if (A.size() < 3)
        return -1;
    int left = 1, n = A.size() - 1, right = n;
    while (left <= right)
    {
        if (A[left] >= A[left - 1])
        {
            left++;
        }
        if (A[right] <= A[right - 1])
        {
            right--;
        }
    }
    return left - 1;
}

int main()
{
    vector<int> res = {0, 1, 1, 2, 1, 0};
    cout << peakIndexInMountainArray(res) << endl;
}