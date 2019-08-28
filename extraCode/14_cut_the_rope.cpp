#include<iostream>
//动态规划相关题目。
#include<vector>
using namespace std;

/**
 * 题目：剪绳子问题，一段长为8的绳子，然后剪成几段几段，这几段的乘积最大化，比如是2，3，3，乘积就是18；
 * 方法 动态规划
 * 思路：
 * 利用动态规划方法，这一部分详细要做，leetcode
 * */

int getfunc_N_num(int n)
{
	if(n<2) return 0;
	if(n==2) return 1;
	if(n==3) return 2;
	vector<int>temp(n+1,0);
	// 这些都是子问题的最优解，可以认为是不需要剪切的绳子长度；
	temp[0]=0;
	temp[1]=1;
	temp[2]=2;
	temp[3]=3;
	int max_num = 0;
	for(int i=4;i<=n;i++) //从4开始计算。前面都已经有了结果
	{
		max_num=0;
		for(int j=1;j<=n/2;j++)
		{
			max_num = max(temp[j]*temp[i-j],max_num);
		}
		temp[i] = max_num;
	}
	return max_num;
}

// 方法2 使用规律，证明一个数，最多是拆成两个2和
int maxProduct(int n)
{
	// boundary condition
	if(n==3) return 2;
	if(n==2) return 1;
	if(n<2) return 0;

	int res = 1;
	if(n%3==1) res *= 4, n-=4; // 如果是余1的话，那么就是两个2相乘，然后再减去4
	if(n%3==2) res *= 2, n-=2; // 如果是余2的话，那么就是只有1个2，减去2；
	while(n)
	{
		n/=3;
		res*=3;
	}
	return res;
}

int main()
{
	cout<<getfunc_N_num(8)<<endl;

	cout<<maxProduct(4)<<endl;
}

