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
string frequencySort(string s)
{
	string res;
	unordered_map<char,int>temp;
	for(char i:s) ++temp[i];
	
	
	
	
	
}



int main()
{
	string s = "tree";
	cout<<frequencySort(s);
	
	return 0;

}






















