/*205. Isomorphic Strings
判断是否同构

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true
*/


/*451. Sort Characters By Frequency
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

/*第一种方法：哈希思路*/

bool isIsomorphic(string s, string t) 
{
	int m1[256] = {0}, m2[256] = {0}, n = s.size();
	for (int i = 0; i < n; ++i) 
	{
		if (m1[s[i]] != m2[t[i]]) return false;
		m1[s[i]] = i + 1;
		m2[t[i]] = i + 1;
	}
	return true;	
}


int main()
{
	string s = "tree";
	string t = "free";
	cout<<isIsomorphic(s,t);
	
	return 0;

}