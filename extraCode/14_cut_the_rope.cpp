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
	temp[0]=0;
	temp[1]=1;
	temp[2]=2;
	temp[3]=3;
	int max_num = 0;
	for(int i=4;i<=n;i++) //从4开始计算。前面都已经有了结果
	{
		max_num=0;
		for(int j=1;j<n/2;j++)
		{
			max_num = max(temp[j]*temp[i-j],max_num);
			temp[i] = max_num;
		}
	}
	// max_num = temp[n]; 可以取到n,不用再次赋值
	return max_num;

}

int main()
{
	cout<<getfunc_N_num(4)<<endl;
}
