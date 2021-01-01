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
void reverseWords1(string &s)
{
	istringstream iss(s);
	string temp;
	iss >> s;
	cout << endl;
	while (iss >> temp)
		s = temp + " " + s;
	if (!s.empty() && s[0] == ' ')
		s = ""; //输入是空格的时候，输出为空
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
 * 比如s="hello world",翻转每个字符，"dlrow olleh",接着翻转每个单词"world hello"完成
 * 用双指针算法来做
*/
string reverseWords3(string s)
{
	
	if(s.empty()) return s;
	int n = s.size();
	for(int i=0,j = n-1;;i++,j--)
	{
		if(s[i]==' ') continue;

	}
}

int main()
{
	string s = " hello world my name ";
	cout << "before reverse is: " << s << endl;
	reverseWords1(s);
	cout << "after reverse is: " << s << endl;
}
