#include<iostream>
#include<cmath>
using namespace std;

/**
 * 输入两个整数n和m，输出一个n行m列的矩阵，将数字 1 到 n*m 按照回字蛇形填充至矩阵中。
 * 具体矩阵形式可参考样例。
 * 输入格式,输入共一行，包含两个整数n和m。
 * 输出格式,输出满足要求的矩阵。
 * 矩阵占n行，每行包含m个空格隔开的整数。
 * 
 * 数据范围
 * 
 * 1≤n,m≤100
 * 输入样例：
 * 3 3
 * 
 * 输出样例：
 * 1 2 3
 * 8 9 4
 * 7 6 5
*/
int t[100][100];

int main()
{
    int n=3, m=3;
    // cin>>n>>m;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    
    for(int i=0, j=0, d=0, k=1; k<=n*m;k++)
    {
        t[i][j] = k;
        int a = i+dx[d], b = j+dy[d];
        if(a<0 || a>=n || b<0 || b>=m || t[a][b])
        {
            d = (d+1)%4;
            a = i+dx[d], b = j+dy[d];
        }
        
        i = a, j = b;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


#include <iostream>

using namespace std;
const int N = 105;

int a[N][N];
int n, m;

int main() {
    cin >> n >> m;

    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    int k = 1;
    while (left <= right && top <= bottom) {
        for (int i = left ; i <= right; i ++) {
            a[top][i] = k ++;
        }
        for (int i = top + 1; i <= bottom; i ++) {
            a[i][right] = k ++;
        }
        for (int i = right - 1; i >= left && top < bottom; i --) {
            a[bottom][i] = k ++;
        }
        for (int i = bottom - 1; i > top && left < right; i --) {
            a[i][left] = k ++;
        }
        left ++, right --, top ++, bottom --;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}