#include <iostream>
#include <vector>
using namespace std;

/**
 * 80 删除数组的重复，使得重复数字最多出现两次
*/

/**
 * 方法 1，
*/
int removeDuplicates(vector<int> &nums)
{
    int count = 1, pre = 0, cur = 0;
    while (cur < nums.size())
    {
        if (nums[cur] == nums[pre] && count == 0)
            ++cur;
        else
        {
            if (nums[pre] == nums[cur])
                --count;
            else
                count = 1;
            nums[++pre] = nums[cur++];
        }
    }
    return pre + 1;
}

int main()
{
    vector<int> res = {1, 1, 2, 3, 4, 4, 4, 5, 6};
    int j = removeDuplicates(res);
    for (int i = 0; i < j; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}