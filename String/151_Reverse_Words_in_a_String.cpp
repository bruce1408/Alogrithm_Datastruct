#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Given an input string, reverse the string word by word.
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 * 
 * 如果是前面和后面有空格的话，翻转的话要去掉空格，如果字符中间有几个空格，也要
 * 缩短为1个
 * 1、输入
 * "  hello world  "
 * 输出
 * "world hello"
 * 
 * 2、输入
 * "a good   map"
 * 输出
 * "map good a"
*/

/**
 * 方法 1，基于字符串流的操作sstream
*/
string reverseWords1(string &s)
{
	istringstream iss(s);
	string temp;
	iss >> s;
	cout << endl;
	while (iss >> temp)
		s = temp + " " + s;
	if (!s.empty() && s[0] == ' ')
		s = ""; //输入是空格的时候，输出为空
	return s;
}

/**
 * 方法 2，代码比较冗余
 * 首先去掉首尾的空格，然后开始遍历这个新的字符串，中间空格数用breaks，如果当前不是空格，breaks为0，
 * 如果当前字符是空格，那么就breaks加1，然后判断breaks如果是1，说明中间的空格数是1，那么就当前的字符串放到结果里面，
 * 否则说明多个空格，那么就忽略，然后重新让临时字符串为空串，最后在翻转即可；
*/
string reverseWords2(string s)
{
	vector<string> res;
	string temp;
	int breaks = 0, begin = 0, end = s.size() - 1; // breaks 记录中间有所少个空格，begin记录最开始的空格，end记录最后面的空格数
	while (begin < end && s[begin] == ' ')
		begin++;
	while (begin < end && s[end] == ' ')
		end--;
	cout << begin << " " << end << endl;
	for (int i = begin; i <= end; i++)
	{
		if (s[i] != ' ')
		{
			temp += s[i];
			breaks = 0;
		}
		else
		{
			breaks++;
			if (breaks == 1)
				res.push_back(temp);
			temp = "";
		}
	}
	if (temp != "")
		res.push_back(temp);
	int left = 0, right = res.size() - 1;
	while (left < right)
		swap(res[left++], res[right--]);
	string t;
	for (auto i : res)
	{
		t += i;
		t += ' ';
	}
	return t.substr(0, t.size() - 1);
}

/**
 * 方法 3，首先对每一个字符进行翻转，然后在对每个单词进行翻转即可
 * 比如s="hello world",
 * 第一就是翻转每个字符，"dlrow olleh",
 * 第二就是接着翻转每个单词"world hello"完成
 * 用双指针算法来做
 * 注意：这里处理首尾空格的方式是把字符串前移到首位即可，覆盖原来的空格，最后每个字符翻转以后删除最后空白的多余空格
 * 这里start要减去1才可以，因为最后一个字符会多加一个空格
*/
string reverseWords3(string s)
{
	if (s.empty())
		return s;
	int n = s.size(), start = 0; // start用来记录当前非空的单词的起始位置
	for (int i = 0; i < n; i++)	 // 遍历每个单词
	{
		if (s[i] == ' ')
			continue;
		int j = i, t = start;				// t指向非空单词的起始位置
		while (j < s.size() && s[j] != ' ') // 把空格的地方用单词向前平移
			s[t++] = s[j++];
		reverse(s.begin() + start, s.begin() + t); // 翻转这个单词
		s[t++] = ' ';							   // 这个单词的下一位加一个空格
		start = t, i = j;						   // 下一个单词的开始位置为当前的t，j赋值给i
	}
	if (start) // 最后的起始位置不为空，那么最后一位空格减去
		start--;
	s.erase(s.begin() + start, s.end());
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	string s = " hello world my name ";
	cout << "before reverse is: " << s << endl;
	// reverseWords1(s);
	// cout << "after reverse is: " << s << endl;
	cout << reverseWords3(s) << endl;
}
