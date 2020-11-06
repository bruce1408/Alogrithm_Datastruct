/**
 * 蛇形矩阵打印出来
 * 
 * 输入的话是 3 3
 * 
 * 1 2 3
 * 8 9 4
 * 7 6 5 
*/
#include<iostream>
using namespace std;

/**
 * 使用偏移量算法
*/

int q[100][100];

int main()
{
    int n, m;
    cin>>n>>m;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    for(int i=0, j=0, d=0, k=1; k<=n*m; k++)
    {
        q[i][j] = k;
        int a = i+dx[d], b = j+dy[d];
        if(a < 0|| a>= n || b<0 || b >=m || q[a][b])
        {
            d = (d+1)%4;
            a = i+dx[d], b = j + dy[d];
        }
        i = a, j = b;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<q[i][j]<<" ";
        }
        cout<<endl;
    }
    
}