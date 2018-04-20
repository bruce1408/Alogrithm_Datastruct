/*387. First Unique Character in a String
第一个没有重复字符的下标


s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


/*方法一：我这个代码还是不够简洁；*/
int firstUniqChar(string s)
{
	unordered_map<char,int>res;
	for(char i:s)
		++res[i];
	for(int i=0;i<s.size();i++)
	{
		if(res[s[i]]==1)
			return i;
	}
	return -1;
		
}



int main()
{
	string s="leetcode";
	string t="loveleetcode";
	cout<<firstUniqChar(t);
	
}














