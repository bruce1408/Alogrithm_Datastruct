#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

/**
 * 447. Number of Boomerangs
 * Input:
 * [[0,0],[1,0],[2,0]]
 * Output:
 * 2
 * 计算距离相同的点的排列方式，如果是五个点的话，有20中可能。
*/

/**
 * 方法 1，首先使用hash表来保存当前点和其他点相同距离的个数，然后因为
 * 比如两个点相同的那么排列方式就是2，a和b、c距离形同，有abc=acb，三个点的话那么就是有6中，按照排列的
 * n*(n-1)，所以每次遍历到当前的点，然后开始累加所有距离相同的排列即可。
*/
int numberOfBoomerangs(vector<vector<int>> &p)
{
	int res = 0;
	for (int i = 0; i < p.size(); i++)
	{
		unordered_map<int, int> hash;
		for (int j = 0; j < p.size(); j++)
		{
			if (j != i)
			{
				int dx = p[i][0] - p[j][0];
				int dy = p[i][1] - p[j][1];
				int dist = dx * dx + dy * dy;
				hash[dist]++; // 如果距离相同的话，记录相同距离的个数
			}
		}
		// for (auto [d, c] : hash)
		// 	res += c * (c - 1);
		for (auto it : hash)
			res += it.second * (it.second - 1); // (n-1) * n;
	}
	return res;
}

int main()
{
	vector<vector<int>> res = {{1, 0}, {0, 1}, {1, 1}, {2, 1}, {1, 2}};
	cout << numberOfBoomerangs(res);
	return 0;
}
