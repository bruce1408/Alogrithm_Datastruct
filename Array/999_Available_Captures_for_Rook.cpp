#include <iostream>
#include <vector>
using namespace std;
/**
 * On an 8 x 8 chessboard, there is one white rook.  
 * There also may be empty squares, white bishops, and black pawns. 
 * These are given as characters 'R', '.', 'B', and 'p' respectively.
 * Uppercase characters represent white pieces,
 * and lowercase characters represent black pieces.
 * The rook moves as in the rules of Chess: 
 * it chooses one of four cardinal directions (north, east, west, and south),
 * then moves in that direction until it chooses to stop, 
 * reaches the edge of the board, 
 * or captures an opposite colored pawn by moving to the same square it occupies.
 * Also, rooks cannot move into the same square as other friendly bishops.
 * Return the number of pawns the rook can capture in one move.
 * 
 * 在一个8*8的棋盘上，有四个类型的棋子，分别是R,.,B,p,他们分别代表了车，空方格，主教，和兵，大写的是
 * 白方，小写的字母表示黑方，车可以上下左右移动，返回在移动一步的情况下可以捕捉到的兵的个数；
*/
int numRookCaptures(vector<vector<char>> &board)
{
    int tempi = 0, tempj = 0, count = 0;
    const int N = 8;
    bool upBool = true, downBool = true, leftBool = true, rightBool = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 'R')
            {
                tempi = i;
                tempj = j;
                break;
            }
        }
    }
    cout << tempi << " " << tempj << endl;
    // 上
    for (int up = tempi; up >= 0; up--)
    {
        if (board[up][tempj] == 'B')
        {
            break;
        }
        if (board[up][tempj] == 'p')
        {
            count += 1;
            break;
        }
    }
    // 下
    for (int down = tempi; down < board[0].size(); down++)
    {
        if (board[down][tempj] == 'B')
        {
            break;
        }
        if (board[down][tempj] == 'p')
        {
            count += 1;
            break;
        }
    }
    // 左
    for (int left = tempj; left >= 0; left--)
    {
        if (board[tempi][left] == 'B')
        {
            break;
        }
        if (board[tempi][left] == 'p')
        {
            count += 1;
            break;
        }
    }
    // 右
    for (int right = tempj; right < board[0].size(); right++)
    {
        if (board[tempi][right] == 'B')
        {
            break;
        }
        if (board[tempi][right] == 'p')
        {
            count += 1;
            break;
        }
    }
    return count;
}

// int main()
// {
//     vector<vector<char>> res =
//     {{".",".",".",".",".",".",".","."},
//     {".",".",".","p",".",".",".","."},
//     {".",".",".","R",".",".",".","p"},
//     {".",".",".",".",".",".",".","."},
//     {".",".",".",".",".",".",".","."},
//     {".",".",".","p",".",".",".","."},
//     {".",".",".",".",".",".",".","."},
//     {".",".",".",".",".",".",".","."}};
//     numRookCaptures(res);
// }

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0;
        //four directions
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if(board[i][j] == 'R')
                {
                    for(int dir = 1; dir <= 4; ++dir)
                    {
                        dfs(board,i,j,res,dir);
                    }
                }
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int& res, int dir){
        if(i < 0||i >= board.size()||j < 0||j >= board[0].size()||board[i][j]=='B') 
        {
            return ;
        }
        if(board[i][j] == 'p') 
        {
            res++;
        }
        else 
        {
            dfs(board,i + ((dir % 2) ? dir - 2 : 0),j + (!(dir % 2) ? dir - 3 : 0), res, dir);
        }
    }
};



int main()
{
    vector<vector<int>> res =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    int i = 0, j = 0, tempi = 0, tempj = 0;
    for (i=0; i < 3; i++)
    {
        for (j=0; j < 3; j++)
        {
            int temp = res[i][j];
            if (res[i][j] == 4)
            {
                tempi = i, tempj = j;
                i = 3, j = 3;
            }
        }
    }
    cout << tempi << " " << tempj << endl;
}