#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * 题目：求解斐波那契数列的第n项
 * 方法1 递归的思想
 * 思路：给定递归的结束条件和递归判别式，但是时间复杂度极高，是O(2^n)每次递归的次数*递归总数,
 * 大约到 n=50 就算不动了，重复计算项太多，递归到一定的程度，会发生栈溢出，
*/

long long faboni1(int n)
{
	if(n<=1) return 1;
	return (faboni1(n - 1) + faboni1(n-2)); 
}

/**
 * 方法2 利用滚动递归变量的方法
 * 思路
 * 斐波那契数列计算只需要前两项即可，没有必要记录所有的数值，利用滚动变量递归即可
 * 时间复杂度是O(n)
*/

long long faboni2(int n)
{
	int result[2]={1, 1};
	if(n<2)
		return result[n];
	long long a = 1, b = 1, x = 0;
	for(unsigned int i=2;i<=n;i++)
	{
		x = a+b;
		b = a;
		a = x;
	}
	return x;
}

/**
 * 方法3 矩阵运算 + 快速幂 计算
 * 思路：
 * 利用快速幂和矩阵计算
*/
void mul(int a[][2], int b[][2], int c[][2])
{
	int temp[][2] = {{0, 0}, {0, 0}};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				temp[i][j] += a[i][k]*b[k][j];
			}
		}
	}

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c[i][j] = temp[i][j];
		}
	}
}

long long faboni3(int n)
{
	int x[2] = {1, 1};
	// int a[2][2] = {{1, 1},{1, 0}};
	int I[][2] = {{1, 0},{0, 1}};
	int E[][2] = {{1, 1},{1, 0}};
	int k = n - 1;
	while(k)
	{
		if(k&1) mul(I, E, I);
		mul(E, E, E);
		k>>=1;
	}

	int res[2] = {0, 0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			res[i] = res[i] + x[i] * I[i][j];
		}
	}
	return res[0];
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
	for(int n=1;n<5;n++)
		cout<<faboni2(n)<<" ";
	//青蛙跳台阶
	// for(int n=1;n<50;n++)
	// 	cout<<stepN(n)<<" ";
	// cout<<endl;
	return 0;
}
