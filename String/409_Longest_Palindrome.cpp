/*409. Longest Palindrome
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

/*第一种方法：哈希思路*/
int longestPalindrome(string s)
{
	int res=0,count=0;
	bool flag = false;
	unordered_map<char,int> temp;
	for(auto i:s) ++temp[i];
	for(auto &x:temp)
	{
		res+=x.second;
		if(x.second%2==1)
		{
			res-=1;
			flag = true;
		}	
	}
	return flag?res+1:res;
}


/*方法二：利用count方法，从A到z、统计所有的字符出现的次数，次数和1&操作，奇数的话是1，偶数为0；
然后统计的是所有奇数的和，最后size长度减去奇数和-1，保留一个即可。
*/


int longestPalindrome(string s) 
{
	int odds = 0;
	for (char c = 'A'; c <= 'z'; ++c) 
	{
		odds += count(s.begin(), s.end(), c) & 1;
	}
	return s.size() - max(0, odds - 1);
}


int main()
{
	string s = "ccc";
	// cout<<longestPalindrome(s);
	int a=4;
	int b=1;
	a = a&b;
	cout<<a;
	return 0;

}






















