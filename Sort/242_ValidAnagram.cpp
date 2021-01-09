#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 242 是变位词的题目，只要一个单词的顺序稍微改变，即可变成另外的一个单词。
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 字母单词相同，但是排列顺序不同
*/

/**
 * 方法 1，对两个字符串进行排序，然后比较是否相同
*/
bool isAnagram1(string s,string t)
{
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	return s==t;
}

/**
 * 方法 2，利用哈希来解决
*/
bool isAnagram(string s, string t)
{
	if (s.size() != t.size())
		return false;
	int m1[26] = {0};
	for (int i = 0; i < s.size(); i++)
		++m1[s[i] - 'a'];
	for (int j = 0; j < t.size(); j++)
	{
		if (--m1[t[j] - 'a'] < 0)
			return false;
	}
	return true;
}
