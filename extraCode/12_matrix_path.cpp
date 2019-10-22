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
 * 存在路径 bfcc, 但是不存在 abfb
 * 方法 利用
 * 思路：如果每一个位置的数在上下左右存在，那么就是true, 否则, false, 同时, 退回到前一个字母的判断当中去;
 * 发散 leetcode 79题 属于backtracking 回溯算法;研究一下回溯算法
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

/**
 * 方法2 在上面判断上下左右移动的时候比较麻烦，可以继续优化
 * 思路：
 * 和上面的思路是一样的，但是唯一不同的就是这里我们不再使用冗长的判断上、下、左、右的判断，优化这部分代码
 * */ 
bool search(vector<vector<char>> &matrix_char, string str, int index, int i, int j)
{
	if(index==str.size()) return true; // index的长度是字符的长度，找到了
	if(i<0 || j<0 || i>=matrix_char.size() || j>=matrix_char[0].size() || matrix_char[i][j]!=str[index])
		return false;
	int positionX[4] = {0, 0, -1, 1}, positionY[4] = {-1, 1, 0, 0};
	char t = matrix_char[i][j];
	matrix_char[i][j]='*';
	for(int i=0;i<4;i++)
	{
		int x_ = positionX[i] + i, y_ = positionY[i] + j;
		if(x_ >=0 && y_>=0 && x_ < matrix_char.size() && y_ < matrix_char[y_].size())
		{
			if (search(matrix_char, str, index+1, x_, y_)) return true;
		}
	}
	matrix_char[i][j] = t;
	return false;
}

bool exist(vector<vector<char>> &matrix_char, string str)
{
	if(str.empty()) return true;
	if(matrix_char.empty()) return false;
	for(int i=0; i<matrix_char.size(); i++)
	{	
		for(int j=0; j<matrix_char[0].size(); j++)
		{
			if(search(matrix_char, str, 0, i, j)) return true;
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
	cout<<exist(matrix_char,a)<<endl;	
}






















