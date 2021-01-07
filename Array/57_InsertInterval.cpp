#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * 57 区间插入，给定一个区间数组，按照第一个元素排列的有序区间。然后插入一个新的
 * 区间，新的区间可能会和原来区间进行合并，所以最后返回这个区间
 * */

/**
 * 方法 1，将整个区间分成3部分，前面没有交集部分，中间交集部分，后面没有交集部分
 * 主要集中在中间产生交集的部分;
 * 设置一个遍历i扫描整个区间范围，
 * 如果是s[i][1] < t[0]没有交集
 * 
*/
vector<vector<int>> insert(vector<vector<int>> &s, vector<int> &t)
{
	if (s.empty())
		return {t};
	vector<vector<int>> res;
	int n = s.size();
	int i = 0;
	while (i < n && s[i][1] < t[0])
		res.push_back(s[i++]);

	while (i < n && s[i][0] <= t[1])
	{
		t[0] = min(s[i][0], t[0]);
		t[1] = max(s[i][1], t[1]);
		i++;
	}
	res.push_back(t);
	while (i < n)
		res.push_back(s[i++]);
	return res;
}

int main()
{
	vector<vector<int>> res = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
	vector<int> ne = {4, 8};
	for (auto x : insert(res, ne))
	{
		for (auto i : x)
			cout << i << " ";
		cout << endl;
	}
}