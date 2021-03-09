/*500. Keyboard Row
判断输入的单词是否在键盘的一行可以输出
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

bool is_instring(string s,string t)
{
	int count = 0;
	for(auto i:t)
	{
		if(s.find(i)!=string::npos) count++;
	}
	if(t.size()==count)
		return true;
	else
		return false;
}

vector<string> findWords(vector<string>& words) 
{
	vector<string> res;
	vector<string>temp ={"QWERTYUIOPqwertyuiop","ASDFGHJKLasdfghjkl","ZXCVBNMzxcvbnm"};
	for(int i=0;i<words.size();i++)
	{
		for(int j=0;j<3;j++)
		{
			if(is_instring(temp[j],words[i]))
			{
				res.push_back(words[i]);
				break;
			}
				
		}
	}
	return res;
}




int main()
{
	

	vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
	// cout<<words[0];
	vector<string> res = findWords(words);
	
	// cout<<is_instring("QWERTYUIOPqwertyuiop","Hello");
	for(auto i:res)
		cout<<i<<" ";
	
	
	
	
	// string s = "QWERTYUIOPqwertyuiop";
	// string t = "Hello";
	// int count = 0;
	// for(auto i:t)
	// {
		// if(s.find(i)!=string::npos)
			// cout<<i<<" ";
	// }
	
	// if(t.size()==count)
		// return true;
	// else
		// return false;
	
	return 0;

}
















































