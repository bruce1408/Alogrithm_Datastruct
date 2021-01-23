#include <iostream>
#include <unordered_map>
#include <vector>
#include "../utils/cout_vec.h"
using namespace std;
/**
 * 350 求两个容器的交集。和349一样，但是可以允许重复数字
 * 思路是想把两个容器用快速排序方法进行排序思路是想把两个容器用快速排序方法进行排序
 * 然后对排好序的容器进行遍历，如果1的值小于2的值，1自增，否则2自增，如果1和2相同，
 * 那么值就放入res容器之中
 * 关键字：快速排序，遍历放值，可以允许重复的数。
*/

/**
 * 方法 1，还是使用排序之后再比较大小即可 
*/
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
	vector<int> res;
	int i = 0, j = 0;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] < nums2[j])
			i++;
		else if (nums1[i] > nums2[j])
			j++;
		else
		{ //这里一定要注意，就是判断里面的条件，如果是后判断空的话是错度。
			res.push_back(nums1[i]);
			i++;
			j++;
		}
	}
	return res;
}

/**
 * 方法 2，使用哈希set来保存第一个元素出现的次数，然后遍历第二个数组，如果出现了，那么保存到结果数组
 * 然后哈希表删除这个元素即可，保证不重复
*/
vector<int> intersect2(vector<int> &a, vector<int> &b)
{
	vector<int> ans;
	unordered_map<int, int> res;
	for (int i = 0; i < a.size(); i++)
		res[a[i]]++;
	for (auto i : b)
	{
		if (res[i])
		{
			ans.push_back(i);
			res[i]--;
		}
	}
	return ans;
}

/**
 * 方法 3，使用multiset，保存多个相同的数
*/
vector<int> intersect3(vector<int> &a, vector<int> &b)
{
	vector<int> ans;
	unordered_multiset<int> res;
	for (int i = 0; i < a.size(); i++)
		res.insert(a[i]);
	for (auto i : b)
	{
		if (res.count(i))
		{
			ans.push_back(i);
			res.erase(res.find(i));
		}
	}
	return ans;
}

int main()
{

	vector<int> num1 = {1, 2, 2, 1};
	vector<int> num2 = {2, 2};
	vector<int> res = intersection2(num1, num2);
	print(res);
	return 0;
}
