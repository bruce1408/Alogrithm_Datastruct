#include <iostream>
#include <vector>
using namespace std;
/**
 * 首先把序列进行排序，注意是逆序排序，然后对这个序列进行分析，如果指数大于等于当前的
 * 这个序列值的话，那么返回这个数，否则，指数自增，如果都不满足条件，那么最后输出的是
 * 序列的个数。
 */

/**
 * 方法 1，按照降序进行排序，然后比较
*/
int hIndex(vector<int> &s)
{
	int n = s.size();
	sort(s.begin(), s.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		if (i >= s[i])
			return i;
	}
	return s.size();
}

/**
 * 方法 2，写法略有不同
*/
int hIndex2(vector<int> &c)
{
	sort(c.begin(), c.end(), greater<int>());
	for (int h = c.size(); h; h--)
		if (c[h - 1] >= h)
			return h;
	return 0;
}

/**
 * 方法 3，使用二分做法,升序排列，然后再利用二分判断
*/
int hIndex3(vector<int> &citations)
{
	if (citations.size() == 0)
		return 0;
	sort(citations.begin(), citations.end());
	int l = 0, r = citations.size() - 1;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1; // 找到最后一个 文章数量大于等于数目的
		if (citations.size() - mid > citations[mid])
			l = mid; // [l,mid-1] [mid,r]
		else
			r = mid - 1;
	}
	if (citations.size() - l <= citations[l])
		l--;
	return citations.size() - (l + 1);
}

int main()
{
	vector<int> a = {3, 0, 6, 1, 5};
	// vector<int> a ={6,6,6,6,6};

	cout << "指数是： " << hIndex(a) << endl;
	return 0;
}
