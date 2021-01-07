
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * 56. Merge Intervals 
 * 合并区间，如果给定一个区间是，有重叠的部分的话就合并
 * 输入: intervals = [[1,3],[2,6],[8,10],[15,18]] 
 * 输出: [[1,6],[8,10],[15,18]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 **/

/**
 * 方法 1，先对所有区间对进行排序，设置第一个区间对的元素分别是l和r，然后不断更新，
 * 更新的方式和方法 2一样。
*/
vector<vector<int>> merge(vector<vector<int>> &s)
{
	sort(s.begin(), s.end());
	vector<vector<int>> res;
	int l = s[0][0], r = s[0][1];
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i][0] > r)
		{
			res.push_back({l, r});
			l = s[i][0], r = s[i][1];
		}
		else
			r = max(s[i][1], r);
	}
	res.push_back({l, r});
	return res;
}

/**
 * 方法 2和方法 1思路相同，写法略有不同,
 * 先对区间对进行首元素从小到大排序，把第一个区间对放进res结果数组中，然后判断下一个
 * 区间对的第一个元素是否大于res最后一个区间对的第二个元素，如果是的话，那么说明
 * 该区间不用合并，直接放入res数组中即可，否则，更新res最后一个元素
*/
vector<vector<int>> merge2(vector<vector<int>> &s)
{
	sort(s.begin(), s.end());
	vector<vector<int>> res;
	res.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (res.back()[1] < s[i][0])
			res.push_back(s[i]);
		else
			res.back()[1] = max(res.back()[1], s[i][1]);
	}
	return res;
}

int main()
{
	vector<vector<int>> res = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	for (auto x : merge2(res))
	{
		for (auto i : x)
			cout << i << " ";
		cout << endl;
	}
}