#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/**
 * 题目：数值的整数次方,不是用函数power，而是直接求解数值的帧数次方
 * 方法 
 * 思路：
 * 一是考虑边界条件，负面测试，功能测试
 * 二是尽量不用乘除操作，而是用与，或操作来替换，这样效率会很高
 * 三是 左移相当于乘以 2，右移是除以 2，和 1 做位与操作可以判断奇数还是偶数，异或也可以。
*/

// 时间复杂度是O(n)
double num_N(double num, double n)
{
	if(n>0)
	{
		vector<double>temp(n+1, 0.0);
		temp[0] = 0;
		temp[1] = num;
		temp[2] = num*num;
		for(int i=3;i<=n;i++)
		{
			temp[i] = temp[1]*temp[i-1];
		}
		return temp[n];
	}
	else if(n<0 && abs(num-0.0)<=1e-7)
		return 0.0;
	else if(n<0)
	{
		return 1.0/num_N(num, abs(n));
	}
	else
		return 1.0;
}

// 方法2：
double myPow(double x, int n)
{
	if(n==0) return 1.0;
	double half = myPow(x, n/2);
	if(n%2==0) return half * half;
	if(n>0) return half * half * x;
	return half * half /x;
}

int main()
{
	// solution 1;
	// double n;
	// double num;
	// cout<<"plea input a num"<<endl;
	// cin>>num;
	// cout<<"plea input a n"<<endl;
	// cin>>n;
	// cout<<"the num:"<<num<<": ^n is:"<<num_N(num,n)<<endl;
	cout<<myPow(4.0, -3)<<endl;

}