#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


/*方法一：我这个代码还是不够简洁；*/
char findTheDifference(string s, string t)
{
	unordered_map<char,int> res;
	for(int i=0;i<s.size();i++)
		++res[s[i]];
	for(int i=0;i<t.size();i++)
	{
		if(!res[t[i]])
			return t[i];
		else
			--res[t[i]];
	}
	return 0;
		
}

/*方法二：*/

char findTheDifference(string s, string t) 
{
	unordered_map<char, int> m;
	for (char c : s) ++m[c];  //auto  类型的函数代替了字符串数组，更加简洁
	for (char c : t) 
	{
		if (--m[c] < 0) return c;
	}
	return 0;
}



int main()
{
	string s="abcd";
	string t="abcde";
	cout<<findTheDifference(s,t);
	
}












