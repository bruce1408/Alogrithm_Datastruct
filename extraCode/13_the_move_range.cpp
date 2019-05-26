#include<iostream>
#include<vector>
using namespace std;

/**
 * 题目：机器人运动范围，在m行n列的方格，机器人每次可以上，下，左，右移动，从(0, 0)坐标开始，
 * 坐标数位之和大于k的格子，当k是18的时候，(35, 37) 3+5+3+7=18可以满足，问机器人可以到达多少格子
 * 方法 回溯算法
 * 思路：
 * 
*/
int getsumOfdigit(int n)
{
	int i=0;
	while(n)
	{
		i+=n%10;
		n = n/10;
	}
	
	return i;
}


bool check(int m,int n,int i,int j,int key,vector<vector<bool>> &visited)
{
	if(i>=0&&j>=0&&i<m&&j<n&&getsumOfdigit(i)+getsumOfdigit(j)<=key&&!visited[i][j]) return true;
	return false;
}


int countCore(int m,int n,int i,int j,int key,vector<vector<bool>> &visited)
{
	int count = 0;
	if(check(m,n,i,j,key,visited))
	{
		visited[i][j]=true;
		count = 1+countCore(m,n,i,j+1,key,visited)+countCore(m,n,i,j-1,key,visited)+countCore(m,n,i-1,j,key,visited)+countCore(m,n,i+1,j,key,visited);
	}
	return count;
}


int countMove(int m,int n, int key)
{
	
	if(key<0 || m<=0 || n<=0) return 0;
	vector<vector<bool>>visited(m,vector<bool>(n,false));
	
	int count = countCore(m,n,0,0,key,visited);
	return count;
	
}

// 第二遍做题；先写一个数位和的函数
int digitSum(int x)
{
	int sum=0;
	while(x!=0)
	{
		sum+=x%10;
		x=x/10;
	}
	return sum;
}

int movingCount1(int num, int rows, int columns)
{
	int count=0;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<columns; j++)
		{
			if(digitSum(i) + digitSum(j) == num)
			{
				count++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	return count;
}

int main()
{
	// vector<vector<int>>temp =;
	cout<<countMove(3,4,2)<<endl;
	cout<<digitSum(1099)<<endl;
	cout<<movingCount1(18, 40, 40)<<endl;
}