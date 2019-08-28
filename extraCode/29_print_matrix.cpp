#include<iostream>
#include<vector>
using namespace std;


class Solution
{
	public:
	void printMatrix(int res[][4],int rows,int columns)
	{
		if(res==nullptr)
			return ;

		int start = 0;

		while(rows>start*2 && columns>start*2)
		{
			printNums(res,rows,columns,start);
			++start;
		}
	}

	void printNums(int res[][4],int rows,int columns,int start)
	{
		int endrow = rows-1-start;
		int endcolumns = columns-1-start;
		//从左到右打印第一行
		for(int i=start;i<=endcolumns;i++)
		{
			int number = res[start][i];
			cout<<number<<" ";
		}
		//从上到下打印
		if(endrow>start)
		{
			for(int i=start+1;i<=endrow;i++)
			{
				int number = res[i][endrow];
				cout<<number<<" ";
			}
		}

		//从右到左打印
		if(start<endcolumns && start< endrow)
		{
			for(int i=endcolumns-1;i>=start;i--)
			{
				int number = res[endrow][i];
				cout<<number<<" ";
			}
		}

		// 从下到上打印
		if(start<endcolumns && start<=endrow-2)
		{
			for(int i=endcolumns-1;i>=start+1;i--)
			{
				int number = res[i][start];
				cout<<number<<" ";
			}
		}
	}

};

int main()
{
	Solution ss;
	int res[4][4];
	int num=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			res[i][j] = ++num;
	}

	ss.printMatrix(res,4,4);
	return 0;
}
