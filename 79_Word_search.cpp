#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


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
		--index;
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
	
	if(exist(matrix_char,a))
		cout<<"find a path in matrix;"<<endl;
	else
		cout<<a<<" :has no path in matrix;"<<endl;
	return 0;
		
}
































