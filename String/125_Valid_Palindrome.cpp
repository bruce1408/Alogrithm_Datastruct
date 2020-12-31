#include <iostream>
#include <string>
using namespace std;

/**
 * 方法 1，利用isalnum()函数来判断字符是数字或者是字母，返回的是bool值，数字或字母是true，
 * 如果是其他字符，那么返回false
 * 把原来那些非字母和数字的符号去掉，然后构成一个新的字符串，判断字符串是否是回文字符串
 */
bool dealpa(string temp)
{
	int left = 0, right = temp.size() - 1;
	while (left < right)
	{
		if ((temp[left] + 32 - 'a') % 32 == (temp[right] + 32 - 'a') % 32)
		{
			left++;
			right--;
		}
		else
			return false;
	}
	return true;
}

bool isPalindrome1(string s)
{
	if (s.size() == 0) // 空字符串的话是回文串
		return true;
	string temp;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalnum(s[i])) // 是否是字母或者是数字
			temp += s[i];
	}
	cout << temp << endl;
	return dealpa(temp);
}

/**
 * 方法 2，不用构成新的字符串，直接判断
 * */
bool isAlphaNum(char &ch);
bool isPalindrome2(string s)
{
	int left = 0, right = s.size() - 1;
	while (left < right)
	{
		if (!isAlphaNum(s[left]))
			++left;
		else if (!isAlphaNum(s[right]))
			--right;
		else if ((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32)
			return false;
		else
		{
			++left;
			--right;
		}
	}
	return true;
}

bool isAlphaNum(char &ch)
{
	if (ch >= 'a' && ch <= 'z')
		return true;
	if (ch >= 'A' && ch <= 'Z')
		return true;
	if (ch >= '0' && ch <= '9')
		return true;
	return false;
}

int main()
{
	string a = "A man, a plan, a canal: Panama";
	// getline(cin,a);
	cout << isPalindrome1(a) << endl;
}