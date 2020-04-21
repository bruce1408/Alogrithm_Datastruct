#include <iostream>
#include <vector>
using namespace std;

/**
 * Example 1:
 * 
 * Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
 * Output: 2
 * 
 * Explanation: 
 * For arr1[0]=4 we have: 
 * |4-10|=6 > d=2 
 * |4-9|=5 > d=2 
 * |4-1|=3 > d=2 
 * |4-8|=4 > d=2 
 * 
 * For arr1[1]=5 we have: 
 * |5-10|=5 > d=2 
 * |5-9|=4 > d=2 
 * |5-1|=4 > d=2 
 * |5-8|=3 > d=2
 * 
 * For arr1[2]=8 we have:
 * |8-10|=2 <= d=2
 * |8-9|=1 <= d=2
 * |8-1|=7 > d=2
 * |8-8|=0 <= d=2
 * 
 * 数组1中的所有数字和数组2中的数字进行绝对值的差，只要所有值都大于d的话，那么就统计进去。
*/

/**
 * 方法 1，暴力解法，时间复杂度是O(n*m)
*/
int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
{
    int sum = 0;
    for (int i = 0; i < arr1.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr2.size(); j++)
        {
            if (abs(arr1[i] - arr2[j]) > d)
            {
                count += 1;
            }
        }
        if (count == arr2.size())
        {
            sum += 1;
        }
    }
    return sum;
}

/**
 * 方法 2
*/
int main()
{
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    cout << findTheDistanceValue(arr1, arr2, 2) << endl;
}
