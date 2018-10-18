#include<iostream>
#include<string>
using namespace std;


//method1 利用isalnum()函数来判断isalnum判断数字和字母，返回的是true，如果是其他字符，那么返回false
//把原来那些非字母和数字的符号去掉，然后构成一个新的字符串，判断字符串是否是回文字符串
// bool dealpa(string temp)
// {
	// int left=0,right=temp.size()-1;
	// while(left<right)
	// {
		// if((temp[left]+32-'a')%32==(temp[right]+32-'a')%32)
		// {
			// left++;
			// right--;
		// }
		// else return false;
	// }
	// return true;
// }

// bool isPalindrome(string s) 
// {
	// if(s.size()==0) return true;
	// string temp;
	// for(int i=0;i<s.size();i++)
	// {
		// if(isalnum(s[i])) temp+=s[i];
	// }
	// cout<<temp<<endl;
	// return dealpa(temp);
// }

//method2 不用构成新的字符串，直接判断
bool isPalindrome(string temp)
{
	int left=0,right=temp.size()-1;
	while(left<right)
	{
		if(!isalnum(temp[left])) left++;
		else if(!isalnum(temp[right])) right--;
		else if((temp[left]+32-'a')%32!=(temp[right]+32-'a')%32) return false;
		else
		{
			left++;right--;
		}
	}
	return true;
}


int main()
{
	string a ="A man, a plan, a canal: Panama" ;
	// getline(cin,a);
	cout<<isPalindrome(a); 
	
	
	
}