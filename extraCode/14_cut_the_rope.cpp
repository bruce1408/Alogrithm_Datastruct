#include<iostream>
//动态规划相关题目。
#include<vector>
using namespace std;

//3的时候是2，为什么4的时候是3？不是4？

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
