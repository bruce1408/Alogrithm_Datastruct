#include<iostream>
#include<vector>
using namespace std;
/**
 * 题目：求解斐波那契数列的第n项
 * 方法1 
 * 思路：取巧的思路，就是给三个变量，然后x=a+b，输出最后的x；
*/

long long faboni(int n)
{
	int result[2]={0,1};
	if(n<2)
		return result[n];
	long long a = 1, b = 0, x = 0;
	for(unsigned int i=2;i<=n;i++)
	{
		x = a+b;
		b = a;
		a = x;
	}
	return x;
}

/**
 * 题目：青蛙跳台阶，第n阶台阶有几种跳法，要么一次跳1阶，要么跳2阶；
 * 方法 利用斐波那契的求第n个数的方法来做，
 * 思路：
 * 第一阶只有1种方法，第二阶有2种跳法，第三种是3种，1+2=3，所以和斐波那契思路一样；
*/

long long stepN(int n)
{
	int rest[2] = {1,2};
	if(n<=2)
		return rest[n-1];
	long long a = 2, b = 1, x = 0;
	for(unsigned int i=3;i<=n;i++) // 从台阶3开始
	{
		x = a+b;
		b = a;
		a = x;
	}
	return x;
}

int main()
{
	//斐波那契
	// for(int n=0;n<50;n++)
		// cout<<faboni(n)<<" ";
	//青蛙跳台阶
	for(int n=1;n<50;n++)
		cout<<stepN(n)<<" ";
	cout<<endl;
	return 0;
}
