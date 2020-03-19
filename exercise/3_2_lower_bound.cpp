#include <iostream>
#include <vector>
using namespace std;

/**
 * 如果是从小到大的排列的话，
 * lower_bound返回的是数组中第一个大于或者等于被查数字的位置
 * upper_bound返回的是第一个大于被查的数字的位置 
 * 
 * 如果是从大到小的排列的话，
 * lower_bound返回的是数组中第一个小于或者等于被查数字的位置
 * upper_bound返回的是第一个小于被查数字的位置
 * 
*/
int cmd(int a, int b)
{
    return a > b;
}
int main()
{
    int num[6] = {1, 2, 4, 7, 15, 34};
    sort(num, num + 6);                            //按从小到大排序
    int pos1 = lower_bound(num, num + 6, 7) - num; //返回数组中第一个大于或等于被查数的值
    int pos2 = upper_bound(num, num + 6, 7) - num; //返回数组中第一个大于被查数的值
    cout << pos1 << " " << num[pos1] << endl;
    cout << pos2 << " " << num[pos2] << endl;
    sort(num, num + 6, cmd);                                       //按从大到小排序
    int pos3 = lower_bound(num, num + 6, 7, greater<int>()) - num; //返回数组中第一个小于或等于被查数的值
    int pos4 = upper_bound(num, num + 6, 7, greater<int>()) - num; //返回数组中第一个小于被查数的值
    cout << pos3 << " " << num[pos3] << endl;
    cout << pos4 << " " << num[pos4] << endl;

    vector<int> res = {2, 3, 1, 4, 5};
    cout << lower_bound(res.begin(), res.end(), 3) - res.begin() << endl;
}
