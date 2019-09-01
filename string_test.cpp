#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestNumber(vector<int> &nums)
	{
		sort(nums.begin(), nums.end(), compare);
		string res;
		for (auto n : nums)
		{
			res += to_string(n);
		}

		auto pos = res.find_first_not_of('0');
		return pos == string::npos ? "0" : res.substr(pos);
	}

private:
	static bool compare(int a, int b)
	{
		auto strA = to_string(a);
		auto strB = to_string(b);
		return (strA + strB > strB + strA);
	}
};

int main()
{

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

	string s("12345asdf");
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

	string a = "hello";
	string b = "elh";
	for (auto i : b)
	{
		if (a.find(i) != a.npos)
		{
			cout << i << endl;
		}
	}

	return 0;
}
