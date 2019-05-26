#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/**
 * 题目：请设计一个函数，用来判断矩阵中是否存在一条包含字符串所有字符的路径，每一步可以在矩阵中移动上、下、左、右各一格子。
 * 例如:
 * a  b  t  g
 * c  f  c  s
 * j  d  e  h
 * 存在路径 bfcc，但是不存在 abfb
 * 方法 利用
 * 思路：
 * 
*/
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
			return false;
		bool* visited = new bool[rows*cols];              //定义一个辅助矩阵，用来标记路径是否已经进入了每个格子
		memset(visited, 0, rows*cols);
		int pathLength = 0;
		for (int row = 0;row < rows;++row)                //该循环是为了实现从任何一个位置出发，寻找路径
		{
			for (int col = 0; col < cols;++col)
			{
				if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
					return true;
			}
		}
		delete[] visited;
		return false;
	}

	/*此函数用来判断在当前路径满足条件下，相邻格子中是否存在一个格子满足条件*/
	bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited)
	{
		if (str[pathLength] == '\0')
			return true;
		bool hasPath = false;
		if (row >= 0 && row < rows&&col >= 0 && col < cols&&matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col])
		{
			++pathLength;
			visited[row*cols + col] = true;
			/*如果矩阵格子(row,col)与路径字符串中下标为pathLength的字符一样时，
			从它的4个相邻格子中寻找与路径字符串下标为pathLength+1的字符相等的格子*/
			hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) || 
				hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) || 
				hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) || 
				hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);
			if (!hasPath)                                  
			{
				--pathLength;           //如果没找到，则说明当前第pathLength个字符定位不正确，返回上一个位置重新定位
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}
};





bool search(vector<vector<char>> &matrix_char,string str,int index,int i, int j,vector<vector<bool>> &visited)
{
	if(index==str.size()) return true;
	if(i<0 || j<0 || i>=matrix_char.size() || j>=matrix_char[0].size() || visited[i][j] || matrix_char[i][j]!=str[index])
		return false;
	
	visited[i][j]=true;
	cout<<i<<""<<j<<endl;
	bool res = search(matrix_char,str,index+1,i-1,j,visited)
	||search(matrix_char,str,index+1,i+1,j,visited)
	||search(matrix_char,str,index+1,i,j-1,visited)
	||search(matrix_char,str,index+1,i,j+1,visited);
	
	
	if(!res)  //如果是res=false，既没有匹配到下一个字符，就是当前的字符在矩阵的位置不正确，重新调整，让这个值设成false，然后
	{
		--index;
		cout<<"error"<<i<<""<<j<<endl;
		visited[i][j]=false;
	}
	
	return res;
}


bool exist(vector<vector<char>> &matrix_char,string str)
{
	if(str.empty()) return true;
	if(matrix_char.empty()) return false;
	vector<vector<bool>>visited(matrix_char.size(),vector<bool>(matrix_char[0].size(),false));
	for(int i=0;i<matrix_char.size();i++)
	{	
		for(int j=0;j<matrix_char[0].size();j++)
		{
			if(search(matrix_char,str,0,i,j,visited)) return true;
		}
	}
	return false;
	
}




int main()
{
	vector<vector<char>> matrix_char= {
		{'a','b','t','g'},
		{'c','f','c','s'},
		{'j','d','e','h'}		
	};
	cout<<"input a string"<<endl;
	string a;
	cin>>a;
	
	cout<<exist(matrix_char,a);
		
}























