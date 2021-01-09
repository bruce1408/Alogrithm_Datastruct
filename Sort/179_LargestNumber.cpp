#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 179 找到数组中数字元素组合的最大数字
 * 比如：
 * given [3, 30, 34, 5, 9], the largest formed number is 9534330
*/

/**
 * 方法 1，定义一个新的排序操作，
 * 就是a<=b等价于ab <= ba;
 * a==b 等价于 ab == ba;
 * 当时这种新的比较符号是不是可以进行比较呢？
 * 比如：
 * a<b; b<c; c<a;
 * 不满足这个比较定义；
 * 所以需要证明一下新的比较运算是不是满足全序关系，参考链接如下
 * https://baike.baidu.com/item/%E5%85%A8%E5%BA%8F%E5%85%B3%E7%B3%BB/943310?fromtitle=%E5%85%A8%E5%BA%8F&fromid=10577699
 * 简单来说就是满足一下三个关系：
 * 如果 a ≤ b 且 b ≤ a 则 a = b (反对称性)
 * 如果 a ≤ b 且 b ≤ c 则 a ≤ c (传递性)
 * 如果 a ≤ b 或 b ≤ a (完全性)
 * */
static bool compare(int a, int b)
{
	auto stra = to_string(a);
	auto strb = to_string(b);
	return (stra + strb > strb + stra); //小于号就是返回最小数。
}

string largestNumber1(vector<int> &nums)
{
	sort(nums.begin(), nums.end(), compare);
	string res;
	for (auto i : nums)
	{
		res += to_string(i);
	}
	//以下两句是说去掉最小数的时候0打头的情况，一般最大数的同时为0的情况也需要判断
	auto pos = res.find_first_not_of('0');
	return pos == string::npos ? "0" : res.substr(pos);
	// return res; //在求最大的数的时候没有问题，但是如果是最小数的话那么可能有0打头。
}

/**
 * 方法 2，使用dfs深度优先搜索来找到所有的可能结果，然后进行筛选即可
*/
void dfs(vector<int> &nums, int n, vector<string> &res, int k, string s, unordered_map<int, bool> &used)
{
	if (k == n)
	{
		res.push_back(s);
		return;
	}
	// 关键是当下如何选择，下一步和当前一步是一样的
	for (int i = 0; i < n; i++)
	{
		if (used[nums[i]] == false)
		{
			used[nums[i]] = true;
			string t = to_string(nums[i]);
			dfs(nums, n, res, k + 1, s + t, used);
			used[nums[i]] = false;
		}
	}
}

string largestNumber2(vector<int> &nums)
{
	int n = nums.size();
	vector<string> res;
	unordered_map<int, bool> used;
	for (auto i : nums)
		used[i] = false;
	dfs(nums, n, res, 0, "", used);
	for (auto i : res)
		cout << i << endl;
	return "";
}

int main()
{
	vector<int> num = {0, 1, 4};
	cout << largestNumber1(num) << endl;
}