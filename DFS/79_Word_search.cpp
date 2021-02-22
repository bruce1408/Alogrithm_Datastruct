#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/**
 * 79 单词搜索
 * 给定一个二维的字符数组，然后和一个目标单词，在二维字符数组中找到这个单词
 * 字符不允许重复使用
*/

/**
 * 方法 1，使用深度优先搜索
*/
bool dfs(vector<vector<char>> &board, string &word, int start, int x, int y)
{
	if (board[x][y] != word[start])
		return false;
	if (start == word.size() - 1)
		return true;
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

	char t = board[x][y];
	board[x][y] = '.'; // 用点表示已经走过了这个格子了
	for (int i = 0; i < 4; i++)
	{
		int a = dx[i] + x, b = dy[i] + y;
		if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.')
			continue;
		if (dfs(board, word, start + 1, a, b))
			return true;
	}
	board[x][y] = t;
	return false;
}

bool exist(vector<vector<char>> &board, string word)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (dfs(board, word, 0, i, j))
				return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> matrix_char =
		{
			{'a', 'b', 't', 'g'},
			{'c', 'f', 'c', 's'},
			{'j', 'd', 'e', 'h'}};

	string a = "absfd";

	if (exist(matrix_char, a))
		cout << "find a path in matrix;" << endl;
	else
		cout << a << " :has no path in matrix;" << endl;
	return 0;
}
