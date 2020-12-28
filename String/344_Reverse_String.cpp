#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * 方法 1，利用swap函数来交换，然后从两头向中间互相交换
 * */
string reverseString1(string s)
{
	int left = 0, right = s.size() - 1;
	while (left < right)
	{
		swap(s[left++], s[right--]);
	}
	return s;
}

/**
 * 方法 2，从元素的最后一个到第一个逆序构成一个新的string
 */
string reverseString2(string s)
{
	if (s.size() <= 0)
		return "";
	string res;
	for (int i = s.size() - 1; i >= 0; i--)
		res += s[i];
	return res;
}

/**
 * 方法 3，同样的思路，不同的写法
*/
void reverseString3(vector<char> &s)
{
	int n = s.size();
	for (int i = 0; i < s.size() / 2; i++)
	{
		swap(s[i], s[n - i - 1]);
	}
}

int main()
{
	string a = "hello";
	// cin >> a;
	cout << "reverse:" << endl;
	cout << reverseString1(a) << endl;
	return 0;
}
