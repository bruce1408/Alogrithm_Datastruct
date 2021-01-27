#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/**
 * 79 单词搜索
 * 给定一个二维的字符数组，然后和一个目标单词，在二维字符数组中找到这个单词
 * 字符不允许重复使用
*/

class Solution {
public:
	bool hasPath(vector<vector<char>> &matrix,string str)
	{
		if(matrix.empty())
			return false;
		//定义一个辅助矩阵，用来标记路径是否已经进入了每个格子
		vector<vector<bool>>visited(matrix.size(),vector<bool>(matrix[0].size(),false)); 
		int pathLength = 0;
		for (int row = 0;row < matrix.size();++row)                //该循环是为了实现从任何一个位置出发，寻找路径
		{
			for (int col = 0; col < matrix[0].size();++col)
			{
				if (hasPathCore(matrix,row, col, str, pathLength, visited))
					return true;
			}
		}
		return false;
	}

	/*此函数用来判断在当前路径满足条件下，相邻格子中是否存在一个格子满足条件*/
	bool hasPathCore(vector<vector<char>> &matrix,int row, int col, string str, int& pathLength, vector<vector<bool>> &visited)
	{
		if (str.size() == pathLength)
			return true;
		bool hasPath = false;
		if (row >= 0 && row < matrix.size()&&col >= 0 && col < matrix[0].size()&&matrix[row][col] == str[pathLength] && !visited[row][col])
		{
			++pathLength;
			visited[row][col] = true;
			/*如果矩阵格子(row,col)与路径字符串中下标为pathLength的字符一样时，
			从它的4个相邻格子中寻找与路径字符串下标为pathLength+1的字符相等的格子*/
			hasPath = hasPathCore(matrix,row, col - 1, str, pathLength, visited) || 
				hasPathCore(matrix,row - 1, col, str, pathLength, visited) || 
				hasPathCore(matrix,row, col + 1, str, pathLength, visited) || 
				hasPathCore(matrix,row + 1, col, str, pathLength, visited);
			if (!hasPath)                                  
			{
				--pathLength;           //如果没找到，则说明当前第pathLength个字符定位不正确，返回上一个位置重新定位
				visited[row][col] = false;
			}
		}
		return hasPath;
	}
};



//换汤不换药
bool search(vector<vector<char>> &matrix_char,string str,int index,int i, int j,vector<vector<bool>> &visited)
{
	if(index==str.size()) return true;
	if(i<0 || j<0 || i>=matrix_char.size() || j>=matrix_char[0].size() || visited[i][j] || matrix_char[i][j]!=str[index])
		return false;
	
	visited[i][j]=true;
	// cout<<i<<""<<j<<endl;
	bool res = search(matrix_char,str,index+1,i-1,j,visited)
	||search(matrix_char,str,index+1,i+1,j,visited)
	||search(matrix_char,str,index+1,i,j-1,visited)
	||search(matrix_char,str,index+1,i,j+1,visited);
	
	
	if(!res)  //如果是res=false，既没有匹配到下一个字符，就是当前的字符在矩阵的位置不正确，重新调整，让这个值设成false，然后
	{
		// cout<<"error"<<i<<""<<j<<endl;
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
	Solution ss;
	
	if(ss.hasPath(matrix_char, a))
	// if(exist(matrix_char,a))
		cout<<"find a path in matrix;"<<endl;
	else
		cout<<a<<" :has no path in matrix;"<<endl;
	return 0;
		
}





























