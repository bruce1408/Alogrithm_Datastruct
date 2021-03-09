#include<iostream>
#include<string>
using namespace std;


//method1 利用swap函数来交换，然后从两头向中间互相交换
class Solution 
{
	public:
		string reverseString(string s) 
		{
			int left = 0, right = s.size() - 1;
			while (left < right) 
			{
				swap(s[left++], s[right--]);
			}
			return s;
		}
};


//method2  从元素的最后一个到第一个逆序构成一个新的string。
string reverseString(string s)
{
	if(s.size()<=0)
		return "";
	string res;
	for(int i=s.size()-1;i>=0;i--)
		res+=s[i];
	return res;
}



int main()
{
	string a;
	cin>>a;
	cout<<"reverse:"<<endl;
	cout<<reverseString(a);
	
}