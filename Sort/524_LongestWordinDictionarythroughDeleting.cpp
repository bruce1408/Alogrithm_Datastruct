#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/**
 * 524. Longest Word in Dictionary through Deleting 
 * 删除后得到的字典中的最长单词
*/

/**
 * 方法 1，不需要排序；只是用一个记录的数字来更新就可以了
 * 这个算法很好理解，思路很好！！
 * 和上面的思路大致一样，只不过没有排序，一直在更新最新的带选取的字符串。如果找到匹配的字符串，
 * 是否i和字符串的长度一样并且str长度>=存放结果的字符串，然后再看，str字符串
 * 要比你原来的字符串长度长，或者如果相同的话，我的首字母要小于你的首字母，也就是相同长度去字母最小*/

class Solution
{
public:
	string findLongestWord(string s, vector<string> &d)
	{
		string res = "";
		for (string str : d)
		{
			int i = 0;
			for (char c : s)
			{
				if (i < str.size() && c == str[i])
					++i;
			}
			if (i == str.size() && str.size() >= res.size())
				if (str.size() > res.size() || str < res) // 大于和等于两种情况的时候!!
					res = str;
		}
		return res;
	}
};

/**
 * 方法 2，遍历字符串数组d，然后寻找s的字符是否和d可以匹配。
*/
bool compare(string s, string a)
{
	int s1 = s.size(), a1 = a.size(), i = 0, j = 0;
	while (i < s1 && j < a1)
	{
		if (s[i] == a[j])
			i++, j++;
		else
			i++;
	}
	if (j == a1)
		return true;
	else
		return false;
}

string findLongestWord2(string s, vector<string> &d)
{

	string ans = "";
	sort(d.begin(), d.end());
	for (int i = 0; i < d.size(); i++)
	{
		if (compare(s, d[i]))
		{
			if (ans.size() < d[i].size())
				ans = d[i];
		}
	}
	return ans;
}

int main()
{
	string s = "abpcplea";
	vector<string> d = {"ale", "apple", "monkey", "plea", "aplea"};
	string s1;
	// Solution ss;
	// s1 = ss.findLongestWord(s, d);
	s1 = findLongestWord2(s, d);
	cout << s1 << endl;
	return 0;
}
