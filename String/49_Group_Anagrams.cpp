
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

/**49. Group Anagrams
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [["ate","eat","tea"], ["nat","tan"], ["bat"]]
*/

/**
 * 方法 1，使用排序，对每一个字符串进行排序，然后再把结果保存到vector
*/
vector<vector<string>> groupAnagrams1(vector<string> &strs)
{
	unordered_map<string, vector<string>> temp;
	vector<vector<string>> res;
	for (string str : strs)
	{
		string t = str;
		sort(t.begin(), t.end());
		temp[t].push_back(str);
	}
	for (auto a : temp)
		res.push_back(a.second);
	return res;
}

/**
 * 方法二： 和方法一其实差不多，就是处理每一个字符串的时候方法不一样，和242题目很像
 * */
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
	unordered_map<string, vector<string>> temp;
	vector<vector<string>> res;
	vector<string> m;
	for (string str : strs)
	{
		string t;
		vector<int> m(26, 0);
		for (char c : str)
			++m[c - 'a'];
		for (int d : m) // 如果是相同字符构成的单词，那么组成的数组是一样的
			t += to_string(d);
		temp[t].push_back(str);
	}

	for (auto a : temp)
		res.push_back(a.second);
	return res;
}

int main()
{
	vector<string> trs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> res;
	res = groupAnagrams2(trs);
	for (auto i : res)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}
