#include<iostream>
#include<vector>
using namespace std;


//得到位数和函数
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

int main()
{
	// vector<vector<int>>temp =;
	cout<<getsumOfdigit(45)+getsumOfdigit(67)<<endl;
	cout<<countMove(3,4,2);
}