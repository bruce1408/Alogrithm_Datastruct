#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 164 Maximum Gap,求解一组序列中两两之间差值最小的那个数。
 * 最简单的就是用sort函数，排序求最大的差值
 * 其他方法是可以用基数排序或者是桶排序！
 * */

/**
 * 方法 1，最简单的思路就是使用排序，然后排序之后两两比较，这样算可以算出来，但是肯定能不满足
 * 题目的线性时间复杂度和空间复杂度，超时
 * 所以使用桶排序的思想，对n个数字，设置n-1个区间，然后尽可能的让每个数均匀的落在每个区间即可
 * 
*/
struct bucket
{
	int min, max;
	bool used;
	bucket() : min(INT_MAX), max(INT_MIN), used(false){};
};

int maximumGap(vector<int> &nums)
{
	int n = nums.size();
	int Min = INT_MAX, Max = INT_MIN;
	for (auto x : nums) // 求这个区间的最大值和最小值
	{
		Min = min(x, Min);
		Max = max(x, Max);
	}
	if (n < 2 || Max == Min)
		return 0;
	vector<bucket> r(n - 1);				 // 区间数
	int len = (Max - Min + n - 2) / (n - 1); // 这一步没有看懂
	for (auto x : nums)						 // 找到每一个区间的最小值和最大值
	{
		if (x == Min)
			continue;
		int k = (x - Min - 1) / len;
		r[k].used = true;
		r[k].min = min(r[k].min, x);
		r[k].max = max(r[k].max, x);
	}
	int res = 0;
	for (int i = 0, last = Min; i < n - 1; i++)
	{
		if (r[i].used)
		{
			res = max(res, r[i].min - last);
			last = r[i].max;
		}
	}
	return res;
}

int main()
{
	vector<int> res = {3, 6, 9, 1};
	cout << maximumGap(res) << endl;
}
