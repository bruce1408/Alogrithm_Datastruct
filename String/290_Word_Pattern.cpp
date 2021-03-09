/*290. Word Pattern

pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.


*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>

using namespace std;

/*第一种方法：哈希思路*/

bool wordPattern(string pattern, string str)
{
	istringstream in(str);
	unordered_map<char,int>m1;
	unordered_map<string,int>m2;
	int i=0;
	for(string word;in>>word;++i)
	{
		if(m1.find(pattern[i])!=m1.end() || m2.find(word)!=m2.end())
		{
			if(m1[pattern[i]]!=m2[word]) return false;
		}
		
		else
			m1[pattern[i]]=m2[word] = i+1;
	}
	return i==pattern.size();
	
}


int main()
{
	
	string s = "abba";
	string t = "dog cat cat dog";
	cout<<wordPattern(s,t);
	
	
	return 0;

}








