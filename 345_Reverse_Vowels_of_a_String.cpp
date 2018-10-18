#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



//method1 从两头向中间判断是否是元音，如果是的话就交换，否则左边是元音右边不是，那么右边自减一，反之左边自加1；
bool isVowel(char c)
{
	return c=='a' || c=='e'|| c=='i'|| c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

string reverseVowels1(string s)
{
	int left=0,right = s.size()-1;
	while(left<right)
	{
		if(isVowel(s[left]) && isVowel(s[right]))
			swap(s[left++],s[right--]);
		else if(isVowel(s[left])) --right;
		else ++left;
	}
	return s;
	
}



//method2
string reverseVowels2(string s)
{
	int left=0,right = s.size()-1;
	while(left<right)
	{
		left = s.find_first_of("aeiouAEIOU",left);
		right = s.find_first_of("aeiouAEIOU",right);
		if(left<right)
		{
			swap(s[left++],s[right--]);
		}
	}
	return s;
	
}

int main()
{
	int left;
	string a;
	cin>>a;
	cout<<"reverse:"<<endl;
	cout<<reverseVowels2(a);

	
}


//the usage of find /find_first_of    by heat_nan  from ZZULI

// int main()
// {
	// string str1("Hi,every one! I am heat_nan from ZZULI. one");
	// string str2("heat_nan");
	// int k=str1.find(str2);
	// cout<<"The position of 'heat_nan' is "<<k<<endl;
	// int k1=str1.find("one");
	// cout<<"The postion of the first 'one' is "<<k1<<endl;
	// int k2=str1.find("one of",k1+1,3);
	// cout<<"The postion of the second 'one' is "<<k2<<endl;
	// int k3=str1.find_first_of("aeiou");//here k3=1
	// while(k3!=string::npos)      //hint:  here "string::npos"means find failed
	// {
		// str1[k3]='*';
		// k3=str1.find_first_of("aeiou",k3+1);
	// }
	// cout<<str1<<endl;
	// return 0;

// }











