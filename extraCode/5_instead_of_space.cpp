#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * 题目：替换空格
 * 方法1 利用replace函数来做
 * 思路：
 * replace函数
 * char *p = a;
	p = &a[5] 或者是 p = a+4，都是从第四个开始把地址给p,但是输出的数值是从当前开始的字符串，而不是单个字符！
	最好还是用字符数组的小标来表示最好;
*/
string stead_str(string a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==' ')
		{
			a.replace(i,1,"%20"); //i是起始位置，1是替换的字符个数，后面的是替换的内容。
		}
	}
	return a;
}

/**
 * 方法2 利用两个指针来做
 * 思路：
 * 求出原来的长度之后，加上新的长度*2,构成一个新的字符串的长度，然后从最后以为往前复制即可，遇到空格，就替换为%20；
*/
void replace_str(char a[],int length)
{
	if(length<0)// 原来的长度是0直接退出
		return ;
	int strlength=0, i=0;
	while(a[i++]!='\0')// 计算字符串的真实长度；
	{
		strlength++;
	}	
	int p1; //设置两个指针，一个指向原来的最后一位；
	int p2=0; //先计算空格的个数。
	int spaceCount=0;
	while(a[p2++]!='\0')
	{
		if(a[p2]==' ')
		{
			spaceCount++;
		}
	}
	
	int newlength = spaceCount*2+strlength;//计算加上替换之后的字符的总长度。
	//下面开始替换；将p1指向原始的最后以为，p2指向修改后的最后一位；
	p1 = strlength;  // 13
	p2 = newlength;  // p2指向修改后的最后一位,17
	
	while(p1>=0 && p2>p1)
	{
		if(a[p1]!=' ')
		{
			a[p2] = a[p1];
			p2--;
			p1--;
		}
		else
		{
			p1--;
			a[p2--]='0';
			a[p2--]='2';
			a[p2--]='%';	
		}
	}
	p1--;
	for(int i=0; i<20; i++)
		cout<<a[i];
}

// 自己做的，和上面的是一样的；
void replace_str1(char a[], int length)
{
	if(a==nullptr || length<0)
	{
		return ;
	}
	// 统计空格的个数
	int p1=0, p2=0, realLength=0;
	int spaceCount=0;
	while(a[p1]!='\0')
	{
		if(a[p1++]==' ') spaceCount++;
	}
	// 统计字符串的真是长度
	while(a[p2++]!='\0')
	{
		realLength++;
	}
	int newLength = realLength + spaceCount*2;
	p1 = realLength, p2 = newLength;
	while(p1>=0)
	{
		if(a[p1]!=' ')
		{
			a[p2--] = a[p1--];
		}
		else
		{
			a[p2--] = '0';
			a[p2--] = '2';
			a[p2--] = '%';
			p1--;
		}
	}
}

int main()
{
	//方法一，直接用replace函数代替
	// string a = "We are happy.";
	// cout<<stead_str(a)<<endl;
	
	
	//方法二，一个一个移，时间复杂度是O(n);
	char str[20]="We are happy.";
	int length = sizeof(str);
	replace_str1(str,length);
	// for(int i=0; i<20; i++)
	// 	cout<<str[i];
	cout<<str<<endl;
	
	// char str1[] = "hello world";
	// char str2[] = "hello world";
	// const char *str3 = "hello world";
	// const char *str4 = "hello world";
	// if(str1==str2) cout<<"yes";
	// else cout<<"no"<<endl;
	
	// if(str3==str4)
	// 	cout<<"yes"<<endl;
	// else cout<<"no"<<endl;
	
	return 0;
}






















