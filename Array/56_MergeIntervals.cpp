
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
 * 方法 1，
*/
vector<vector<int>> merge(vector<vector<int>> &s)
{
	int n = s.size(), i = 0;
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
 * 方法 2
*/
vector<vector<int>> merge(vector<vector<int>> &s)
{
	sort(s.begin(), s.end());
	vector<vector<int>> res;
	res.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i][0] > res.back()[1])
			res.push_back(s[i]);
		else
		{
			res.back()[1] = max(res.back()[1], s[i][1]);
		}
	}
	return res;
}
