#include<iostream>
#include<vector>
using namespace std;

/*
    矩阵中有0的话，那就这个0的行列都是0即可；
        Input: 
    [
    [1,1,1],
    [1,0,1],
    [1,1,1]
    ]
    Output: 
    [
    [1,0,1],
    [0,0,0],
    [1,0,1]
    ]
*/ 
void print(vector<vector<int>>& res);
void setZeroes(vector<vector<int>>& matrix) 
{
    int rows = matrix.size(), cols = matrix[0].size();
    int i=0,j=0;
    bool rowFlag=false,colFlag = false;
    while(i<cols)
    {
        if(matrix[0][i++]==0) 
        {
            rowFlag = true;
            break;
        }
    }
    while(j<rows)
    {
        if(matrix[j++][0]==0)
        {
            colFlag = true;
            break;
        } 
    }

    // 如果是0的话，那么对应的第一行的或者第一列的对应数字设置为0
    for( i=1;i<rows;i++)
    {
        for(j=1;j<cols;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }

    // 检查，如果是第一行对应的为的位置是0，整列都是设置0.两种写法。我个人建议第二种，清晰
    for(i = 1;i<rows;i++) // 第一种写法。 合并了第二种写法的两个特点
    {
        for(j=1;j<cols;j++)
        {
            if(matrix[0][j]==0 || matrix[i][0]==0)
            {
                matrix[i][j]=0;
            }
        }
    }
    // 第二种方法 在对矩阵补0 的时候更加思路自然
    // for(i = 1;i<cols;i++)
    // {
    //     if(matrix[0][i]==0)
    //     {
    //         for( j=1;j<rows;j++)
    //         {
    //             matrix[j][i] = 0;
    //         }
    //     }
    // }

    // for(i=1;i<rows;i++)
    // {
    //     if(matrix[i][0]==0)
    //     {
    //         for(j=1;j<cols;j++)
    //         {
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }
    // while(i<cols)
    // {
    //     int setrow=0;
    //     if(matrix[0][i]==0)
    //     {
    //         matrix[setrow][i] = 0;
    //         setrow++;
    //     }
    //     i++;
    // }

    // while(j<rows)
    // {
    //     int setcol=0;
    //     if(matrix[j][0]==0)
    //     {
    //         matrix[j][setcol] = 0;
    //         setcol++;   
    //     }
    //     j++;
    // }
   
    if (rowFlag) 
    {
        for (int i = 0; i < cols; ++i) matrix[0][i] = 0;
    }
    if(colFlag) 
    {
        for (int i = 0; i < rows; ++i) matrix[i][0] = 0;
    }
}
void print(vector<vector<int>>& res)
{
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> res ={{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(res);
    print(res);
    
}