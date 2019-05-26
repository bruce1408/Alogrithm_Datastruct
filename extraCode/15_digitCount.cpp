/*二进制中的1的个数*/
#include<iostream>
using namespace std;

//传统解法，换成二进制，然后余数加起来
int digitCount1(int n)
{
	if(n<1) return 0;
	int count = 0;
	while(n)
	{
		count+=n%2;
		n = n/2;
	}
	return count;
}


//利用位运算,遇到有符号数会陷入死循环
int digitCount2(int n)
{
	if(n<1) return 0;
	int count = 0;
	while(n)
	{
		if(n&1)
			count++;
		n = n>>1;
	}
	return count;
}

//升级版
int digitCount3(int n)
{
	if(n<1) return 0;
	int count = 0;
	unsigned int i=1;
	while(i)
	{
		if(n&i)
			count++;
		i = i<<1;
	}
	return count;
}


int main()
{
	unsigned int n = 1;
	//无符号32位二进制数最后移位会到0。
	// while(n)
	// {
		// n =n<<1;
		// cout<<n<<endl;
	// }
	cout<<digitCount3(n);
}












