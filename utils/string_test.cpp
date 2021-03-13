#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include <regex>
using namespace std;

// class Solution
// {
// public:
// 	string largestNumber(vector<int> &nums)
// 	{
// 		sort(nums.begin(), nums.end(), compare);
// 		string res;
// 		for (auto n : nums)
// 		{
// 			res += to_string(n);
// 		}

// 		auto pos = res.find_first_not_of('0');
// 		return pos == string::npos ? "0" : res.substr(pos);
// 	}

// private:
// 	static bool compare(int a, int b)
// 	{
// 		auto strA = to_string(a);
// 		auto strB = to_string(b);
// 		return (strA + strB > strB + strA);
// 	}
// };

// int main()
// {

// int a = 10;
// cout<<typeid(a).name()<<endl;
// cout<<to_string(a)<<endl;
// cout<<typeid(a).name()<<endl;
// string s1 = "110";
// string s2 = "1";
// string s3 = s1+s2;
// cout<<typeid(s1).name()<<endl;
// cout<<s3<<endl;

// int a=10,b=90;
// string sta = to_string(a);
// string stb = to_string(b);

// cout<<sta<<endl;
// cout<<stb<<endl;
// if(sta+stb>stb+sta)
// cout<<sta+stb<<endl;
// else
// cout<<stb+sta<<endl;

// string s("12345asdf");
// string aa=s.substr(2);
// cout<<aa<<endl;
// cout<<max(9,10)<<endl;

// for(int i=0;i<s.size();i++)
// {
// if(s[i]>'0' && s[i]<'9')
// cout<<i<<endl;
// }
// cout<<s*2<<endl;

// char a ='7';
// cout<<a<<endl;
// cout<<a-48<<endl;
// int n ;
// n = a-48;
// int as=n;

// cout<<as-9<<endl;
// cout<<a-'0'<<endl;
// int i=9;
// i++;
// cout<<i<<endl;

// string a = "hello";
// string b = "elh";
// for (auto i : b)
// {
// 	if (a.find(i) != a.npos)
// 	{
// 		cout << i << endl;
// 	}
// }

// for (int i = 5; i > 0;)
// {
// 	cout << "before" << i << endl;  //运算符的优先级
// 	if (--i < 5)
// 	{
// 		cout << "after" << i << endl;
// 		// break;
// 	}
// }
// return 0;

// }

// int main()
// {
// 	string pattern = {"\\d{4}-\\d{2}-\\d{2}"};
// 	regex re(pattern);
// 	string a  = "2019-02-10";
// 	int year = 0;
// 	year = stoi(a.substr(0, 4));
// 	cout<<year+2<<endl;

// }

bool isStraight(vector<int> nums)
{
	sort(nums.begin(), nums.end());
	int k = 0;
	for (int i = 0; i < nums.size();)
	{
		int j = i + 1;
		if (j < nums.size() && nums[i] == (nums[j] - 1))
		{
			i++;
			cout << i << endl;
		}
		else if (k >= 2)
			return false;
		else if (j < nums.size() && nums[i] == 0 && nums[j] == 0)
		{
			k = 2;
			i = i + 2;
		}
		else if (j < nums.size() && (nums[i] == 0 || nums[j] == 0))
		{
			k++;
			i++;
		}
		else if (j < nums.size() && nums[i] != (nums[j] - 1))
		{
			cout << "the " << j << endl;
			return false;
		}
		else return true;
	}
	return true;
}

int main()
{
	vector<int> res = {1, 2, 3, 4, 5};
	cout << isStraight(res) << endl;
}