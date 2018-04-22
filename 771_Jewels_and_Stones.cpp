/*771. Jewels and Stones

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>

using namespace std;



int numJewelsInStones(string j, string s)
{
	unordered_map<char,int>temp;
	int res = 0;
	for(int i=0;i<s.size();i++) ++temp[s[i]];
	for(auto i:j)
	{
		if(temp.find(i)!=temp.end())
			res+=temp.find(i)->second;	
	}
	return res;
}


int main()
{
	
	string j = "aA";
	string s = "aAAbbbb";
	cout<<numJewelsInStones(j,s);
	
	
	return 0;

}
