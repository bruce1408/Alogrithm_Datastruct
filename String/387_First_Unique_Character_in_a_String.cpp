#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * 387. First Unique Character in a String
 * 第一个没有重复字符的下标
 * 
 * s = "leetcode" 
 * return 0.
 * 
 * s = "loveleetcode", 
 * return 2.
*/

/**
 * 方法 1，使用哈希表来做即可
 * 存储每个字符出现的次数，然后再次遍历这个字符串，如果当前的哈希表中次数为1，那么返回下标即可，
 * 如果遍历结束都没有满足，那么返回-1即可
*/
int firstUniqChar(string s)
{
	unordered_map<char, int> res;
	for (char i : s)
		++res[i];
	for (int i = 0; i < s.size(); i++)
	{
		if (res[s[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	string s = "leetcode";
	string t = "loveleetcode";
	cout << firstUniqChar(t);
}
