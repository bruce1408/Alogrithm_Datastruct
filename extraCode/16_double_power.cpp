#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/**
 * 题目：数值的整数次方,不是用函数power，而是直接求解数值的帧数次方
 * 方法 递归思路，考虑到负数的情况应该怎么去判断
 * 思路：
 * 利用递归的方法来做，递归每次如果n的次数是0次，那么直接输出1，然后每次递归折半n/2的方式进入递归，
 * 如果是n是偶数的话，那么就应该返回值**2，如果n>0的话,
 * 那么直接返回的是返回值**2*num，如果是小于0，那么就返回值**2/num；方法 3 和方法 4 都很好
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

// 方法2：利用递归来做
double myPow(double x, int n)
{
	if(n==0) return 1.0;
	double half = myPow(x, n/2);
	if(n%2==0) return half * half;
	if(n>0) return half * half * x;
	return half * half /x;
}

// 方法3：这种方法更愿意接受，因为逻辑上思路更好理解
// 递归的思想，如果n为0，那么直接返回递归终止条件，然后递归n/2,然后判断n是奇数还是偶数，如果是偶数，
// 那么就自乘，如果是奇数的话，乘上x，最后n小于0的话，那么就是除以自己
// 递归的时间是O(logn)，比起O(n)要小很多。
double myPow1(double x, int n)
{
	if(n==0) return 1.0;
	double half = myPow(x, n/2);
	if(n%2==0) return half * half;
	if(n>0) return half * half * x;
	else return half * half /x;
}

//方法4：按照迭代的思想来做, 我们让i初始化为n，然后看i是否是2的倍数，
// 如果不是的话res乘以x，同时 x每次要乘以自己，
// 相当于res * (x**2), i每次循环缩小一半，
// 直到为0停止循环。最后看n的正负，如果为负，返回其倒数
double myPow2(double x, int n)
{
	int res = 1.0;
	if(n==0) return 1.0;
	for(int i=n; i!=0; i/=2)
	{
		if(i%2!=0) res = res * x;
		x *= x;
	}
	return (n<0)? 1.0/res:res;
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
	cout<<myPow2(2, -3)<<endl;
}